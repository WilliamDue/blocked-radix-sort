module mk_blocked_radix_sort = {
  def block_size : i64 = 256

  def bit_chunk : i32 = 4

  def num_elems : i64 = 2

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

  def elems_reduce 'a
                   (f: a -> i16)
                   (vs: [num_elems * block_size]a) : [block_size](i16, i16) =
    tabulate block_size (\i ->
                           let c =
                             loop acc = 0
                             for v in vs[i::num_elems] do
                               acc + f v
                           in (c, i16.(i64 num_elems - c)))

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
        let offsets =
          elems_reduce (i16.i32 <-< get_bit (i + digit_n)) as
          |> scan add2 (0, 0)
        let (o, _) = offsets[block_size - 1]
        let accs = replicate block_size 0i16
        let (as, _) =
          loop (as, accs) = (as :> [num_elems * block_size]a, accs :> [block_size]i16)
          for j < num_elems do
            let js = sized block_size (j..num_elems..<num_elems * block_size)
            let is =
              map2 (\k (o0, o1) ->
                      let f = get_bit (i + digit_n) as[k]
                      in i64.i16 (if f == 1 then o0 - 1 else o + o1 - 1))
                   js
                   offsets
            let dest = #[scratch] copy as
            let as = scatter dest is (sized block_size as[j::num_elems])
            let accs = map2 (\a v -> a + i16.i32 (get_bit (i + digit_n) v)) accs as[j::num_elems]
            in (as, accs)
        in as
    in (sorted, bins, offsets)

  #[inline]
  def blocked_radix_sort_step [n] [m] 't
                              (size: i64)
                              (get_bit: i32 -> t -> i32)
                              (digit_n: i32)
                              (blocks: [n * m]t) =
    let (sorted_blocks, hist_blocks, offsets_blocks) =
      #[incremental_flattening(only_intra)]
      unflatten blocks
      |> map2 (step digit_n get_bit <-< sized (T.num_elems * block_size)) (iota n)
      |> unzip3
    let sorted = sized (n * m) (flatten sorted_blocks)
    let old_offsets = offsets_blocks
    let new_offsets =
      hist_blocks
      |> map i64.i16
      |> transpose
      |> flatten
      |> expresum
      |> unflatten
      |> transpose
    let is =
      tabulate (n * m) (\i ->
                          let elem = sorted[i]
                          let bin =
                            if i < size
                            then get_bin get_bit digit_n elem
                            else (1 << i64.i32 bit_chunk) - 1
                          let block_idx = i / m
                          let new_offset = new_offsets[block_idx][bin]
                          let old_block_offset = i64.i16 old_offsets[block_idx][bin]
                          let old_offset = m * block_idx + old_block_offset
                          let idx = (i - old_offset) + new_offset
                          in idx)
    in scatter (copy blocks) is sorted

  def blocked_radix_sort [n] 't
                         (num_bits: i32)
                         (get_bit: i32 -> t -> i32)
                         (xs: [n]t) : [n]t =
    let iters = if n == 0 then 0 else (num_bits + bit_chunk - 1) / bit_chunk
    let n_blocks = if n == 0 then 0 else 1 + (n - 1) / block_size
    let empty = replicate (n_blocks * block_size) xs[0]
    in take n (loop ys = scatter empty (map (\i -> T.const i) (iota n)) xs
               for i < iters do
                 blocked_radix_sort_step n get_bit (i * bit_chunk) ys)
}

module blocked_radix_sort = mk_blocked_radix_sort tuple2

entry main [n] (xs: [n]i64) : [n]i64 =
  blocked_radix_sort.blocked_radix_sort i64.num_bits i64.get_bit xs
