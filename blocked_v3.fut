def num_elems : i64 = 2
def block_size : i64 = 2

module blocked_radix_sort = {
  def bit_chunk : i32 = 4

  def num_bins = 2 ** i64.i32 bit_chunk

  #[inline]
  def count 'a
            (f: a -> i64)
            (vs: [num_elems * block_size]a) : *[num_bins]i16 =
    let dest = rep 0
    in loop dest
       for i < num_elems do
         let is = map f vs[i::num_elems]
         in reduce_by_index dest (+) 0 is (rep 1)

  #[inline]
  def get_bin 'a
              (get_bit: i32 -> a -> i32)
              (digit_n: i32)
              (a: a) : i64 =
    i64.i32
    <| loop acc = 0
       for i < bit_chunk do
         acc + (get_bit (digit_n + i) a << i)

  #[inline]
  def expresum [n] (xs: [n]i64) : [n]i64 =
    map2 (-) (scan (+) 0 xs) xs

  #[inline]
  def sequential_offsets [k] (bins: [k]i16) : [k]i16 =
    (loop (offsets, acc) = (replicate k 0i16, 0i16)
     for i < k do
       let offsets[i] = acc
       in (offsets, acc + bins[i])).0

  #[inline]
  def elems_reduce 'a
                   (f: a -> i16)
                   (as: [num_elems * block_size]a) : [block_size](i16, i16) =
    tabulate block_size (\i ->
                           let c =
                             loop acc = 0
                             for v in as[i::num_elems] do
                               acc + f v
                           in (c, i16.(i64 num_elems - c)))

  def add2 (a0: i16, a1: i16) (b0: i16, b1: i16) =
    (a0 + b0, a1 + b1)

  def gather [n] [m] 'a (as: [n]a) (is: [m]i64) : [m]a =
    map (\i -> #[unsafe] as[i]) is

  def sort_block 'a
                 (get_bit: i32 -> a -> i32)
                 (ith_digit: i32)
                 (as: [num_elems * block_size]a) : [num_elems * block_size]a =
    let get = i16.i32 <-< get_bit ith_digit
    let offsets =
      elems_reduce get as
      |> scan add2 (0, 0)
    let (o, _) = #[unsafe] offsets[block_size - 1]
    let accs = replicate block_size (0i16, 0i16)
    let (as, _) =
      loop (as, accs)
      for k < num_elems do
        let js = #[trace] sized block_size (k..(num_elems + k)..<num_elems * block_size)
        let is =
          map3 (\i j (a0, a1) ->
                  let f = #[unsafe] get as[j]
                  let (o0, o1) = if i == 0 then (0i16, 0i16) else #[unsafe] offsets[i - 1]
                  in i64.i16 (if f == 1
                              then o0 + a0
                              else o + o1 + a1))
               (iota block_size)
               js
               accs
        let vs = gather as js
        let as = scatter (#[scratch] copy as) is vs
        let accs =
          map2 (\(a0, a1) v ->
                  let i = get v in (a0 + i, a1 + (1 ^ i)))
               accs
               vs
        in (as, accs)
    in as

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
        sort_block get_bit (i + digit_n) as
    in (sorted, bins, offsets)
}

entry main (xs: [2][2]i64) =
  blocked_radix_sort.step 0 i64.get_bit (flatten xs :> [num_elems * block_size]i64)
