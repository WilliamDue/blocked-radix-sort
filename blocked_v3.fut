module type tuple = {
  type t 'a

  val num_elems : i64

  val const 'a : a -> t a

  val last 'a : t a -> a

  val map 'a 'b : (a -> b) -> t a -> t b

  val map2 'a 'b 'c : (a -> b -> c) -> t a -> t b -> t c

  val scan 'a : (a -> a -> a) -> t a -> t a

  val scatter [n] [m] 'a : *[n]a -> [m](t i64) -> [m](t a) -> *[n]a

  val count [n] 'a :
    (k: i64)
    -> (a -> i64)
    -> [num_elems * n]a -> *[k]i16

  val from_array [n] 'a : [num_elems * n]a -> [n](t a)
}

module tuple2 = {
  type t 'a = (a, a)

  def num_elems : i64 = 2

  #[inline]
  def const 'a (a: a) : t a =
    (a, a)

  #[inline]
  def last 'a : t a -> a = (.1)

  #[inline]
  def scan 'a (op: a -> a -> a) (t: t a) : t a =
    let t0 = t.0
    let t1 = t0 `op` t.1
    in (t0, t1)

  #[inline]
  def scatter [n] [m] 'a
              (dest: *[n]a)
              (is: [m](t i64))
              (vs: [m](t a)) : *[n]a =
    let dest = scatter dest (map (.0) is) (map (.0) vs)
    let dest = scatter dest (map (.1) is) (map (.1) vs)
    in dest

  #[inline]
  def count [n] 'a
            (k: i64)
            (f: a -> i64)
            (vs: [num_elems * n]a) : *[k]i16 =
    let dest = rep 0
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[0::num_elems])) (rep 1)
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[1::num_elems])) (rep 1)
    in dest

  #[inline]
  def map 'a 'b (f: a -> b) (t: t a) : t b =
    (f t.0, f t.1)

  #[inline]
  def map2 'a 'b 'c (f: a -> b -> c) (t: t a) (t': t b) : t c =
    (f t.0 t'.0, f t.1 t'.1)

  #[inline]
  def from_array_offset [n] 'a (as: [n]a) (offset: i64) : t a =
    (as[offset], as[offset + 1])

  #[inline]
  def from_array [n] 'a (as: [num_elems * n]a) : [n](t a) =
    tabulate n (\i -> from_array_offset as (i * num_elems))
}

module tuple4 = {
  type t 'a = (a, a, a, a)

  def num_elems : i64 = 4

  #[inline]
  def const 'a (a: a) : t a =
    (a, a, a, a)

  #[inline]
  def last 'a : t a -> a = (.3)

  #[inline]
  def scan 'a (op: a -> a -> a) (t: t a) : t a =
    let t0 = t.0
    let t1 = t0 `op` t.1
    let t2 = t1 `op` t.2
    let t3 = t2 `op` t.3
    in (t0, t1, t2, t3)

  #[inline]
  def scatter [n] [m] 'a
              (dest: *[n]a)
              (is: [m](t i64))
              (vs: [m](t a)) : *[n]a =
    let dest = scatter dest (map (.0) is) (map (.0) vs)
    let dest = scatter dest (map (.1) is) (map (.1) vs)
    let dest = scatter dest (map (.2) is) (map (.2) vs)
    let dest = scatter dest (map (.3) is) (map (.3) vs)
    in dest

  #[inline]
  def count [n] 'a
            (k: i64)
            (f: a -> i64)
            (vs: [num_elems * n]a) : *[k]i16 =
    let dest = rep 0
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[0::num_elems])) (rep 1)
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[1::num_elems])) (rep 1)
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[2::num_elems])) (rep 1)
    let dest = reduce_by_index dest (+) 0 (map f (sized n vs[3::num_elems])) (rep 1)
    in dest

  #[inline]
  def map 'a 'b (f: a -> b) (t: t a) : t b =
    (f t.0, f t.1, f t.2, f t.3)

  #[inline]
  def map2 'a 'b 'c (f: a -> b -> c) (t: t a) (t': t b) : t c =
    (f t.0 t'.0, f t.1 t'.1, f t.2 t'.2, f t.3 t'.3)

  #[inline]
  def from_array_offset [n] 'a (as: [n]a) (offset: i64) : t a =
    (as[offset], as[offset + 1], as[offset + 2], as[offset + 3])

  #[inline]
  def from_array [n] 'a (as: [num_elems * n]a) : [n](t a) =
    tabulate n (\i -> from_array_offset as (i * num_elems))
}

module mk_blocked_radix_sort (T: tuple) = {
  def block_size : i64 = 256

  def bit_chunk : i32 = 4

  def num_bins = 2 ** i64.i32 bit_chunk

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
  def tuple_scan [n] 'a (op: a -> a -> a) (ne: a) (as: [n](T.t a)) : [n](T.t a) =
    let as' = map (T.scan op) as
    let block = map T.last as' |> scan op ne
    in map2 (\i a -> if i != 0 then T.map (op block[i - 1]) a else a) (iota n) as'

  #[inline]
  def add2 (a0: i16, b0: i16) (a1: i16, b1: i16) =
    (a0 + a1, b0 + b1)

  #[inline]
  def to_bits get_bit digit_n a =
    let b = get_bit digit_n a
    in (i16.i32 (1 ^ b), i16.i32 b)

  #[inline]
  def step 'a
           (digit_n: i32)
           (get_bit: i32 -> a -> i32)
           (as: [T.num_elems * block_size]a) =
    let as = manifest as
    let bins = T.count num_bins (get_bin get_bit digit_n) as
    let offsets = sequential_offsets bins
    let sorted =
      loop as
      for i < bit_chunk do
        let ts = copy (T.from_array as)
        let flags = map (T.map (to_bits get_bit (i + digit_n))) ts
        let offsets_scan = tuple_scan add2 (0, 0) flags
        let (o, _) = T.last offsets_scan[block_size - 1]
        let is =
          map2 (T.map2 (\(f, _) (o0, o1) ->
                          i64.i16 (if f == 1 then o0 - 1 else o + o1 - 1)))
               flags
               offsets_scan
        let as = T.scatter as is ts
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
