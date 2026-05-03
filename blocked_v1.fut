local
def exscan op ne xs =
  let s =
    scan op ne xs
    |> rotate (-1)
  let s[0] = ne
  in s

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
def radix_sort_step_i16 [n] 't
                        (get_bit: i32 -> t -> i32)
                        (digit_n: i32)
                        (xs: [n]t) : ([n]t, [4]i64, [4]i16) =
  let num x = i16.i32 (get_bit (digit_n + 1) x * 2 + get_bit digit_n x)
  let pairwise op (a1, b1, c1, d1) (a2, b2, c2, d2) = (a1 `op` a2, b1 `op` b2, c1 `op` c2, d1 `op` d2)
  let bins = xs |> map num
  let flags =
    bins
    |> map (\x ->
              ( i16.bool (x == 0)
              , i16.bool (x == 1)
              , i16.bool (x == 2)
              , i16.bool (x == 3)
              ))
  let offsets = scan (pairwise (+)) (0, 0, 0, 0) flags
  let (na, nb, nc, nd) = if n == 0 then (0, 0, 0, 0) else last offsets
  let f bin (a, b, c, d) =
    i64.i16 ((-1)
             + a * (i16.bool (bin == 0))
             + na * (i16.bool (bin > 0))
             + b * (i16.bool (bin == 1))
             + nb * (i16.bool (bin > 1))
             + c * (i16.bool (bin == 2))
             + nc * (i16.bool (bin > 2))
             + d * (i16.bool (bin == 3)))
  let is = map2 f bins offsets
  in ( scatter (copy xs) is xs
     , map i64.i16 [na, nb, nc, nd]
     , [0, na, na + nb, na + nb + nc]
     )

local
def blocked_radix_sort_step [n] [m] [r] 't
                            (get_bit: i32 -> t -> i32)
                            (digit_n: i32)
                            (xs: *[n * m + r]t) =
  let (blocks, rest) = split xs
  let (sorted_rest, hist_rest, offsets_rest) =
    radix_sort_step_i16 get_bit digit_n rest
  let (sorted_blocks, hist_blocks, offsets_blocks) =
    unflatten blocks
    |> map (radix_sort_step_i16 get_bit digit_n)
    |> unzip3
  let histograms = hist_blocks ++ [hist_rest]
  let sorted = sized (n * m + r) (flatten sorted_blocks ++ sorted_rest)
  let old_offsets = offsets_blocks ++ [offsets_rest]
  let new_offsets =
    histograms
    |> transpose
    |> flatten
    |> exscan (+) 0
    |> unflatten
    |> transpose
  let is =
    tabulate (n * m + r) (\i ->
                            let elem = sorted[i]
                            let bin = get_bin 2 get_bit digit_n elem
                            let block_idx = i / m
                            let new_offset = new_offsets[block_idx][bin]
                            let old_block_offset = i64.i16 old_offsets[block_idx][bin]
                            let old_offset = m * block_idx + old_block_offset
                            let idx = (i - old_offset) + new_offset
                            in idx)
  in scatter xs is sorted

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
  let iters = if n == 0 then 0 else (num_bits + 2 - 1) / 2
  let block = i64.i16 block
  let n_blocks = n / block
  let rest = n % block
  let xs = sized (n_blocks * block + rest) xs
  in sized n
     <| loop xs = copy xs
        for i < iters do
          blocked_radix_sort_step get_bit (i * 2) xs

-- ==
-- entry: bench
-- notest random input { [71680000]u32 }
entry bench =
  blocked_radix_sort 256 u32.num_bits u32.get_bit
