def num_elems : i64 = 2
def block_size : i64 = 2

module blocked_radix_sort = {
  def bit_chunk : i32 = 4

  def num_bins = 2 ** i64.i32 bit_chunk

  #[inline]
  def iota_stride (n: i64) (step: i64) (offset) : [n]i64 =
    iota n
    |> map ((+ offset) <-< (* step))

  #[inline]
  def gather [n] [m] 'a (as: [n]a) (is: [m]i64) : [m]a =
    map (\i -> #[unsafe] as[i]) is

  #[inline]
  def count 'a
            (f: a -> i64)
            (vs: [num_elems * block_size]a) : *[num_bins]i16 =
    let dest = rep 0
    in loop dest
       for i < num_elems do
         let js = iota_stride block_size num_elems i
         let is = gather vs js |> map f
         in reduce_by_index dest (+) 0 is (rep 1)

  #[inline]
  def get_bin 'a
              (get_bit: i32 -> a -> i32)
              (digit_n: i32)
              (a: a) : i64 =
    i64.i32
    <| (loop acc = 0
        for i < bit_chunk do
          acc + (get_bit (digit_n + i) a << i))

  #[inline]
  def expresum [n] (xs: [n]i64) : [n]i64 =
    map2 (-) (scan (+) 0 xs) xs

  #[inline]
  def sequential_offsets [k] (bins: [k]i16) : [k]i16 =
    (loop (offsets, acc) = (replicate k 0i16, 0i16)
     for i < k do
       #[unsafe]
       let offsets[i] = acc
       in (offsets, acc + bins[i])).0

  #[inline]
  def elems_reduce 'a
                   (f: a -> i16)
                   (as: [num_elems * block_size]a) : [block_size](i16, i16) =
    tabulate block_size (\i ->
                           let c =
                             loop acc = 0
                             for v in #[unsafe] as[i * num_elems:(i + 1) * num_elems] do
                               acc + f v
                           in (c, i16.(i64 num_elems - c)))

  #[inline]
  def add2 (a0: i16, a1: i16) (b0: i16, b1: i16) =
    (a0 + b0, a1 + b1)

  #[inline]
  def step 'a
           (digit_n: i32)
           (get_bit: i32 -> a -> i32)
           (as: [num_elems * block_size]a) =
    let as = manifest as
    let bins = count (get_bin get_bit digit_n) as
    let offsets = sequential_offsets bins
    let sorted =
      loop as
      for i < bit_chunk do
        let get = i16.i32 <-< get_bit (i + digit_n)
        let offsets =
          manifest (elems_reduce get as)
          |> scan add2 (0i16, 0i16)
        let (_, z) = #[unsafe] offsets[block_size - 1]
        let accs = manifest (replicate block_size (0i16, 0i16))
        let dst = manifest (#[scratch] copy as)
        let (dst, _) =
          loop (dst, accs)
          for k < num_elems do
            let is =
              iota_stride block_size num_elems k
              |> map3 (\(a1, a0) (p1, p0) j ->
                         let b = get as[j]
                         in i64.i16 (if b == 0
                                     then p0 + a0
                                     else z + p1 + a1))
                      accs
                      offsets
            let dst =
              scatter dst is (gather as (iota_stride block_size num_elems k))
            let accs =
              iota_stride block_size num_elems k
              |> map2 (\(a1, a0) j ->
                         let b = get as[j]
                         in (a1 + b, a0 + (1i16 ^ b)))
                      accs
            in (dst, accs)
        in dst
    in (sorted, bins, offsets)

  def sort [n] 'a
           (digit_n: i32)
           (get_bit: i32 -> a -> i32)
           (ass: [n * (num_elems * block_size)]a) =
    #[incremental_flattening(only_intra)]
    map (step digit_n get_bit) (unflatten ass)
}

entry main [n] (xss: [n][num_elems][block_size]i64) =
  blocked_radix_sort.sort 0 i64.get_bit (flatten (map flatten xss))
