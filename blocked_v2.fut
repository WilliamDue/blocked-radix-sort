local
def exscan f ne xs =
  map2 (\i x -> if i == 0 then ne else x)
       (indices xs)
       (rotate (-1) (scan f ne xs))

local
def get_bin 't
            (k: i32)
            (get_bit: i32 -> t -> i32)
            (digit_n: i32)
            (x: t) : i64 =
  i64.i32
  <| loop acc = 0
     for i < k do
       acc + (get_bit (digit_n + i) x << i)

local
def radix_sort_step_i16 [m] 't
                        (size: i64)
                        (get_bit: i32 -> t -> i32)
                        (digit_n: i32)
                        (block_offset: i64)
                        (xs: [m]t) : ([m]t, [16]i64, [16]i16) =
  let offset = block_offset * m
  let sorted =
    loop ys = copy xs
    for i in 0i32..<4i32 do
      let flags =
        map2 (\j x ->
                let b =
                  if offset + j < size
                  then get_bit (i + digit_n) x
                  else 1
                in (i16.i32 (1 ^ b), i16.i32 b))
             (iota m)
             ys
      let flags_scan =
        scan (\(a0, a1) (b0, b1) -> (a0 + b0, a1 + b1)) (0, 0) flags
      let (o, _) = flags_scan[m - 1]
      let is =
        map2 (\f (o0, o1) ->
                if f.0 == 1 then o0 - 1 else o + o1 - 1)
             flags
             flags_scan
      in scatter ys (map i64.i16 is) (copy ys)
  let is =
    map2 (\j x ->
            if offset + j < size
            then get_bin 4 get_bit digit_n x
            else (1 << 4) - 1)
         (iota m)
         xs
  let bins = hist (+) 0 16 is (replicate m 1)
  let offsets = exscan (+) 0 bins
  in ( sorted
     , map i64.i16 bins
     , offsets
     )

local
def blocked_radix_sort_step [n] [m] 't
                            (size: i64)
                            (get_bit: i32 -> t -> i32)
                            (digit_n: i32)
                            (blocks: [n * m]t) =
  let (sorted_blocks, hist_blocks, offsets_blocks) =
    #[incremental_flattening(only_intra)]
    unflatten blocks
    |> map2 (radix_sort_step_i16 size get_bit digit_n) (iota n)
    |> unzip3
  let sorted = sized (n * m) (flatten sorted_blocks)
  let old_offsets = offsets_blocks
  let new_offsets =
    hist_blocks
    |> transpose
    |> flatten
    |> exscan (+) 0
    |> unflatten
    |> transpose
  let is =
    tabulate (n * m) (\i ->
                        let elem = sorted[i]
                        let bin =
                          if i < size
                          then get_bin 4 get_bit digit_n elem
                          else (1 << 4) - 1
                        let block_idx = i / m
                        let new_offset = new_offsets[block_idx][bin]
                        let old_block_offset = i64.i16 old_offsets[block_idx][bin]
                        let old_offset = m * block_idx + old_block_offset
                        let idx = (i - old_offset) + new_offset
                        in idx)
  in scatter (copy blocks) is sorted

-- | This implementation of radix sort is based on an algorithm which
-- splits the input up into blocks, sorts them and collect them [1].
-- This leads to performance gains if you choose a good `block` size
-- based on the GPU thread block. The sorting algorithm is stable and
-- its work is *O(k n)* and the span is *O(k log(n))* where *k* is the
-- number of bits in the elements being sorted. In the analysis of the
-- asymptotics we assume the `block` size is some constant.
--
-- [1] N. Satish, M. Harris and M. Garland, "Designing efficient
-- sorting algorithms for manycore GPUs," 2009 IEEE International
-- Symposium on Parallel & Distributed Processing, Rome, Italy, 2009,
-- pp. 1-10, doi: 10.1109/IPDPS.2009.5161005.
def blocked_radix_sort [n] 't
                       (block: i16)
                       (num_bits: i32)
                       (get_bit: i32 -> t -> i32)
                       (xs: [n]t) : [n]t =
  let iters = if n == 0 then 0 else (num_bits + 4 - 1) / 4
  let block = i64.i16 block
  let n_blocks = if n == 0 then 0 else 1 + (n - 1) / block
  let empty = replicate (n_blocks * block) xs[0]
  in take n (loop ys = scatter empty (iota n) xs
             for i < iters do
               blocked_radix_sort_step n get_bit (i * 4) ys)
