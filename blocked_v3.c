
// We need to define _GNU_SOURCE before
// _any_ headers files are imported to get
// the usage statistics of a thread (i.e. have RUSAGE_THREAD) on GNU/Linux
// https://manpages.courier-mta.org/htmlman2/getrusage.2.html
#ifndef _GNU_SOURCE // Avoid possible double-definition warning.
#define _GNU_SOURCE
#endif

#ifdef __clang__
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"
#pragma clang diagnostic ignored "-Wparentheses"
#pragma clang diagnostic ignored "-Wunused-label"
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#elif __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

// Headers
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <float.h>

#ifdef __cplusplus
extern "C" {
#endif

// Initialisation
struct futhark_context_config;
struct futhark_context_config *futhark_context_config_new(void);
void futhark_context_config_free(struct futhark_context_config *cfg);
int futhark_context_config_set_tuning_param(struct futhark_context_config *cfg, const char *param_name, size_t new_value);
struct futhark_context;
struct futhark_context *futhark_context_new(struct futhark_context_config *cfg);
void futhark_context_free(struct futhark_context *ctx);
void futhark_context_config_set_debugging(struct futhark_context_config *cfg, int flag);
void futhark_context_config_set_profiling(struct futhark_context_config *cfg, int flag);
void futhark_context_config_set_logging(struct futhark_context_config *cfg, int flag);
int futhark_get_tuning_param_count(void);
const char *futhark_get_tuning_param_name(int);
const char *futhark_get_tuning_param_class(int);

// Arrays
struct futhark_i64_1d;
struct futhark_i64_1d *futhark_new_i64_1d(struct futhark_context *ctx, const int64_t *data, int64_t dim0);
struct futhark_i64_1d *futhark_new_raw_i64_1d(struct futhark_context *ctx, unsigned char *data, int64_t dim0);
int futhark_free_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr);
int futhark_values_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr, int64_t *data);
int futhark_index_i64_1d(struct futhark_context *ctx, int64_t *out, struct futhark_i64_1d *arr, int64_t i0);
unsigned char *futhark_values_raw_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr);
const int64_t *futhark_shape_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr);
struct futhark_i64_3d;
struct futhark_i64_3d *futhark_new_i64_3d(struct futhark_context *ctx, const int64_t *data, int64_t dim0, int64_t dim1, int64_t dim2);
struct futhark_i64_3d *futhark_new_raw_i64_3d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1, int64_t dim2);
int futhark_free_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr);
int futhark_values_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr, int64_t *data);
int futhark_index_i64_3d(struct futhark_context *ctx, int64_t *out, struct futhark_i64_3d *arr, int64_t i0, int64_t i1, int64_t i2);
unsigned char *futhark_values_raw_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr);
const int64_t *futhark_shape_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr);
struct futhark_u32_1d;
struct futhark_u32_1d *futhark_new_u32_1d(struct futhark_context *ctx, const uint32_t *data, int64_t dim0);
struct futhark_u32_1d *futhark_new_raw_u32_1d(struct futhark_context *ctx, unsigned char *data, int64_t dim0);
int futhark_free_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr);
int futhark_values_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr, uint32_t *data);
int futhark_index_u32_1d(struct futhark_context *ctx, uint32_t *out, struct futhark_u32_1d *arr, int64_t i0);
unsigned char *futhark_values_raw_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr);
const int64_t *futhark_shape_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr);
struct futhark_u32_2d;
struct futhark_u32_2d *futhark_new_u32_2d(struct futhark_context *ctx, const uint32_t *data, int64_t dim0, int64_t dim1);
struct futhark_u32_2d *futhark_new_raw_u32_2d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1);
int futhark_free_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr);
int futhark_values_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr, uint32_t *data);
int futhark_index_u32_2d(struct futhark_context *ctx, uint32_t *out, struct futhark_u32_2d *arr, int64_t i0, int64_t i1);
unsigned char *futhark_values_raw_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr);
const int64_t *futhark_shape_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr);
struct futhark_u8_2d;
struct futhark_u8_2d *futhark_new_u8_2d(struct futhark_context *ctx, const uint8_t *data, int64_t dim0, int64_t dim1);
struct futhark_u8_2d *futhark_new_raw_u8_2d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1);
int futhark_free_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr);
int futhark_values_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr, uint8_t *data);
int futhark_index_u8_2d(struct futhark_context *ctx, uint8_t *out, struct futhark_u8_2d *arr, int64_t i0, int64_t i1);
unsigned char *futhark_values_raw_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr);
const int64_t *futhark_shape_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr);

// Opaque values



// Entry points
int futhark_entry_bench(struct futhark_context *ctx, struct futhark_u32_1d **out, const struct futhark_u32_1d *in0);
int futhark_entry_is_sorted(struct futhark_context *ctx, bool *out, const struct futhark_u32_2d *in0);
int futhark_entry_is_stable(struct futhark_context *ctx, bool *out, const struct futhark_u8_2d *in0);
int futhark_entry_main(struct futhark_context *ctx, struct futhark_i64_1d **out, const struct futhark_i64_3d *in0);
int futhark_entry_test_sort_reversed(struct futhark_context *ctx, bool *out);

// Miscellaneous
int futhark_context_sync(struct futhark_context *ctx);
void futhark_context_config_set_cache_file(struct futhark_context_config *cfg, const char *f);
char *futhark_context_get_error(struct futhark_context *ctx);
void futhark_context_set_logging_file(struct futhark_context *ctx, FILE *f);
void futhark_context_pause_profiling(struct futhark_context *ctx);
void futhark_context_unpause_profiling(struct futhark_context *ctx);
char *futhark_context_report(struct futhark_context *ctx);
int futhark_context_clear_caches(struct futhark_context *ctx);
#define FUTHARK_BACKEND_c
#define FUTHARK_SUCCESS 0
#define FUTHARK_PROGRAM_ERROR 2
#define FUTHARK_OUT_OF_MEMORY 3

#ifdef __cplusplus
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
// If NDEBUG is set, the assert() macro will do nothing. Since Futhark
// (unfortunately) makes use of assert() for error detection (and even some
// side effects), we want to avoid that.
#undef NDEBUG
#include <assert.h>
#include <stdarg.h>
#define SCALAR_FUN_ATTR static inline
// Start of util.h.
//
// Various helper functions that are useful in all generated C code.

#include <errno.h>
#include <string.h>

static const char *fut_progname = "(embedded Futhark)";

static void futhark_panic(int eval, const char *fmt, ...) __attribute__((noreturn));
static char* msgprintf(const char *s, ...);
static void* slurp_file(const char *filename, size_t *size);
static int dump_file(const char *file, const void *buf, size_t n);
struct str_builder;
static void str_builder_init(struct str_builder *b);
static void str_builder(struct str_builder *b, const char *s, ...);
static char *strclone(const char *str);

static void futhark_panic(int eval, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  fprintf(stderr, "%s: ", fut_progname);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
  exit(eval);
}

// For generating arbitrary-sized error messages.  It is the callers
// responsibility to free the buffer at some point.
static char* msgprintf(const char *s, ...) {
  va_list vl;
  va_start(vl, s);
  size_t needed = 1 + (size_t)vsnprintf(NULL, 0, s, vl);
  char *buffer = (char*) malloc(needed);
  va_start(vl, s); // Must re-init.
  vsnprintf(buffer, needed, s, vl);
  return buffer;
}

static inline void check_err(int errval, int sets_errno, const char *fun, int line,
                             const char *msg, ...) {
  if (errval) {
    char errnum[10];

    va_list vl;
    va_start(vl, msg);

    fprintf(stderr, "ERROR: ");
    vfprintf(stderr, msg, vl);
    fprintf(stderr, " in %s() at line %d with error code %s\n",
            fun, line,
            sets_errno ? strerror(errno) : errnum);
    exit(errval);
  }
}

#define CHECK_ERR(err, ...) check_err(err, 0, __func__, __LINE__, __VA_ARGS__)
#define CHECK_ERRNO(err, ...) check_err(err, 1, __func__, __LINE__, __VA_ARGS__)

// Read the rest of an open file into a NUL-terminated string; returns
// NULL on error.
static void* fslurp_file(FILE *f, size_t *size) {
  long start = ftell(f);
  fseek(f, 0, SEEK_END);
  long src_size = ftell(f)-start;
  fseek(f, start, SEEK_SET);
  unsigned char *s = (unsigned char*) malloc((size_t)src_size + 1);
  if (fread(s, 1, (size_t)src_size, f) != (size_t)src_size) {
    free(s);
    s = NULL;
  } else {
    s[src_size] = '\0';
  }

  if (size) {
    *size = (size_t)src_size;
  }

  return s;
}

// Read a file into a NUL-terminated string; returns NULL on error.
static void* slurp_file(const char *filename, size_t *size) {
  FILE *f = fopen(filename, "rb"); // To avoid Windows messing with linebreaks.
  if (f == NULL) return NULL;
  unsigned char *s = fslurp_file(f, size);
  fclose(f);
  return s;
}

// Dump 'n' bytes from 'buf' into the file at the designated location.
// Returns 0 on success.
static int dump_file(const char *file, const void *buf, size_t n) {
  FILE *f = fopen(file, "w");

  if (f == NULL) {
    return 1;
  }

  if (fwrite(buf, sizeof(char), n, f) != n) {
    return 1;
  }

  if (fclose(f) != 0) {
    return 1;
  }

  return 0;
}

struct str_builder {
  char *str;
  size_t capacity; // Size of buffer.
  size_t used; // Bytes used, *not* including final zero.
};

static void str_builder_init(struct str_builder *b) {
  b->capacity = 10;
  b->used = 0;
  b->str = malloc(b->capacity);
  b->str[0] = 0;
}

static void str_builder(struct str_builder *b, const char *s, ...) {
  va_list vl;
  va_start(vl, s);
  size_t needed = (size_t)vsnprintf(NULL, 0, s, vl);

  while (b->capacity < b->used + needed + 1) {
    b->capacity *= 2;
    b->str = realloc(b->str, b->capacity);
  }

  va_start(vl, s); // Must re-init.
  vsnprintf(b->str+b->used, b->capacity-b->used, s, vl);
  b->used += needed;
}

static void str_builder_str(struct str_builder *b, const char *s) {
  size_t needed = strlen(s);
  if (b->capacity < b->used + needed + 1) {
    b->capacity *= 2;
    b->str = realloc(b->str, b->capacity);
  }
  strcpy(b->str+b->used, s);
  b->used += needed;
}

static void str_builder_char(struct str_builder *b, char c) {
  size_t needed = 1;
  if (b->capacity < b->used + needed + 1) {
    b->capacity *= 2;
    b->str = realloc(b->str, b->capacity);
  }
  b->str[b->used] = c;
  b->str[b->used+1] = 0;
  b->used += needed;
}

static void str_builder_json_str(struct str_builder* sb, const char* s) {
  str_builder_char(sb, '"');
  for (int j = 0; s[j]; j++) {
    char c = s[j];
    switch (c) {
    case '\n':
      str_builder_str(sb, "\\n");
      break;
    case '"':
      str_builder_str(sb, "\\\"");
      break;
    default:
      str_builder_char(sb, c);
    }
  }
  str_builder_char(sb, '"');
}

static char *strclone(const char *str) {
  size_t size = strlen(str) + 1;
  char *copy = (char*) malloc(size);
  if (copy == NULL) {
    return NULL;
  }

  memcpy(copy, str, size);
  return copy;
}

// Assumes NULL-terminated.
static char *strconcat(const char *src_fragments[]) {
  size_t src_len = 0;
  const char **p;

  for (p = src_fragments; *p; p++) {
    src_len += strlen(*p);
  }

  char *src = (char*) malloc(src_len + 1);
  size_t n = 0;
  for (p = src_fragments; *p; p++) {
    strcpy(src + n, *p);
    n += strlen(*p);
  }

  return src;
}

// End of util.h.
// Start of cache.h

#define CACHE_HASH_SIZE 8 // In 32-bit words.

struct cache_hash {
  uint32_t hash[CACHE_HASH_SIZE];
};

// Initialise a blank cache.
static void cache_hash_init(struct cache_hash *c);

// Hash some bytes and add them to the accumulated hash.
static void cache_hash(struct cache_hash *out, const char *in, size_t n);

// Try to restore cache contents from a file with the given name.
// Assumes the cache is invalid if it contains the given hash.
// Allocates memory and reads the cache conents, which is returned in
// *buf with size *buflen.  If the cache is successfully loaded, this
// function returns 0.  Otherwise it returns nonzero.  Errno is set if
// the failure to load the cache is due to anything except invalid
// cache conents.  Note that failing to restore the cache is not
// necessarily a problem: it might just be invalid or not created yet.
static int cache_restore(const char *fname, const struct cache_hash *hash,
                         unsigned char **buf, size_t *buflen);

// Store cache contents in the given file, with the given hash.
static int cache_store(const char *fname, const struct cache_hash *hash,
                       const unsigned char *buf, size_t buflen);

// Now for the implementation.

static void cache_hash_init(struct cache_hash *c) {
  memset(c->hash, 0, CACHE_HASH_SIZE * sizeof(uint32_t));
}

static void cache_hash(struct cache_hash *out, const char *in, size_t n) {
  // Adaptation of djb2 for larger output size by storing intermediate
  // states.
  uint32_t hash = 5381;
  for (size_t i = 0; i < n; i++) {
    hash = ((hash << 5) + hash) + in[i];
    out->hash[i % CACHE_HASH_SIZE] ^= hash;
  }
}

#define CACHE_HEADER_SIZE 8
static const char cache_header[CACHE_HEADER_SIZE] = "FUTHARK\0";

static int cache_restore(const char *fname, const struct cache_hash *hash,
                         unsigned char **buf, size_t *buflen) {
  FILE *f = fopen(fname, "rb");

  if (f == NULL) {
    return 1;
  }

  char f_header[CACHE_HEADER_SIZE];

  if (fread(f_header, sizeof(char), CACHE_HEADER_SIZE, f) != CACHE_HEADER_SIZE) {
    goto error;
  }

  if (memcmp(f_header, cache_header, CACHE_HEADER_SIZE) != 0) {
    goto error;
  }

  if (fseek(f, 0, SEEK_END) != 0) {
    goto error;
  }
  int64_t f_size = (int64_t)ftell(f);
  if (fseek(f, CACHE_HEADER_SIZE, SEEK_SET) != 0) {
    goto error;
  }

  int64_t expected_size;

  if (fread(&expected_size, sizeof(int64_t), 1, f) != 1) {
    goto error;
  }

  if (f_size != expected_size) {
    errno = 0;
    goto error;
  }

  int32_t f_hash[CACHE_HASH_SIZE];

  if (fread(f_hash, sizeof(int32_t), CACHE_HASH_SIZE, f) != CACHE_HASH_SIZE) {
    goto error;
  }

  if (memcmp(f_hash, hash->hash, CACHE_HASH_SIZE) != 0) {
    errno = 0;
    goto error;
  }

  *buflen = f_size - CACHE_HEADER_SIZE - sizeof(int64_t) - CACHE_HASH_SIZE*sizeof(int32_t);
  *buf = malloc(*buflen);
  if (fread(*buf, sizeof(char), *buflen, f) != *buflen) {
    free(*buf);
    goto error;
  }

  fclose(f);

  return 0;

 error:
  fclose(f);
  return 1;
}

static int cache_store(const char *fname, const struct cache_hash *hash,
                       const unsigned char *buf, size_t buflen) {
  FILE *f = fopen(fname, "wb");

  if (f == NULL) {
    return 1;
  }

  if (fwrite(cache_header, CACHE_HEADER_SIZE, 1, f) != 1) {
    goto error;
  }

  int64_t size = CACHE_HEADER_SIZE + sizeof(int64_t) + CACHE_HASH_SIZE*sizeof(int32_t) + buflen;

  if (fwrite(&size, sizeof(size), 1, f) != 1) {
    goto error;
  }

  if (fwrite(hash->hash, sizeof(int32_t), CACHE_HASH_SIZE, f) != CACHE_HASH_SIZE) {
    goto error;
  }

  if (fwrite(buf, sizeof(unsigned char), buflen, f) != buflen) {
    goto error;
  }

  fclose(f);

  return 0;

 error:
  fclose(f);
  return 1;
}

// End of cache.h
// Start of half.h.

// Conversion functions are from http://half.sourceforge.net/, but
// translated to C.
//
// Copyright (c) 2012-2021 Christian Rau
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef __OPENCL_VERSION__
#define __constant
#endif

__constant static const uint16_t base_table[512] = {
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100,
  0x0200, 0x0400, 0x0800, 0x0C00, 0x1000, 0x1400, 0x1800, 0x1C00, 0x2000, 0x2400, 0x2800, 0x2C00, 0x3000, 0x3400, 0x3800, 0x3C00,
  0x4000, 0x4400, 0x4800, 0x4C00, 0x5000, 0x5400, 0x5800, 0x5C00, 0x6000, 0x6400, 0x6800, 0x6C00, 0x7000, 0x7400, 0x7800, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00, 0x7C00,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
  0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8001, 0x8002, 0x8004, 0x8008, 0x8010, 0x8020, 0x8040, 0x8080, 0x8100,
  0x8200, 0x8400, 0x8800, 0x8C00, 0x9000, 0x9400, 0x9800, 0x9C00, 0xA000, 0xA400, 0xA800, 0xAC00, 0xB000, 0xB400, 0xB800, 0xBC00,
  0xC000, 0xC400, 0xC800, 0xCC00, 0xD000, 0xD400, 0xD800, 0xDC00, 0xE000, 0xE400, 0xE800, 0xEC00, 0xF000, 0xF400, 0xF800, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00,
  0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00, 0xFC00 };

__constant static const unsigned char shift_table[512] = {
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
  13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 13,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
  13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 13 };

__constant static const uint32_t mantissa_table[2048] = {
  0x00000000, 0x33800000, 0x34000000, 0x34400000, 0x34800000, 0x34A00000, 0x34C00000, 0x34E00000, 0x35000000, 0x35100000, 0x35200000, 0x35300000, 0x35400000, 0x35500000, 0x35600000, 0x35700000,
  0x35800000, 0x35880000, 0x35900000, 0x35980000, 0x35A00000, 0x35A80000, 0x35B00000, 0x35B80000, 0x35C00000, 0x35C80000, 0x35D00000, 0x35D80000, 0x35E00000, 0x35E80000, 0x35F00000, 0x35F80000,
  0x36000000, 0x36040000, 0x36080000, 0x360C0000, 0x36100000, 0x36140000, 0x36180000, 0x361C0000, 0x36200000, 0x36240000, 0x36280000, 0x362C0000, 0x36300000, 0x36340000, 0x36380000, 0x363C0000,
  0x36400000, 0x36440000, 0x36480000, 0x364C0000, 0x36500000, 0x36540000, 0x36580000, 0x365C0000, 0x36600000, 0x36640000, 0x36680000, 0x366C0000, 0x36700000, 0x36740000, 0x36780000, 0x367C0000,
  0x36800000, 0x36820000, 0x36840000, 0x36860000, 0x36880000, 0x368A0000, 0x368C0000, 0x368E0000, 0x36900000, 0x36920000, 0x36940000, 0x36960000, 0x36980000, 0x369A0000, 0x369C0000, 0x369E0000,
  0x36A00000, 0x36A20000, 0x36A40000, 0x36A60000, 0x36A80000, 0x36AA0000, 0x36AC0000, 0x36AE0000, 0x36B00000, 0x36B20000, 0x36B40000, 0x36B60000, 0x36B80000, 0x36BA0000, 0x36BC0000, 0x36BE0000,
  0x36C00000, 0x36C20000, 0x36C40000, 0x36C60000, 0x36C80000, 0x36CA0000, 0x36CC0000, 0x36CE0000, 0x36D00000, 0x36D20000, 0x36D40000, 0x36D60000, 0x36D80000, 0x36DA0000, 0x36DC0000, 0x36DE0000,
  0x36E00000, 0x36E20000, 0x36E40000, 0x36E60000, 0x36E80000, 0x36EA0000, 0x36EC0000, 0x36EE0000, 0x36F00000, 0x36F20000, 0x36F40000, 0x36F60000, 0x36F80000, 0x36FA0000, 0x36FC0000, 0x36FE0000,
  0x37000000, 0x37010000, 0x37020000, 0x37030000, 0x37040000, 0x37050000, 0x37060000, 0x37070000, 0x37080000, 0x37090000, 0x370A0000, 0x370B0000, 0x370C0000, 0x370D0000, 0x370E0000, 0x370F0000,
  0x37100000, 0x37110000, 0x37120000, 0x37130000, 0x37140000, 0x37150000, 0x37160000, 0x37170000, 0x37180000, 0x37190000, 0x371A0000, 0x371B0000, 0x371C0000, 0x371D0000, 0x371E0000, 0x371F0000,
  0x37200000, 0x37210000, 0x37220000, 0x37230000, 0x37240000, 0x37250000, 0x37260000, 0x37270000, 0x37280000, 0x37290000, 0x372A0000, 0x372B0000, 0x372C0000, 0x372D0000, 0x372E0000, 0x372F0000,
  0x37300000, 0x37310000, 0x37320000, 0x37330000, 0x37340000, 0x37350000, 0x37360000, 0x37370000, 0x37380000, 0x37390000, 0x373A0000, 0x373B0000, 0x373C0000, 0x373D0000, 0x373E0000, 0x373F0000,
  0x37400000, 0x37410000, 0x37420000, 0x37430000, 0x37440000, 0x37450000, 0x37460000, 0x37470000, 0x37480000, 0x37490000, 0x374A0000, 0x374B0000, 0x374C0000, 0x374D0000, 0x374E0000, 0x374F0000,
  0x37500000, 0x37510000, 0x37520000, 0x37530000, 0x37540000, 0x37550000, 0x37560000, 0x37570000, 0x37580000, 0x37590000, 0x375A0000, 0x375B0000, 0x375C0000, 0x375D0000, 0x375E0000, 0x375F0000,
  0x37600000, 0x37610000, 0x37620000, 0x37630000, 0x37640000, 0x37650000, 0x37660000, 0x37670000, 0x37680000, 0x37690000, 0x376A0000, 0x376B0000, 0x376C0000, 0x376D0000, 0x376E0000, 0x376F0000,
  0x37700000, 0x37710000, 0x37720000, 0x37730000, 0x37740000, 0x37750000, 0x37760000, 0x37770000, 0x37780000, 0x37790000, 0x377A0000, 0x377B0000, 0x377C0000, 0x377D0000, 0x377E0000, 0x377F0000,
  0x37800000, 0x37808000, 0x37810000, 0x37818000, 0x37820000, 0x37828000, 0x37830000, 0x37838000, 0x37840000, 0x37848000, 0x37850000, 0x37858000, 0x37860000, 0x37868000, 0x37870000, 0x37878000,
  0x37880000, 0x37888000, 0x37890000, 0x37898000, 0x378A0000, 0x378A8000, 0x378B0000, 0x378B8000, 0x378C0000, 0x378C8000, 0x378D0000, 0x378D8000, 0x378E0000, 0x378E8000, 0x378F0000, 0x378F8000,
  0x37900000, 0x37908000, 0x37910000, 0x37918000, 0x37920000, 0x37928000, 0x37930000, 0x37938000, 0x37940000, 0x37948000, 0x37950000, 0x37958000, 0x37960000, 0x37968000, 0x37970000, 0x37978000,
  0x37980000, 0x37988000, 0x37990000, 0x37998000, 0x379A0000, 0x379A8000, 0x379B0000, 0x379B8000, 0x379C0000, 0x379C8000, 0x379D0000, 0x379D8000, 0x379E0000, 0x379E8000, 0x379F0000, 0x379F8000,
  0x37A00000, 0x37A08000, 0x37A10000, 0x37A18000, 0x37A20000, 0x37A28000, 0x37A30000, 0x37A38000, 0x37A40000, 0x37A48000, 0x37A50000, 0x37A58000, 0x37A60000, 0x37A68000, 0x37A70000, 0x37A78000,
  0x37A80000, 0x37A88000, 0x37A90000, 0x37A98000, 0x37AA0000, 0x37AA8000, 0x37AB0000, 0x37AB8000, 0x37AC0000, 0x37AC8000, 0x37AD0000, 0x37AD8000, 0x37AE0000, 0x37AE8000, 0x37AF0000, 0x37AF8000,
  0x37B00000, 0x37B08000, 0x37B10000, 0x37B18000, 0x37B20000, 0x37B28000, 0x37B30000, 0x37B38000, 0x37B40000, 0x37B48000, 0x37B50000, 0x37B58000, 0x37B60000, 0x37B68000, 0x37B70000, 0x37B78000,
  0x37B80000, 0x37B88000, 0x37B90000, 0x37B98000, 0x37BA0000, 0x37BA8000, 0x37BB0000, 0x37BB8000, 0x37BC0000, 0x37BC8000, 0x37BD0000, 0x37BD8000, 0x37BE0000, 0x37BE8000, 0x37BF0000, 0x37BF8000,
  0x37C00000, 0x37C08000, 0x37C10000, 0x37C18000, 0x37C20000, 0x37C28000, 0x37C30000, 0x37C38000, 0x37C40000, 0x37C48000, 0x37C50000, 0x37C58000, 0x37C60000, 0x37C68000, 0x37C70000, 0x37C78000,
  0x37C80000, 0x37C88000, 0x37C90000, 0x37C98000, 0x37CA0000, 0x37CA8000, 0x37CB0000, 0x37CB8000, 0x37CC0000, 0x37CC8000, 0x37CD0000, 0x37CD8000, 0x37CE0000, 0x37CE8000, 0x37CF0000, 0x37CF8000,
  0x37D00000, 0x37D08000, 0x37D10000, 0x37D18000, 0x37D20000, 0x37D28000, 0x37D30000, 0x37D38000, 0x37D40000, 0x37D48000, 0x37D50000, 0x37D58000, 0x37D60000, 0x37D68000, 0x37D70000, 0x37D78000,
  0x37D80000, 0x37D88000, 0x37D90000, 0x37D98000, 0x37DA0000, 0x37DA8000, 0x37DB0000, 0x37DB8000, 0x37DC0000, 0x37DC8000, 0x37DD0000, 0x37DD8000, 0x37DE0000, 0x37DE8000, 0x37DF0000, 0x37DF8000,
  0x37E00000, 0x37E08000, 0x37E10000, 0x37E18000, 0x37E20000, 0x37E28000, 0x37E30000, 0x37E38000, 0x37E40000, 0x37E48000, 0x37E50000, 0x37E58000, 0x37E60000, 0x37E68000, 0x37E70000, 0x37E78000,
  0x37E80000, 0x37E88000, 0x37E90000, 0x37E98000, 0x37EA0000, 0x37EA8000, 0x37EB0000, 0x37EB8000, 0x37EC0000, 0x37EC8000, 0x37ED0000, 0x37ED8000, 0x37EE0000, 0x37EE8000, 0x37EF0000, 0x37EF8000,
  0x37F00000, 0x37F08000, 0x37F10000, 0x37F18000, 0x37F20000, 0x37F28000, 0x37F30000, 0x37F38000, 0x37F40000, 0x37F48000, 0x37F50000, 0x37F58000, 0x37F60000, 0x37F68000, 0x37F70000, 0x37F78000,
  0x37F80000, 0x37F88000, 0x37F90000, 0x37F98000, 0x37FA0000, 0x37FA8000, 0x37FB0000, 0x37FB8000, 0x37FC0000, 0x37FC8000, 0x37FD0000, 0x37FD8000, 0x37FE0000, 0x37FE8000, 0x37FF0000, 0x37FF8000,
  0x38000000, 0x38004000, 0x38008000, 0x3800C000, 0x38010000, 0x38014000, 0x38018000, 0x3801C000, 0x38020000, 0x38024000, 0x38028000, 0x3802C000, 0x38030000, 0x38034000, 0x38038000, 0x3803C000,
  0x38040000, 0x38044000, 0x38048000, 0x3804C000, 0x38050000, 0x38054000, 0x38058000, 0x3805C000, 0x38060000, 0x38064000, 0x38068000, 0x3806C000, 0x38070000, 0x38074000, 0x38078000, 0x3807C000,
  0x38080000, 0x38084000, 0x38088000, 0x3808C000, 0x38090000, 0x38094000, 0x38098000, 0x3809C000, 0x380A0000, 0x380A4000, 0x380A8000, 0x380AC000, 0x380B0000, 0x380B4000, 0x380B8000, 0x380BC000,
  0x380C0000, 0x380C4000, 0x380C8000, 0x380CC000, 0x380D0000, 0x380D4000, 0x380D8000, 0x380DC000, 0x380E0000, 0x380E4000, 0x380E8000, 0x380EC000, 0x380F0000, 0x380F4000, 0x380F8000, 0x380FC000,
  0x38100000, 0x38104000, 0x38108000, 0x3810C000, 0x38110000, 0x38114000, 0x38118000, 0x3811C000, 0x38120000, 0x38124000, 0x38128000, 0x3812C000, 0x38130000, 0x38134000, 0x38138000, 0x3813C000,
  0x38140000, 0x38144000, 0x38148000, 0x3814C000, 0x38150000, 0x38154000, 0x38158000, 0x3815C000, 0x38160000, 0x38164000, 0x38168000, 0x3816C000, 0x38170000, 0x38174000, 0x38178000, 0x3817C000,
  0x38180000, 0x38184000, 0x38188000, 0x3818C000, 0x38190000, 0x38194000, 0x38198000, 0x3819C000, 0x381A0000, 0x381A4000, 0x381A8000, 0x381AC000, 0x381B0000, 0x381B4000, 0x381B8000, 0x381BC000,
  0x381C0000, 0x381C4000, 0x381C8000, 0x381CC000, 0x381D0000, 0x381D4000, 0x381D8000, 0x381DC000, 0x381E0000, 0x381E4000, 0x381E8000, 0x381EC000, 0x381F0000, 0x381F4000, 0x381F8000, 0x381FC000,
  0x38200000, 0x38204000, 0x38208000, 0x3820C000, 0x38210000, 0x38214000, 0x38218000, 0x3821C000, 0x38220000, 0x38224000, 0x38228000, 0x3822C000, 0x38230000, 0x38234000, 0x38238000, 0x3823C000,
  0x38240000, 0x38244000, 0x38248000, 0x3824C000, 0x38250000, 0x38254000, 0x38258000, 0x3825C000, 0x38260000, 0x38264000, 0x38268000, 0x3826C000, 0x38270000, 0x38274000, 0x38278000, 0x3827C000,
  0x38280000, 0x38284000, 0x38288000, 0x3828C000, 0x38290000, 0x38294000, 0x38298000, 0x3829C000, 0x382A0000, 0x382A4000, 0x382A8000, 0x382AC000, 0x382B0000, 0x382B4000, 0x382B8000, 0x382BC000,
  0x382C0000, 0x382C4000, 0x382C8000, 0x382CC000, 0x382D0000, 0x382D4000, 0x382D8000, 0x382DC000, 0x382E0000, 0x382E4000, 0x382E8000, 0x382EC000, 0x382F0000, 0x382F4000, 0x382F8000, 0x382FC000,
  0x38300000, 0x38304000, 0x38308000, 0x3830C000, 0x38310000, 0x38314000, 0x38318000, 0x3831C000, 0x38320000, 0x38324000, 0x38328000, 0x3832C000, 0x38330000, 0x38334000, 0x38338000, 0x3833C000,
  0x38340000, 0x38344000, 0x38348000, 0x3834C000, 0x38350000, 0x38354000, 0x38358000, 0x3835C000, 0x38360000, 0x38364000, 0x38368000, 0x3836C000, 0x38370000, 0x38374000, 0x38378000, 0x3837C000,
  0x38380000, 0x38384000, 0x38388000, 0x3838C000, 0x38390000, 0x38394000, 0x38398000, 0x3839C000, 0x383A0000, 0x383A4000, 0x383A8000, 0x383AC000, 0x383B0000, 0x383B4000, 0x383B8000, 0x383BC000,
  0x383C0000, 0x383C4000, 0x383C8000, 0x383CC000, 0x383D0000, 0x383D4000, 0x383D8000, 0x383DC000, 0x383E0000, 0x383E4000, 0x383E8000, 0x383EC000, 0x383F0000, 0x383F4000, 0x383F8000, 0x383FC000,
  0x38400000, 0x38404000, 0x38408000, 0x3840C000, 0x38410000, 0x38414000, 0x38418000, 0x3841C000, 0x38420000, 0x38424000, 0x38428000, 0x3842C000, 0x38430000, 0x38434000, 0x38438000, 0x3843C000,
  0x38440000, 0x38444000, 0x38448000, 0x3844C000, 0x38450000, 0x38454000, 0x38458000, 0x3845C000, 0x38460000, 0x38464000, 0x38468000, 0x3846C000, 0x38470000, 0x38474000, 0x38478000, 0x3847C000,
  0x38480000, 0x38484000, 0x38488000, 0x3848C000, 0x38490000, 0x38494000, 0x38498000, 0x3849C000, 0x384A0000, 0x384A4000, 0x384A8000, 0x384AC000, 0x384B0000, 0x384B4000, 0x384B8000, 0x384BC000,
  0x384C0000, 0x384C4000, 0x384C8000, 0x384CC000, 0x384D0000, 0x384D4000, 0x384D8000, 0x384DC000, 0x384E0000, 0x384E4000, 0x384E8000, 0x384EC000, 0x384F0000, 0x384F4000, 0x384F8000, 0x384FC000,
  0x38500000, 0x38504000, 0x38508000, 0x3850C000, 0x38510000, 0x38514000, 0x38518000, 0x3851C000, 0x38520000, 0x38524000, 0x38528000, 0x3852C000, 0x38530000, 0x38534000, 0x38538000, 0x3853C000,
  0x38540000, 0x38544000, 0x38548000, 0x3854C000, 0x38550000, 0x38554000, 0x38558000, 0x3855C000, 0x38560000, 0x38564000, 0x38568000, 0x3856C000, 0x38570000, 0x38574000, 0x38578000, 0x3857C000,
  0x38580000, 0x38584000, 0x38588000, 0x3858C000, 0x38590000, 0x38594000, 0x38598000, 0x3859C000, 0x385A0000, 0x385A4000, 0x385A8000, 0x385AC000, 0x385B0000, 0x385B4000, 0x385B8000, 0x385BC000,
  0x385C0000, 0x385C4000, 0x385C8000, 0x385CC000, 0x385D0000, 0x385D4000, 0x385D8000, 0x385DC000, 0x385E0000, 0x385E4000, 0x385E8000, 0x385EC000, 0x385F0000, 0x385F4000, 0x385F8000, 0x385FC000,
  0x38600000, 0x38604000, 0x38608000, 0x3860C000, 0x38610000, 0x38614000, 0x38618000, 0x3861C000, 0x38620000, 0x38624000, 0x38628000, 0x3862C000, 0x38630000, 0x38634000, 0x38638000, 0x3863C000,
  0x38640000, 0x38644000, 0x38648000, 0x3864C000, 0x38650000, 0x38654000, 0x38658000, 0x3865C000, 0x38660000, 0x38664000, 0x38668000, 0x3866C000, 0x38670000, 0x38674000, 0x38678000, 0x3867C000,
  0x38680000, 0x38684000, 0x38688000, 0x3868C000, 0x38690000, 0x38694000, 0x38698000, 0x3869C000, 0x386A0000, 0x386A4000, 0x386A8000, 0x386AC000, 0x386B0000, 0x386B4000, 0x386B8000, 0x386BC000,
  0x386C0000, 0x386C4000, 0x386C8000, 0x386CC000, 0x386D0000, 0x386D4000, 0x386D8000, 0x386DC000, 0x386E0000, 0x386E4000, 0x386E8000, 0x386EC000, 0x386F0000, 0x386F4000, 0x386F8000, 0x386FC000,
  0x38700000, 0x38704000, 0x38708000, 0x3870C000, 0x38710000, 0x38714000, 0x38718000, 0x3871C000, 0x38720000, 0x38724000, 0x38728000, 0x3872C000, 0x38730000, 0x38734000, 0x38738000, 0x3873C000,
  0x38740000, 0x38744000, 0x38748000, 0x3874C000, 0x38750000, 0x38754000, 0x38758000, 0x3875C000, 0x38760000, 0x38764000, 0x38768000, 0x3876C000, 0x38770000, 0x38774000, 0x38778000, 0x3877C000,
  0x38780000, 0x38784000, 0x38788000, 0x3878C000, 0x38790000, 0x38794000, 0x38798000, 0x3879C000, 0x387A0000, 0x387A4000, 0x387A8000, 0x387AC000, 0x387B0000, 0x387B4000, 0x387B8000, 0x387BC000,
  0x387C0000, 0x387C4000, 0x387C8000, 0x387CC000, 0x387D0000, 0x387D4000, 0x387D8000, 0x387DC000, 0x387E0000, 0x387E4000, 0x387E8000, 0x387EC000, 0x387F0000, 0x387F4000, 0x387F8000, 0x387FC000,
  0x38000000, 0x38002000, 0x38004000, 0x38006000, 0x38008000, 0x3800A000, 0x3800C000, 0x3800E000, 0x38010000, 0x38012000, 0x38014000, 0x38016000, 0x38018000, 0x3801A000, 0x3801C000, 0x3801E000,
  0x38020000, 0x38022000, 0x38024000, 0x38026000, 0x38028000, 0x3802A000, 0x3802C000, 0x3802E000, 0x38030000, 0x38032000, 0x38034000, 0x38036000, 0x38038000, 0x3803A000, 0x3803C000, 0x3803E000,
  0x38040000, 0x38042000, 0x38044000, 0x38046000, 0x38048000, 0x3804A000, 0x3804C000, 0x3804E000, 0x38050000, 0x38052000, 0x38054000, 0x38056000, 0x38058000, 0x3805A000, 0x3805C000, 0x3805E000,
  0x38060000, 0x38062000, 0x38064000, 0x38066000, 0x38068000, 0x3806A000, 0x3806C000, 0x3806E000, 0x38070000, 0x38072000, 0x38074000, 0x38076000, 0x38078000, 0x3807A000, 0x3807C000, 0x3807E000,
  0x38080000, 0x38082000, 0x38084000, 0x38086000, 0x38088000, 0x3808A000, 0x3808C000, 0x3808E000, 0x38090000, 0x38092000, 0x38094000, 0x38096000, 0x38098000, 0x3809A000, 0x3809C000, 0x3809E000,
  0x380A0000, 0x380A2000, 0x380A4000, 0x380A6000, 0x380A8000, 0x380AA000, 0x380AC000, 0x380AE000, 0x380B0000, 0x380B2000, 0x380B4000, 0x380B6000, 0x380B8000, 0x380BA000, 0x380BC000, 0x380BE000,
  0x380C0000, 0x380C2000, 0x380C4000, 0x380C6000, 0x380C8000, 0x380CA000, 0x380CC000, 0x380CE000, 0x380D0000, 0x380D2000, 0x380D4000, 0x380D6000, 0x380D8000, 0x380DA000, 0x380DC000, 0x380DE000,
  0x380E0000, 0x380E2000, 0x380E4000, 0x380E6000, 0x380E8000, 0x380EA000, 0x380EC000, 0x380EE000, 0x380F0000, 0x380F2000, 0x380F4000, 0x380F6000, 0x380F8000, 0x380FA000, 0x380FC000, 0x380FE000,
  0x38100000, 0x38102000, 0x38104000, 0x38106000, 0x38108000, 0x3810A000, 0x3810C000, 0x3810E000, 0x38110000, 0x38112000, 0x38114000, 0x38116000, 0x38118000, 0x3811A000, 0x3811C000, 0x3811E000,
  0x38120000, 0x38122000, 0x38124000, 0x38126000, 0x38128000, 0x3812A000, 0x3812C000, 0x3812E000, 0x38130000, 0x38132000, 0x38134000, 0x38136000, 0x38138000, 0x3813A000, 0x3813C000, 0x3813E000,
  0x38140000, 0x38142000, 0x38144000, 0x38146000, 0x38148000, 0x3814A000, 0x3814C000, 0x3814E000, 0x38150000, 0x38152000, 0x38154000, 0x38156000, 0x38158000, 0x3815A000, 0x3815C000, 0x3815E000,
  0x38160000, 0x38162000, 0x38164000, 0x38166000, 0x38168000, 0x3816A000, 0x3816C000, 0x3816E000, 0x38170000, 0x38172000, 0x38174000, 0x38176000, 0x38178000, 0x3817A000, 0x3817C000, 0x3817E000,
  0x38180000, 0x38182000, 0x38184000, 0x38186000, 0x38188000, 0x3818A000, 0x3818C000, 0x3818E000, 0x38190000, 0x38192000, 0x38194000, 0x38196000, 0x38198000, 0x3819A000, 0x3819C000, 0x3819E000,
  0x381A0000, 0x381A2000, 0x381A4000, 0x381A6000, 0x381A8000, 0x381AA000, 0x381AC000, 0x381AE000, 0x381B0000, 0x381B2000, 0x381B4000, 0x381B6000, 0x381B8000, 0x381BA000, 0x381BC000, 0x381BE000,
  0x381C0000, 0x381C2000, 0x381C4000, 0x381C6000, 0x381C8000, 0x381CA000, 0x381CC000, 0x381CE000, 0x381D0000, 0x381D2000, 0x381D4000, 0x381D6000, 0x381D8000, 0x381DA000, 0x381DC000, 0x381DE000,
  0x381E0000, 0x381E2000, 0x381E4000, 0x381E6000, 0x381E8000, 0x381EA000, 0x381EC000, 0x381EE000, 0x381F0000, 0x381F2000, 0x381F4000, 0x381F6000, 0x381F8000, 0x381FA000, 0x381FC000, 0x381FE000,
  0x38200000, 0x38202000, 0x38204000, 0x38206000, 0x38208000, 0x3820A000, 0x3820C000, 0x3820E000, 0x38210000, 0x38212000, 0x38214000, 0x38216000, 0x38218000, 0x3821A000, 0x3821C000, 0x3821E000,
  0x38220000, 0x38222000, 0x38224000, 0x38226000, 0x38228000, 0x3822A000, 0x3822C000, 0x3822E000, 0x38230000, 0x38232000, 0x38234000, 0x38236000, 0x38238000, 0x3823A000, 0x3823C000, 0x3823E000,
  0x38240000, 0x38242000, 0x38244000, 0x38246000, 0x38248000, 0x3824A000, 0x3824C000, 0x3824E000, 0x38250000, 0x38252000, 0x38254000, 0x38256000, 0x38258000, 0x3825A000, 0x3825C000, 0x3825E000,
  0x38260000, 0x38262000, 0x38264000, 0x38266000, 0x38268000, 0x3826A000, 0x3826C000, 0x3826E000, 0x38270000, 0x38272000, 0x38274000, 0x38276000, 0x38278000, 0x3827A000, 0x3827C000, 0x3827E000,
  0x38280000, 0x38282000, 0x38284000, 0x38286000, 0x38288000, 0x3828A000, 0x3828C000, 0x3828E000, 0x38290000, 0x38292000, 0x38294000, 0x38296000, 0x38298000, 0x3829A000, 0x3829C000, 0x3829E000,
  0x382A0000, 0x382A2000, 0x382A4000, 0x382A6000, 0x382A8000, 0x382AA000, 0x382AC000, 0x382AE000, 0x382B0000, 0x382B2000, 0x382B4000, 0x382B6000, 0x382B8000, 0x382BA000, 0x382BC000, 0x382BE000,
  0x382C0000, 0x382C2000, 0x382C4000, 0x382C6000, 0x382C8000, 0x382CA000, 0x382CC000, 0x382CE000, 0x382D0000, 0x382D2000, 0x382D4000, 0x382D6000, 0x382D8000, 0x382DA000, 0x382DC000, 0x382DE000,
  0x382E0000, 0x382E2000, 0x382E4000, 0x382E6000, 0x382E8000, 0x382EA000, 0x382EC000, 0x382EE000, 0x382F0000, 0x382F2000, 0x382F4000, 0x382F6000, 0x382F8000, 0x382FA000, 0x382FC000, 0x382FE000,
  0x38300000, 0x38302000, 0x38304000, 0x38306000, 0x38308000, 0x3830A000, 0x3830C000, 0x3830E000, 0x38310000, 0x38312000, 0x38314000, 0x38316000, 0x38318000, 0x3831A000, 0x3831C000, 0x3831E000,
  0x38320000, 0x38322000, 0x38324000, 0x38326000, 0x38328000, 0x3832A000, 0x3832C000, 0x3832E000, 0x38330000, 0x38332000, 0x38334000, 0x38336000, 0x38338000, 0x3833A000, 0x3833C000, 0x3833E000,
  0x38340000, 0x38342000, 0x38344000, 0x38346000, 0x38348000, 0x3834A000, 0x3834C000, 0x3834E000, 0x38350000, 0x38352000, 0x38354000, 0x38356000, 0x38358000, 0x3835A000, 0x3835C000, 0x3835E000,
  0x38360000, 0x38362000, 0x38364000, 0x38366000, 0x38368000, 0x3836A000, 0x3836C000, 0x3836E000, 0x38370000, 0x38372000, 0x38374000, 0x38376000, 0x38378000, 0x3837A000, 0x3837C000, 0x3837E000,
  0x38380000, 0x38382000, 0x38384000, 0x38386000, 0x38388000, 0x3838A000, 0x3838C000, 0x3838E000, 0x38390000, 0x38392000, 0x38394000, 0x38396000, 0x38398000, 0x3839A000, 0x3839C000, 0x3839E000,
  0x383A0000, 0x383A2000, 0x383A4000, 0x383A6000, 0x383A8000, 0x383AA000, 0x383AC000, 0x383AE000, 0x383B0000, 0x383B2000, 0x383B4000, 0x383B6000, 0x383B8000, 0x383BA000, 0x383BC000, 0x383BE000,
  0x383C0000, 0x383C2000, 0x383C4000, 0x383C6000, 0x383C8000, 0x383CA000, 0x383CC000, 0x383CE000, 0x383D0000, 0x383D2000, 0x383D4000, 0x383D6000, 0x383D8000, 0x383DA000, 0x383DC000, 0x383DE000,
  0x383E0000, 0x383E2000, 0x383E4000, 0x383E6000, 0x383E8000, 0x383EA000, 0x383EC000, 0x383EE000, 0x383F0000, 0x383F2000, 0x383F4000, 0x383F6000, 0x383F8000, 0x383FA000, 0x383FC000, 0x383FE000,
  0x38400000, 0x38402000, 0x38404000, 0x38406000, 0x38408000, 0x3840A000, 0x3840C000, 0x3840E000, 0x38410000, 0x38412000, 0x38414000, 0x38416000, 0x38418000, 0x3841A000, 0x3841C000, 0x3841E000,
  0x38420000, 0x38422000, 0x38424000, 0x38426000, 0x38428000, 0x3842A000, 0x3842C000, 0x3842E000, 0x38430000, 0x38432000, 0x38434000, 0x38436000, 0x38438000, 0x3843A000, 0x3843C000, 0x3843E000,
  0x38440000, 0x38442000, 0x38444000, 0x38446000, 0x38448000, 0x3844A000, 0x3844C000, 0x3844E000, 0x38450000, 0x38452000, 0x38454000, 0x38456000, 0x38458000, 0x3845A000, 0x3845C000, 0x3845E000,
  0x38460000, 0x38462000, 0x38464000, 0x38466000, 0x38468000, 0x3846A000, 0x3846C000, 0x3846E000, 0x38470000, 0x38472000, 0x38474000, 0x38476000, 0x38478000, 0x3847A000, 0x3847C000, 0x3847E000,
  0x38480000, 0x38482000, 0x38484000, 0x38486000, 0x38488000, 0x3848A000, 0x3848C000, 0x3848E000, 0x38490000, 0x38492000, 0x38494000, 0x38496000, 0x38498000, 0x3849A000, 0x3849C000, 0x3849E000,
  0x384A0000, 0x384A2000, 0x384A4000, 0x384A6000, 0x384A8000, 0x384AA000, 0x384AC000, 0x384AE000, 0x384B0000, 0x384B2000, 0x384B4000, 0x384B6000, 0x384B8000, 0x384BA000, 0x384BC000, 0x384BE000,
  0x384C0000, 0x384C2000, 0x384C4000, 0x384C6000, 0x384C8000, 0x384CA000, 0x384CC000, 0x384CE000, 0x384D0000, 0x384D2000, 0x384D4000, 0x384D6000, 0x384D8000, 0x384DA000, 0x384DC000, 0x384DE000,
  0x384E0000, 0x384E2000, 0x384E4000, 0x384E6000, 0x384E8000, 0x384EA000, 0x384EC000, 0x384EE000, 0x384F0000, 0x384F2000, 0x384F4000, 0x384F6000, 0x384F8000, 0x384FA000, 0x384FC000, 0x384FE000,
  0x38500000, 0x38502000, 0x38504000, 0x38506000, 0x38508000, 0x3850A000, 0x3850C000, 0x3850E000, 0x38510000, 0x38512000, 0x38514000, 0x38516000, 0x38518000, 0x3851A000, 0x3851C000, 0x3851E000,
  0x38520000, 0x38522000, 0x38524000, 0x38526000, 0x38528000, 0x3852A000, 0x3852C000, 0x3852E000, 0x38530000, 0x38532000, 0x38534000, 0x38536000, 0x38538000, 0x3853A000, 0x3853C000, 0x3853E000,
  0x38540000, 0x38542000, 0x38544000, 0x38546000, 0x38548000, 0x3854A000, 0x3854C000, 0x3854E000, 0x38550000, 0x38552000, 0x38554000, 0x38556000, 0x38558000, 0x3855A000, 0x3855C000, 0x3855E000,
  0x38560000, 0x38562000, 0x38564000, 0x38566000, 0x38568000, 0x3856A000, 0x3856C000, 0x3856E000, 0x38570000, 0x38572000, 0x38574000, 0x38576000, 0x38578000, 0x3857A000, 0x3857C000, 0x3857E000,
  0x38580000, 0x38582000, 0x38584000, 0x38586000, 0x38588000, 0x3858A000, 0x3858C000, 0x3858E000, 0x38590000, 0x38592000, 0x38594000, 0x38596000, 0x38598000, 0x3859A000, 0x3859C000, 0x3859E000,
  0x385A0000, 0x385A2000, 0x385A4000, 0x385A6000, 0x385A8000, 0x385AA000, 0x385AC000, 0x385AE000, 0x385B0000, 0x385B2000, 0x385B4000, 0x385B6000, 0x385B8000, 0x385BA000, 0x385BC000, 0x385BE000,
  0x385C0000, 0x385C2000, 0x385C4000, 0x385C6000, 0x385C8000, 0x385CA000, 0x385CC000, 0x385CE000, 0x385D0000, 0x385D2000, 0x385D4000, 0x385D6000, 0x385D8000, 0x385DA000, 0x385DC000, 0x385DE000,
  0x385E0000, 0x385E2000, 0x385E4000, 0x385E6000, 0x385E8000, 0x385EA000, 0x385EC000, 0x385EE000, 0x385F0000, 0x385F2000, 0x385F4000, 0x385F6000, 0x385F8000, 0x385FA000, 0x385FC000, 0x385FE000,
  0x38600000, 0x38602000, 0x38604000, 0x38606000, 0x38608000, 0x3860A000, 0x3860C000, 0x3860E000, 0x38610000, 0x38612000, 0x38614000, 0x38616000, 0x38618000, 0x3861A000, 0x3861C000, 0x3861E000,
  0x38620000, 0x38622000, 0x38624000, 0x38626000, 0x38628000, 0x3862A000, 0x3862C000, 0x3862E000, 0x38630000, 0x38632000, 0x38634000, 0x38636000, 0x38638000, 0x3863A000, 0x3863C000, 0x3863E000,
  0x38640000, 0x38642000, 0x38644000, 0x38646000, 0x38648000, 0x3864A000, 0x3864C000, 0x3864E000, 0x38650000, 0x38652000, 0x38654000, 0x38656000, 0x38658000, 0x3865A000, 0x3865C000, 0x3865E000,
  0x38660000, 0x38662000, 0x38664000, 0x38666000, 0x38668000, 0x3866A000, 0x3866C000, 0x3866E000, 0x38670000, 0x38672000, 0x38674000, 0x38676000, 0x38678000, 0x3867A000, 0x3867C000, 0x3867E000,
  0x38680000, 0x38682000, 0x38684000, 0x38686000, 0x38688000, 0x3868A000, 0x3868C000, 0x3868E000, 0x38690000, 0x38692000, 0x38694000, 0x38696000, 0x38698000, 0x3869A000, 0x3869C000, 0x3869E000,
  0x386A0000, 0x386A2000, 0x386A4000, 0x386A6000, 0x386A8000, 0x386AA000, 0x386AC000, 0x386AE000, 0x386B0000, 0x386B2000, 0x386B4000, 0x386B6000, 0x386B8000, 0x386BA000, 0x386BC000, 0x386BE000,
  0x386C0000, 0x386C2000, 0x386C4000, 0x386C6000, 0x386C8000, 0x386CA000, 0x386CC000, 0x386CE000, 0x386D0000, 0x386D2000, 0x386D4000, 0x386D6000, 0x386D8000, 0x386DA000, 0x386DC000, 0x386DE000,
  0x386E0000, 0x386E2000, 0x386E4000, 0x386E6000, 0x386E8000, 0x386EA000, 0x386EC000, 0x386EE000, 0x386F0000, 0x386F2000, 0x386F4000, 0x386F6000, 0x386F8000, 0x386FA000, 0x386FC000, 0x386FE000,
  0x38700000, 0x38702000, 0x38704000, 0x38706000, 0x38708000, 0x3870A000, 0x3870C000, 0x3870E000, 0x38710000, 0x38712000, 0x38714000, 0x38716000, 0x38718000, 0x3871A000, 0x3871C000, 0x3871E000,
  0x38720000, 0x38722000, 0x38724000, 0x38726000, 0x38728000, 0x3872A000, 0x3872C000, 0x3872E000, 0x38730000, 0x38732000, 0x38734000, 0x38736000, 0x38738000, 0x3873A000, 0x3873C000, 0x3873E000,
  0x38740000, 0x38742000, 0x38744000, 0x38746000, 0x38748000, 0x3874A000, 0x3874C000, 0x3874E000, 0x38750000, 0x38752000, 0x38754000, 0x38756000, 0x38758000, 0x3875A000, 0x3875C000, 0x3875E000,
  0x38760000, 0x38762000, 0x38764000, 0x38766000, 0x38768000, 0x3876A000, 0x3876C000, 0x3876E000, 0x38770000, 0x38772000, 0x38774000, 0x38776000, 0x38778000, 0x3877A000, 0x3877C000, 0x3877E000,
  0x38780000, 0x38782000, 0x38784000, 0x38786000, 0x38788000, 0x3878A000, 0x3878C000, 0x3878E000, 0x38790000, 0x38792000, 0x38794000, 0x38796000, 0x38798000, 0x3879A000, 0x3879C000, 0x3879E000,
  0x387A0000, 0x387A2000, 0x387A4000, 0x387A6000, 0x387A8000, 0x387AA000, 0x387AC000, 0x387AE000, 0x387B0000, 0x387B2000, 0x387B4000, 0x387B6000, 0x387B8000, 0x387BA000, 0x387BC000, 0x387BE000,
  0x387C0000, 0x387C2000, 0x387C4000, 0x387C6000, 0x387C8000, 0x387CA000, 0x387CC000, 0x387CE000, 0x387D0000, 0x387D2000, 0x387D4000, 0x387D6000, 0x387D8000, 0x387DA000, 0x387DC000, 0x387DE000,
  0x387E0000, 0x387E2000, 0x387E4000, 0x387E6000, 0x387E8000, 0x387EA000, 0x387EC000, 0x387EE000, 0x387F0000, 0x387F2000, 0x387F4000, 0x387F6000, 0x387F8000, 0x387FA000, 0x387FC000, 0x387FE000 };
__constant static const uint32_t exponent_table[64] = {
  0x00000000, 0x00800000, 0x01000000, 0x01800000, 0x02000000, 0x02800000, 0x03000000, 0x03800000, 0x04000000, 0x04800000, 0x05000000, 0x05800000, 0x06000000, 0x06800000, 0x07000000, 0x07800000,
  0x08000000, 0x08800000, 0x09000000, 0x09800000, 0x0A000000, 0x0A800000, 0x0B000000, 0x0B800000, 0x0C000000, 0x0C800000, 0x0D000000, 0x0D800000, 0x0E000000, 0x0E800000, 0x0F000000, 0x47800000,
  0x80000000, 0x80800000, 0x81000000, 0x81800000, 0x82000000, 0x82800000, 0x83000000, 0x83800000, 0x84000000, 0x84800000, 0x85000000, 0x85800000, 0x86000000, 0x86800000, 0x87000000, 0x87800000,
  0x88000000, 0x88800000, 0x89000000, 0x89800000, 0x8A000000, 0x8A800000, 0x8B000000, 0x8B800000, 0x8C000000, 0x8C800000, 0x8D000000, 0x8D800000, 0x8E000000, 0x8E800000, 0x8F000000, 0xC7800000 };
__constant static const unsigned short offset_table[64] = {
  0, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024,
  0, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024 };

SCALAR_FUN_ATTR uint16_t float2halfbits(float value) {
  union { float x; uint32_t y; } u;
  u.x = value;
  uint32_t bits = u.y;

  uint16_t hbits = base_table[bits>>23] + (uint16_t)((bits&0x7FFFFF)>>shift_table[bits>>23]);;

  return hbits;
}

SCALAR_FUN_ATTR float halfbits2float(uint16_t value) {
  uint32_t bits = mantissa_table[offset_table[value>>10]+(value&0x3FF)] + exponent_table[value>>10];

  union { uint32_t x; float y; } u;
  u.x = bits;
  return u.y;
}

SCALAR_FUN_ATTR uint16_t halfbitsnextafter(uint16_t from, uint16_t to) {
  int fabs = from & 0x7FFF, tabs = to & 0x7FFF;
  if(fabs > 0x7C00 || tabs > 0x7C00) {
    return ((from&0x7FFF)>0x7C00) ? (from|0x200) : (to|0x200);
  }
  if(from == to || !(fabs|tabs)) {
    return to;
  }
  if(!fabs) {
    return (to&0x8000)+1;
  }
  unsigned int out =
    from +
    (((from>>15)^(unsigned int)((from^(0x8000|(0x8000-(from>>15))))<(to^(0x8000|(0x8000-(to>>15))))))<<1)
    - 1;
  return out;
}

// End of half.h.
// Start of timing.h.

// The function get_wall_time() returns the wall time in microseconds
// (with an unspecified offset).

#ifdef _WIN32

#define NOGDI
#include <windows.h>

static int64_t get_wall_time(void) {
  LARGE_INTEGER time,freq;
  assert(QueryPerformanceFrequency(&freq));
  assert(QueryPerformanceCounter(&time));
  return ((double)time.QuadPart / freq.QuadPart) * 1000000;
}

static int64_t get_wall_time_ns(void) {
  return get_wall_time() * 1000;
}

#else
// Assuming POSIX

#include <time.h>
#include <sys/time.h>

static int64_t get_wall_time_ns(void) {
  struct timespec time;
  assert(clock_gettime(CLOCK_MONOTONIC, &time) == 0);
  return time.tv_sec * 1000000000 + time.tv_nsec;
}

static int64_t get_wall_time(void) {
  return get_wall_time_ns() / 1000;
}


#endif

// End of timing.h.
// Start of lock.h.

// A very simple cross-platform implementation of locks.  Uses
// pthreads on Unix and some Windows thing there.  Futhark's
// host-level code is not multithreaded, but user code may be, so we
// need some mechanism for ensuring atomic access to API functions.
// This is that mechanism.  It is not exposed to user code at all, so
// we do not have to worry about name collisions.

#ifdef _WIN32

typedef HANDLE lock_t;

static void create_lock(lock_t *lock) {
  *lock = CreateMutex(NULL,  // Default security attributes.
                      FALSE, // Initially unlocked.
                      NULL); // Unnamed.
}

static void lock_lock(lock_t *lock) {
  assert(WaitForSingleObject(*lock, INFINITE) == WAIT_OBJECT_0);
}

static void lock_unlock(lock_t *lock) {
  assert(ReleaseMutex(*lock));
}

static void free_lock(lock_t *lock) {
  CloseHandle(*lock);
}

#else
// Assuming POSIX

#include <pthread.h>

typedef pthread_mutex_t lock_t;

static void create_lock(lock_t *lock) {
  int r = pthread_mutex_init(lock, NULL);
  assert(r == 0);
}

static void lock_lock(lock_t *lock) {
  int r = pthread_mutex_lock(lock);
  assert(r == 0);
}

static void lock_unlock(lock_t *lock) {
  int r = pthread_mutex_unlock(lock);
  assert(r == 0);
}

static void free_lock(lock_t *lock) {
  // Nothing to do for pthreads.
  (void)lock;
}

#endif

// End of lock.h.
// Start of free_list.h.

typedef uintptr_t fl_mem;

// An entry in the free list.  May be invalid, to avoid having to
// deallocate entries as soon as they are removed.  There is also a
// tag, to help with memory reuse.
struct free_list_entry {
  size_t size;
  fl_mem mem;
  const char *tag;
  unsigned char valid;
};

struct free_list {
  struct free_list_entry *entries; // Pointer to entries.
  int capacity;                    // Number of entries.
  int used;                        // Number of valid entries.
  lock_t lock;                     // Thread safety.
};

static void free_list_init(struct free_list *l) {
  l->capacity = 30; // Picked arbitrarily.
  l->used = 0;
  l->entries = (struct free_list_entry*) malloc(sizeof(struct free_list_entry) * l->capacity);
  for (int i = 0; i < l->capacity; i++) {
    l->entries[i].valid = 0;
  }
  create_lock(&l->lock);
}

// Remove invalid entries from the free list.
static void free_list_pack(struct free_list *l) {
  lock_lock(&l->lock);
  int p = 0;
  for (int i = 0; i < l->capacity; i++) {
    if (l->entries[i].valid) {
      l->entries[p] = l->entries[i];
      if (i > p) {
        l->entries[i].valid = 0;
      }
      p++;
    }
  }

  // Now p is the number of used elements.  We don't want it to go
  // less than the default capacity (although in practice it's OK as
  // long as it doesn't become 1).
  if (p < 30) {
    p = 30;
  }
  l->entries = realloc(l->entries, p * sizeof(struct free_list_entry));
  l->capacity = p;
  lock_unlock(&l->lock);
}

static void free_list_destroy(struct free_list *l) {
  assert(l->used == 0);
  free(l->entries);
  free_lock(&l->lock);
}

// Not part of the interface, so no locking.
static int free_list_find_invalid(struct free_list *l) {
  int i;
  for (i = 0; i < l->capacity; i++) {
    if (!l->entries[i].valid) {
      break;
    }
  }
  return i;
}

static void free_list_insert(struct free_list *l, size_t size, fl_mem mem, const char *tag) {
  lock_lock(&l->lock);
  int i = free_list_find_invalid(l);

  if (i == l->capacity) {
    // List is full; so we have to grow it.
    int new_capacity = l->capacity * 2 * sizeof(struct free_list_entry);
    l->entries = realloc(l->entries, new_capacity);
    for (int j = 0; j < l->capacity; j++) {
      l->entries[j+l->capacity].valid = 0;
    }
    l->capacity *= 2;
  }

  // Now 'i' points to the first invalid entry.
  l->entries[i].valid = 1;
  l->entries[i].size = size;
  l->entries[i].mem = mem;
  l->entries[i].tag = tag;

  l->used++;
  lock_unlock(&l->lock);
}

// Determine whether this entry in the free list is acceptable for
// satisfying the request.  Not public, so no locking.
static bool free_list_acceptable(size_t size, const char* tag, struct free_list_entry *entry) {
  // We check not just the hard requirement (is the entry acceptable
  // and big enough?) but also put a cap on how much wasted space
  // (internal fragmentation) we allow.  This is necessarily a
  // heuristic, and a crude one.

  if (!entry->valid) {
    return false;
  }

  if (size > entry->size) {
    return false;
  }

  // We know the block fits.  Now the question is whether it is too
  // big.  Our policy is as follows:
  //
  // 1) We don't care about wasted space below 4096 bytes (to avoid
  // churn in tiny allocations).
  //
  // 2) If the tag matches, we allow _any_ amount of wasted space.
  //
  // 3) Otherwise we allow up to 50% wasted space.

  if (entry->size < 4096) {
    return true;
  }

  if (entry->tag == tag) {
    return true;
  }

  if (entry->size < size * 2) {
    return true;
  }

  return false;
}

// Find and remove a memory block of the indicated tag, or if that
// does not exist, another memory block with exactly the desired size.
// Returns 0 on success.
static int free_list_find(struct free_list *l, size_t size, const char *tag,
                          size_t *size_out, fl_mem *mem_out) {
  lock_lock(&l->lock);
  int size_match = -1;
  int i;
  int ret = 1;
  for (i = 0; i < l->capacity; i++) {
    if (free_list_acceptable(size, tag, &l->entries[i]) &&
        (size_match < 0 || l->entries[i].size < l->entries[size_match].size)) {
      // If this entry is valid, has sufficient size, and is smaller than the
      // best entry found so far, use this entry.
      size_match = i;
    }
  }

  if (size_match >= 0) {
    l->entries[size_match].valid = 0;
    *size_out = l->entries[size_match].size;
    *mem_out = l->entries[size_match].mem;
    l->used--;
    ret = 0;
  }
  lock_unlock(&l->lock);
  return ret;
}

// Remove the first block in the free list.  Returns 0 if a block was
// removed, and nonzero if the free list was already empty.
static int free_list_first(struct free_list *l, fl_mem *mem_out) {
  lock_lock(&l->lock);
  int ret = 1;
  for (int i = 0; i < l->capacity; i++) {
    if (l->entries[i].valid) {
      l->entries[i].valid = 0;
      *mem_out = l->entries[i].mem;
      l->used--;
      ret = 0;
      break;
    }
  }
  lock_unlock(&l->lock);
  return ret;
}

// End of free_list.h.
// Start of event_list.h

typedef int (*event_report_fn)(struct str_builder*, void*);

// A collection of key-value associations. Used to associate extra data with
// events.
struct kvs {
  // A buffer that contains all value data. Must be freed when the struct kvs is
  // no longer used.
  char *buf;

  // Size of buf in bytes.
  size_t buf_size;

  // Number of bytes used in buf.
  size_t buf_used;

  // Number of associations stored.
  size_t n;

  // Capacity of vals.
  size_t vals_capacity;

  // An array of keys.
  const char* *keys;

  // Indexes into 'buf' that contains the values as zero-terminated strings.
  size_t *vals;
};

static const size_t KVS_INIT_BUF_SIZE = 128;
static const size_t KVS_INIT_NUMKEYS = 8;

void kvs_init(struct kvs* kvs) {
  kvs->buf = malloc(KVS_INIT_BUF_SIZE);
  kvs->buf_size = KVS_INIT_BUF_SIZE;
  kvs->buf_used = 0;
  kvs->vals_capacity = KVS_INIT_NUMKEYS;
  kvs->keys = calloc(kvs->vals_capacity, sizeof(const char*));
  kvs->vals = calloc(kvs->vals_capacity, sizeof(size_t));
  kvs->n = 0;
}

struct kvs* kvs_new(void) {
  struct kvs *kvs = malloc(sizeof(struct kvs));
  kvs_init(kvs);
  return kvs;
}

void kvs_printf(struct kvs* kvs, const char* key, const char* fmt, ...) {
  va_list vl;
  va_start(vl, fmt);

  size_t needed = 1 + (size_t)vsnprintf(NULL, 0, fmt, vl);

  while (kvs->buf_used+needed > kvs->buf_size) {
    kvs->buf_size *= 2;
    kvs->buf = realloc(kvs->buf, kvs->buf_size * sizeof(const char*));
  }

  if (kvs->n == kvs->vals_capacity) {
    kvs->vals_capacity *= 2;
    kvs->vals = realloc(kvs->vals, kvs->vals_capacity * sizeof(size_t));
    kvs->keys = realloc(kvs->keys, kvs->vals_capacity * sizeof(char*));
  }

  kvs->keys[kvs->n] = key;
  kvs->vals[kvs->n] = kvs->buf_used;
  kvs->buf_used += needed;

  va_start(vl, fmt); // Must re-init.
  vsnprintf(&kvs->buf[kvs->vals[kvs->n]], needed, fmt, vl);

  kvs->n++;
}

void kvs_free(struct kvs* kvs) {
  free(kvs->vals);
  free(kvs->keys);
  free(kvs->buf);
}

// Assumes all of the values are valid JSON objects.
void kvs_json(const struct kvs* kvs, struct str_builder *sb) {
  str_builder_char(sb, '{');
  for (size_t i = 0; i < kvs->n; i++) {
    if (i != 0) {
      str_builder_str(sb, ",");
    }
    str_builder_json_str(sb, kvs->keys[i]);
    str_builder_str(sb, ":");
    str_builder_str(sb, &kvs->buf[kvs->vals[i]]);
  }
  str_builder_char(sb, '}');
}

void kvs_log(const struct kvs* kvs, const char* prefix, FILE* f) {
  for (size_t i = 0; i < kvs->n; i++) {
    fprintf(f, "%s%s: %s\n",
            prefix,
            kvs->keys[i],
            &kvs->buf[kvs->vals[i]]);
  }
}

struct event {
  void* data;
  event_report_fn f;
  const char* name;
  const char *provenance;
  // Key-value information that is also to be printed.
  struct kvs *kvs;
};

struct event_list {
  struct event *events;
  int num_events;
  int capacity;
};

static void event_list_init(struct event_list *l) {
  l->capacity = 100;
  l->num_events = 0;
  l->events = calloc(l->capacity, sizeof(struct event));
}

static void event_list_free(struct event_list *l) {
  free(l->events);
}

static void add_event_to_list(struct event_list *l,
                              const char* name,
                              const char* provenance,
                              struct kvs *kvs,
                              void* data,
                              event_report_fn f) {
  if (l->num_events == l->capacity) {
    l->capacity *= 2;
    l->events = realloc(l->events, l->capacity * sizeof(struct event));
  }
  l->events[l->num_events].name = name;
  l->events[l->num_events].provenance =
    provenance ? provenance : "unknown";
  l->events[l->num_events].kvs = kvs;
  l->events[l->num_events].data = data;
  l->events[l->num_events].f = f;
  l->num_events++;
}

static int report_events_in_list(struct event_list *l,
                                 struct str_builder* sb) {
  int ret = 0;
  for (int i = 0; i < l->num_events; i++) {
    if (i != 0) {
      str_builder_str(sb, ",");
    }
    str_builder_str(sb, "{\"name\":");
    str_builder_json_str(sb, l->events[i].name);
    str_builder_str(sb, ",\"provenance\":");
    str_builder_json_str(sb, l->events[i].provenance);
    if (l->events[i].f(sb, l->events[i].data) != 0) {
      ret = 1;
      break;
    }

    str_builder_str(sb, ",\"details\":");
    if (l->events[i].kvs) {
      kvs_json(l->events[i].kvs, sb);
      kvs_free(l->events[i].kvs);
    } else {
      str_builder_str(sb, "{}");
    }

    str_builder(sb, "}");
  }
  event_list_free(l);
  event_list_init(l);
  return ret;
}

// End of event_list.h
#include <getopt.h>
#include <ctype.h>
#include <inttypes.h>
static const char *entry_point = "main";
// Start of values.h.

//// Text I/O

typedef int (*writer)(FILE*, const void*);
typedef int (*bin_reader)(void*);
typedef int (*str_reader)(char *, void*);

struct array_reader {
  char* elems;
  int64_t n_elems_space;
  int64_t elem_size;
  int64_t n_elems_used;
  int64_t *shape;
  str_reader elem_reader;
};

static void skipspaces(FILE *f) {
  int c;
  do {
    c = getc(f);
  } while (isspace(c));

  if (c != EOF) {
    ungetc(c, f);
  }
}

static int constituent(char c) {
  return isalnum(c) || c == '.' || c == '-' || c == '+' || c == '_';
}

// Produces an empty token only on EOF.
static void next_token(FILE *f, char *buf, int bufsize) {
 start:
  skipspaces(f);

  int i = 0;
  while (i < bufsize) {
    int c = getc(f);
    buf[i] = (char)c;

    if (c == EOF) {
      buf[i] = 0;
      return;
    } else if (c == '-' && i == 1 && buf[0] == '-') {
      // Line comment, so skip to end of line and start over.
      for (; c != '\n' && c != EOF; c = getc(f));
      goto start;
    } else if (!constituent((char)c)) {
      if (i == 0) {
        // We permit single-character tokens that are not
        // constituents; this lets things like ']' and ',' be
        // tokens.
        buf[i+1] = 0;
        return;
      } else {
        ungetc(c, f);
        buf[i] = 0;
        return;
      }
    }

    i++;
  }

  buf[bufsize-1] = 0;
}

static int next_token_is(FILE *f, char *buf, int bufsize, const char* expected) {
  next_token(f, buf, bufsize);
  return strcmp(buf, expected) == 0;
}

static void remove_underscores(char *buf) {
  char *w = buf;

  for (char *r = buf; *r; r++) {
    if (*r != '_') {
      *w++ = *r;
    }
  }

  *w++ = 0;
}

static int read_str_elem(char *buf, struct array_reader *reader) {
  int ret;
  if (reader->n_elems_used == reader->n_elems_space) {
    reader->n_elems_space *= 2;
    reader->elems = (char*) realloc(reader->elems,
                                    (size_t)(reader->n_elems_space * reader->elem_size));
  }

  ret = reader->elem_reader(buf, reader->elems + reader->n_elems_used * reader->elem_size);

  if (ret == 0) {
    reader->n_elems_used++;
  }

  return ret;
}

static int read_str_array_elems(FILE *f,
                                char *buf, int bufsize,
                                struct array_reader *reader, int64_t dims) {
  int ret = 1;
  int expect_elem = 1;
  char *knows_dimsize = (char*) calloc((size_t)dims, sizeof(char));
  int cur_dim = (int)dims-1;
  int64_t *elems_read_in_dim = (int64_t*) calloc((size_t)dims, sizeof(int64_t));

  while (1) {
    next_token(f, buf, bufsize);
    if (strcmp(buf, "]") == 0) {
      expect_elem = 0;
      if (knows_dimsize[cur_dim]) {
        if (reader->shape[cur_dim] != elems_read_in_dim[cur_dim]) {
          ret = 1;
          break;
        }
      } else {
        knows_dimsize[cur_dim] = 1;
        reader->shape[cur_dim] = elems_read_in_dim[cur_dim];
      }
      if (cur_dim == 0) {
        ret = 0;
        break;
      } else {
        cur_dim--;
        elems_read_in_dim[cur_dim]++;
      }
    } else if (!expect_elem && strcmp(buf, ",") == 0) {
      expect_elem = 1;
    } else if (expect_elem) {
      if (strcmp(buf, "[") == 0) {
        if (cur_dim == dims - 1) {
          ret = 1;
          break;
        }
        cur_dim++;
        elems_read_in_dim[cur_dim] = 0;
      } else if (cur_dim == dims - 1) {
        ret = read_str_elem(buf, reader);
        if (ret != 0) {
          break;
        }
        expect_elem = 0;
        elems_read_in_dim[cur_dim]++;
      } else {
        ret = 1;
        break;
      }
    } else {
      ret = 1;
      break;
    }
  }

  free(knows_dimsize);
  free(elems_read_in_dim);
  return ret;
}

static int read_str_empty_array(FILE *f, char *buf, int bufsize,
                                const char *type_name, int64_t *shape, int64_t dims) {
  if (strlen(buf) == 0) {
    // EOF
    return 1;
  }

  if (strcmp(buf, "empty") != 0) {
    return 1;
  }

  if (!next_token_is(f, buf, bufsize, "(")) {
    return 1;
  }

  for (int i = 0; i < dims; i++) {
    if (!next_token_is(f, buf, bufsize, "[")) {
      return 1;
    }

    next_token(f, buf, bufsize);

    if (sscanf(buf, "%"SCNu64, (uint64_t*)&shape[i]) != 1) {
      return 1;
    }

    if (!next_token_is(f, buf, bufsize, "]")) {
      return 1;
    }
  }

  if (!next_token_is(f, buf, bufsize, type_name)) {
    return 1;
  }


  if (!next_token_is(f, buf, bufsize, ")")) {
    return 1;
  }

  // Check whether the array really is empty.
  for (int i = 0; i < dims; i++) {
    if (shape[i] == 0) {
      return 0;
    }
  }

  // Not an empty array!
  return 1;
}

static int read_str_array(FILE *f,
                          int64_t elem_size, str_reader elem_reader,
                          const char *type_name,
                          void **data, int64_t *shape, int64_t dims) {
  int ret;
  struct array_reader reader;
  char buf[100];

  int dims_seen;
  for (dims_seen = 0; dims_seen < dims; dims_seen++) {
    if (!next_token_is(f, buf, sizeof(buf), "[")) {
      break;
    }
  }

  if (dims_seen == 0) {
    return read_str_empty_array(f, buf, sizeof(buf), type_name, shape, dims);
  }

  if (dims_seen != dims) {
    return 1;
  }

  reader.shape = shape;
  reader.n_elems_used = 0;
  reader.elem_size = elem_size;
  reader.n_elems_space = 16;
  reader.elems = (char*) realloc(*data, (size_t)(elem_size*reader.n_elems_space));
  reader.elem_reader = elem_reader;

  ret = read_str_array_elems(f, buf, sizeof(buf), &reader, dims);

  *data = reader.elems;

  return ret;
}

#define READ_STR(MACRO, PTR, SUFFIX)                                   \
  remove_underscores(buf);                                              \
  int j;                                                                \
  if (sscanf(buf, "%"MACRO"%n", (PTR*)dest, &j) == 1) {                 \
    return !(strcmp(buf+j, "") == 0 || strcmp(buf+j, SUFFIX) == 0);     \
  } else {                                                              \
    return 1;                                                           \
  }

static int read_str_i8(char *buf, void* dest) {
  // Some platforms (WINDOWS) does not support scanf %hhd or its
  // cousin, %SCNi8.  Read into int first to avoid corrupting
  // memory.
  //
  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=63417
  remove_underscores(buf);
  int j, x;
  if (sscanf(buf, "%i%n", &x, &j) == 1) {
    *(int8_t*)dest = (int8_t)x;
    return !(strcmp(buf+j, "") == 0 || strcmp(buf+j, "i8") == 0);
  } else {
    return 1;
  }
}

static int read_str_u8(char *buf, void* dest) {
  // Some platforms (WINDOWS) does not support scanf %hhd or its
  // cousin, %SCNu8.  Read into int first to avoid corrupting
  // memory.
  //
  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=63417
  remove_underscores(buf);
  int j, x;
  if (sscanf(buf, "%i%n", &x, &j) == 1) {
    *(uint8_t*)dest = (uint8_t)x;
    return !(strcmp(buf+j, "") == 0 || strcmp(buf+j, "u8") == 0);
  } else {
    return 1;
  }
}

static int read_str_i16(char *buf, void* dest) {
  READ_STR(SCNi16, int16_t, "i16");
}

static int read_str_u16(char *buf, void* dest) {
  READ_STR(SCNi16, int16_t, "u16");
}

static int read_str_i32(char *buf, void* dest) {
  READ_STR(SCNi32, int32_t, "i32");
}

static int read_str_u32(char *buf, void* dest) {
  READ_STR(SCNi32, int32_t, "u32");
}

static int read_str_i64(char *buf, void* dest) {
  READ_STR(SCNi64, int64_t, "i64");
}

static int read_str_u64(char *buf, void* dest) {
  // FIXME: This is not correct, as SCNu64 only permits decimal
  // literals.  However, SCNi64 does not handle very large numbers
  // correctly (it's really for signed numbers, so that's fair).
  READ_STR(SCNu64, uint64_t, "u64");
}

static int read_str_f16(char *buf, void* dest) {
  remove_underscores(buf);
  if (strcmp(buf, "f16.nan") == 0) {
    *(uint16_t*)dest = float2halfbits(NAN);
    return 0;
  } else if (strcmp(buf, "f16.inf") == 0) {
    *(uint16_t*)dest = float2halfbits(INFINITY);
    return 0;
  } else if (strcmp(buf, "-f16.inf") == 0) {
    *(uint16_t*)dest = float2halfbits(-INFINITY);
    return 0;
  } else {
    int j;
    float x;
    if (sscanf(buf, "%f%n", &x, &j) == 1) {
      if (strcmp(buf+j, "") == 0 || strcmp(buf+j, "f16") == 0) {
        *(uint16_t*)dest = float2halfbits(x);
        return 0;
      }
    }
    return 1;
  }
}

static int read_str_f32(char *buf, void* dest) {
  remove_underscores(buf);
  if (strcmp(buf, "f32.nan") == 0) {
    *(float*)dest = (float)NAN;
    return 0;
  } else if (strcmp(buf, "f32.inf") == 0) {
    *(float*)dest = (float)INFINITY;
    return 0;
  } else if (strcmp(buf, "-f32.inf") == 0) {
    *(float*)dest = (float)-INFINITY;
    return 0;
  } else {
    READ_STR("f", float, "f32");
  }
}

static int read_str_f64(char *buf, void* dest) {
  remove_underscores(buf);
  if (strcmp(buf, "f64.nan") == 0) {
    *(double*)dest = (double)NAN;
    return 0;
  } else if (strcmp(buf, "f64.inf") == 0) {
    *(double*)dest = (double)INFINITY;
    return 0;
  } else if (strcmp(buf, "-f64.inf") == 0) {
    *(double*)dest = (double)-INFINITY;
    return 0;
  } else {
    READ_STR("lf", double, "f64");
  }
}

static int read_str_bool(char *buf, void* dest) {
  if (strcmp(buf, "true") == 0) {
    *(char*)dest = 1;
    return 0;
  } else if (strcmp(buf, "false") == 0) {
    *(char*)dest = 0;
    return 0;
  } else {
    return 1;
  }
}

static int read_str_unit(char *buf, void* dest) {
  (void)dest;
  if (strcmp(buf, "()") == 0) {
    return 0;
  } else {
    return 1;
  }
}

static int write_str_i8(FILE *out, const int8_t *src) {
  return fprintf(out, "%hhdi8", *src);
}

static int write_str_u8(FILE *out, const uint8_t *src) {
  return fprintf(out, "%hhuu8", *src);
}

static int write_str_i16(FILE *out, const int16_t *src) {
  return fprintf(out, "%hdi16", *src);
}

static int write_str_u16(FILE *out, const uint16_t *src) {
  return fprintf(out, "%huu16", *src);
}

static int write_str_i32(FILE *out, const int32_t *src) {
  return fprintf(out, "%di32", *src);
}

static int write_str_u32(FILE *out, const uint32_t *src) {
  return fprintf(out, "%uu32", *src);
}

static int write_str_i64(FILE *out, const int64_t *src) {
  return fprintf(out, "%"PRIi64"i64", *src);
}

static int write_str_u64(FILE *out, const uint64_t *src) {
  return fprintf(out, "%"PRIu64"u64", *src);
}

// FLT_DECIMAL_DIG and DBL_DECIMAL_DIG are defined in C11.
// If we want C99 compatibility, we must define them ourselves.
// We choose the standard values on platforms that use the IEEE754 defaults, with fallback to an overestimate.
#ifndef FLT_DECIMAL_DIG
  #if FLT_RADIX == 2 && FLT_MANT_DIG <= 24 && 9 < DECIMAL_DIG
    #define FLT_DECIMAL_DIG 9
  #else
    #define FLT_DECIMAL_DIG DECIMAL_DIG
  #endif
#endif
#ifndef DBL_DECIMAL_DIG
  #if FLT_RADIX == 2 && DBL_MANT_DIG <= 53 && 17 < DECIMAL_DIG
    #define DBL_DECIMAL_DIG 17
  #else
    #define DBL_DECIMAL_DIG DECIMAL_DIG
  #endif
#endif

static int write_str_f16(FILE *out, const uint16_t *src) {
  float x = halfbits2float(*src);
  if (isnan(x)) {
    return fprintf(out, "f16.nan");
  } else if (isinf(x) && x >= 0) {
    return fprintf(out, "f16.inf");
  } else if (isinf(x)) {
    return fprintf(out, "-f16.inf");
  } else {
    return fprintf(out, "%.*gf16", FLT_DECIMAL_DIG, x);
  }
}

static int write_str_f32(FILE *out, const float *src) {
  float x = *src;
  if (isnan(x)) {
    return fprintf(out, "f32.nan");
  } else if (isinf(x) && x >= 0) {
    return fprintf(out, "f32.inf");
  } else if (isinf(x)) {
    return fprintf(out, "-f32.inf");
  } else {
    return fprintf(out, "%.*gf32", FLT_DECIMAL_DIG, x);
  }
}

static int write_str_f64(FILE *out, const double *src) {
  double x = *src;
  if (isnan(x)) {
    return fprintf(out, "f64.nan");
  } else if (isinf(x) && x >= 0) {
    return fprintf(out, "f64.inf");
  } else if (isinf(x)) {
    return fprintf(out, "-f64.inf");
  } else {
    return fprintf(out, "%.*gf64", DBL_DECIMAL_DIG, x);
  }
}

static int write_str_bool(FILE *out, const void *src) {
  return fprintf(out, *(char*)src ? "true" : "false");
}

static int write_str_unit(FILE *out, const void *src) {
  (void)src;
  return fprintf(out, "()");
}

//// Binary I/O

#define BINARY_FORMAT_VERSION 2
#define IS_BIG_ENDIAN (!*(unsigned char *)&(uint16_t){1})

static void flip_bytes(size_t elem_size, unsigned char *elem) {
  for (size_t j=0; j<elem_size/2; j++) {
    unsigned char head = elem[j];
    size_t tail_index = elem_size-1-j;
    elem[j] = elem[tail_index];
    elem[tail_index] = head;
  }
}

// On Windows we need to explicitly set the file mode to not mangle
// newline characters.  On *nix there is no difference.
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
static void set_binary_mode(FILE *f) {
  setmode(fileno(f), O_BINARY);
}
#else
static void set_binary_mode(FILE *f) {
  (void)f;
}
#endif

static int read_byte(FILE *f, void* dest) {
  size_t num_elems_read = fread(dest, 1, 1, f);
  return num_elems_read == 1 ? 0 : 1;
}

//// Types

struct primtype_info_t {
  const char binname[4]; // Used for parsing binary data.
  const char* type_name; // Same name as in Futhark.
  const int64_t size; // in bytes
  const writer write_str; // Write in text format.
  const str_reader read_str; // Read in text format.
};

static const struct primtype_info_t i8_info =
  {.binname = "  i8", .type_name = "i8",   .size = 1,
   .write_str = (writer)write_str_i8, .read_str = (str_reader)read_str_i8};
static const struct primtype_info_t i16_info =
  {.binname = " i16", .type_name = "i16",  .size = 2,
   .write_str = (writer)write_str_i16, .read_str = (str_reader)read_str_i16};
static const struct primtype_info_t i32_info =
  {.binname = " i32", .type_name = "i32",  .size = 4,
   .write_str = (writer)write_str_i32, .read_str = (str_reader)read_str_i32};
static const struct primtype_info_t i64_info =
  {.binname = " i64", .type_name = "i64",  .size = 8,
   .write_str = (writer)write_str_i64, .read_str = (str_reader)read_str_i64};
static const struct primtype_info_t u8_info =
  {.binname = "  u8", .type_name = "u8",   .size = 1,
   .write_str = (writer)write_str_u8, .read_str = (str_reader)read_str_u8};
static const struct primtype_info_t u16_info =
  {.binname = " u16", .type_name = "u16",  .size = 2,
   .write_str = (writer)write_str_u16, .read_str = (str_reader)read_str_u16};
static const struct primtype_info_t u32_info =
  {.binname = " u32", .type_name = "u32",  .size = 4,
   .write_str = (writer)write_str_u32, .read_str = (str_reader)read_str_u32};
static const struct primtype_info_t u64_info =
  {.binname = " u64", .type_name = "u64",  .size = 8,
   .write_str = (writer)write_str_u64, .read_str = (str_reader)read_str_u64};
static const struct primtype_info_t f16_info =
  {.binname = " f16", .type_name = "f16",  .size = 2,
   .write_str = (writer)write_str_f16, .read_str = (str_reader)read_str_f16};
static const struct primtype_info_t f32_info =
  {.binname = " f32", .type_name = "f32",  .size = 4,
   .write_str = (writer)write_str_f32, .read_str = (str_reader)read_str_f32};
static const struct primtype_info_t f64_info =
  {.binname = " f64", .type_name = "f64",  .size = 8,
   .write_str = (writer)write_str_f64, .read_str = (str_reader)read_str_f64};
static const struct primtype_info_t bool_info =
  {.binname = "bool", .type_name = "bool", .size = 1,
   .write_str = (writer)write_str_bool, .read_str = (str_reader)read_str_bool};
static const struct primtype_info_t unit_info =
  {.binname = "bool", .type_name = "unit",   .size = 1,
   .write_str = (writer)write_str_unit, .read_str = (str_reader)read_str_unit};

static const struct primtype_info_t* primtypes[] = {
  &i8_info, &i16_info, &i32_info, &i64_info,
  &u8_info, &u16_info, &u32_info, &u64_info,
  &f16_info, &f32_info, &f64_info,
  &bool_info,
  NULL // NULL-terminated
};

// General value interface.  All endian business taken care of at
// lower layers.

static int read_is_binary(FILE *f) {
  skipspaces(f);
  int c = getc(f);
  if (c == 'b') {
    int8_t bin_version;
    int ret = read_byte(f, &bin_version);

    if (ret != 0) { futhark_panic(1, "binary-input: could not read version.\n"); }

    if (bin_version != BINARY_FORMAT_VERSION) {
      futhark_panic(1, "binary-input: File uses version %i, but I only understand version %i.\n",
            bin_version, BINARY_FORMAT_VERSION);
    }

    return 1;
  }
  ungetc(c, f);
  return 0;
}

static const struct primtype_info_t* read_bin_read_type_enum(FILE *f) {
  char read_binname[4];

  int num_matched = fscanf(f, "%4c", read_binname);
  if (num_matched != 1) { futhark_panic(1, "binary-input: Couldn't read element type.\n"); }

  const struct primtype_info_t **type = primtypes;

  for (; *type != NULL; type++) {
    // I compare the 4 characters manually instead of using strncmp because
    // this allows any value to be used, also NULL bytes
    if (memcmp(read_binname, (*type)->binname, 4) == 0) {
      return *type;
    }
  }
  futhark_panic(1, "binary-input: Did not recognize the type '%s'.\n", read_binname);
  return NULL;
}

static void read_bin_ensure_scalar(FILE *f, const struct primtype_info_t *expected_type) {
  int8_t bin_dims;
  int ret = read_byte(f, &bin_dims);
  if (ret != 0) { futhark_panic(1, "binary-input: Couldn't get dims.\n"); }

  if (bin_dims != 0) {
    futhark_panic(1, "binary-input: Expected scalar (0 dimensions), but got array with %i dimensions.\n",
          bin_dims);
  }

  const struct primtype_info_t *bin_type = read_bin_read_type_enum(f);
  if (bin_type != expected_type) {
    futhark_panic(1, "binary-input: Expected scalar of type %s but got scalar of type %s.\n",
          expected_type->type_name,
          bin_type->type_name);
  }
}

//// High-level interface

static int read_bin_array(FILE *f,
                          const struct primtype_info_t *expected_type, void **data, int64_t *shape, int64_t dims) {
  int ret;

  int8_t bin_dims;
  ret = read_byte(f, &bin_dims);
  if (ret != 0) { futhark_panic(1, "binary-input: Couldn't get dims.\n"); }

  if (bin_dims != dims) {
    futhark_panic(1, "binary-input: Expected %i dimensions, but got array with %i dimensions.\n",
          dims, bin_dims);
  }

  const struct primtype_info_t *bin_primtype = read_bin_read_type_enum(f);
  if (expected_type != bin_primtype) {
    futhark_panic(1, "binary-input: Expected %iD-array with element type '%s' but got %iD-array with element type '%s'.\n",
          dims, expected_type->type_name, dims, bin_primtype->type_name);
  }

  int64_t elem_count = 1;
  for (int i=0; i<dims; i++) {
    int64_t bin_shape;
    ret = (int)fread(&bin_shape, sizeof(bin_shape), 1, f);
    if (ret != 1) {
      futhark_panic(1, "binary-input: Couldn't read size for dimension %i of array.\n", i);
    }
    if (IS_BIG_ENDIAN) {
      flip_bytes(sizeof(bin_shape), (unsigned char*) &bin_shape);
    }
    elem_count *= bin_shape;
    shape[i] = bin_shape;
  }

  int64_t elem_size = expected_type->size;
  void* tmp = realloc(*data, (size_t)(elem_count * elem_size));
  if (tmp == NULL) {
    futhark_panic(1, "binary-input: Failed to allocate array of size %i.\n",
          elem_count * elem_size);
  }
  *data = tmp;

  int64_t num_elems_read = (int64_t)fread(*data, (size_t)elem_size, (size_t)elem_count, f);
  if (num_elems_read != elem_count) {
    futhark_panic(1, "binary-input: tried to read %i elements of an array, but only got %i elements.\n",
          elem_count, num_elems_read);
  }

  // If we're on big endian platform we must change all multibyte elements
  // from using little endian to big endian
  if (IS_BIG_ENDIAN && elem_size != 1) {
    flip_bytes((size_t)elem_size, (unsigned char*) *data);
  }

  return 0;
}

static int read_array(FILE *f, const struct primtype_info_t *expected_type, void **data, int64_t *shape, int64_t dims) {
  if (!read_is_binary(f)) {
    return read_str_array(f, expected_type->size, (str_reader)expected_type->read_str, expected_type->type_name, data, shape, dims);
  } else {
    return read_bin_array(f, expected_type, data, shape, dims);
  }
}

static int end_of_input(FILE *f) {
  skipspaces(f);
  char token[2];
  next_token(f, token, sizeof(token));
  if (strcmp(token, "") == 0) {
    return 0;
  } else {
    return 1;
  }
}

static int write_str_array(FILE *out,
                           const struct primtype_info_t *elem_type,
                           const unsigned char *data,
                           const int64_t *shape,
                           int8_t rank) {
  if (rank==0) {
    elem_type->write_str(out, (const void*)data);
  } else {
    int64_t len = (int64_t)shape[0];
    int64_t slice_size = 1;

    int64_t elem_size = elem_type->size;
    for (int8_t i = 1; i < rank; i++) {
      slice_size *= shape[i];
    }

    if (len*slice_size == 0) {
      fprintf(out, "empty(");
      for (int64_t i = 0; i < rank; i++) {
        fprintf(out, "[%"PRIi64"]", shape[i]);
      }
      fprintf(out, "%s", elem_type->type_name);
      fprintf(out, ")");
    } else if (rank==1) {
      fputc('[', out);
      for (int64_t i = 0; i < len; i++) {
        elem_type->write_str(out, (const void*) (data + i * elem_size));
        if (i != len-1) {
          fprintf(out, ", ");
        }
      }
      fputc(']', out);
    } else {
      fputc('[', out);
      for (int64_t i = 0; i < len; i++) {
        write_str_array(out, elem_type, data + i * slice_size * elem_size, shape+1, rank-1);
        if (i != len-1) {
          fprintf(out, ", ");
        }
      }
      fputc(']', out);
    }
  }
  return 0;
}

static int write_bin_array(FILE *out,
                           const struct primtype_info_t *elem_type,
                           const unsigned char *data,
                           const int64_t *shape,
                           int8_t rank) {
  int64_t num_elems = 1;
  for (int64_t i = 0; i < rank; i++) {
    num_elems *= shape[i];
  }

  fputc('b', out);
  fputc((char)BINARY_FORMAT_VERSION, out);
  fwrite(&rank, sizeof(int8_t), 1, out);
  fwrite(elem_type->binname, 4, 1, out);
  if (shape != NULL) {
    fwrite(shape, sizeof(int64_t), (size_t)rank, out);
  }

  if (IS_BIG_ENDIAN) {
    for (int64_t i = 0; i < num_elems; i++) {
      const unsigned char *elem = data+i*elem_type->size;
      for (int64_t j = 0; j < elem_type->size; j++) {
        fwrite(&elem[elem_type->size-j], 1, 1, out);
      }
    }
  } else {
    fwrite(data, (size_t)elem_type->size, (size_t)num_elems, out);
  }

  return 0;
}

static int write_array(FILE *out, int write_binary,
                       const struct primtype_info_t *elem_type,
                       const void *data,
                       const int64_t *shape,
                       const int8_t rank) {
  if (write_binary) {
    return write_bin_array(out, elem_type, data, shape, rank);
  } else {
    return write_str_array(out, elem_type, data, shape, rank);
  }
}

static int read_scalar(FILE *f,
                       const struct primtype_info_t *expected_type, void *dest) {
  if (!read_is_binary(f)) {
    char buf[100];
    next_token(f, buf, sizeof(buf));
    return expected_type->read_str(buf, dest);
  } else {
    read_bin_ensure_scalar(f, expected_type);
    size_t elem_size = (size_t)expected_type->size;
    size_t num_elems_read = fread(dest, elem_size, 1, f);
    if (IS_BIG_ENDIAN) {
      flip_bytes(elem_size, (unsigned char*) dest);
    }
    return num_elems_read == 1 ? 0 : 1;
  }
}

static int write_scalar(FILE *out, int write_binary, const struct primtype_info_t *type, void *src) {
  if (write_binary) {
    return write_bin_array(out, type, src, NULL, 0);
  } else {
    return type->write_str(out, src);
  }
}

// End of values.h.

// Start of server.h.

// Forward declarations of things that we technically don't know until
// the application header file is included, but which we need.
struct futhark_context_config;
struct futhark_context;
char *futhark_context_get_error(struct futhark_context *ctx);
int futhark_context_sync(struct futhark_context *ctx);
int futhark_context_clear_caches(struct futhark_context *ctx);
int futhark_context_config_set_tuning_param(struct futhark_context_config *cfg,
                                            const char *param_name,
                                            size_t new_value);
int futhark_get_tuning_param_count(void);
const char* futhark_get_tuning_param_name(int i);
const char* futhark_get_tuning_param_class(int i);

typedef int (*restore_fn)(const void*, FILE*, struct futhark_context*, void*);
typedef void (*store_fn)(const void*, FILE*, struct futhark_context*, void*);
typedef int (*free_fn)(const void*, struct futhark_context*, void*);
typedef int (*array_new_fn)(struct futhark_context *, void**, const void*, const int64_t*);
typedef int (*array_set_fn)(struct futhark_context *, const void*, const void*, const int64_t*);
typedef const int64_t* (*array_shape_fn)(struct futhark_context*, const void*);
typedef int (*array_index_fn)(struct futhark_context*, void*, const void*, const int64_t*);
typedef int (*project_fn)(struct futhark_context*, void*, const void*);
typedef int (*variant_fn)(struct futhark_context*, const void*);
typedef int (*new_fn)(struct futhark_context*, void**, const void*[]);
typedef int (*destruct_fn)(struct futhark_context*, const void*[], const void*);

enum kind {
  PRIMITIVE,
  ARRAY,
  RECORD,
  SUM,
  OPAQUE
};

struct array {
  int rank;
  const struct type *element_type;
  array_new_fn new;
  array_set_fn set;
  array_shape_fn shape;
  array_index_fn index;
};

struct field {
  const char *name;
  const struct type *type;
  project_fn project;
};

struct record {
  int num_fields;
  const struct field* fields;
  new_fn new;
};

struct variant {
  const char *name;
  int num_types;
  const struct type **types;
  new_fn new;
  destruct_fn destruct;
};

struct sum {
  int num_variants;
  const struct variant *variants;
  variant_fn variant;
};

struct type {
  const char *name;
  restore_fn restore;
  store_fn store;
  free_fn free;
  const void *aux;
  const enum kind kind;
  const void *info;
};

int free_scalar(const void *aux, struct futhark_context *ctx, void *p) {
  (void)aux;
  (void)ctx;
  (void)p;
  // Nothing to do.
  return 0;
}

#define DEF_SCALAR_TYPE(T)                                      \
  int restore_##T(const void *aux, FILE *f,                     \
                  struct futhark_context *ctx, void *p) {       \
    (void)aux;                                                  \
    (void)ctx;                                                  \
    return read_scalar(f, &T##_info, p);                        \
  }                                                             \
                                                                \
  void store_##T(const void *aux, FILE *f,                      \
                 struct futhark_context *ctx, void *p) {        \
    (void)aux;                                                  \
    (void)ctx;                                                  \
    write_scalar(f, 1, &T##_info, p);                           \
  }                                                             \
                                                                \
  struct type type_##T =                                        \
    { .name = #T,                                               \
      .restore = restore_##T,                                   \
      .store = store_##T,                                       \
      .free = free_scalar                                       \
    }                                                           \

DEF_SCALAR_TYPE(i8);
DEF_SCALAR_TYPE(i16);
DEF_SCALAR_TYPE(i32);
DEF_SCALAR_TYPE(i64);
DEF_SCALAR_TYPE(u8);
DEF_SCALAR_TYPE(u16);
DEF_SCALAR_TYPE(u32);
DEF_SCALAR_TYPE(u64);
DEF_SCALAR_TYPE(f16);
DEF_SCALAR_TYPE(f32);
DEF_SCALAR_TYPE(f64);
DEF_SCALAR_TYPE(bool);

struct value {
  const struct type *type;
  union {
    void *v_ptr;
    int8_t  v_i8;
    int16_t v_i16;
    int32_t v_i32;
    int64_t v_i64;

    uint8_t  v_u8;
    uint16_t v_u16;
    uint32_t v_u32;
    uint64_t v_u64;

    uint16_t v_f16;
    float v_f32;
    double v_f64;

    bool v_bool;
  } value;
};

void* value_ptr(struct value *v) {
  if (v->type == &type_i8) {
    return &v->value.v_i8;
  }
  if (v->type == &type_i16) {
    return &v->value.v_i16;
  }
  if (v->type == &type_i32) {
    return &v->value.v_i32;
  }
  if (v->type == &type_i64) {
    return &v->value.v_i64;
  }
  if (v->type == &type_u8) {
    return &v->value.v_u8;
  }
  if (v->type == &type_u16) {
    return &v->value.v_u16;
  }
  if (v->type == &type_u32) {
    return &v->value.v_u32;
  }
  if (v->type == &type_u64) {
    return &v->value.v_u64;
  }
  if (v->type == &type_f16) {
    return &v->value.v_f16;
  }
  if (v->type == &type_f32) {
    return &v->value.v_f32;
  }
  if (v->type == &type_f64) {
    return &v->value.v_f64;
  }
  if (v->type == &type_bool) {
    return &v->value.v_bool;
  }
  return &v->value.v_ptr;
}

struct variable {
  // NULL name indicates free slot.  Name is owned by this struct.
  char *name;
  struct value value;
};

typedef int (*entry_point_fn)(struct futhark_context*, void*, void**);

struct entry_point {
  const char *name;
  entry_point_fn f;
  const char** tuning_params;
  const char** attrs;
  const struct type *out_type;
  bool out_unique;
  const struct type **in_types;
  bool *in_unique;
};

int entry_num_ins(struct entry_point *e) {
  int count = 0;
  while (e->in_types[count]) {
    count++;
  }
  return count;
}

struct futhark_prog {
  // Last entry point identified by NULL name.
  struct entry_point *entry_points;
  // Last type identified by NULL name.
  const struct type **types;
};

struct server_state {
  struct futhark_prog prog;
  struct futhark_context_config *cfg;
  struct futhark_context *ctx;
  int variables_capacity;
  struct variable *variables;
};

struct variable* get_variable(struct server_state *s,
                              const char *name) {
  for (int i = 0; i < s->variables_capacity; i++) {
    if (s->variables[i].name != NULL &&
        strcmp(s->variables[i].name, name) == 0) {
      return &s->variables[i];
    }
  }

  return NULL;
}

struct variable* create_variable(struct server_state *s,
                                 const char *name,
                                 const struct type *type) {
  int found = -1;
  for (int i = 0; i < s->variables_capacity; i++) {
    if (found == -1 && s->variables[i].name == NULL) {
      found = i;
    } else if (s->variables[i].name != NULL &&
               strcmp(s->variables[i].name, name) == 0) {
      return NULL;
    }
  }

  if (found != -1) {
    // Found a free spot.
    s->variables[found].name = strdup(name);
    s->variables[found].value.type = type;
    return &s->variables[found];
  }

  // Need to grow the buffer.
  found = s->variables_capacity;
  s->variables_capacity *= 2;
  s->variables = realloc(s->variables,
                         s->variables_capacity * sizeof(struct variable));

  s->variables[found].name = strdup(name);
  s->variables[found].value.type = type;

  for (int i = found+1; i < s->variables_capacity; i++) {
    s->variables[i].name = NULL;
  }

  return &s->variables[found];
}

void drop_variable(struct variable *v) {
  free(v->name);
  v->name = NULL;
}

int arg_exists(const char *args[], int i) {
  return args[i] != NULL;
}

const char* get_arg(const char *args[], int i) {
  if (!arg_exists(args, i)) {
    futhark_panic(1, "Insufficient command args.\n");
  }
  return args[i];
}

const struct type* get_type(struct server_state *s, const char *name) {
  for (int i = 0; s->prog.types[i]; i++) {
    if (strcmp(s->prog.types[i]->name, name) == 0) {
      return s->prog.types[i];
    }
  }

  futhark_panic(1, "Unknown type %s\n", name);
  return NULL;
}

struct entry_point* get_entry_point(struct server_state *s, const char *name) {
  for (int i = 0; s->prog.entry_points[i].name; i++) {
    if (strcmp(s->prog.entry_points[i].name, name) == 0) {
      return &s->prog.entry_points[i];
    }
  }

  return NULL;
}

// Print the command-done marker, indicating that we are ready for
// more input.
void ok(void) {
  printf("%%%%%% OK\n");
  fflush(stdout);
}

// Print the failure marker.  Output is now an error message until the
// next ok().
void failure(void) {
  printf("%%%%%% FAILURE\n");
}

void error_check(struct server_state *s, int err) {
  if (err != 0) {
    failure();
    char *error = futhark_context_get_error(s->ctx);
    if (error != NULL) {
      puts(error);
    }
    free(error);
  }
}

void cmd_call(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);

  struct entry_point *e = get_entry_point(s, name);

  if (e == NULL) {
    failure();
    printf("Unknown entry point: %s\n", name);
    return;
  }

  int num_ins = entry_num_ins(e);
  // +1 to avoid zero-size arrays, which is UB.
  void* out;
  void* ins[num_ins+1];

  for (int i = 0; i < num_ins; i++) {
    const char *in_name = get_arg(args, 2+i);
    struct variable *v = get_variable(s, in_name);
    if (v == NULL) {
      failure();
      printf("Unknown variable: %s\n", in_name);
      return;
    }
    if (v->value.type != e->in_types[i]) {
      failure();
      printf("Wrong input type.  Expected %s, got %s.\n",
             e->in_types[i]->name, v->value.type->name);
      return;
    }
    ins[i] = value_ptr(&v->value);
  }

  const char *out_name = get_arg(args, 1);
  struct variable *v = create_variable(s, out_name, e->out_type);
  if (v == NULL) {
    failure();
    printf("Variable already exists: %s\n", out_name);
    return;
  }
  out = value_ptr(&v->value);

  int64_t t_start = get_wall_time();
  int err = e->f(s->ctx, out, ins);
  err |= futhark_context_sync(s->ctx);
  int64_t t_end = get_wall_time();
  long long int elapsed_usec = t_end - t_start;
  printf("runtime: %lld\n", elapsed_usec);

  error_check(s, err);
  if (err != 0) {
    // Need to uncreate the output variable, which would otherwise be left
    // in an uninitialised state.
    const char *out_name = get_arg(args, 1);
    struct variable *v = get_variable(s, out_name);
    if (v) {
      drop_variable(v);
    }
  }
}

void cmd_restore(struct server_state *s, const char *args[]) {
  const char *fname = get_arg(args, 0);

  FILE *f = fopen(fname, "rb");
  if (f == NULL) {
    failure();
    printf("Failed to open %s: %s\n", fname, strerror(errno));
    return;
  }

  int bad = 0;
  int values = 0;
  for (int i = 1; arg_exists(args, i); i+=2, values++) {
    const char *vname = get_arg(args, i);
    const char *type = get_arg(args, i+1);

    const struct type *t = get_type(s, type);
    struct variable *v = create_variable(s, vname, t);

    if (v == NULL) {
      bad = 1;
      failure();
      printf("Variable already exists: %s\n", vname);
      break;
    }

    errno = 0;
    if (t->restore(t->aux, f, s->ctx, value_ptr(&v->value)) != 0) {
      bad = 1;
      failure();
      printf("Failed to restore variable %s.\n"
             "Possibly malformed data in %s (errno: %s)\n",
             vname, fname, strerror(errno));
      drop_variable(v);
      break;
    }
  }

  if (!bad && end_of_input(f) != 0) {
    failure();
    printf("Expected EOF after reading %d values from %s\n",
           values, fname);
  }

  fclose(f);

  if (!bad) {
    int err = futhark_context_sync(s->ctx);
    error_check(s, err);
  }
}

void cmd_store(struct server_state *s, const char *args[]) {
  const char *fname = get_arg(args, 0);

  FILE *f = fopen(fname, "wb");
  if (f == NULL) {
    failure();
    printf("Failed to open %s: %s\n", fname, strerror(errno));
  } else {
    for (int i = 1; arg_exists(args, i); i++) {
      const char *vname = get_arg(args, i);
      struct variable *v = get_variable(s, vname);

      if (v == NULL) {
        failure();
        printf("Unknown variable: %s\n", vname);
        return;
      }

      const struct type *t = v->value.type;
      t->store(t->aux, f, s->ctx, value_ptr(&v->value));
    }
    fclose(f);
  }
}

void cmd_free(struct server_state *s, const char *args[]) {
  for (int i = 0; arg_exists(args, i); i++) {
    const char *name = get_arg(args, i);
    struct variable *v = get_variable(s, name);

    if (v == NULL) {
      failure();
      printf("Unknown variable: %s\n", name);
      return;
    }

    const struct type *t = v->value.type;

    int err = t->free(t->aux, s->ctx, value_ptr(&v->value));
    error_check(s, err);
    drop_variable(v);
  }
}

void cmd_rename(struct server_state *s, const char *args[]) {
  const char *oldname = get_arg(args, 0);
  const char *newname = get_arg(args, 1);
  struct variable *old = get_variable(s, oldname);
  struct variable *new = get_variable(s, newname);

  if (old == NULL) {
    failure();
    printf("Unknown variable: %s\n", oldname);
    return;
  }

  if (new != NULL) {
    failure();
    printf("Variable already exists: %s\n", newname);
    return;
  }

  free(old->name);
  old->name = strdup(newname);
}

void cmd_inputs(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct entry_point *e = get_entry_point(s, name);

  if (e == NULL) {
    failure();
    printf("Unknown entry point: %s\n", name);
    return;
  }

  int num_ins = entry_num_ins(e);
  for (int i = 0; i < num_ins; i++) {
    if (e->in_unique[i]) {
      putchar('*');
    }
    puts(e->in_types[i]->name);
  }
}

void cmd_output(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct entry_point *e = get_entry_point(s, name);

  if (e == NULL) {
    failure();
    printf("Unknown entry point: %s\n", name);
    return;
  }

  if (e->out_unique) {
    putchar('*');
  }
  puts(e->out_type->name);
}

void cmd_clear(struct server_state *s, const char *args[]) {
  (void)args;
  int err = 0;
  for (int i = 0; i < s->variables_capacity; i++) {
    struct variable *v = &s->variables[i];
    if (v->name != NULL) {
      err |= v->value.type->free(v->value.type->aux, s->ctx, value_ptr(&v->value));
      drop_variable(v);
    }
  }
  err |= futhark_context_clear_caches(s->ctx);
  error_check(s, err);
}

void cmd_pause_profiling(struct server_state *s, const char *args[]) {
  (void)args;
  futhark_context_pause_profiling(s->ctx);
}

void cmd_unpause_profiling(struct server_state *s, const char *args[]) {
  (void)args;
  futhark_context_unpause_profiling(s->ctx);
}

void cmd_report(struct server_state *s, const char *args[]) {
  (void)args;
  char *report = futhark_context_report(s->ctx);
  if (report) {
    puts(report);
  } else {
    failure();
    report = futhark_context_get_error(s->ctx);
    if (report) {
      puts(report);
    } else {
      puts("Failed to produce profiling report.\n");
    }
  }
  free(report);
}

void cmd_set_tuning_param(struct server_state *s, const char *args[]) {
  const char *param = get_arg(args, 0);
  const char *val_s = get_arg(args, 1);
  size_t val = atol(val_s);
  int err = futhark_context_config_set_tuning_param(s->cfg, param, val);

  error_check(s, err);

  if (err != 0) {
    printf("Failed to set tuning parameter %s to %ld\n", param, (long)val);
  }
}

void cmd_tuning_params(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct entry_point *e = get_entry_point(s, name);

  if (e == NULL) {
    failure();
    printf("Unknown entry point: %s\n", name);
    return;
  }

  const char **params = e->tuning_params;
  for (int i = 0; params[i] != NULL; i++) {
    printf("%s\n", params[i]);
  }
}

void cmd_tuning_param_class(struct server_state *s, const char *args[]) {
  (void)s;
  const char *param = get_arg(args, 0);

  int n = futhark_get_tuning_param_count();

  for (int i = 0; i < n; i++) {
    if (strcmp(futhark_get_tuning_param_name(i), param) == 0) {
      printf("%s\n", futhark_get_tuning_param_class(i));
      return;
    }
  }

  failure();
  printf("Unknown tuning parameter: %s\n", param);
}

void cmd_attributes(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct entry_point *e = get_entry_point(s, name);

  if (e == NULL) {
    failure();
    printf("Unknown entry point: %s\n", name);
    return;
  }

  const char **params = e->attrs;
  for (int i = 0; params[i] != NULL; i++) {
    printf("%s\n", params[i]);
  }
}

void cmd_kind(struct server_state *s, const char *args[]) {
  const char *type = get_arg(args, 0);
  const struct type *t = get_type(s, type);

  switch (t->kind) {
    case PRIMITIVE: printf("primitive\n"); return;
    case ARRAY:     printf("array\n");     return;
    case RECORD:    printf("record\n");    return;
    case SUM:       printf("sum\n");       return;
    case OPAQUE:    printf("opaque\n");    return;
  }
  futhark_panic(1, "Invalid kind detected on type \"%s\".\n", t->name);
}

void cmd_type(struct server_state *s, const char *args[]) {
  const char *from_name = get_arg(args, 0);
  struct variable *v = get_variable(s, from_name);

  if (v == NULL) {
    failure();
    printf("Unknown variable: %s\n", from_name);
    return;
  }

  printf("%s\n", v->value.type->name);
}

void cmd_shape(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct variable* v = get_variable(s, name);

  if (v == NULL) {
    failure();
    printf("Unknown variable: %s\n", name);
    return;
  }

  if (v->value.type->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = v->value.type->info;

  const int64_t *shape = a->shape(s->ctx, v->value.value.v_ptr);
  for (int i = 0; i < a->rank; ++i) {
    printf("%lld\n", (long long)shape[i]);
  }
}

void cmd_elemtype(struct server_state *s, const char *args[]) {
  const char *type = get_arg(args, 0);
  const struct type *t = get_type(s, type);

  if (t->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = t->info;

  printf("%s\n", a->element_type->name);
}

void cmd_rank(struct server_state *s, const char *args[]) {
  const char *type = get_arg(args, 0);
  const struct type *t = get_type(s, type);

  if (t->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = t->info;
  printf("%d\n", a->rank);
}

void cmd_new_array(struct server_state *s, const char *args[]) {
  const char *to_name = get_arg(args, 0);
  const char *type_name = get_arg(args, 1);
  const struct type *type = get_type(s, type_name);
  struct variable *to = create_variable(s, to_name, type);

  if (to == NULL) {
    failure();
    printf("Variable already exists: %s\n", to_name);
    return;
  }

  if (type->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = type->info;

  int num_args = 0;
  for (int i = 2; arg_exists(args, i); i++) {
    num_args++;
  }

  if (num_args < a->rank) {
    failure();
    printf("Expected %d dimensions, but got %d.\n", a->rank, num_args);
    return;
  }

  int64_t* dims = alloca(a->rank * sizeof(int64_t));
  int64_t n_values = 1;

  for (int i = 0; i < a->rank; ++i) {
    const char *size_arg = get_arg(args, 2+i);
    char* end;
    errno = 0;
    int64_t size = strtoll(size_arg, &end, 10);

    if (errno == ERANGE || *end != '\0' || size < 0) {
      failure();
      printf("Invalid size `%s` of dimension %d.\n", size_arg, i+1);
      return;
    }

    dims[i] = size;
    n_values *= size;
  }

  if (num_args - a->rank != n_values) {
    failure();
    printf("Expected %d values, but got %d.\n", (int)n_values, num_args - a->rank);
    return;
  }

  const void** value_ptrs = alloca(n_values * sizeof(void*));

  for (int64_t i = 0; i < n_values; i++) {
    struct variable* v = get_variable(s, args[2+a->rank+i]);

    if (v == NULL) {
      failure();
      printf("Unknown variable: %s\n", args[2+a->rank+i]);
      return;
    }

    if (strcmp(v->value.type->name, a->element_type->name) != 0) {
      failure();
      printf("Value %d mismatch: expected type %s, got %s\n",
             (int)i, a->element_type->name, v->value.type->name);
      return;
    }

    value_ptrs[i] = value_ptr(&v->value);
  }

  a->new(s->ctx, value_ptr(&to->value), value_ptrs, dims);
}

void cmd_set(struct server_state *s, const char *args[]) {
  const char *arr_name = get_arg(args, 0);
  const char *val_name = get_arg(args, 1);
  struct variable* arr = get_variable(s, arr_name);
  struct variable* val = get_variable(s, val_name);

  if (arr == NULL) {
    failure();
    printf("Unknown variable: %s\n", arr_name);
    return;
  }
  if (val == NULL) {
    failure();
    printf("Unknown variable: %s\n", val_name);
    return;
  }

  if (arr->value.type->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = arr->value.type->info;

  if (strcmp(val->value.type->name, a->element_type->name) != 0) {
    failure();
    printf("Type mismatch: expected element of type %s, got %s\n",
            a->element_type->name, val->value.type->name);
    return;
  }

  for (int i = 0; ; ++i) {
    if (!arg_exists(args, 2+i)) {
      if (i != a->rank) {
        failure();
        printf("%d indices expected but %d values provided.\n", a->rank, i);
        return;
      }
      break;
    }
  }

  const int64_t *shape = a->shape(s->ctx, arr->value.value.v_ptr);
  int64_t* indices = alloca(a->rank * sizeof(int64_t));

  for (int i = 0; i < a->rank; ++i) {
    const char *idx_arg = get_arg(args, 2+i);
    char* end;
    errno = 0;
    int64_t idx = strtoll(idx_arg, &end, 10);

    if (errno == ERANGE || *end != '\0' || idx < 0 || idx >= shape[i]) {
      failure();
      printf("Invalid index `%s` on dimension %d.\n", idx_arg, i+1);
      return;
    }

    indices[i] = idx;
  }

  a->set(s->ctx, arr->value.value.v_ptr, value_ptr(&val->value), indices);
}

void cmd_index(struct server_state *s, const char *args[]) {
  const char *to_name = get_arg(args, 0);
  const char *from_name = get_arg(args, 1);
  struct variable* from = get_variable(s, from_name);

  if (from == NULL) {
    failure();
    printf("Unknown variable: %s\n", from_name);
    return;
  }

  if (from->value.type->kind != ARRAY) {
    failure();
    printf("Not an array type\n");
    return;
  }

  const struct array *a = from->value.type->info;

  for (int i = 0; ; ++i) {
    if (!arg_exists(args, 2+i)) {
      if (i != a->rank) {
        failure();
        printf("%d indices expected but %d values provided.\n", a->rank, i);
        return;
      }
      break;
    }
  }

  const int64_t *shape = a->shape(s->ctx, from->value.value.v_ptr);
  int64_t* indices = alloca(a->rank * sizeof(int64_t));

  for (int i = 0; i < a->rank; ++i) {
    const char *idx_arg = get_arg(args, 2+i);
    char* end;
    errno = 0;
    int64_t idx = strtoll(idx_arg, &end, 10);

    if (errno == ERANGE || *end != '\0' || idx < 0 || idx >= shape[i]) {
      failure();
      printf("Invalid index `%s` on dimension %d.\n", idx_arg, i+1);
      return;
    }

    indices[i] = idx;
  }

  struct variable* to = create_variable(s, to_name, a->element_type);

  if (to == NULL) {
    failure();
    printf("Variable already exists: %s\n", to_name);
    return;
  }

  a->index(s->ctx, value_ptr(&to->value), from->value.value.v_ptr, indices);
}

void cmd_fields(struct server_state *s, const char *args[]) {
  const char *type = get_arg(args, 0);
  const struct type *t = get_type(s, type);

  if (t->kind != RECORD) {
    failure();
    printf("Not a record type\n");
    return;
  }

  const struct record *r = t->info;

  for (int i = 0; i < r->num_fields; i++) {
    const struct field f = r->fields[i];
    printf("%s %s\n", f.name, f.type->name);
  }
}

void cmd_variants(struct server_state *s, const char *args[]) {
  const char *type = get_arg(args, 0);
  const struct type *t = get_type(s, type);

  if (t->kind != SUM) {
    failure();
    printf("Not a sum type\n");
    return;
  }

  const struct sum *st = t->info;

  for (int i = 0; i < st->num_variants; i++) {
    const struct variant *v = &st->variants[i];
    printf("%s\n", v->name);
    for (int i = 0; i < v->num_types; i++) {
      const struct type *f = v->types[i];
      printf("- %s\n", f->name);
    }
  }
}

void cmd_variant(struct server_state *s, const char *args[]) {
  const char *name = get_arg(args, 0);
  struct variable* v = get_variable(s, name);

  if (v == NULL) {
    failure();
    printf("Unknown variable: %s\n", name);
    return;
  }

  const struct type *t = get_type(s, v->value.type->name);

  if (t->kind != SUM) {
    failure();
    printf("Not a sum type\n");
    return;
  }

  const struct sum *st = t->info;

  int i = st->variant(s->ctx, v->value.value.v_ptr);
  const struct variant *var = &st->variants[i];
  printf("%s\n", var->name);
}

void cmd_project(struct server_state *s, const char *args[]) {
  const char *to_name = get_arg(args, 0);
  const char *from_name = get_arg(args, 1);
  const char *field_name = get_arg(args, 2);

  struct variable *from = get_variable(s, from_name);

  if (from == NULL) {
    failure();
    printf("Unknown variable: %s\n", from_name);
    return;
  }

  const struct type *from_type = from->value.type;

  if (from_type->kind != RECORD) {
    failure();
    printf("Not a record type\n");
    return;
  }

  const struct record *r = from_type->info;

  const struct field *field = NULL;
  for (int i = 0; i < r->num_fields; i++) {
    if (strcmp(r->fields[i].name, field_name) == 0) {
      field = &r->fields[i];
      break;
    }
  }

  if (field == NULL) {
    failure();
    printf("No such field\n");
  }

  struct variable *to = create_variable(s, to_name, field->type);

  if (to == NULL) {
    failure();
    printf("Variable already exists: %s\n", to_name);
    return;
  }

  field->project(s->ctx, value_ptr(&to->value), from->value.value.v_ptr);
}

void cmd_new(struct server_state *s, const char *args[]) {
  const char *to_name = get_arg(args, 0);
  const char *type_name = get_arg(args, 1);
  const struct type *type = get_type(s, type_name);
  struct variable *to = create_variable(s, to_name, type);

  if (to == NULL) {
    failure();
    printf("Variable already exists: %s\n", to_name);
    return;
  }

  if (type->kind != RECORD) {
    failure();
    printf("Not a record type\n");
    return;
  }

  const struct record *r = type->info;

  int num_args = 0;
  for (int i = 2; arg_exists(args, i); i++) {
    num_args++;
  }

  if (num_args != r->num_fields) {
    failure();
    printf("%d fields expected but %d values provided.\n", num_args, r->num_fields);
    return;
  }

  const void** value_ptrs = alloca(num_args * sizeof(void*));

  for (int i = 0; i < num_args; i++) {
    struct variable* v = get_variable(s, args[2+i]);

    if (v == NULL) {
      failure();
      printf("Unknown variable: %s\n", args[2+i]);
      return;
    }

    if (strcmp(v->value.type->name, r->fields[i].type->name) != 0) {
      failure();
      printf("Field %s mismatch: expected type %s, got %s\n",
             r->fields[i].name, r->fields[i].type->name, v->value.type->name);
      return;
    }

    value_ptrs[i] = value_ptr(&v->value);
  }

  r->new(s->ctx, value_ptr(&to->value), value_ptrs);
}

void cmd_construct(struct server_state *s, const char *args[]) {
  const char *to_name = get_arg(args, 0);
  const char *type_name = get_arg(args, 1);
  const char *variant_name = get_arg(args, 2);
  const struct type *type = get_type(s, type_name);
  struct variable *to = create_variable(s, to_name, type);

  if (to == NULL) {
    failure();
    printf("Variable already exists: %s\n", to_name);
    return;
  }

  if (type->kind != SUM) {
    failure();
    printf("Not a sum type\n");
    return;
  }

  const struct sum *st = type->info;

  for (int i = 0; i < st->num_variants; i++) {
    const struct variant *var = &st->variants[i];
    if (strcmp(var->name, variant_name) == 0) {
      int num_args = 0;
      for (int i = 3; arg_exists(args, i); i++) {
        num_args++;
      }

      if (num_args != var->num_types) {
        failure();
        printf("%d values expected but %d values provided.\n", var->num_types, num_args);
        return;
      }

      const void** value_ptrs = alloca(num_args * sizeof(void*));

      for (int i = 0; i < num_args; i++) {
        const char *vname = get_arg(args, 3+i);
        struct variable* v = get_variable(s, vname);

        if (v == NULL) {
          failure();
          printf("Unknown variable: %s\n", vname);
          return;
        }

        if (strcmp(v->value.type->name, var->types[i]->name) != 0) {
          failure();
          printf("Value %d mismatch: expected type %s, got %s\n",
                i, var->types[i]->name, v->value.type->name);
          return;
        }

        value_ptrs[i] = value_ptr(&v->value);
      }

      var->new(s->ctx, value_ptr(&to->value), value_ptrs);
      return;
    }
  }

  failure();
  printf("No such variant\n");
}

void cmd_destruct(struct server_state *s, const char *args[]) {
  const char *from_name = get_arg(args, 0);
  struct variable *v = get_variable(s, from_name);

  if (v == NULL) {
    failure();
    printf("Unknown variable: %s\n", from_name);
    return;
  }

  if (v->value.type->kind != SUM) {
    failure();
    printf("Not a sum type\n");
    return;
  }

  const struct sum *sum = v->value.type->info;
  const struct variant *var = &sum->variants[sum->variant(s->ctx, v->value.value.v_ptr)];

  int num_args = 0;
  for (int i = 1; arg_exists(args, i); i++) {
    num_args++;
  }

  if (num_args != var->num_types) {
    failure();
    printf("%d variables expected but %d variables provided.  %s\n", var->num_types, num_args, var->name);
    return;
  }

  const void **value_ptrs = alloca(num_args * sizeof(struct variable*));

  for (int i = 0; i < num_args; i++) {
    const char *vname = get_arg(args, i+1);
    struct variable *vn = create_variable(s, vname, var->types[i]);
    if (vn == NULL) {
      failure();
      printf("Variable already exists: %s\n", vname);
      return;
    }
    value_ptrs[i] = value_ptr(&vn->value);
  }

  var->destruct(s->ctx, value_ptrs, v->value.value.v_ptr);
  return;
}

void cmd_entry_points(struct server_state *s, const char *args[]) {
  (void)args;
  for (int i = 0; s->prog.entry_points[i].name; i++) {
    puts(s->prog.entry_points[i].name);
  }
}

void cmd_types(struct server_state *s, const char *args[]) {
  (void)args;
  for (int i = 0; s->prog.types[i] != NULL; i++) {
    puts(s->prog.types[i]->name);
  }
}

char *next_word(char **line) {
  char *p = *line;

  while (isspace(*p)) {
    p++;
  }

  if (*p == 0) {
    return NULL;
  }

  if (*p == '"') {
    char *save = p+1;
    // Skip ahead till closing quote.
    p++;

    while (*p && *p != '"') {
      p++;
    }

    if (*p == '"') {
      *p = 0;
      *line = p+1;
      return save;
    } else {
      return NULL;
    }
  } else {
    char *save = p;
    // Skip ahead till next whitespace.

    while (*p && !isspace(*p)) {
      p++;
    }

    if (*p) {
      *p = 0;
      *line = p+1;
    } else {
      *line = p;
    }
    return save;
  }
}

void process_line(struct server_state *s, char *line) {
  int max_num_tokens = 1000;
  const char* tokens[max_num_tokens];
  int num_tokens = 0;

  while ((tokens[num_tokens] = next_word(&line)) != NULL) {
    num_tokens++;
    if (num_tokens == max_num_tokens) {
      futhark_panic(1, "Line too long.\n");
    }
  }

  const char *command = tokens[0];

  if (command == NULL) {
    failure();
    printf("Empty line\n");
  } else if (strcmp(command, "call") == 0) {
    cmd_call(s, tokens+1);
  } else if (strcmp(command, "restore") == 0) {
    cmd_restore(s, tokens+1);
  } else if (strcmp(command, "store") == 0) {
    cmd_store(s, tokens+1);
  } else if (strcmp(command, "free") == 0) {
    cmd_free(s, tokens+1);
  } else if (strcmp(command, "rename") == 0) {
    cmd_rename(s, tokens+1);
  } else if (strcmp(command, "inputs") == 0) {
    cmd_inputs(s, tokens+1);
  } else if (strcmp(command, "output") == 0) {
    cmd_output(s, tokens+1);
  } else if (strcmp(command, "clear") == 0) {
    cmd_clear(s, tokens+1);
  } else if (strcmp(command, "pause_profiling") == 0) {
    cmd_pause_profiling(s, tokens+1);
  } else if (strcmp(command, "unpause_profiling") == 0) {
    cmd_unpause_profiling(s, tokens+1);
  } else if (strcmp(command, "report") == 0) {
    cmd_report(s, tokens+1);
  } else if (strcmp(command, "set_tuning_param") == 0) {
    cmd_set_tuning_param(s, tokens+1);
  } else if (strcmp(command, "tuning_params") == 0) {
    cmd_tuning_params(s, tokens+1);
  } else if (strcmp(command, "tuning_param_class") == 0) {
    cmd_tuning_param_class(s, tokens+1);
  } else if (strcmp(command, "kind") == 0) {
    cmd_kind(s, tokens+1);
  } else if (strcmp(command, "type") == 0) {
    cmd_type(s, tokens+1);
  } else if (strcmp(command, "shape") == 0) {
    cmd_shape(s, tokens+1);
  } else if (strcmp(command, "elemtype") == 0) {
    cmd_elemtype(s, tokens+1);
  } else if (strcmp(command, "rank") == 0) {
    cmd_rank(s, tokens+1);
  } else if (strcmp(command, "new_array") == 0) {
    cmd_new_array(s, tokens+1);
  } else if (strcmp(command, "set") == 0) {
    cmd_set(s, tokens+1);
  } else if (strcmp(command, "index") == 0) {
    cmd_index(s, tokens+1);
  } else if (strcmp(command, "fields") == 0) {
    cmd_fields(s, tokens+1);
  } else if (strcmp(command, "variants") == 0) {
    cmd_variants(s, tokens+1);
  } else if (strcmp(command, "variant") == 0) {
    cmd_variant(s, tokens+1);
  } else if (strcmp(command, "new") == 0) {
    cmd_new(s, tokens+1);
  } else if (strcmp(command, "construct") == 0) {
    cmd_construct(s, tokens+1);
  } else if (strcmp(command, "destruct") == 0) {
    cmd_destruct(s, tokens+1);
  } else if (strcmp(command, "project") == 0) {
    cmd_project(s, tokens+1);
  } else if (strcmp(command, "entry_points") == 0) {
    cmd_entry_points(s, tokens+1);
  } else if (strcmp(command, "attributes") == 0) {
    cmd_attributes(s, tokens+1);
  } else if (strcmp(command, "types") == 0) {
    cmd_types(s, tokens+1);
  } else {
    futhark_panic(1, "Unknown command: %s\n", command);
  }
}

void run_server(struct futhark_prog *prog,
                struct futhark_context_config *cfg,
                struct futhark_context *ctx) {
  char *line = NULL;
  size_t buflen = 0;
  ssize_t linelen;

  struct server_state s = {
    .cfg = cfg,
    .ctx = ctx,
    .variables_capacity = 100,
    .prog = *prog
  };

  s.variables = malloc(s.variables_capacity * sizeof(struct variable));

  for (int i = 0; i < s.variables_capacity; i++) {
    s.variables[i].name = NULL;
  }

  ok();
  while ((linelen = getline(&line, &buflen, stdin)) > 0) {
    process_line(&s, line);
    ok();
  }

  free(s.variables);
  free(line);
}

// The aux struct lets us write generic method implementations without
// code duplication.

typedef void* (*aux_array_new_fn)(struct futhark_context*, const void**, const int64_t*);
typedef const int64_t* (*aux_array_shape_fn)(struct futhark_context*, void*);
typedef int (*aux_array_index_fn)(struct futhark_context*, void*, const void*, const int64_t*);
typedef int (*aux_array_values_fn)(struct futhark_context*, void*, void*);
typedef int (*aux_array_free_fn)(struct futhark_context*, void*);

struct array_aux {
  int rank;
  const struct primtype_info_t* info;
  const char *name;
  aux_array_new_fn new;
  aux_array_shape_fn shape;
  aux_array_values_fn values;
  aux_array_free_fn free;
};

int restore_array(const struct array_aux *aux, FILE *f,
                  struct futhark_context *ctx, void *p) {
  void *data = NULL;
  int64_t shape[aux->rank];
  if (read_array(f, aux->info, &data, shape, aux->rank) != 0) {
    return 1;
  }

  void *arr = aux->new(ctx, data, shape);
  if (arr == NULL) {
    return 1;
  }
  int err = futhark_context_sync(ctx);
  *(void**)p = arr;
  free(data);
  return err;
}

void store_array(const struct array_aux *aux, FILE *f,
                 struct futhark_context *ctx, void *p) {
  void *arr = *(void**)p;
  const int64_t *shape = aux->shape(ctx, arr);
  int64_t size = sizeof(aux->info->size);
  for (int i = 0; i < aux->rank; i++) {
    size *= shape[i];
  }
  int32_t *data = malloc(size);
  assert(aux->values(ctx, arr, data) == 0);
  assert(futhark_context_sync(ctx) == 0);
  assert(write_array(f, 1, aux->info, data, shape, aux->rank) == 0);
  free(data);
}

int free_array(const struct array_aux *aux,
               struct futhark_context *ctx, void *p) {
  void *arr = *(void**)p;
  return aux->free(ctx, arr);
}

typedef void* (*opaque_restore_fn)(struct futhark_context*, void*);
typedef int (*opaque_store_fn)(struct futhark_context*, const void*, void **, size_t *);
typedef int (*opaque_free_fn)(struct futhark_context*, void*);

struct opaque_aux {
  opaque_restore_fn restore;
  opaque_store_fn store;
  opaque_free_fn free;
};

int restore_opaque(const struct opaque_aux *aux, FILE *f,
                   struct futhark_context *ctx, void *p) {
  // We have a problem: we need to load data from 'f', since the
  // restore function takes a pointer, but we don't know how much we
  // need (and cannot possibly).  So we do something hacky: we read
  // *all* of the file, pass all of the data to the restore function
  // (which doesn't care if there's extra at the end), then we compute
  // how much space the the object actually takes in serialised form
  // and rewind the file to that position.  The only downside is more IO.
  size_t start = ftell(f);
  size_t size;
  char *bytes = fslurp_file(f, &size);
  void *obj = aux->restore(ctx, bytes);
  free(bytes);
  if (obj != NULL) {
    *(void**)p = obj;
    size_t obj_size;
    (void)aux->store(ctx, obj, NULL, &obj_size);
    fseek(f, start+obj_size, SEEK_SET);
    return 0;
  } else {
    fseek(f, start, SEEK_SET);
    return 1;
  }
}

void store_opaque(const struct opaque_aux *aux, FILE *f,
                  struct futhark_context *ctx, void *p) {
  void *obj = *(void**)p;
  size_t obj_size;
  void *data = NULL;
  (void)aux->store(ctx, obj, &data, &obj_size);
  assert(futhark_context_sync(ctx) == 0);
  fwrite(data, sizeof(char), obj_size, f);
  free(data);
}

int free_opaque(const struct opaque_aux *aux,
                struct futhark_context *ctx, void *p) {
  void *obj = *(void**)p;
  return aux->free(ctx, obj);
}

// End of server.h.

// Start of tuning.h.


int is_blank_line_or_comment(const char *s) {
  size_t i = strspn(s, " \t\n");
  return s[i] == '\0' || // Line is blank.
         strncmp(s + i, "--", 2) == 0; // Line is comment.
}

static char* load_tuning_file(const char *fname,
                              void *cfg,
                              int (*set_tuning_param)(void*, const char*, size_t)) {
  const int max_line_len = 1024;
  char* line = (char*) malloc(max_line_len);

  FILE *f = fopen(fname, "r");

  if (f == NULL) {
    snprintf(line, max_line_len, "Cannot open file: %s", strerror(errno));
    return line;
  }

  int lineno = 0;
  while (fgets(line, max_line_len, f) != NULL) {
    lineno++;
    if (is_blank_line_or_comment(line)) {
      continue;
    }
    char *eql = strstr(line, "=");
    if (eql) {
      *eql = 0;
      char *endptr;
      int value = strtol(eql+1, &endptr, 10);
      if (*endptr && *endptr != '\n') {
        snprintf(line, max_line_len, "Invalid line %d (must be of form 'name=int').",
                 lineno);
        return line;
      }
      if (set_tuning_param(cfg, line, (size_t)value) != 0) {
        char* err = (char*) malloc(max_line_len + 50);
        snprintf(err, max_line_len + 50, "Unknown name '%s' on line %d.", line, lineno);
        free(line);
        return err;
      }
    } else {
      snprintf(line, max_line_len, "Invalid line %d (must be of form 'name=int').",
               lineno);
      return line;
    }
  }

  free(line);

  return NULL;
}

// End of tuning.h.

const struct type type_ZMZNZMZNZMZNi64;
const struct type type_ZMZNZMZNu32;
const struct type type_ZMZNZMZNu8;
const struct type type_ZMZNi64;
const struct type type_ZMZNu32;
void *futhark_new_i64_3d_aux_wrap(struct futhark_context *ctx, const void *p, const int64_t *shape)
{
    return futhark_new_i64_3d(ctx, p, shape[0], shape[1], shape[2]);
}
int futhark_new_i64_3d_wrap(struct futhark_context *ctx, struct futhark_i64_3d * *outp, int64_t *ps[], const int64_t *shape)
{
    int64_t n_values = 1;
    
    for (int i = 0; i < 3; ++i)
        n_values *= shape[i];
    
    int64_t *values = alloca(n_values * sizeof(int64_t));
    
    for (int64_t i = 0; i < n_values; ++i)
        values[i] = *ps[i];
    *outp = futhark_new_i64_3d(ctx, values, shape[0], shape[1], shape[2]);
    return 0;
}
int futhark_new_i64_3d_set(struct futhark_context *ctx, struct futhark_i64_3d * arr, int64_t *val, const int64_t *is)
{
    const int64_t *shape = futhark_shape_i64_3d(ctx, arr);
    uint64_t idx = is[0];
    
    for (int i = 1; i < 3; ++i) {
        idx *= shape[i - 1];
        idx += is[i];
    }
    ((int64_t *) futhark_values_raw_i64_3d(ctx, arr))[idx] = *val;
    return 0;
}
int futhark_index_i64_3d_wrap(struct futhark_context *ctx, void *dest, struct futhark_i64_3d * arr, const int64_t *is)
{
    return futhark_index_i64_3d(ctx, dest, arr, is[0], is[1], is[2]);
}
const struct array type_ZMZNZMZNZMZNi64_array = {.rank =3, .element_type =&type_i64, .new =(array_new_fn) futhark_new_i64_3d_wrap, .set =(array_set_fn) futhark_new_i64_3d_set, .shape =(array_shape_fn) futhark_shape_i64_3d, .index =(array_index_fn) futhark_index_i64_3d_wrap};
const struct array_aux type_ZMZNZMZNZMZNi64_aux = {.name ="[][][]i64", .rank =3, .info =&i64_info, .new =(aux_array_new_fn) futhark_new_i64_3d_aux_wrap, .free =(aux_array_free_fn) futhark_free_i64_3d, .shape =(aux_array_shape_fn) futhark_shape_i64_3d, .values =(aux_array_values_fn) futhark_values_i64_3d};
const struct type type_ZMZNZMZNZMZNi64 = {.name ="[][][]i64", .restore =(restore_fn) restore_array, .store =(store_fn) store_array, .free =(free_fn) free_array, .aux =&type_ZMZNZMZNZMZNi64_aux, .kind =ARRAY, .info =&type_ZMZNZMZNZMZNi64_array};
void *futhark_new_u32_2d_aux_wrap(struct futhark_context *ctx, const void *p, const int64_t *shape)
{
    return futhark_new_u32_2d(ctx, p, shape[0], shape[1]);
}
int futhark_new_u32_2d_wrap(struct futhark_context *ctx, struct futhark_u32_2d * *outp, uint32_t *ps[], const int64_t *shape)
{
    int64_t n_values = 1;
    
    for (int i = 0; i < 2; ++i)
        n_values *= shape[i];
    
    uint32_t *values = alloca(n_values * sizeof(uint32_t));
    
    for (int64_t i = 0; i < n_values; ++i)
        values[i] = *ps[i];
    *outp = futhark_new_u32_2d(ctx, values, shape[0], shape[1]);
    return 0;
}
int futhark_new_u32_2d_set(struct futhark_context *ctx, struct futhark_u32_2d * arr, uint32_t *val, const int64_t *is)
{
    const int64_t *shape = futhark_shape_u32_2d(ctx, arr);
    uint64_t idx = is[0];
    
    for (int i = 1; i < 2; ++i) {
        idx *= shape[i - 1];
        idx += is[i];
    }
    ((uint32_t *) futhark_values_raw_u32_2d(ctx, arr))[idx] = *val;
    return 0;
}
int futhark_index_u32_2d_wrap(struct futhark_context *ctx, void *dest, struct futhark_u32_2d * arr, const int64_t *is)
{
    return futhark_index_u32_2d(ctx, dest, arr, is[0], is[1]);
}
const struct array type_ZMZNZMZNu32_array = {.rank =2, .element_type =&type_u32, .new =(array_new_fn) futhark_new_u32_2d_wrap, .set =(array_set_fn) futhark_new_u32_2d_set, .shape =(array_shape_fn) futhark_shape_u32_2d, .index =(array_index_fn) futhark_index_u32_2d_wrap};
const struct array_aux type_ZMZNZMZNu32_aux = {.name ="[][]u32", .rank =2, .info =&u32_info, .new =(aux_array_new_fn) futhark_new_u32_2d_aux_wrap, .free =(aux_array_free_fn) futhark_free_u32_2d, .shape =(aux_array_shape_fn) futhark_shape_u32_2d, .values =(aux_array_values_fn) futhark_values_u32_2d};
const struct type type_ZMZNZMZNu32 = {.name ="[][]u32", .restore =(restore_fn) restore_array, .store =(store_fn) store_array, .free =(free_fn) free_array, .aux =&type_ZMZNZMZNu32_aux, .kind =ARRAY, .info =&type_ZMZNZMZNu32_array};
void *futhark_new_u8_2d_aux_wrap(struct futhark_context *ctx, const void *p, const int64_t *shape)
{
    return futhark_new_u8_2d(ctx, p, shape[0], shape[1]);
}
int futhark_new_u8_2d_wrap(struct futhark_context *ctx, struct futhark_u8_2d * *outp, uint8_t *ps[], const int64_t *shape)
{
    int64_t n_values = 1;
    
    for (int i = 0; i < 2; ++i)
        n_values *= shape[i];
    
    uint8_t *values = alloca(n_values * sizeof(uint8_t));
    
    for (int64_t i = 0; i < n_values; ++i)
        values[i] = *ps[i];
    *outp = futhark_new_u8_2d(ctx, values, shape[0], shape[1]);
    return 0;
}
int futhark_new_u8_2d_set(struct futhark_context *ctx, struct futhark_u8_2d * arr, uint8_t *val, const int64_t *is)
{
    const int64_t *shape = futhark_shape_u8_2d(ctx, arr);
    uint64_t idx = is[0];
    
    for (int i = 1; i < 2; ++i) {
        idx *= shape[i - 1];
        idx += is[i];
    }
    ((uint8_t *) futhark_values_raw_u8_2d(ctx, arr))[idx] = *val;
    return 0;
}
int futhark_index_u8_2d_wrap(struct futhark_context *ctx, void *dest, struct futhark_u8_2d * arr, const int64_t *is)
{
    return futhark_index_u8_2d(ctx, dest, arr, is[0], is[1]);
}
const struct array type_ZMZNZMZNu8_array = {.rank =2, .element_type =&type_u8, .new =(array_new_fn) futhark_new_u8_2d_wrap, .set =(array_set_fn) futhark_new_u8_2d_set, .shape =(array_shape_fn) futhark_shape_u8_2d, .index =(array_index_fn) futhark_index_u8_2d_wrap};
const struct array_aux type_ZMZNZMZNu8_aux = {.name ="[][]u8", .rank =2, .info =&u8_info, .new =(aux_array_new_fn) futhark_new_u8_2d_aux_wrap, .free =(aux_array_free_fn) futhark_free_u8_2d, .shape =(aux_array_shape_fn) futhark_shape_u8_2d, .values =(aux_array_values_fn) futhark_values_u8_2d};
const struct type type_ZMZNZMZNu8 = {.name ="[][]u8", .restore =(restore_fn) restore_array, .store =(store_fn) store_array, .free =(free_fn) free_array, .aux =&type_ZMZNZMZNu8_aux, .kind =ARRAY, .info =&type_ZMZNZMZNu8_array};
void *futhark_new_i64_1d_aux_wrap(struct futhark_context *ctx, const void *p, const int64_t *shape)
{
    return futhark_new_i64_1d(ctx, p, shape[0]);
}
int futhark_new_i64_1d_wrap(struct futhark_context *ctx, struct futhark_i64_1d * *outp, int64_t *ps[], const int64_t *shape)
{
    int64_t n_values = 1;
    
    for (int i = 0; i < 1; ++i)
        n_values *= shape[i];
    
    int64_t *values = alloca(n_values * sizeof(int64_t));
    
    for (int64_t i = 0; i < n_values; ++i)
        values[i] = *ps[i];
    *outp = futhark_new_i64_1d(ctx, values, shape[0]);
    return 0;
}
int futhark_new_i64_1d_set(struct futhark_context *ctx, struct futhark_i64_1d * arr, int64_t *val, const int64_t *is)
{
    const int64_t *shape = futhark_shape_i64_1d(ctx, arr);
    uint64_t idx = is[0];
    
    for (int i = 1; i < 1; ++i) {
        idx *= shape[i - 1];
        idx += is[i];
    }
    ((int64_t *) futhark_values_raw_i64_1d(ctx, arr))[idx] = *val;
    return 0;
}
int futhark_index_i64_1d_wrap(struct futhark_context *ctx, void *dest, struct futhark_i64_1d * arr, const int64_t *is)
{
    return futhark_index_i64_1d(ctx, dest, arr, is[0]);
}
const struct array type_ZMZNi64_array = {.rank =1, .element_type =&type_i64, .new =(array_new_fn) futhark_new_i64_1d_wrap, .set =(array_set_fn) futhark_new_i64_1d_set, .shape =(array_shape_fn) futhark_shape_i64_1d, .index =(array_index_fn) futhark_index_i64_1d_wrap};
const struct array_aux type_ZMZNi64_aux = {.name ="[]i64", .rank =1, .info =&i64_info, .new =(aux_array_new_fn) futhark_new_i64_1d_aux_wrap, .free =(aux_array_free_fn) futhark_free_i64_1d, .shape =(aux_array_shape_fn) futhark_shape_i64_1d, .values =(aux_array_values_fn) futhark_values_i64_1d};
const struct type type_ZMZNi64 = {.name ="[]i64", .restore =(restore_fn) restore_array, .store =(store_fn) store_array, .free =(free_fn) free_array, .aux =&type_ZMZNi64_aux, .kind =ARRAY, .info =&type_ZMZNi64_array};
void *futhark_new_u32_1d_aux_wrap(struct futhark_context *ctx, const void *p, const int64_t *shape)
{
    return futhark_new_u32_1d(ctx, p, shape[0]);
}
int futhark_new_u32_1d_wrap(struct futhark_context *ctx, struct futhark_u32_1d * *outp, uint32_t *ps[], const int64_t *shape)
{
    int64_t n_values = 1;
    
    for (int i = 0; i < 1; ++i)
        n_values *= shape[i];
    
    uint32_t *values = alloca(n_values * sizeof(uint32_t));
    
    for (int64_t i = 0; i < n_values; ++i)
        values[i] = *ps[i];
    *outp = futhark_new_u32_1d(ctx, values, shape[0]);
    return 0;
}
int futhark_new_u32_1d_set(struct futhark_context *ctx, struct futhark_u32_1d * arr, uint32_t *val, const int64_t *is)
{
    const int64_t *shape = futhark_shape_u32_1d(ctx, arr);
    uint64_t idx = is[0];
    
    for (int i = 1; i < 1; ++i) {
        idx *= shape[i - 1];
        idx += is[i];
    }
    ((uint32_t *) futhark_values_raw_u32_1d(ctx, arr))[idx] = *val;
    return 0;
}
int futhark_index_u32_1d_wrap(struct futhark_context *ctx, void *dest, struct futhark_u32_1d * arr, const int64_t *is)
{
    return futhark_index_u32_1d(ctx, dest, arr, is[0]);
}
const struct array type_ZMZNu32_array = {.rank =1, .element_type =&type_u32, .new =(array_new_fn) futhark_new_u32_1d_wrap, .set =(array_set_fn) futhark_new_u32_1d_set, .shape =(array_shape_fn) futhark_shape_u32_1d, .index =(array_index_fn) futhark_index_u32_1d_wrap};
const struct array_aux type_ZMZNu32_aux = {.name ="[]u32", .rank =1, .info =&u32_info, .new =(aux_array_new_fn) futhark_new_u32_1d_aux_wrap, .free =(aux_array_free_fn) futhark_free_u32_1d, .shape =(aux_array_shape_fn) futhark_shape_u32_1d, .values =(aux_array_values_fn) futhark_values_u32_1d};
const struct type type_ZMZNu32 = {.name ="[]u32", .restore =(restore_fn) restore_array, .store =(store_fn) store_array, .free =(free_fn) free_array, .aux =&type_ZMZNu32_aux, .kind =ARRAY, .info =&type_ZMZNu32_array};
const struct type *bench_in_types[] = {&type_ZMZNu32, NULL};
bool bench_in_unique[] = {false};
const char *bench_tuning_params[] = {NULL};
const char *bench_attrs[] = {NULL};
int call_bench(struct futhark_context *ctx, void *out, void **ins)
{
    struct futhark_u32_1d * in0 = *(struct futhark_u32_1d * *) ins[0];
    
    return futhark_entry_bench(ctx, out, in0);
}
const struct type *is_sorted_in_types[] = {&type_ZMZNZMZNu32, NULL};
bool is_sorted_in_unique[] = {false};
const char *is_sorted_tuning_params[] = {NULL};
const char *is_sorted_attrs[] = {NULL};
int call_is_sorted(struct futhark_context *ctx, void *out, void **ins)
{
    struct futhark_u32_2d * in0 = *(struct futhark_u32_2d * *) ins[0];
    
    return futhark_entry_is_sorted(ctx, out, in0);
}
const struct type *is_stable_in_types[] = {&type_ZMZNZMZNu8, NULL};
bool is_stable_in_unique[] = {false};
const char *is_stable_tuning_params[] = {NULL};
const char *is_stable_attrs[] = {NULL};
int call_is_stable(struct futhark_context *ctx, void *out, void **ins)
{
    struct futhark_u8_2d * in0 = *(struct futhark_u8_2d * *) ins[0];
    
    return futhark_entry_is_stable(ctx, out, in0);
}
const struct type *main_in_types[] = {&type_ZMZNZMZNZMZNi64, NULL};
bool main_in_unique[] = {false};
const char *main_tuning_params[] = {NULL};
const char *main_attrs[] = {NULL};
int call_main(struct futhark_context *ctx, void *out, void **ins)
{
    struct futhark_i64_3d * in0 = *(struct futhark_i64_3d * *) ins[0];
    
    return futhark_entry_main(ctx, out, in0);
}
const struct type *test_sort_reversed_in_types[] = {NULL};
bool test_sort_reversed_in_unique[] = {};
const char *test_sort_reversed_tuning_params[] = {NULL};
const char *test_sort_reversed_attrs[] = {NULL};
int call_test_sort_reversed(struct futhark_context *ctx, void *out, void **ins)
{
    (void) ins;
    return futhark_entry_test_sort_reversed(ctx, out);
}
const struct type *types[] = {&type_i8, &type_i16, &type_i32, &type_i64, &type_u8, &type_u16, &type_u32, &type_u64, &type_f16, &type_f32, &type_f64, &type_bool, &type_ZMZNZMZNZMZNi64, &type_ZMZNZMZNu32, &type_ZMZNZMZNu8, &type_ZMZNi64, &type_ZMZNu32, NULL};
struct entry_point entry_points[] = {{.name ="bench", .f =call_bench, .tuning_params =bench_tuning_params, .in_types =bench_in_types, .out_type =&type_ZMZNu32, .in_unique =bench_in_unique, .out_unique =false, .attrs =bench_attrs}, {.name ="is_sorted", .f =call_is_sorted, .tuning_params =is_sorted_tuning_params, .in_types =is_sorted_in_types, .out_type =&type_bool, .in_unique =is_sorted_in_unique, .out_unique =false, .attrs =is_sorted_attrs}, {.name ="is_stable", .f =call_is_stable, .tuning_params =is_stable_tuning_params, .in_types =is_stable_in_types, .out_type =&type_bool, .in_unique =is_stable_in_unique, .out_unique =false, .attrs =is_stable_attrs}, {.name ="main", .f =call_main, .tuning_params =main_tuning_params, .in_types =main_in_types, .out_type =&type_ZMZNi64, .in_unique =main_in_unique, .out_unique =true, .attrs =main_attrs}, {.name ="test_sort_reversed", .f =call_test_sort_reversed, .tuning_params =test_sort_reversed_tuning_params, .in_types =test_sort_reversed_in_types, .out_type =&type_bool, .in_unique =test_sort_reversed_in_unique, .out_unique =false, .attrs =test_sort_reversed_attrs}, {.name =NULL}};
struct futhark_prog prog = {.types =types, .entry_points =entry_points};
int parse_options(struct futhark_context_config *cfg, int argc, char *const argv[])
{
    int ch;
    static struct option long_options[] = {{"debugging", no_argument, NULL, 1}, {"log", no_argument, NULL, 2}, {"profile", no_argument, NULL, 3}, {"help", no_argument, NULL, 4}, {"print-params", no_argument, NULL, 5}, {"param", required_argument, NULL, 6}, {"tuning", required_argument, NULL, 7}, {"cache-file", required_argument, NULL, 8}, {0, 0, 0, 0}};
    static char *option_descriptions = "  -D/--debugging     Perform possibly expensive internal correctness checks and verbose logging.\n  -L/--log           Print various low-overhead logging information while running.\n  -P/--profile       Enable the collection of profiling information.\n  -h/--help          Print help information and exit.\n  --print-params     Print all tuning parameters that can be set with --param or --tuning.\n  --param ASSIGNMENT Set a tuning parameter to the given value.\n  --tuning FILE      Read size=value assignments from the given file.\n  --cache-file FILE  Store program cache here.\n";
    
    while ((ch = getopt_long(argc, argv, ":DLPh", long_options, NULL)) != -1) {
        if (ch == 1 || ch == 'D')
            futhark_context_config_set_debugging(cfg, 1);
        if (ch == 2 || ch == 'L')
            futhark_context_config_set_logging(cfg, 1);
        if (ch == 3 || ch == 'P')
            futhark_context_config_set_profiling(cfg, 1);
        if (ch == 4 || ch == 'h') {
            printf("Usage: %s [OPTIONS]...\nOptions:\n\n%s\nFor more information, consult the Futhark User's Guide or the man pages.\n", fut_progname, option_descriptions);
            exit(0);
        }
        if (ch == 5) {
            int n = futhark_get_tuning_param_count();
            
            for (int i = 0; i < n; i++)
                printf("%s (%s)\n", futhark_get_tuning_param_name(i), futhark_get_tuning_param_class(i));
            exit(0);
        }
        if (ch == 6) {
            char *name = optarg;
            char *equals = strstr(optarg, "=");
            char *value_str = equals != NULL ? equals + 1 : optarg;
            int value = atoi(value_str);
            
            if (equals != NULL) {
                *equals = 0;
                if (futhark_context_config_set_tuning_param(cfg, name, value) != 0)
                    futhark_panic(1, "Unknown parameter: %s\n", name);
            } else
                futhark_panic(1, "Invalid argument for --parameter option: %s\n", optarg);
        }
        if (ch == 7) {
            char *ret = load_tuning_file(optarg, cfg, (int (*)(void *, const char *, size_t)) futhark_context_config_set_tuning_param);
            
            if (ret != NULL)
                futhark_panic(1, "When loading tuning file '%s': %s\n", optarg, ret);
        }
        if (ch == 8)
            futhark_context_config_set_cache_file(cfg, optarg);
        if (ch == ':')
            futhark_panic(-1, "Missing argument for option %s\n", argv[optind - 1]);
        if (ch == '?') {
            fprintf(stderr, "Usage: %s [OPTIONS]...\nOptions:\n\n%s\n", fut_progname, "  -D/--debugging     Perform possibly expensive internal correctness checks and verbose logging.\n  -L/--log           Print various low-overhead logging information while running.\n  -P/--profile       Enable the collection of profiling information.\n  -h/--help          Print help information and exit.\n  --print-params     Print all tuning parameters that can be set with --param or --tuning.\n  --param ASSIGNMENT Set a tuning parameter to the given value.\n  --tuning FILE      Read size=value assignments from the given file.\n  --cache-file FILE  Store program cache here.\n");
            futhark_panic(1, "Unknown option: %s\n", argv[optind - 1]);
        }
    }
    return optind;
}
int main(int argc, char **argv)
{
    fut_progname = argv[0];
    
    struct futhark_context_config *cfg = futhark_context_config_new();
    
    assert(cfg != NULL);
    
    int parsed_options = parse_options(cfg, argc, argv);
    
    argc -= parsed_options;
    argv += parsed_options;
    if (argc != 0)
        futhark_panic(1, "Excess non-option: %s\n", argv[0]);
    
    struct futhark_context *ctx = futhark_context_new(cfg);
    
    assert(ctx != NULL);
    futhark_context_set_logging_file(ctx, stdout);
    
    char *error = futhark_context_get_error(ctx);
    
    if (error != NULL)
        futhark_panic(1, "Error during context initialisation:\n%s", error);
    if (entry_point != NULL)
        run_server(&prog, cfg, ctx);
    futhark_context_free(ctx);
    futhark_context_config_free(cfg);
}

#ifdef _MSC_VER
#define inline __inline
#endif
#include <string.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <ctype.h>



#define FUTHARK_F64_ENABLED

// Start of scalar.h.

// Implementation of the primitive scalar operations.  Very
// repetitive.  This code is inserted directly into both CUDA and
// OpenCL programs, as well as the CPU code, so it has some #ifdefs to
// work everywhere.  Some operations are defined as macros because
// this allows us to use them as constant expressions in things like
// array sizes and static initialisers.

// Some of the #ifdefs are because OpenCL uses type-generic functions
// for some operations (e.g. sqrt), while C and CUDA sensibly use
// distinct functions for different precisions (e.g. sqrtf() and
// sqrt()).  This is quite annoying.  Due to C's unfortunate casting
// rules, it is also really easy to accidentally implement
// floating-point functions in the wrong precision, so be careful.

// Double-precision definitions are only included if the preprocessor
// macro FUTHARK_F64_ENABLED is set.

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

SCALAR_FUN_ATTR int32_t fptobits_f32_i32(float x);
SCALAR_FUN_ATTR float bitstofp_i32_f32(int32_t x);

SCALAR_FUN_ATTR uint8_t   add8(uint8_t x, uint8_t y)   { return x + y; }
SCALAR_FUN_ATTR uint16_t add16(uint16_t x, uint16_t y) { return x + y; }
SCALAR_FUN_ATTR uint32_t add32(uint32_t x, uint32_t y) { return x + y; }
SCALAR_FUN_ATTR uint64_t add64(uint64_t x, uint64_t y) { return x + y; }

SCALAR_FUN_ATTR uint8_t   sub8(uint8_t x, uint8_t y)   { return x - y; }
SCALAR_FUN_ATTR uint16_t sub16(uint16_t x, uint16_t y) { return x - y; }
SCALAR_FUN_ATTR uint32_t sub32(uint32_t x, uint32_t y) { return x - y; }
SCALAR_FUN_ATTR uint64_t sub64(uint64_t x, uint64_t y) { return x - y; }

SCALAR_FUN_ATTR uint8_t   mul8(uint8_t x, uint8_t y)   { return x * y; }
SCALAR_FUN_ATTR uint16_t mul16(uint16_t x, uint16_t y) { return x * y; }
SCALAR_FUN_ATTR uint32_t mul32(uint32_t x, uint32_t y) { return x * y; }
SCALAR_FUN_ATTR uint64_t mul64(uint64_t x, uint64_t y) { return x * y; }

#if defined(ISPC)

SCALAR_FUN_ATTR uint8_t udiv8(uint8_t x, uint8_t y) {
  // This strange pattern is used to prevent the ISPC compiler from
  // causing SIGFPEs and bogus results on divisions where inactive lanes
  // have 0-valued divisors. It ensures that any inactive lane instead
  // has a divisor of 1. https://github.com/ispc/ispc/issues/2292
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR uint16_t udiv16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR uint32_t udiv32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR uint64_t udiv64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR uint8_t udiv_up8(uint8_t x, uint8_t y) {
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint16_t udiv_up16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint32_t udiv_up32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint64_t udiv_up64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint8_t umod8(uint8_t x, uint8_t y) {
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR uint16_t umod16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR uint32_t umod32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR uint64_t umod64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR uint8_t udiv_safe8(uint8_t x, uint8_t y) {
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR uint16_t udiv_safe16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR uint32_t udiv_safe32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR uint64_t udiv_safe64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR uint8_t udiv_up_safe8(uint8_t x, uint8_t y) {
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint16_t udiv_up_safe16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint32_t udiv_up_safe32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint64_t udiv_up_safe64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : (x + y - 1) / ys;
}

SCALAR_FUN_ATTR uint8_t umod_safe8(uint8_t x, uint8_t y) {
  uint8_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR uint16_t umod_safe16(uint16_t x, uint16_t y) {
  uint16_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR uint32_t umod_safe32(uint32_t x, uint32_t y) {
  uint32_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR uint64_t umod_safe64(uint64_t x, uint64_t y) {
  uint64_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR int8_t sdiv8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  int8_t q = x / ys;
  int8_t r = x % ys;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int16_t sdiv16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  int16_t q = x / ys;
  int16_t r = x % ys;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int32_t sdiv32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  int32_t q = x / ys;
  int32_t r = x % ys;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int64_t sdiv64(int64_t x, int64_t y) {
  int64_t ys = 1;
  foreach_active(i) { ys = y; }
  int64_t q = x / ys;
  int64_t r = x % ys;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int8_t sdiv_up8(int8_t x, int8_t y) { return sdiv8(x + y - 1, y); }
SCALAR_FUN_ATTR int16_t sdiv_up16(int16_t x, int16_t y) { return sdiv16(x + y - 1, y); }
SCALAR_FUN_ATTR int32_t sdiv_up32(int32_t x, int32_t y) { return sdiv32(x + y - 1, y); }
SCALAR_FUN_ATTR int64_t sdiv_up64(int64_t x, int64_t y) { return sdiv64(x + y - 1, y); }

SCALAR_FUN_ATTR int8_t smod8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  int8_t r = x % ys;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int16_t smod16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  int16_t r = x % ys;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int32_t smod32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  int32_t r = x % ys;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int64_t smod64(int64_t x, int64_t y) {
  int64_t ys = 1;
  foreach_active(i) { ys = y; }
  int64_t r = x % ys;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int8_t   sdiv_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : sdiv8(x, y); }
SCALAR_FUN_ATTR int16_t sdiv_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : sdiv16(x, y); }
SCALAR_FUN_ATTR int32_t sdiv_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : sdiv32(x, y); }
SCALAR_FUN_ATTR int64_t sdiv_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : sdiv64(x, y); }

SCALAR_FUN_ATTR int8_t sdiv_up_safe8(int8_t x, int8_t y)     { return sdiv_safe8(x + y - 1, y); }
SCALAR_FUN_ATTR int16_t sdiv_up_safe16(int16_t x, int16_t y) { return sdiv_safe16(x + y - 1, y); }
SCALAR_FUN_ATTR int32_t sdiv_up_safe32(int32_t x, int32_t y) { return sdiv_safe32(x + y - 1, y); }
SCALAR_FUN_ATTR int64_t sdiv_up_safe64(int64_t x, int64_t y) { return sdiv_safe64(x + y - 1, y); }

SCALAR_FUN_ATTR int8_t   smod_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : smod8(x, y); }
SCALAR_FUN_ATTR int16_t smod_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : smod16(x, y); }
SCALAR_FUN_ATTR int32_t smod_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : smod32(x, y); }
SCALAR_FUN_ATTR int64_t smod_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : smod64(x, y); }

SCALAR_FUN_ATTR int8_t squot8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR int16_t squot16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR int32_t squot32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR int64_t squot64(int64_t x, int64_t y) {
  int64_t ys = 1;
  foreach_active(i) { ys = y; }
  return x / ys;
}

SCALAR_FUN_ATTR int8_t srem8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR int16_t srem16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR int32_t srem32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR int64_t srem64(int64_t x, int64_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  return x % ys;
}

SCALAR_FUN_ATTR int8_t squot_safe8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR int16_t squot_safe16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR int32_t squot_safe32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR int64_t squot_safe64(int64_t x, int64_t y) {
  int64_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x / ys;
}

SCALAR_FUN_ATTR int8_t srem_safe8(int8_t x, int8_t y) {
  int8_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR int16_t srem_safe16(int16_t x, int16_t y) {
  int16_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR int32_t srem_safe32(int32_t x, int32_t y) {
  int32_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

SCALAR_FUN_ATTR int64_t srem_safe64(int64_t x, int64_t y) {
  int64_t ys = 1;
  foreach_active(i) { ys = y; }
  return y == 0 ? 0 : x % ys;
}

#else

SCALAR_FUN_ATTR uint8_t   udiv8(uint8_t x, uint8_t y)   { return x / y; }
SCALAR_FUN_ATTR uint16_t udiv16(uint16_t x, uint16_t y) { return x / y; }
SCALAR_FUN_ATTR uint32_t udiv32(uint32_t x, uint32_t y) { return x / y; }
SCALAR_FUN_ATTR uint64_t udiv64(uint64_t x, uint64_t y) { return x / y; }

SCALAR_FUN_ATTR uint8_t   udiv_up8(uint8_t x, uint8_t y)   { return (x + y - 1) / y; }
SCALAR_FUN_ATTR uint16_t udiv_up16(uint16_t x, uint16_t y) { return (x + y - 1) / y; }
SCALAR_FUN_ATTR uint32_t udiv_up32(uint32_t x, uint32_t y) { return (x + y - 1) / y; }
SCALAR_FUN_ATTR uint64_t udiv_up64(uint64_t x, uint64_t y) { return (x + y - 1) / y; }

SCALAR_FUN_ATTR uint8_t   umod8(uint8_t x, uint8_t y)   { return x % y; }
SCALAR_FUN_ATTR uint16_t umod16(uint16_t x, uint16_t y) { return x % y; }
SCALAR_FUN_ATTR uint32_t umod32(uint32_t x, uint32_t y) { return x % y; }
SCALAR_FUN_ATTR uint64_t umod64(uint64_t x, uint64_t y) { return x % y; }

SCALAR_FUN_ATTR uint8_t   udiv_safe8(uint8_t x, uint8_t y)   { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR uint16_t udiv_safe16(uint16_t x, uint16_t y) { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR uint32_t udiv_safe32(uint32_t x, uint32_t y) { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR uint64_t udiv_safe64(uint64_t x, uint64_t y) { return y == 0 ? 0 : x / y; }

SCALAR_FUN_ATTR uint8_t   udiv_up_safe8(uint8_t x, uint8_t y)   { return y == 0 ? 0 : (x + y - 1) / y; }
SCALAR_FUN_ATTR uint16_t udiv_up_safe16(uint16_t x, uint16_t y) { return y == 0 ? 0 : (x + y - 1) / y; }
SCALAR_FUN_ATTR uint32_t udiv_up_safe32(uint32_t x, uint32_t y) { return y == 0 ? 0 : (x + y - 1) / y; }
SCALAR_FUN_ATTR uint64_t udiv_up_safe64(uint64_t x, uint64_t y) { return y == 0 ? 0 : (x + y - 1) / y; }

SCALAR_FUN_ATTR uint8_t   umod_safe8(uint8_t x, uint8_t y)   { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR uint16_t umod_safe16(uint16_t x, uint16_t y) { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR uint32_t umod_safe32(uint32_t x, uint32_t y) { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR uint64_t umod_safe64(uint64_t x, uint64_t y) { return y == 0 ? 0 : x % y; }

SCALAR_FUN_ATTR int8_t sdiv8(int8_t x, int8_t y) {
  int8_t q = x / y;
  int8_t r = x % y;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int16_t sdiv16(int16_t x, int16_t y) {
  int16_t q = x / y;
  int16_t r = x % y;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int32_t sdiv32(int32_t x, int32_t y) {
  int32_t q = x / y;
  int32_t r = x % y;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int64_t sdiv64(int64_t x, int64_t y) {
  int64_t q = x / y;
  int64_t r = x % y;
  return q - ((r != 0 && r < 0 != y < 0) ? 1 : 0);
}

SCALAR_FUN_ATTR int8_t   sdiv_up8(int8_t x, int8_t y)   { return sdiv8(x + y - 1, y); }
SCALAR_FUN_ATTR int16_t sdiv_up16(int16_t x, int16_t y) { return sdiv16(x + y - 1, y); }
SCALAR_FUN_ATTR int32_t sdiv_up32(int32_t x, int32_t y) { return sdiv32(x + y - 1, y); }
SCALAR_FUN_ATTR int64_t sdiv_up64(int64_t x, int64_t y) { return sdiv64(x + y - 1, y); }

SCALAR_FUN_ATTR int8_t smod8(int8_t x, int8_t y) {
  int8_t r = x % y;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int16_t smod16(int16_t x, int16_t y) {
  int16_t r = x % y;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int32_t smod32(int32_t x, int32_t y) {
  int32_t r = x % y;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int64_t smod64(int64_t x, int64_t y) {
  int64_t r = x % y;
  return r + (r == 0 || (x > 0 && y > 0) || (x < 0 && y < 0) ? 0 : y);
}

SCALAR_FUN_ATTR int8_t   sdiv_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : sdiv8(x, y); }
SCALAR_FUN_ATTR int16_t sdiv_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : sdiv16(x, y); }
SCALAR_FUN_ATTR int32_t sdiv_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : sdiv32(x, y); }
SCALAR_FUN_ATTR int64_t sdiv_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : sdiv64(x, y); }

SCALAR_FUN_ATTR int8_t   sdiv_up_safe8(int8_t x, int8_t y)   { return sdiv_safe8(x + y - 1, y);}
SCALAR_FUN_ATTR int16_t sdiv_up_safe16(int16_t x, int16_t y) { return sdiv_safe16(x + y - 1, y); }
SCALAR_FUN_ATTR int32_t sdiv_up_safe32(int32_t x, int32_t y) { return sdiv_safe32(x + y - 1, y); }
SCALAR_FUN_ATTR int64_t sdiv_up_safe64(int64_t x, int64_t y) { return sdiv_safe64(x + y - 1, y); }

SCALAR_FUN_ATTR int8_t   smod_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : smod8(x, y); }
SCALAR_FUN_ATTR int16_t smod_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : smod16(x, y); }
SCALAR_FUN_ATTR int32_t smod_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : smod32(x, y); }
SCALAR_FUN_ATTR int64_t smod_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : smod64(x, y); }

SCALAR_FUN_ATTR int8_t   squot8(int8_t x, int8_t y)   { return x / y; }
SCALAR_FUN_ATTR int16_t squot16(int16_t x, int16_t y) { return x / y; }
SCALAR_FUN_ATTR int32_t squot32(int32_t x, int32_t y) { return x / y; }
SCALAR_FUN_ATTR int64_t squot64(int64_t x, int64_t y) { return x / y; }

SCALAR_FUN_ATTR int8_t   srem8(int8_t x, int8_t y)   { return x % y; }
SCALAR_FUN_ATTR int16_t srem16(int16_t x, int16_t y) { return x % y; }
SCALAR_FUN_ATTR int32_t srem32(int32_t x, int32_t y) { return x % y; }
SCALAR_FUN_ATTR int64_t srem64(int64_t x, int64_t y) { return x % y; }

SCALAR_FUN_ATTR int8_t   squot_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR int16_t squot_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR int32_t squot_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : x / y; }
SCALAR_FUN_ATTR int64_t squot_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : x / y; }

SCALAR_FUN_ATTR int8_t   srem_safe8(int8_t x, int8_t y)   { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR int16_t srem_safe16(int16_t x, int16_t y) { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR int32_t srem_safe32(int32_t x, int32_t y) { return y == 0 ? 0 : x % y; }
SCALAR_FUN_ATTR int64_t srem_safe64(int64_t x, int64_t y) { return y == 0 ? 0 : x % y; }

#endif

SCALAR_FUN_ATTR int8_t   smin8(int8_t x, int8_t y)   { return x < y ? x : y; }
SCALAR_FUN_ATTR int16_t smin16(int16_t x, int16_t y) { return x < y ? x : y; }
SCALAR_FUN_ATTR int32_t smin32(int32_t x, int32_t y) { return x < y ? x : y; }
SCALAR_FUN_ATTR int64_t smin64(int64_t x, int64_t y) { return x < y ? x : y; }

SCALAR_FUN_ATTR uint8_t   umin8(uint8_t x, uint8_t y)   { return x < y ? x : y; }
SCALAR_FUN_ATTR uint16_t umin16(uint16_t x, uint16_t y) { return x < y ? x : y; }
SCALAR_FUN_ATTR uint32_t umin32(uint32_t x, uint32_t y) { return x < y ? x : y; }
SCALAR_FUN_ATTR uint64_t umin64(uint64_t x, uint64_t y) { return x < y ? x : y; }

SCALAR_FUN_ATTR int8_t  smax8(int8_t x, int8_t y)    { return x < y ? y : x; }
SCALAR_FUN_ATTR int16_t smax16(int16_t x, int16_t y) { return x < y ? y : x; }
SCALAR_FUN_ATTR int32_t smax32(int32_t x, int32_t y) { return x < y ? y : x; }
SCALAR_FUN_ATTR int64_t smax64(int64_t x, int64_t y) { return x < y ? y : x; }

SCALAR_FUN_ATTR uint8_t   umax8(uint8_t x, uint8_t y)   { return x < y ? y : x; }
SCALAR_FUN_ATTR uint16_t umax16(uint16_t x, uint16_t y) { return x < y ? y : x; }
SCALAR_FUN_ATTR uint32_t umax32(uint32_t x, uint32_t y) { return x < y ? y : x; }
SCALAR_FUN_ATTR uint64_t umax64(uint64_t x, uint64_t y) { return x < y ? y : x; }

SCALAR_FUN_ATTR uint8_t   shl8(uint8_t x, uint8_t y)   { return (uint8_t)(x << y); }
SCALAR_FUN_ATTR uint16_t shl16(uint16_t x, uint16_t y) { return (uint16_t)(x << y); }
SCALAR_FUN_ATTR uint32_t shl32(uint32_t x, uint32_t y) { return x << y; }
SCALAR_FUN_ATTR uint64_t shl64(uint64_t x, uint64_t y) { return x << y; }

SCALAR_FUN_ATTR uint8_t   lshr8(uint8_t x, uint8_t y)   { return x >> y; }
SCALAR_FUN_ATTR uint16_t lshr16(uint16_t x, uint16_t y) { return x >> y; }
SCALAR_FUN_ATTR uint32_t lshr32(uint32_t x, uint32_t y) { return x >> y; }
SCALAR_FUN_ATTR uint64_t lshr64(uint64_t x, uint64_t y) { return x >> y; }

SCALAR_FUN_ATTR int8_t   ashr8(int8_t x, int8_t y)   { return x >> y; }
SCALAR_FUN_ATTR int16_t ashr16(int16_t x, int16_t y) { return x >> y; }
SCALAR_FUN_ATTR int32_t ashr32(int32_t x, int32_t y) { return x >> y; }
SCALAR_FUN_ATTR int64_t ashr64(int64_t x, int64_t y) { return x >> y; }

SCALAR_FUN_ATTR uint8_t   and8(uint8_t x, uint8_t y)   { return x & y; }
SCALAR_FUN_ATTR uint16_t and16(uint16_t x, uint16_t y) { return x & y; }
SCALAR_FUN_ATTR uint32_t and32(uint32_t x, uint32_t y) { return x & y; }
SCALAR_FUN_ATTR uint64_t and64(uint64_t x, uint64_t y) { return x & y; }

SCALAR_FUN_ATTR uint8_t    or8(uint8_t x, uint8_t y)  { return x | y; }
SCALAR_FUN_ATTR uint16_t or16(uint16_t x, uint16_t y) { return x | y; }
SCALAR_FUN_ATTR uint32_t or32(uint32_t x, uint32_t y) { return x | y; }
SCALAR_FUN_ATTR uint64_t or64(uint64_t x, uint64_t y) { return x | y; }

SCALAR_FUN_ATTR uint8_t   xor8(uint8_t x, uint8_t y)   { return x ^ y; }
SCALAR_FUN_ATTR uint16_t xor16(uint16_t x, uint16_t y) { return x ^ y; }
SCALAR_FUN_ATTR uint32_t xor32(uint32_t x, uint32_t y) { return x ^ y; }
SCALAR_FUN_ATTR uint64_t xor64(uint64_t x, uint64_t y) { return x ^ y; }

SCALAR_FUN_ATTR bool ult8(uint8_t x, uint8_t y)    { return x < y; }
SCALAR_FUN_ATTR bool ult16(uint16_t x, uint16_t y) { return x < y; }
SCALAR_FUN_ATTR bool ult32(uint32_t x, uint32_t y) { return x < y; }
SCALAR_FUN_ATTR bool ult64(uint64_t x, uint64_t y) { return x < y; }

SCALAR_FUN_ATTR bool ule8(uint8_t x, uint8_t y)    { return x <= y; }
SCALAR_FUN_ATTR bool ule16(uint16_t x, uint16_t y) { return x <= y; }
SCALAR_FUN_ATTR bool ule32(uint32_t x, uint32_t y) { return x <= y; }
SCALAR_FUN_ATTR bool ule64(uint64_t x, uint64_t y) { return x <= y; }

SCALAR_FUN_ATTR bool  slt8(int8_t x, int8_t y)   { return x < y; }
SCALAR_FUN_ATTR bool slt16(int16_t x, int16_t y) { return x < y; }
SCALAR_FUN_ATTR bool slt32(int32_t x, int32_t y) { return x < y; }
SCALAR_FUN_ATTR bool slt64(int64_t x, int64_t y) { return x < y; }

SCALAR_FUN_ATTR bool  sle8(int8_t x, int8_t y)   { return x <= y; }
SCALAR_FUN_ATTR bool sle16(int16_t x, int16_t y) { return x <= y; }
SCALAR_FUN_ATTR bool sle32(int32_t x, int32_t y) { return x <= y; }
SCALAR_FUN_ATTR bool sle64(int64_t x, int64_t y) { return x <= y; }

SCALAR_FUN_ATTR uint8_t pow8(uint8_t x, uint8_t y) {
  uint8_t res = 1, rem = y;
  while (rem != 0) {
    if (rem & 1)
      res *= x;
    rem >>= 1;
    x *= x;
  }
  return res;
}

SCALAR_FUN_ATTR uint16_t pow16(uint16_t x, uint16_t y) {
  uint16_t res = 1, rem = y;
  while (rem != 0) {
    if (rem & 1)
      res *= x;
    rem >>= 1;
    x *= x;
  }
  return res;
}

SCALAR_FUN_ATTR uint32_t pow32(uint32_t x, uint32_t y) {
  uint32_t res = 1, rem = y;
  while (rem != 0) {
    if (rem & 1)
      res *= x;
    rem >>= 1;
    x *= x;
  }
  return res;
}

SCALAR_FUN_ATTR uint64_t pow64(uint64_t x, uint64_t y) {
  uint64_t res = 1, rem = y;
  while (rem != 0) {
    if (rem & 1)
      res *= x;
    rem >>= 1;
    x *= x;
  }
  return res;
}

SCALAR_FUN_ATTR bool  itob_i8_bool(int8_t x)  { return x != 0; }
SCALAR_FUN_ATTR bool itob_i16_bool(int16_t x) { return x != 0; }
SCALAR_FUN_ATTR bool itob_i32_bool(int32_t x) { return x != 0; }
SCALAR_FUN_ATTR bool itob_i64_bool(int64_t x) { return x != 0; }

SCALAR_FUN_ATTR int8_t btoi_bool_i8(bool x)   { return x; }
SCALAR_FUN_ATTR int16_t btoi_bool_i16(bool x) { return x; }
SCALAR_FUN_ATTR int32_t btoi_bool_i32(bool x) { return x; }
SCALAR_FUN_ATTR int64_t btoi_bool_i64(bool x) { return x; }

#define sext_i8_i8(x) ((int8_t) (int8_t) (x))
#define sext_i8_i16(x) ((int16_t) (int8_t) (x))
#define sext_i8_i32(x) ((int32_t) (int8_t) (x))
#define sext_i8_i64(x) ((int64_t) (int8_t) (x))
#define sext_i16_i8(x) ((int8_t) (int16_t) (x))
#define sext_i16_i16(x) ((int16_t) (int16_t) (x))
#define sext_i16_i32(x) ((int32_t) (int16_t) (x))
#define sext_i16_i64(x) ((int64_t) (int16_t) (x))
#define sext_i32_i8(x) ((int8_t) (int32_t) (x))
#define sext_i32_i16(x) ((int16_t) (int32_t) (x))
#define sext_i32_i32(x) ((int32_t) (int32_t) (x))
#define sext_i32_i64(x) ((int64_t) (int32_t) (x))
#define sext_i64_i8(x) ((int8_t) (int64_t) (x))
#define sext_i64_i16(x) ((int16_t) (int64_t) (x))
#define sext_i64_i32(x) ((int32_t) (int64_t) (x))
#define sext_i64_i64(x) ((int64_t) (int64_t) (x))
#define zext_i8_i8(x) ((int8_t) (uint8_t) (x))
#define zext_i8_i16(x) ((int16_t) (uint8_t) (x))
#define zext_i8_i32(x) ((int32_t) (uint8_t) (x))
#define zext_i8_i64(x) ((int64_t) (uint8_t) (x))
#define zext_i16_i8(x) ((int8_t) (uint16_t) (x))
#define zext_i16_i16(x) ((int16_t) (uint16_t) (x))
#define zext_i16_i32(x) ((int32_t) (uint16_t) (x))
#define zext_i16_i64(x) ((int64_t) (uint16_t) (x))
#define zext_i32_i8(x) ((int8_t) (uint32_t) (x))
#define zext_i32_i16(x) ((int16_t) (uint32_t) (x))
#define zext_i32_i32(x) ((int32_t) (uint32_t) (x))
#define zext_i32_i64(x) ((int64_t) (uint32_t) (x))
#define zext_i64_i8(x) ((int8_t) (uint64_t) (x))
#define zext_i64_i16(x) ((int16_t) (uint64_t) (x))
#define zext_i64_i32(x) ((int32_t) (uint64_t) (x))
#define zext_i64_i64(x) ((int64_t) (uint64_t) (x))

SCALAR_FUN_ATTR int8_t   abs8(int8_t x)  { return (int8_t)abs(x); }
SCALAR_FUN_ATTR int16_t abs16(int16_t x) { return (int16_t)abs(x); }
SCALAR_FUN_ATTR int32_t abs32(int32_t x) { return abs(x); }
SCALAR_FUN_ATTR int64_t abs64(int64_t x) {
#if defined(__OPENCL_VERSION__) || defined(ISPC)
  return abs(x);
#else
  return llabs(x);
#endif
}

#if defined(__OPENCL_VERSION__)

SCALAR_FUN_ATTR int32_t  futrts_popc8(int8_t x)  { return popcount(x); }
SCALAR_FUN_ATTR int32_t futrts_popc16(int16_t x) { return popcount(x); }
SCALAR_FUN_ATTR int32_t futrts_popc32(int32_t x) { return popcount(x); }
SCALAR_FUN_ATTR int32_t futrts_popc64(int64_t x) { return popcount(x); }

#elif defined(__CUDA_ARCH__)

SCALAR_FUN_ATTR int32_t  futrts_popc8(int8_t x)  { return __popc(zext_i8_i32(x)); }
SCALAR_FUN_ATTR int32_t futrts_popc16(int16_t x) { return __popc(zext_i16_i32(x)); }
SCALAR_FUN_ATTR int32_t futrts_popc32(int32_t x) { return __popc(x); }
SCALAR_FUN_ATTR int32_t futrts_popc64(int64_t x) { return __popcll(x); }

#else // Not OpenCL or CUDA, but plain C.

SCALAR_FUN_ATTR int32_t futrts_popc8(uint8_t x) {
  int c = 0;
  for (; x; ++c) { x &= x - 1; }
  return c;
}

SCALAR_FUN_ATTR int32_t futrts_popc16(uint16_t x) {
  int c = 0;
  for (; x; ++c) { x &= x - 1; }
  return c;
}

SCALAR_FUN_ATTR int32_t futrts_popc32(uint32_t x) {
  int c = 0;
  for (; x; ++c) { x &= x - 1; }
  return c;
}

SCALAR_FUN_ATTR int32_t futrts_popc64(uint64_t x) {
  int c = 0;
  for (; x; ++c) { x &= x - 1; }
  return c;
}
#endif

#if defined(__OPENCL_VERSION__)
SCALAR_FUN_ATTR uint8_t  futrts_umul_hi8 ( uint8_t a,  uint8_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint16_t futrts_umul_hi16(uint16_t a, uint16_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint32_t futrts_umul_hi32(uint32_t a, uint32_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint64_t futrts_umul_hi64(uint64_t a, uint64_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint8_t  futrts_smul_hi8 ( int8_t a,  int8_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint16_t futrts_smul_hi16(int16_t a, int16_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint32_t futrts_smul_hi32(int32_t a, int32_t b) { return mul_hi(a, b); }
SCALAR_FUN_ATTR uint64_t futrts_smul_hi64(int64_t a, int64_t b) { return mul_hi(a, b); }
#elif defined(__CUDA_ARCH__)
SCALAR_FUN_ATTR  uint8_t futrts_umul_hi8(uint8_t a, uint8_t b) { return ((uint16_t)a) * ((uint16_t)b) >> 8; }
SCALAR_FUN_ATTR uint16_t futrts_umul_hi16(uint16_t a, uint16_t b) { return ((uint32_t)a) * ((uint32_t)b) >> 16; }
SCALAR_FUN_ATTR uint32_t futrts_umul_hi32(uint32_t a, uint32_t b) { return __umulhi(a, b); }
SCALAR_FUN_ATTR uint64_t futrts_umul_hi64(uint64_t a, uint64_t b) { return __umul64hi(a, b); }
SCALAR_FUN_ATTR  uint8_t futrts_smul_hi8 ( int8_t a, int8_t b) { return ((int16_t)a) * ((int16_t)b) >> 8; }
SCALAR_FUN_ATTR uint16_t futrts_smul_hi16(int16_t a, int16_t b) { return ((int32_t)a) * ((int32_t)b) >> 16; }
SCALAR_FUN_ATTR uint32_t futrts_smul_hi32(int32_t a, int32_t b) { return __mulhi(a, b); }
SCALAR_FUN_ATTR uint64_t futrts_smul_hi64(int64_t a, int64_t b) { return __mul64hi(a, b); }
#elif defined(ISPC)
SCALAR_FUN_ATTR uint8_t futrts_umul_hi8(uint8_t a, uint8_t b) { return ((uint16_t)a) * ((uint16_t)b) >> 8; }
SCALAR_FUN_ATTR uint16_t futrts_umul_hi16(uint16_t a, uint16_t b) { return ((uint32_t)a) * ((uint32_t)b) >> 16; }
SCALAR_FUN_ATTR uint32_t futrts_umul_hi32(uint32_t a, uint32_t b) { return ((uint64_t)a) * ((uint64_t)b) >> 32; }
SCALAR_FUN_ATTR uint64_t futrts_umul_hi64(uint64_t a, uint64_t b) {
  uint64_t ah = a >> 32;
  uint64_t al = a & 0xffffffff;
  uint64_t bh = b >> 32;
  uint64_t bl = b & 0xffffffff;

  uint64_t p1 = al * bl;
  uint64_t p2 = al * bh;
  uint64_t p3 = ah * bl;
  uint64_t p4 = ah * bh;

  uint64_t p1h = p1 >> 32;
  uint64_t p2h = p2 >> 32;
  uint64_t p3h = p3 >> 32;
  uint64_t p2l = p2 & 0xffffffff;
  uint64_t p3l = p3 & 0xffffffff;

  uint64_t l = p1h + p2l + p3l;
  uint64_t m = (p2 >> 32) + (p3 >> 32);
  uint64_t h = (l >> 32) + m + p4;

  return h;
}
SCALAR_FUN_ATTR  int8_t futrts_smul_hi8 ( int8_t a,  int8_t b) { return ((uint16_t)a) * ((uint16_t)b) >> 8; }
SCALAR_FUN_ATTR int16_t futrts_smul_hi16(int16_t a, int16_t b) { return ((uint32_t)a) * ((uint32_t)b) >> 16; }
SCALAR_FUN_ATTR int32_t futrts_smul_hi32(int32_t a, int32_t b) { return ((uint64_t)a) * ((uint64_t)b) >> 32; }
SCALAR_FUN_ATTR int64_t futrts_smul_hi64(int64_t a, int64_t b) {
  uint64_t ah = a >> 32;
  uint64_t al = a & 0xffffffff;
  uint64_t bh = b >> 32;
  uint64_t bl = b & 0xffffffff;

  uint64_t p1 =  al * bl;
  int64_t  p2 = al * bh;
  int64_t  p3 = ah * bl;
  uint64_t p4 =  ah * bh;

  uint64_t p1h = p1 >> 32;
  uint64_t p2h = p2 >> 32;
  uint64_t p3h = p3 >> 32;
  uint64_t p2l = p2 & 0xffffffff;
  uint64_t p3l = p3 & 0xffffffff;

  uint64_t l = p1h + p2l + p3l;
  uint64_t m = (p2 >> 32) + (p3 >> 32);
  uint64_t h = (l >> 32) + m + p4;

  return h;
}

#else // Not OpenCL, ISPC, or CUDA, but plain C.
SCALAR_FUN_ATTR uint8_t futrts_umul_hi8(uint8_t a, uint8_t b) { return ((uint16_t)a) * ((uint16_t)b) >> 8; }
SCALAR_FUN_ATTR uint16_t futrts_umul_hi16(uint16_t a, uint16_t b) { return ((uint32_t)a) * ((uint32_t)b) >> 16; }
SCALAR_FUN_ATTR uint32_t futrts_umul_hi32(uint32_t a, uint32_t b) { return ((uint64_t)a) * ((uint64_t)b) >> 32; }
SCALAR_FUN_ATTR uint64_t futrts_umul_hi64(uint64_t a, uint64_t b) { return ((__uint128_t)a) * ((__uint128_t)b) >> 64; }
SCALAR_FUN_ATTR int8_t futrts_smul_hi8(int8_t a, int8_t b) { return ((int16_t)a) * ((int16_t)b) >> 8; }
SCALAR_FUN_ATTR int16_t futrts_smul_hi16(int16_t a, int16_t b) { return ((int32_t)a) * ((int32_t)b) >> 16; }
SCALAR_FUN_ATTR int32_t futrts_smul_hi32(int32_t a, int32_t b) { return ((int64_t)a) * ((int64_t)b) >> 32; }
SCALAR_FUN_ATTR int64_t futrts_smul_hi64(int64_t a, int64_t b) { return ((__int128_t)a) * ((__int128_t)b) >> 64; }
#endif

#if defined(__OPENCL_VERSION__)
SCALAR_FUN_ATTR  uint8_t futrts_umad_hi8 ( uint8_t a,  uint8_t b,  uint8_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint16_t futrts_umad_hi16(uint16_t a, uint16_t b, uint16_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint32_t futrts_umad_hi32(uint32_t a, uint32_t b, uint32_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint64_t futrts_umad_hi64(uint64_t a, uint64_t b, uint64_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR  uint8_t futrts_smad_hi8( int8_t a,  int8_t b,   int8_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint16_t futrts_smad_hi16(int16_t a, int16_t b, int16_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint32_t futrts_smad_hi32(int32_t a, int32_t b, int32_t c) { return mad_hi(a, b, c); }
SCALAR_FUN_ATTR uint64_t futrts_smad_hi64(int64_t a, int64_t b, int64_t c) { return mad_hi(a, b, c); }
#else // Not OpenCL

SCALAR_FUN_ATTR  uint8_t futrts_umad_hi8( uint8_t a,  uint8_t b,  uint8_t c) { return futrts_umul_hi8(a, b) + c; }
SCALAR_FUN_ATTR uint16_t futrts_umad_hi16(uint16_t a, uint16_t b, uint16_t c) { return futrts_umul_hi16(a, b) + c; }
SCALAR_FUN_ATTR uint32_t futrts_umad_hi32(uint32_t a, uint32_t b, uint32_t c) { return futrts_umul_hi32(a, b) + c; }
SCALAR_FUN_ATTR uint64_t futrts_umad_hi64(uint64_t a, uint64_t b, uint64_t c) { return futrts_umul_hi64(a, b) + c; }
SCALAR_FUN_ATTR  uint8_t futrts_smad_hi8 ( int8_t a,  int8_t b,  int8_t c) { return futrts_smul_hi8(a, b) + c; }
SCALAR_FUN_ATTR uint16_t futrts_smad_hi16(int16_t a, int16_t b, int16_t c) { return futrts_smul_hi16(a, b) + c; }
SCALAR_FUN_ATTR uint32_t futrts_smad_hi32(int32_t a, int32_t b, int32_t c) { return futrts_smul_hi32(a, b) + c; }
SCALAR_FUN_ATTR uint64_t futrts_smad_hi64(int64_t a, int64_t b, int64_t c) { return futrts_smul_hi64(a, b) + c; }
#endif

#if defined(__OPENCL_VERSION__)
SCALAR_FUN_ATTR int32_t  futrts_clzz8(int8_t x)  { return clz(x); }
SCALAR_FUN_ATTR int32_t futrts_clzz16(int16_t x) { return clz(x); }
SCALAR_FUN_ATTR int32_t futrts_clzz32(int32_t x) { return clz(x); }
SCALAR_FUN_ATTR int32_t futrts_clzz64(int64_t x) { return clz(x); }

#elif defined(__CUDA_ARCH__)

SCALAR_FUN_ATTR int32_t  futrts_clzz8(int8_t x)  { return __clz(zext_i8_i32(x)) - 24; }
SCALAR_FUN_ATTR int32_t futrts_clzz16(int16_t x) { return __clz(zext_i16_i32(x)) - 16; }
SCALAR_FUN_ATTR int32_t futrts_clzz32(int32_t x) { return __clz(x); }
SCALAR_FUN_ATTR int32_t futrts_clzz64(int64_t x) { return __clzll(x); }

#elif defined(ISPC)

SCALAR_FUN_ATTR int32_t  futrts_clzz8(int8_t x)  { return count_leading_zeros((int32_t)(uint8_t)x)-24; }
SCALAR_FUN_ATTR int32_t futrts_clzz16(int16_t x) { return count_leading_zeros((int32_t)(uint16_t)x)-16; }
SCALAR_FUN_ATTR int32_t futrts_clzz32(int32_t x) { return count_leading_zeros(x); }
SCALAR_FUN_ATTR int32_t futrts_clzz64(int64_t x) { return count_leading_zeros(x); }

#else // Not OpenCL, ISPC or CUDA, but plain C.

SCALAR_FUN_ATTR int32_t futrts_clzz8(int8_t x)
{ return x == 0 ? 8 : __builtin_clz((uint32_t)zext_i8_i32(x)) - 24; }
SCALAR_FUN_ATTR int32_t futrts_clzz16(int16_t x)
{ return x == 0 ? 16 : __builtin_clz((uint32_t)zext_i16_i32(x)) - 16; }
SCALAR_FUN_ATTR int32_t futrts_clzz32(int32_t x)
{ return x == 0 ? 32 : __builtin_clz((uint32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_clzz64(int64_t x)
{ return x == 0 ? 64 : __builtin_clzll((uint64_t)x); }
#endif

#if defined(__OPENCL_VERSION__)
SCALAR_FUN_ATTR int32_t futrts_ctzz8(int8_t x) {
  int i = 0;
  for (; i < 8 && (x & 1) == 0; i++, x >>= 1) ;
  return i;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz16(int16_t x) {
  int i = 0;
  for (; i < 16 && (x & 1) == 0; i++, x >>= 1) ;
  return i;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz32(int32_t x) {
  int i = 0;
  for (; i < 32 && (x & 1) == 0; i++, x >>= 1) ;
  return i;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz64(int64_t x) {
  int i = 0;
  for (; i < 64 && (x & 1) == 0; i++, x >>= 1) ;
  return i;
}

#elif defined(__CUDA_ARCH__)

SCALAR_FUN_ATTR int32_t futrts_ctzz8(int8_t x) {
  int y = __ffs(x);
  return y == 0 ? 8 : y - 1;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz16(int16_t x) {
  int y = __ffs(x);
  return y == 0 ? 16 : y - 1;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz32(int32_t x) {
  int y = __ffs(x);
  return y == 0 ? 32 : y - 1;
}

SCALAR_FUN_ATTR int32_t futrts_ctzz64(int64_t x) {
  int y = __ffsll(x);
  return y == 0 ? 64 : y - 1;
}

#elif defined(ISPC)

SCALAR_FUN_ATTR int32_t futrts_ctzz8(int8_t x) { return x == 0 ? 8 : count_trailing_zeros((int32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz16(int16_t x) { return x == 0 ? 16 : count_trailing_zeros((int32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz32(int32_t x) { return count_trailing_zeros(x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz64(int64_t x) { return count_trailing_zeros(x); }

#else // Not OpenCL or CUDA, but plain C.

SCALAR_FUN_ATTR int32_t  futrts_ctzz8(int8_t x)  { return x == 0 ? 8 : __builtin_ctz((uint32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz16(int16_t x) { return x == 0 ? 16 : __builtin_ctz((uint32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz32(int32_t x) { return x == 0 ? 32 : __builtin_ctz((uint32_t)x); }
SCALAR_FUN_ATTR int32_t futrts_ctzz64(int64_t x) { return x == 0 ? 64 : __builtin_ctzll((uint64_t)x); }
#endif

SCALAR_FUN_ATTR float fdiv32(float x, float y) { return x / y; }
SCALAR_FUN_ATTR float fadd32(float x, float y) { return x + y; }
SCALAR_FUN_ATTR float fsub32(float x, float y) { return x - y; }
SCALAR_FUN_ATTR float fmul32(float x, float y) { return x * y; }
SCALAR_FUN_ATTR bool cmplt32(float x, float y) { return x < y; }
SCALAR_FUN_ATTR bool cmple32(float x, float y) { return x <= y; }
SCALAR_FUN_ATTR float sitofp_i8_f32(int8_t x)  { return (float) x; }

SCALAR_FUN_ATTR float sitofp_i16_f32(int16_t x) { return (float) x; }
SCALAR_FUN_ATTR float sitofp_i32_f32(int32_t x) { return (float) x; }
SCALAR_FUN_ATTR float sitofp_i64_f32(int64_t x) { return (float) x; }
SCALAR_FUN_ATTR float  uitofp_i8_f32(uint8_t x)  { return (float) x; }
SCALAR_FUN_ATTR float uitofp_i16_f32(uint16_t x) { return (float) x; }
SCALAR_FUN_ATTR float uitofp_i32_f32(uint32_t x) { return (float) x; }
SCALAR_FUN_ATTR float uitofp_i64_f32(uint64_t x) { return (float) x; }

#ifdef __OPENCL_VERSION__
SCALAR_FUN_ATTR float fabs32(float x)          { return fabs(x); }
SCALAR_FUN_ATTR float fmax32(float x, float y) { return fmax(x, y); }
SCALAR_FUN_ATTR float fmin32(float x, float y) { return fmin(x, y); }
SCALAR_FUN_ATTR float fpow32(float x, float y) { return pow(x, y); }

#elif defined(ISPC)

SCALAR_FUN_ATTR float fabs32(float x) { return abs(x); }
SCALAR_FUN_ATTR float fmax32(float x, float y) { return isnan(x) ? y : isnan(y) ? x : max(x, y); }
SCALAR_FUN_ATTR float fmin32(float x, float y) { return isnan(x) ? y : isnan(y) ? x : min(x, y); }
SCALAR_FUN_ATTR float fpow32(float a, float b) {
  float ret;
  foreach_active (i) {
      uniform float r = pow(extract(a, i), extract(b, i));
      ret = insert(ret, i, r);
  }
  return ret;
}

#else // Not OpenCL, but CUDA or plain C.

SCALAR_FUN_ATTR float fabs32(float x)          { return fabsf(x); }
SCALAR_FUN_ATTR float fmax32(float x, float y) { return fmaxf(x, y); }
SCALAR_FUN_ATTR float fmin32(float x, float y) { return fminf(x, y); }
SCALAR_FUN_ATTR float fpow32(float x, float y) { return powf(x, y); }
#endif

SCALAR_FUN_ATTR bool futrts_isnan32(float x) { return isnan(x); }

#if defined(ISPC)

SCALAR_FUN_ATTR bool futrts_isinf32(float x) { return !isnan(x) && isnan(x - x); }

SCALAR_FUN_ATTR bool futrts_isfinite32(float x) { return !isnan(x) && !futrts_isinf32(x); }

#else

SCALAR_FUN_ATTR bool futrts_isinf32(float x) { return isinf(x); }

#endif

SCALAR_FUN_ATTR int8_t fptosi_f32_i8(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (int8_t) x;
  }
}

SCALAR_FUN_ATTR int16_t fptosi_f32_i16(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (int16_t) x;
  }
}

SCALAR_FUN_ATTR int32_t fptosi_f32_i32(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (int32_t) x;
  }
}

SCALAR_FUN_ATTR int64_t fptosi_f32_i64(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (int64_t) x;
  };
}

SCALAR_FUN_ATTR uint8_t fptoui_f32_i8(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (uint8_t) (int8_t) x;
  }
}

SCALAR_FUN_ATTR uint16_t fptoui_f32_i16(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (uint16_t) (int16_t) x;
  }
}

SCALAR_FUN_ATTR uint32_t fptoui_f32_i32(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (uint32_t) (int32_t) x;
  }
}

SCALAR_FUN_ATTR uint64_t fptoui_f32_i64(float x) {
  if (futrts_isnan32(x) || futrts_isinf32(x)) {
    return 0;
  } else {
    return (uint64_t) (int64_t) x;
  }
}

SCALAR_FUN_ATTR bool ftob_f32_bool(float x) { return x != 0; }
SCALAR_FUN_ATTR float btof_bool_f32(bool x) { return x ? 1 : 0; }

#ifdef __OPENCL_VERSION__
SCALAR_FUN_ATTR float futrts_log32(float x) { return log(x); }
SCALAR_FUN_ATTR float futrts_log2_32(float x) { return log2(x); }
SCALAR_FUN_ATTR float futrts_log10_32(float x) { return log10(x); }
SCALAR_FUN_ATTR float futrts_log1p_32(float x) { return log1p(x); }
SCALAR_FUN_ATTR float futrts_sqrt32(float x) { return sqrt(x); }
SCALAR_FUN_ATTR float futrts_rsqrt32(float x) { return rsqrt(x); }
SCALAR_FUN_ATTR float futrts_cbrt32(float x) { return cbrt(x); }
SCALAR_FUN_ATTR float futrts_exp32(float x) { return exp(x); }
SCALAR_FUN_ATTR float futrts_cos32(float x) { return cos(x); }
SCALAR_FUN_ATTR float futrts_cospi32(float x) { return cospi(x); }
SCALAR_FUN_ATTR float futrts_sin32(float x) { return sin(x); }
SCALAR_FUN_ATTR float futrts_sinpi32(float x) { return sinpi(x); }
SCALAR_FUN_ATTR float futrts_tan32(float x) { return tan(x); }
SCALAR_FUN_ATTR float futrts_tanpi32(float x) { return tanpi(x); }
SCALAR_FUN_ATTR float futrts_acos32(float x) { return acos(x); }
SCALAR_FUN_ATTR float futrts_acospi32(float x) { return acospi(x); }
SCALAR_FUN_ATTR float futrts_asin32(float x) { return asin(x); }
SCALAR_FUN_ATTR float futrts_asinpi32(float x) { return asinpi(x); }
SCALAR_FUN_ATTR float futrts_atan32(float x) { return atan(x); }
SCALAR_FUN_ATTR float futrts_atanpi32(float x) { return atanpi(x); }
SCALAR_FUN_ATTR float futrts_cosh32(float x) { return cosh(x); }
SCALAR_FUN_ATTR float futrts_sinh32(float x) { return sinh(x); }
SCALAR_FUN_ATTR float futrts_tanh32(float x) { return tanh(x); }
SCALAR_FUN_ATTR float futrts_acosh32(float x) { return acosh(x); }
SCALAR_FUN_ATTR float futrts_asinh32(float x) { return asinh(x); }
SCALAR_FUN_ATTR float futrts_atanh32(float x) { return atanh(x); }
SCALAR_FUN_ATTR float futrts_atan2_32(float x, float y) { return atan2(x, y); }
SCALAR_FUN_ATTR float futrts_atan2pi_32(float x, float y) { return atan2pi(x, y); }
SCALAR_FUN_ATTR float futrts_hypot32(float x, float y) { return hypot(x, y); }
SCALAR_FUN_ATTR float futrts_gamma32(float x) { return tgamma(x); }
SCALAR_FUN_ATTR float futrts_lgamma32(float x) { return lgamma(x); }
SCALAR_FUN_ATTR float futrts_erf32(float x) { return erf(x); }
SCALAR_FUN_ATTR float futrts_erfc32(float x) { return erfc(x); }
SCALAR_FUN_ATTR float fmod32(float x, float y) { return fmod(x, y); }
SCALAR_FUN_ATTR float futrts_round32(float x) { return rint(x); }
SCALAR_FUN_ATTR float futrts_floor32(float x) { return floor(x); }
SCALAR_FUN_ATTR float futrts_ceil32(float x) { return ceil(x); }
SCALAR_FUN_ATTR float futrts_nextafter32(float x, float y) { return nextafter(x, y); }
SCALAR_FUN_ATTR float futrts_lerp32(float v0, float v1, float t) { return mix(v0, v1, t); }
SCALAR_FUN_ATTR float futrts_ldexp32(float x, int32_t y) { return ldexp(x, y); }
SCALAR_FUN_ATTR float futrts_copysign32(float x, float y) { return copysign(x, y); }
SCALAR_FUN_ATTR float futrts_mad32(float a, float b, float c) { return mad(a, b, c); }
SCALAR_FUN_ATTR float futrts_fma32(float a, float b, float c) { return fma(a, b, c); }

#elif defined(ISPC)

SCALAR_FUN_ATTR float futrts_log32(float x) { return futrts_isfinite32(x) || (futrts_isinf32(x) && x < 0)? log(x) : x; }
SCALAR_FUN_ATTR float futrts_log2_32(float x) { return futrts_log32(x) / log(2.0f); }
SCALAR_FUN_ATTR float futrts_log10_32(float x) { return futrts_log32(x) / log(10.0f); }

SCALAR_FUN_ATTR float futrts_log1p_32(float x) {
  if(x == -1.0f || (futrts_isinf32(x) && x > 0.0f)) return x / 0.0f;
  float y = 1.0f + x;
  float z = y - 1.0f;
  return log(y) - (z-x)/y;
}

SCALAR_FUN_ATTR float futrts_sqrt32(float x) { return sqrt(x); }
SCALAR_FUN_ATTR float futrts_rsqrt32(float x) { return 1/sqrt(x); }

extern "C" unmasked uniform float cbrtf(uniform float);
SCALAR_FUN_ATTR float futrts_cbrt32(float x) {
  float res;
  foreach_active (i) {
    uniform float r = cbrtf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR float futrts_exp32(float x) { return exp(x); }
SCALAR_FUN_ATTR float futrts_cos32(float x) { return cos(x); }
SCALAR_FUN_ATTR float futrts_cospi32(float x) { return cos((float)M_PI*x); }
SCALAR_FUN_ATTR float futrts_sin32(float x) { return sin(x); }
SCALAR_FUN_ATTR float futrts_sinpi32(float x) { return sin(M_PI*x); }
SCALAR_FUN_ATTR float futrts_tan32(float x) { return tan(x); }
SCALAR_FUN_ATTR float futrts_tanpi32(float x) { return tan((float)M_PI*x); }
SCALAR_FUN_ATTR float futrts_acos32(float x) { return acos(x); }
SCALAR_FUN_ATTR float futrts_acospi32(float x) { return acos(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_asin32(float x) { return asin(x); }
SCALAR_FUN_ATTR float futrts_asinpi32(float x) { return asin(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_atan32(float x) { return atan(x); }
SCALAR_FUN_ATTR float futrts_atanpi32(float x) { return atan(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_cosh32(float x) { return (exp(x)+exp(-x)) / 2.0f; }
SCALAR_FUN_ATTR float futrts_sinh32(float x) { return (exp(x)-exp(-x)) / 2.0f; }
SCALAR_FUN_ATTR float futrts_tanh32(float x) { return futrts_sinh32(x)/futrts_cosh32(x); }

SCALAR_FUN_ATTR float futrts_acosh32(float x) {
  float f = x+sqrt(x*x-1);
  if (futrts_isfinite32(f)) return log(f);
  return f;
}

SCALAR_FUN_ATTR float futrts_asinh32(float x) {
  float f = x+sqrt(x*x+1);
  if (futrts_isfinite32(f)) return log(f);
  return f;
}

SCALAR_FUN_ATTR float futrts_atanh32(float x) {
  float f = (1+x)/(1-x);
  if (futrts_isfinite32(f)) return log(f)/2.0f;
  return f;
}

SCALAR_FUN_ATTR float futrts_atan2_32(float x, float y)
{ return (x == 0.0f && y == 0.0f) ? 0.0f : atan2(x, y); }
SCALAR_FUN_ATTR float futrts_atan2pi_32(float x, float y)
{ return (x == 0.0f && y == 0.0f) ? 0.0f : atan2(x, y) / (float)M_PI; }

SCALAR_FUN_ATTR float futrts_hypot32(float x, float y) {
  if (futrts_isfinite32(x) && futrts_isfinite32(y)) {
    x = abs(x);
    y = abs(y);
    float a;
    float b;
    if (x >= y){
        a = x;
        b = y;
    } else {
        a = y;
        b = x;
    }
    if(b == 0){
      return a;
    }

    int e;
    float an;
    float bn;
    an = frexp (a, &e);
    bn = ldexp (b, - e);
    float cn;
    cn = sqrt (an * an + bn * bn);
    return ldexp (cn, e);
  } else {
    if (futrts_isinf32(x) || futrts_isinf32(y)) return INFINITY;
    else return x + y;
  }

}

extern "C" unmasked uniform float tgammaf(uniform float x);
SCALAR_FUN_ATTR float futrts_gamma32(float x) {
  float res;
  foreach_active (i) {
    uniform float r = tgammaf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform float lgammaf(uniform float x);
SCALAR_FUN_ATTR float futrts_lgamma32(float x) {
  float res;
  foreach_active (i) {
    uniform float r = lgammaf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform float erff(uniform float x);
SCALAR_FUN_ATTR float futrts_erf32(float x) {
  float res;
  foreach_active (i) {
    uniform float r = erff(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform float erfcf(uniform float x);
SCALAR_FUN_ATTR float futrts_erfc32(float x) {
  float res;
  foreach_active (i) {
    uniform float r = erfcf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR float fmod32(float x, float y) { return x - y * trunc(x/y); }
SCALAR_FUN_ATTR float futrts_round32(float x) { return round(x); }
SCALAR_FUN_ATTR float futrts_floor32(float x) { return floor(x); }
SCALAR_FUN_ATTR float futrts_ceil32(float x) { return ceil(x); }

extern "C" unmasked uniform float nextafterf(uniform float x, uniform float y);
SCALAR_FUN_ATTR float futrts_nextafter32(float x, float y) {
  float res;
  foreach_active (i) {
    uniform float r = nextafterf(extract(x, i), extract(y, i));
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR float futrts_lerp32(float v0, float v1, float t) {
  return v0 + (v1 - v0) * t;
}

SCALAR_FUN_ATTR float futrts_ldexp32(float x, int32_t y) {
  return x * pow((uniform float)2.0, (float)y);
}

SCALAR_FUN_ATTR float futrts_copysign32(float x, float y) {
  int32_t xb = fptobits_f32_i32(x);
  int32_t yb = fptobits_f32_i32(y);
  return bitstofp_i32_f32((xb & ~(1<<31)) | (yb & (1<<31)));
}

SCALAR_FUN_ATTR float futrts_mad32(float a, float b, float c) {
  return a * b + c;
}

SCALAR_FUN_ATTR float futrts_fma32(float a, float b, float c) {
  return a * b + c;
}

#else // Not OpenCL or ISPC, but CUDA or plain C.

SCALAR_FUN_ATTR float futrts_log32(float x) { return logf(x); }
SCALAR_FUN_ATTR float futrts_log2_32(float x) { return log2f(x); }
SCALAR_FUN_ATTR float futrts_log10_32(float x) { return log10f(x); }
SCALAR_FUN_ATTR float futrts_log1p_32(float x) { return log1pf(x); }
SCALAR_FUN_ATTR float futrts_sqrt32(float x) { return sqrtf(x); }
SCALAR_FUN_ATTR float futrts_rsqrt32(float x) { return 1/sqrtf(x); }
SCALAR_FUN_ATTR float futrts_cbrt32(float x) { return cbrtf(x); }
SCALAR_FUN_ATTR float futrts_exp32(float x) { return expf(x); }
SCALAR_FUN_ATTR float futrts_cos32(float x) { return cosf(x); }

SCALAR_FUN_ATTR float futrts_cospi32(float x) {
#if defined(__CUDA_ARCH__)
  return cospif(x);
#else
  return cosf(((float)M_PI)*x);
#endif
}
SCALAR_FUN_ATTR float futrts_sin32(float x) { return sinf(x); }

SCALAR_FUN_ATTR float futrts_sinpi32(float x) {
#if defined(__CUDA_ARCH__)
  return sinpif(x);
#else
  return sinf((float)M_PI*x);
#endif
}

SCALAR_FUN_ATTR float futrts_tan32(float x) { return tanf(x); }
SCALAR_FUN_ATTR float futrts_tanpi32(float x) { return tanf((float)M_PI*x); }
SCALAR_FUN_ATTR float futrts_acos32(float x) { return acosf(x); }
SCALAR_FUN_ATTR float futrts_acospi32(float x) { return acosf(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_asin32(float x) { return asinf(x); }
SCALAR_FUN_ATTR float futrts_asinpi32(float x) { return asinf(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_atan32(float x) { return atanf(x); }
SCALAR_FUN_ATTR float futrts_atanpi32(float x) { return atanf(x)/(float)M_PI; }
SCALAR_FUN_ATTR float futrts_cosh32(float x) { return coshf(x); }
SCALAR_FUN_ATTR float futrts_sinh32(float x) { return sinhf(x); }
SCALAR_FUN_ATTR float futrts_tanh32(float x) { return tanhf(x); }
SCALAR_FUN_ATTR float futrts_acosh32(float x) { return acoshf(x); }
SCALAR_FUN_ATTR float futrts_asinh32(float x) { return asinhf(x); }
SCALAR_FUN_ATTR float futrts_atanh32(float x) { return atanhf(x); }
SCALAR_FUN_ATTR float futrts_atan2_32(float x, float y) { return atan2f(x, y); }
SCALAR_FUN_ATTR float futrts_atan2pi_32(float x, float y) { return atan2f(x, y) / (float)M_PI; }
SCALAR_FUN_ATTR float futrts_hypot32(float x, float y) { return hypotf(x, y); }
SCALAR_FUN_ATTR float futrts_gamma32(float x) { return tgammaf(x); }
SCALAR_FUN_ATTR float futrts_lgamma32(float x) { return lgammaf(x); }
SCALAR_FUN_ATTR float futrts_erf32(float x) { return erff(x); }
SCALAR_FUN_ATTR float futrts_erfc32(float x) { return erfcf(x); }
SCALAR_FUN_ATTR float fmod32(float x, float y) { return fmodf(x, y); }
SCALAR_FUN_ATTR float futrts_round32(float x) { return rintf(x); }
SCALAR_FUN_ATTR float futrts_floor32(float x) { return floorf(x); }
SCALAR_FUN_ATTR float futrts_ceil32(float x) { return ceilf(x); }
SCALAR_FUN_ATTR float futrts_nextafter32(float x, float y) { return nextafterf(x, y); }
SCALAR_FUN_ATTR float futrts_lerp32(float v0, float v1, float t) { return v0 + (v1 - v0) * t; }
SCALAR_FUN_ATTR float futrts_ldexp32(float x, int32_t y) { return ldexpf(x, y); }
SCALAR_FUN_ATTR float futrts_copysign32(float x, float y) { return copysignf(x, y); }
SCALAR_FUN_ATTR float futrts_mad32(float a, float b, float c) { return a * b + c; }
SCALAR_FUN_ATTR float futrts_fma32(float a, float b, float c) { return fmaf(a, b, c); }

#endif

#if defined(ISPC)

SCALAR_FUN_ATTR int32_t fptobits_f32_i32(float x) { return intbits(x); }
SCALAR_FUN_ATTR float bitstofp_i32_f32(int32_t x) { return floatbits(x); }
SCALAR_FUN_ATTR uniform int32_t fptobits_f32_i32(uniform float x) { return intbits(x); }
SCALAR_FUN_ATTR uniform float bitstofp_i32_f32(uniform int32_t x) { return floatbits(x); }

#else

SCALAR_FUN_ATTR int32_t fptobits_f32_i32(float x) {
  union {
    float f;
    int32_t t;
  } p;

  p.f = x;
  return p.t;
}

SCALAR_FUN_ATTR float bitstofp_i32_f32(int32_t x) {
  union {
    int32_t f;
    float t;
  } p;

  p.f = x;
  return p.t;
}
#endif

SCALAR_FUN_ATTR float fsignum32(float x) {
  return futrts_isnan32(x) ? x : (x > 0 ? 1 : 0) - (x < 0 ? 1 : 0);
}

#ifdef FUTHARK_F64_ENABLED

SCALAR_FUN_ATTR double bitstofp_i64_f64(int64_t x);
SCALAR_FUN_ATTR int64_t fptobits_f64_i64(double x);

#if defined(ISPC)

SCALAR_FUN_ATTR bool futrts_isinf64(double x) { return !isnan(x) && isnan(x - x); }
SCALAR_FUN_ATTR bool futrts_isfinite64(double x) { return !isnan(x) && !futrts_isinf64(x); }
SCALAR_FUN_ATTR double fdiv64(double x, double y) { return x / y; }
SCALAR_FUN_ATTR double fadd64(double x, double y) { return x + y; }
SCALAR_FUN_ATTR double fsub64(double x, double y) { return x - y; }
SCALAR_FUN_ATTR double fmul64(double x, double y) { return x * y; }
SCALAR_FUN_ATTR bool cmplt64(double x, double y) { return x < y; }
SCALAR_FUN_ATTR bool cmple64(double x, double y) { return x <= y; }
SCALAR_FUN_ATTR double sitofp_i8_f64(int8_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i16_f64(int16_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i32_f64(int32_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i64_f64(int64_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i8_f64(uint8_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i16_f64(uint16_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i32_f64(uint32_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i64_f64(uint64_t x) { return (double) x; }
SCALAR_FUN_ATTR double fabs64(double x) { return abs(x); }
SCALAR_FUN_ATTR double fmax64(double x, double y) { return isnan(x) ? y : isnan(y) ? x : max(x, y); }
SCALAR_FUN_ATTR double fmin64(double x, double y) { return isnan(x) ? y : isnan(y) ? x : min(x, y); }

SCALAR_FUN_ATTR double fpow64(double a, double b) {
  float ret;
  foreach_active (i) {
      uniform float r = pow(extract(a, i), extract(b, i));
      ret = insert(ret, i, r);
  }
  return ret;
}
SCALAR_FUN_ATTR double futrts_log64(double x) { return futrts_isfinite64(x) || (futrts_isinf64(x) && x < 0)? log(x) : x; }
SCALAR_FUN_ATTR double futrts_log2_64(double x) { return futrts_log64(x)/log(2.0d); }
SCALAR_FUN_ATTR double futrts_log10_64(double x) { return futrts_log64(x)/log(10.0d); }

SCALAR_FUN_ATTR double futrts_log1p_64(double x) {
  if(x == -1.0d || (futrts_isinf64(x) && x > 0.0d)) return x / 0.0d;
  double y = 1.0d + x;
  double z = y - 1.0d;
  return log(y) - (z-x)/y;
}

SCALAR_FUN_ATTR double futrts_sqrt64(double x) { return sqrt(x); }
SCALAR_FUN_ATTR double futrts_rsqrt64(double x) { return 1/sqrt(x); }

SCALAR_FUN_ATTR double futrts_cbrt64(double x) {
  double res;
  foreach_active (i) {
    uniform double r = cbrtf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}
SCALAR_FUN_ATTR double futrts_exp64(double x) { return exp(x); }
SCALAR_FUN_ATTR double futrts_cos64(double x) { return cos(x); }
SCALAR_FUN_ATTR double futrts_cospi64(double x) { return cos(M_PI*x); }
SCALAR_FUN_ATTR double futrts_sin64(double x) { return sin(x); }
SCALAR_FUN_ATTR double futrts_sinpi64(double x) { return sin(M_PI*x); }
SCALAR_FUN_ATTR double futrts_tan64(double x) { return tan(x); }
SCALAR_FUN_ATTR double futrts_tanpi64(double x) { return tan(M_PI*x); }
SCALAR_FUN_ATTR double futrts_acos64(double x) { return acos(x); }
SCALAR_FUN_ATTR double futrts_acospi64(double x) { return acos(x)/M_PI; }
SCALAR_FUN_ATTR double futrts_asin64(double x) { return asin(x); }
SCALAR_FUN_ATTR double futrts_asinpi64(double x) { return asin(x)/M_PI; }
SCALAR_FUN_ATTR double futrts_atan64(double x) { return atan(x); }
SCALAR_FUN_ATTR double futrts_atanpi64(double x) { return atan(x)/M_PI; }
SCALAR_FUN_ATTR double futrts_cosh64(double x) { return (exp(x)+exp(-x)) / 2.0d; }
SCALAR_FUN_ATTR double futrts_sinh64(double x) { return (exp(x)-exp(-x)) / 2.0d; }
SCALAR_FUN_ATTR double futrts_tanh64(double x) { return futrts_sinh64(x)/futrts_cosh64(x); }

SCALAR_FUN_ATTR double futrts_acosh64(double x) {
  double f = x+sqrt(x*x-1.0d);
  if(futrts_isfinite64(f)) return log(f);
  return f;
}

SCALAR_FUN_ATTR double futrts_asinh64(double x) {
  double f = x+sqrt(x*x+1.0d);
  if(futrts_isfinite64(f)) return log(f);
  return f;
}

SCALAR_FUN_ATTR double futrts_atanh64(double x) {
  double f = (1.0d+x)/(1.0d-x);
  if(futrts_isfinite64(f)) return log(f)/2.0d;
  return f;
}
SCALAR_FUN_ATTR double futrts_atan2_64(double x, double y) { return atan2(x, y); }

SCALAR_FUN_ATTR double futrts_atan2pi_64(double x, double y) { return atan2(x, y) / M_PI; }

extern "C" unmasked uniform double hypot(uniform double x, uniform double y);
SCALAR_FUN_ATTR double futrts_hypot64(double x, double y) {
  double res;
  foreach_active (i) {
    uniform double r = hypot(extract(x, i), extract(y, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform double tgamma(uniform double x);
SCALAR_FUN_ATTR double futrts_gamma64(double x) {
  double res;
  foreach_active (i) {
    uniform double r = tgamma(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform double lgamma(uniform double x);
SCALAR_FUN_ATTR double futrts_lgamma64(double x) {
  double res;
  foreach_active (i) {
    uniform double r = lgamma(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform double erf(uniform double x);
SCALAR_FUN_ATTR double futrts_erf64(double x) {
  double res;
  foreach_active (i) {
    uniform double r = erf(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform double erfc(uniform double x);
SCALAR_FUN_ATTR double futrts_erfc64(double x) {
  double res;
  foreach_active (i) {
    uniform double r = erfc(extract(x, i));
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR double futrts_fma64(double a, double b, double c) { return a * b + c; }
SCALAR_FUN_ATTR double futrts_round64(double x) { return round(x); }
SCALAR_FUN_ATTR double futrts_ceil64(double x) { return ceil(x); }

extern "C" unmasked uniform double nextafter(uniform float x, uniform double y);
SCALAR_FUN_ATTR double futrts_nextafter64(double x, double y) {
  double res;
  foreach_active (i) {
    uniform double r = nextafter(extract(x, i), extract(y, i));
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR double futrts_floor64(double x) { return floor(x); }
SCALAR_FUN_ATTR bool futrts_isnan64(double x) { return isnan(x); }

SCALAR_FUN_ATTR int8_t fptosi_f64_i8(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int8_t) x;
  }
}

SCALAR_FUN_ATTR int16_t fptosi_f64_i16(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int16_t) x;
  }
}

SCALAR_FUN_ATTR int32_t fptosi_f64_i32(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int32_t) x;
  }
}

SCALAR_FUN_ATTR int64_t fptosi_f64_i64(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int64_t) x;
  }
}

SCALAR_FUN_ATTR uint8_t fptoui_f64_i8(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint8_t) (int8_t) x;
  }
}

SCALAR_FUN_ATTR uint16_t fptoui_f64_i16(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint16_t) (int16_t) x;
  }
}

SCALAR_FUN_ATTR uint32_t fptoui_f64_i32(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint32_t) (int32_t) x;
  }
}

SCALAR_FUN_ATTR uint64_t fptoui_f64_i64(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint64_t) (int64_t) x;
  }
}

SCALAR_FUN_ATTR bool ftob_f64_bool(double x) { return x != 0.0; }
SCALAR_FUN_ATTR double btof_bool_f64(bool x) { return x ? 1.0 : 0.0; }

SCALAR_FUN_ATTR int64_t fptobits_f64_i64(double x) {
  int64_t res;
  foreach_active (i) {
    uniform double tmp = extract(x, i);
    uniform int64_t r = *((uniform int64_t* uniform)&tmp);
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR double bitstofp_i64_f64(int64_t x) {
  double res;
  foreach_active (i) {
    uniform int64_t tmp = extract(x, i);
    uniform double r = *((uniform double* uniform)&tmp);
    res = insert(res, i, r);
  }
  return res;
}

SCALAR_FUN_ATTR uniform int64_t fptobits_f64_i64(uniform double x) {
  return intbits(x);
}

SCALAR_FUN_ATTR uniform double bitstofp_i64_f64(uniform int64_t x) {
  return doublebits(x);
}

SCALAR_FUN_ATTR double fmod64(double x, double y) {
  return x - y * trunc(x/y);
}

SCALAR_FUN_ATTR double fsignum64(double x) {
  return futrts_isnan64(x) ? x : (x > 0 ? 1.0d : 0.0d) - (x < 0 ? 1.0d : 0.0d);
}

SCALAR_FUN_ATTR double futrts_lerp64(double v0, double v1, double t) {
  return v0 + (v1 - v0) * t;
}

SCALAR_FUN_ATTR double futrts_ldexp64(double x, int32_t y) {
  return x * pow((uniform double)2.0, (double)y);
}

SCALAR_FUN_ATTR double futrts_copysign64(double x, double y) {
  int64_t xb = fptobits_f64_i64(x);
  int64_t yb = fptobits_f64_i64(y);
  return bitstofp_i64_f64((xb & ~(((int64_t)1)<<63)) | (yb & (((int64_t)1)<<63)));
}

SCALAR_FUN_ATTR double futrts_mad64(double a, double b, double c) { return a * b + c; }
SCALAR_FUN_ATTR float fpconv_f32_f32(float x) { return (float) x; }
SCALAR_FUN_ATTR double fpconv_f32_f64(float x) { return (double) x; }
SCALAR_FUN_ATTR float fpconv_f64_f32(double x) { return (float) x; }
SCALAR_FUN_ATTR double fpconv_f64_f64(double x) { return (double) x; }

#else

SCALAR_FUN_ATTR double fdiv64(double x, double y) { return x / y; }
SCALAR_FUN_ATTR double fadd64(double x, double y) { return x + y; }
SCALAR_FUN_ATTR double fsub64(double x, double y) { return x - y; }
SCALAR_FUN_ATTR double fmul64(double x, double y) { return x * y; }
SCALAR_FUN_ATTR bool cmplt64(double x, double y) { return x < y; }
SCALAR_FUN_ATTR bool cmple64(double x, double y) { return x <= y; }
SCALAR_FUN_ATTR double sitofp_i8_f64(int8_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i16_f64(int16_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i32_f64(int32_t x) { return (double) x; }
SCALAR_FUN_ATTR double sitofp_i64_f64(int64_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i8_f64(uint8_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i16_f64(uint16_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i32_f64(uint32_t x) { return (double) x; }
SCALAR_FUN_ATTR double uitofp_i64_f64(uint64_t x) { return (double) x; }
SCALAR_FUN_ATTR double fabs64(double x) { return fabs(x); }
SCALAR_FUN_ATTR double fmax64(double x, double y) { return fmax(x, y); }
SCALAR_FUN_ATTR double fmin64(double x, double y) { return fmin(x, y); }
SCALAR_FUN_ATTR double fpow64(double x, double y) { return pow(x, y); }
SCALAR_FUN_ATTR double futrts_log64(double x) { return log(x); }
SCALAR_FUN_ATTR double futrts_log2_64(double x) { return log2(x); }
SCALAR_FUN_ATTR double futrts_log10_64(double x) { return log10(x); }
SCALAR_FUN_ATTR double futrts_log1p_64(double x) { return log1p(x); }
SCALAR_FUN_ATTR double futrts_sqrt64(double x) { return sqrt(x); }
SCALAR_FUN_ATTR double futrts_rsqrt64(double x) { return 1/sqrt(x); }
SCALAR_FUN_ATTR double futrts_cbrt64(double x) { return cbrt(x); }
SCALAR_FUN_ATTR double futrts_exp64(double x) { return exp(x); }
SCALAR_FUN_ATTR double futrts_cos64(double x) { return cos(x); }

SCALAR_FUN_ATTR double futrts_cospi64(double x) {
#ifdef __OPENCL_VERSION__
  return cospi(x);
#elif defined(__CUDA_ARCH__)
  return cospi(x);
#else
  return cos(M_PI*x);
#endif
}

SCALAR_FUN_ATTR double futrts_sin64(double x) {
  return sin(x);
}

SCALAR_FUN_ATTR double futrts_sinpi64(double x) {
#ifdef __OPENCL_VERSION__
  return sinpi(x);
#elif defined(__CUDA_ARCH__)
  return sinpi(x);
#else
  return sin(M_PI*x);
#endif
}

SCALAR_FUN_ATTR double futrts_tan64(double x) {
  return tan(x);
}

SCALAR_FUN_ATTR double futrts_tanpi64(double x) {
#ifdef __OPENCL_VERSION__
  return tanpi(x);
#else
  return tan(M_PI*x);
#endif
}

SCALAR_FUN_ATTR double futrts_acos64(double x) {
  return acos(x);
}

SCALAR_FUN_ATTR double futrts_acospi64(double x) {
#ifdef __OPENCL_VERSION__
  return acospi(x);
#else
  return acos(x) / M_PI;
#endif
}

SCALAR_FUN_ATTR double futrts_asin64(double x) {
  return asin(x);
}

SCALAR_FUN_ATTR double futrts_asinpi64(double x) {
#ifdef __OPENCL_VERSION__
  return asinpi(x);
#else
  return asin(x) / M_PI;
#endif
}

SCALAR_FUN_ATTR double futrts_atan64(double x) {
  return atan(x);
}

SCALAR_FUN_ATTR double futrts_atanpi64(double x) {
#ifdef __OPENCL_VERSION__
  return atanpi(x);
#else
  return atan(x) / M_PI;
#endif
}

SCALAR_FUN_ATTR double futrts_cosh64(double x) { return cosh(x); }
SCALAR_FUN_ATTR double futrts_sinh64(double x) { return sinh(x); }
SCALAR_FUN_ATTR double futrts_tanh64(double x) { return tanh(x); }
SCALAR_FUN_ATTR double futrts_acosh64(double x) { return acosh(x); }
SCALAR_FUN_ATTR double futrts_asinh64(double x) { return asinh(x); }
SCALAR_FUN_ATTR double futrts_atanh64(double x) { return atanh(x); }
SCALAR_FUN_ATTR double futrts_atan2_64(double x, double y) { return atan2(x, y); }

SCALAR_FUN_ATTR double futrts_atan2pi_64(double x, double y) {
#ifdef __OPENCL_VERSION__
  return atan2pi(x, y);
#else
  return atan2(x, y) / M_PI;
#endif
}

SCALAR_FUN_ATTR double futrts_hypot64(double x, double y) { return hypot(x, y); }
SCALAR_FUN_ATTR double futrts_gamma64(double x) { return tgamma(x); }
SCALAR_FUN_ATTR double futrts_lgamma64(double x) { return lgamma(x); }
SCALAR_FUN_ATTR double futrts_erf64(double x) { return erf(x); }
SCALAR_FUN_ATTR double futrts_erfc64(double x) { return erfc(x); }
SCALAR_FUN_ATTR double futrts_fma64(double a, double b, double c) { return fma(a, b, c); }
SCALAR_FUN_ATTR double futrts_round64(double x) { return rint(x); }
SCALAR_FUN_ATTR double futrts_ceil64(double x) { return ceil(x); }
SCALAR_FUN_ATTR double futrts_nextafter64(double x, double y) { return nextafter(x, y); }
SCALAR_FUN_ATTR double futrts_floor64(double x) { return floor(x); }
SCALAR_FUN_ATTR bool futrts_isnan64(double x) { return isnan(x); }
SCALAR_FUN_ATTR bool futrts_isinf64(double x) { return isinf(x); }

SCALAR_FUN_ATTR int8_t fptosi_f64_i8(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int8_t) x;
  }
}

SCALAR_FUN_ATTR int16_t fptosi_f64_i16(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int16_t) x;
  }
}

SCALAR_FUN_ATTR int32_t fptosi_f64_i32(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int32_t) x;
  }
}

SCALAR_FUN_ATTR int64_t fptosi_f64_i64(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (int64_t) x;
  }
}

SCALAR_FUN_ATTR uint8_t fptoui_f64_i8(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint8_t) (int8_t) x;
  }
}

SCALAR_FUN_ATTR uint16_t fptoui_f64_i16(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint16_t) (int16_t) x;
  }
}

SCALAR_FUN_ATTR uint32_t fptoui_f64_i32(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint32_t) (int32_t) x;
  }
}

SCALAR_FUN_ATTR uint64_t fptoui_f64_i64(double x) {
  if (futrts_isnan64(x) || futrts_isinf64(x)) {
    return 0;
  } else {
    return (uint64_t) (int64_t) x;
  }
}

SCALAR_FUN_ATTR bool ftob_f64_bool(double x) { return x != 0; }
SCALAR_FUN_ATTR double btof_bool_f64(bool x) { return x ? 1 : 0; }

SCALAR_FUN_ATTR int64_t fptobits_f64_i64(double x) {
  union {
    double f;
    int64_t t;
  } p;

  p.f = x;
  return p.t;
}

SCALAR_FUN_ATTR double bitstofp_i64_f64(int64_t x) {
  union {
    int64_t f;
    double t;
  } p;

  p.f = x;
  return p.t;
}

SCALAR_FUN_ATTR double fmod64(double x, double y) {
  return fmod(x, y);
}

SCALAR_FUN_ATTR double fsignum64(double x) {
  return futrts_isnan64(x) ? x : (x > 0) - (x < 0);
}

SCALAR_FUN_ATTR double futrts_lerp64(double v0, double v1, double t) {
#ifdef __OPENCL_VERSION__
  return mix(v0, v1, t);
#else
  return v0 + (v1 - v0) * t;
#endif
}

SCALAR_FUN_ATTR double futrts_ldexp64(double x, int32_t y) {
  return ldexp(x, y);
}

SCALAR_FUN_ATTR double futrts_copysign64(double x, double y) {
  return copysign(x, y);
}

SCALAR_FUN_ATTR double futrts_mad64(double a, double b, double c) {
#ifdef __OPENCL_VERSION__
  return mad(a, b, c);
#else
  return a * b + c;
#endif
}

SCALAR_FUN_ATTR float fpconv_f32_f32(float x) { return (float) x; }
SCALAR_FUN_ATTR double fpconv_f32_f64(float x) { return (double) x; }
SCALAR_FUN_ATTR float fpconv_f64_f32(double x) { return (float) x; }
SCALAR_FUN_ATTR double fpconv_f64_f64(double x) { return (double) x; }

#endif

#endif

#define futrts_cond_f16(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_f32(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_f64(x,y,z) ((x) ? (y) : (z))

#define futrts_cond_i8(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_i16(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_i32(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_i64(x,y,z) ((x) ? (y) : (z))

#define futrts_cond_bool(x,y,z) ((x) ? (y) : (z))
#define futrts_cond_unit(x,y,z) ((x) ? (y) : (z))

// End of scalar.h.
// Start of scalar_f16.h.

// Half-precision is emulated if needed (e.g. in straight C) with the
// native type used if possible.  The emulation works by typedef'ing
// 'float' to 'f16', and then implementing all operations on single
// precision.  To cut down on duplication, we use the same code for
// those Futhark functions that require just operators or casts.  The
// in-memory representation for arrays will still be 16 bits even
// under emulation, so the compiler will have to be careful when
// generating reads or writes.

#if !defined(cl_khr_fp16) && !(defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 600) && !(defined(ISPC))
#define EMULATE_F16
#endif

#if !defined(EMULATE_F16) && defined(__OPENCL_VERSION__)
#pragma OPENCL EXTENSION cl_khr_fp16 : enable
#endif

#ifdef EMULATE_F16

// Note that the half-precision storage format is still 16 bits - the
// compiler will have to be real careful!
typedef float f16;

#elif defined(ISPC)
typedef float16 f16;

#else

#ifdef __CUDA_ARCH__
#include <cuda_fp16.h>
#endif

typedef half f16;

#endif

// Some of these functions convert to single precision because half
// precision versions are not available.
SCALAR_FUN_ATTR f16 fadd16(f16 x, f16 y) { return x + y; }
SCALAR_FUN_ATTR f16 fsub16(f16 x, f16 y) { return x - y; }
SCALAR_FUN_ATTR f16 fmul16(f16 x, f16 y) { return x * y; }
SCALAR_FUN_ATTR bool cmplt16(f16 x, f16 y) { return x < y; }
SCALAR_FUN_ATTR bool cmple16(f16 x, f16 y) { return x <= y; }
SCALAR_FUN_ATTR f16 sitofp_i8_f16(int8_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 sitofp_i16_f16(int16_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 sitofp_i32_f16(int32_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 sitofp_i64_f16(int64_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 uitofp_i8_f16(uint8_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 uitofp_i16_f16(uint16_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 uitofp_i32_f16(uint32_t x) { return (f16) x; }
SCALAR_FUN_ATTR f16 uitofp_i64_f16(uint64_t x) { return (f16) x; }
SCALAR_FUN_ATTR int8_t fptosi_f16_i8(f16 x) { return (int8_t) (float) x; }
SCALAR_FUN_ATTR int16_t fptosi_f16_i16(f16 x) { return (int16_t) x; }
SCALAR_FUN_ATTR int32_t fptosi_f16_i32(f16 x) { return (int32_t) x; }
SCALAR_FUN_ATTR int64_t fptosi_f16_i64(f16 x) { return (int64_t) x; }
SCALAR_FUN_ATTR uint8_t fptoui_f16_i8(f16 x) { return (uint8_t) (float) x; }
SCALAR_FUN_ATTR uint16_t fptoui_f16_i16(f16 x) { return (uint16_t) x; }
SCALAR_FUN_ATTR uint32_t fptoui_f16_i32(f16 x) { return (uint32_t) x; }
SCALAR_FUN_ATTR uint64_t fptoui_f16_i64(f16 x) { return (uint64_t) x; }
SCALAR_FUN_ATTR bool ftob_f16_bool(f16 x) { return x != (f16)0; }
SCALAR_FUN_ATTR f16 btof_bool_f16(bool x) { return x ? 1 : 0; }

#ifndef EMULATE_F16

SCALAR_FUN_ATTR bool futrts_isnan16(f16 x) { return isnan((float)x); }

#ifdef __OPENCL_VERSION__

SCALAR_FUN_ATTR f16 fabs16(f16 x) { return fabs(x); }
SCALAR_FUN_ATTR f16 fmax16(f16 x, f16 y) { return fmax(x, y); }
SCALAR_FUN_ATTR f16 fmin16(f16 x, f16 y) { return fmin(x, y); }
SCALAR_FUN_ATTR f16 fpow16(f16 x, f16 y) { return pow(x, y); }

#elif defined(ISPC)

SCALAR_FUN_ATTR f16 fabs16(f16 x) { return abs(x); }
SCALAR_FUN_ATTR f16 fmax16(f16 x, f16 y) { return futrts_isnan16(x) ? y : futrts_isnan16(y) ? x : max(x, y); }
SCALAR_FUN_ATTR f16 fmin16(f16 x, f16 y) { return futrts_isnan16(x) ? y : futrts_isnan16(y) ? x : min(x, y); }
SCALAR_FUN_ATTR f16 fpow16(f16 x, f16 y) { return pow(x, y); }

#else // Assuming CUDA.

SCALAR_FUN_ATTR f16 fabs16(f16 x) { return fabsf(x); }
SCALAR_FUN_ATTR f16 fmax16(f16 x, f16 y) { return fmaxf(x, y); }
SCALAR_FUN_ATTR f16 fmin16(f16 x, f16 y) { return fminf(x, y); }
SCALAR_FUN_ATTR f16 fpow16(f16 x, f16 y) { return powf(x, y); }

#endif

#if defined(ISPC)
SCALAR_FUN_ATTR bool futrts_isinf16(float x) { return !futrts_isnan16(x) && futrts_isnan16(x - x); }
SCALAR_FUN_ATTR bool futrts_isfinite16(float x) { return !futrts_isnan16(x) && !futrts_isinf16(x); }
#else
SCALAR_FUN_ATTR bool futrts_isinf16(f16 x) { return isinf((float)x); }
#endif

#ifdef __OPENCL_VERSION__
SCALAR_FUN_ATTR f16 futrts_log16(f16 x) { return log(x); }
SCALAR_FUN_ATTR f16 futrts_log2_16(f16 x) { return log2(x); }
SCALAR_FUN_ATTR f16 futrts_log10_16(f16 x) { return log10(x); }
SCALAR_FUN_ATTR f16 futrts_log1p_16(f16 x) { return log1p(x); }
SCALAR_FUN_ATTR f16 futrts_sqrt16(f16 x) { return sqrt(x); }
SCALAR_FUN_ATTR f16 futrts_rsqrt16(f16 x) { return rsqrt(x); }
SCALAR_FUN_ATTR f16 futrts_cbrt16(f16 x) { return cbrt(x); }
SCALAR_FUN_ATTR f16 futrts_exp16(f16 x) { return exp(x); }
SCALAR_FUN_ATTR f16 futrts_cos16(f16 x) { return cos(x); }
SCALAR_FUN_ATTR f16 futrts_cospi16(f16 x) { return cospi(x); }
SCALAR_FUN_ATTR f16 futrts_sin16(f16 x) { return sin(x); }
SCALAR_FUN_ATTR f16 futrts_sinpi16(f16 x) { return sinpi(x); }
SCALAR_FUN_ATTR f16 futrts_tan16(f16 x) { return tan(x); }
SCALAR_FUN_ATTR f16 futrts_tanpi16(f16 x) { return tanpi(x); }
SCALAR_FUN_ATTR f16 futrts_acos16(f16 x) { return acos(x); }
SCALAR_FUN_ATTR f16 futrts_acospi16(f16 x) { return acospi(x); }
SCALAR_FUN_ATTR f16 futrts_asin16(f16 x) { return asin(x); }
SCALAR_FUN_ATTR f16 futrts_asinpi16(f16 x) { return asinpi(x); }
SCALAR_FUN_ATTR f16 futrts_atan16(f16 x) { return atan(x); }
SCALAR_FUN_ATTR f16 futrts_atanpi16(f16 x) { return atanpi(x); }
SCALAR_FUN_ATTR f16 futrts_cosh16(f16 x) { return cosh(x); }
SCALAR_FUN_ATTR f16 futrts_sinh16(f16 x) { return sinh(x); }
SCALAR_FUN_ATTR f16 futrts_tanh16(f16 x) { return tanh(x); }
SCALAR_FUN_ATTR f16 futrts_acosh16(f16 x) { return acosh(x); }
SCALAR_FUN_ATTR f16 futrts_asinh16(f16 x) { return asinh(x); }
SCALAR_FUN_ATTR f16 futrts_atanh16(f16 x) { return atanh(x); }
SCALAR_FUN_ATTR f16 futrts_atan2_16(f16 x, f16 y) { return atan2(x, y); }
SCALAR_FUN_ATTR f16 futrts_atan2pi_16(f16 x, f16 y) { return atan2pi(x, y); }
SCALAR_FUN_ATTR f16 futrts_hypot16(f16 x, f16 y) { return hypot(x, y); }
SCALAR_FUN_ATTR f16 futrts_gamma16(f16 x) { return tgamma(x); }
SCALAR_FUN_ATTR f16 futrts_lgamma16(f16 x) { return lgamma(x); }
SCALAR_FUN_ATTR f16 futrts_erf16(f16 x) { return erf(x); }
SCALAR_FUN_ATTR f16 futrts_erfc16(f16 x) { return erfc(x); }
SCALAR_FUN_ATTR f16 fmod16(f16 x, f16 y) { return fmod(x, y); }
SCALAR_FUN_ATTR f16 futrts_round16(f16 x) { return rint(x); }
SCALAR_FUN_ATTR f16 futrts_floor16(f16 x) { return floor(x); }
SCALAR_FUN_ATTR f16 futrts_ceil16(f16 x) { return ceil(x); }
SCALAR_FUN_ATTR f16 futrts_nextafter16(f16 x, f16 y) { return nextafter(x, y); }
SCALAR_FUN_ATTR f16 futrts_lerp16(f16 v0, f16 v1, f16 t) { return mix(v0, v1, t); }
SCALAR_FUN_ATTR f16 futrts_ldexp16(f16 x, int32_t y) { return ldexp(x, y); }
SCALAR_FUN_ATTR f16 futrts_copysign16(f16 x, f16 y) { return copysign(x, y); }
SCALAR_FUN_ATTR f16 futrts_mad16(f16 a, f16 b, f16 c) { return mad(a, b, c); }
SCALAR_FUN_ATTR f16 futrts_fma16(f16 a, f16 b, f16 c) { return fma(a, b, c); }

#elif defined(ISPC)

SCALAR_FUN_ATTR f16 futrts_log16(f16 x) { return futrts_isfinite16(x) || (futrts_isinf16(x) && x < 0) ? log(x) : x; }
SCALAR_FUN_ATTR f16 futrts_log2_16(f16 x) { return futrts_log16(x) / log(2.0f16); }
SCALAR_FUN_ATTR f16 futrts_log10_16(f16 x) { return futrts_log16(x) / log(10.0f16); }
SCALAR_FUN_ATTR f16 futrts_log1p_16(f16 x) {
  if(x == -1.0f16 || (futrts_isinf16(x) && x > 0.0f16)) return x / 0.0f16;
  f16 y = 1.0f16 + x;
  f16 z = y - 1.0f16;
  return log(y) - (z-x)/y;
}
SCALAR_FUN_ATTR f16 futrts_sqrt16(f16 x) { return (float16)sqrt((float)x); }
SCALAR_FUN_ATTR f16 futrts_rsqrt16(f16 x) { return (float16)1/sqrt((float)x); }
SCALAR_FUN_ATTR f16 futrts_exp16(f16 x) { return exp(x); }
SCALAR_FUN_ATTR f16 futrts_cos16(f16 x) { return (float16)cos((float)x); }
SCALAR_FUN_ATTR f16 futrts_cospi16(f16 x) { return (float16)cos((float)M_PI*(float)x); }
SCALAR_FUN_ATTR f16 futrts_sin16(f16 x) { return (float16)sin((float)x); }
SCALAR_FUN_ATTR f16 futrts_sinpi16(f16 x) { return (float16)sin((float)M_PI*(float)x); }
SCALAR_FUN_ATTR f16 futrts_tan16(f16 x) { return (float16)tan((float)x); }
SCALAR_FUN_ATTR f16 futrts_tanpi16(f16 x) { return (float16)(tan((float)M_PI*(float)x)); }
SCALAR_FUN_ATTR f16 futrts_acos16(f16 x) { return (float16)acos((float)x); }
SCALAR_FUN_ATTR f16 futrts_acospi16(f16 x) { return (float16)(acos((float)x)/(float)M_PI); }
SCALAR_FUN_ATTR f16 futrts_asin16(f16 x) { return (float16)asin((float)x); }
SCALAR_FUN_ATTR f16 futrts_asinpi16(f16 x) { return (float16)(asin((float)x)/(float)M_PI); }
SCALAR_FUN_ATTR f16 futrts_atan16(f16 x) { return (float16)atan((float)x); }
SCALAR_FUN_ATTR f16 futrts_atanpi16(f16 x) { return (float16)(atan((float)x)/(float)M_PI); }
SCALAR_FUN_ATTR f16 futrts_cosh16(f16 x) { return (exp(x)+exp(-x)) / 2.0f16; }
SCALAR_FUN_ATTR f16 futrts_sinh16(f16 x) { return (exp(x)-exp(-x)) / 2.0f16; }
SCALAR_FUN_ATTR f16 futrts_tanh16(f16 x) { return futrts_sinh16(x)/futrts_cosh16(x); }
SCALAR_FUN_ATTR f16 futrts_acosh16(f16 x) {
  float16 f = x+(float16)sqrt((float)(x*x-1));
  if(futrts_isfinite16(f)) return log(f);
  return f;
}
SCALAR_FUN_ATTR f16 futrts_asinh16(f16 x) {
  float16 f = x+(float16)sqrt((float)(x*x+1));
  if(futrts_isfinite16(f)) return log(f);
  return f;
}
SCALAR_FUN_ATTR f16 futrts_atanh16(f16 x) {
  float16 f = (1+x)/(1-x);
  if(futrts_isfinite16(f)) return log(f)/2.0f16;
  return f;
}
SCALAR_FUN_ATTR f16 futrts_atan2_16(f16 x, f16 y) { return (float16)atan2((float)x, (float)y); }
SCALAR_FUN_ATTR f16 futrts_atan2pi_16(f16 x, f16 y) { return (float16)(atan2((float)x, (float)y)/(float)M_PI); }
SCALAR_FUN_ATTR f16 futrts_hypot16(f16 x, f16 y) { return (float16)futrts_hypot32((float)x, (float)y); }

extern "C" unmasked uniform float tgammaf(uniform float x);
SCALAR_FUN_ATTR f16 futrts_gamma16(f16 x) {
  f16 res;
  foreach_active (i) {
    uniform f16 r = (f16)tgammaf(extract((float)x, i));
    res = insert(res, i, r);
  }
  return res;
}

extern "C" unmasked uniform float lgammaf(uniform float x);
SCALAR_FUN_ATTR f16 futrts_lgamma16(f16 x) {
  f16 res;
  foreach_active (i) {
    uniform f16 r = (f16)lgammaf(extract((float)x, i));
    res = insert(res, i, r);
  }
  return res;
}
SCALAR_FUN_ATTR f16 futrts_cbrt16(f16 x) { return (f16)futrts_cbrt32((float)x); }
SCALAR_FUN_ATTR f16 futrts_erf16(f16 x) { return (f16)futrts_erf32((float)x); }
SCALAR_FUN_ATTR f16 futrts_erfc16(f16 x) { return (f16)futrts_erfc32((float)x); }
SCALAR_FUN_ATTR f16 fmod16(f16 x, f16 y) { return x - y * (float16)trunc((float) (x/y)); }
SCALAR_FUN_ATTR f16 futrts_round16(f16 x) { return (float16)round((float)x); }
SCALAR_FUN_ATTR f16 futrts_floor16(f16 x) { return (float16)floor((float)x); }
SCALAR_FUN_ATTR f16 futrts_ceil16(f16 x) { return (float16)ceil((float)x); }
SCALAR_FUN_ATTR f16 futrts_nextafter16(f16 x, f16 y) { return (float16)futrts_nextafter32((float)x, (float) y); }
SCALAR_FUN_ATTR f16 futrts_lerp16(f16 v0, f16 v1, f16 t) { return v0 + (v1 - v0) * t; }
SCALAR_FUN_ATTR f16 futrts_ldexp16(f16 x, int32_t y) { return futrts_ldexp32((float)x, y); }
SCALAR_FUN_ATTR f16 futrts_copysign16(f16 x, f16 y) { return futrts_copysign32((float)x, y); }
SCALAR_FUN_ATTR f16 futrts_mad16(f16 a, f16 b, f16 c) { return a * b + c; }
SCALAR_FUN_ATTR f16 futrts_fma16(f16 a, f16 b, f16 c) { return a * b + c; }

#else // Assume CUDA.

SCALAR_FUN_ATTR f16 futrts_log16(f16 x) { return hlog(x); }
SCALAR_FUN_ATTR f16 futrts_log2_16(f16 x) { return hlog2(x); }
SCALAR_FUN_ATTR f16 futrts_log10_16(f16 x) { return hlog10(x); }
SCALAR_FUN_ATTR f16 futrts_log1p_16(f16 x) { return (f16)log1pf((float)x); }
SCALAR_FUN_ATTR f16 futrts_sqrt16(f16 x) { return hsqrt(x); }
SCALAR_FUN_ATTR f16 futrts_rsqrt16(f16 x) { return hrsqrt(x); }
SCALAR_FUN_ATTR f16 futrts_cbrt16(f16 x) { return cbrtf(x); }
SCALAR_FUN_ATTR f16 futrts_exp16(f16 x) { return hexp(x); }
SCALAR_FUN_ATTR f16 futrts_cos16(f16 x) { return hcos(x); }
SCALAR_FUN_ATTR f16 futrts_cospi16(f16 x) { return hcos((f16)M_PI*x); }
SCALAR_FUN_ATTR f16 futrts_sin16(f16 x) { return hsin(x); }
SCALAR_FUN_ATTR f16 futrts_sinpi16(f16 x) { return hsin((f16)M_PI*x); }
SCALAR_FUN_ATTR f16 futrts_tan16(f16 x) { return tanf(x); }
SCALAR_FUN_ATTR f16 futrts_tanpi16(f16 x) { return tanf((f16)M_PI*x); }
SCALAR_FUN_ATTR f16 futrts_acos16(f16 x) { return acosf(x); }
SCALAR_FUN_ATTR f16 futrts_acospi16(f16 x) { return (f16)acosf(x)/(f16)M_PI; }
SCALAR_FUN_ATTR f16 futrts_asin16(f16 x) { return asinf(x); }
SCALAR_FUN_ATTR f16 futrts_asinpi16(f16 x) { return (f16)asinf(x)/(f16)M_PI; }
SCALAR_FUN_ATTR f16 futrts_atan16(f16 x) { return (f16)atanf(x); }
SCALAR_FUN_ATTR f16 futrts_atanpi16(f16 x) { return (f16)atanf(x)/(f16)M_PI; }
SCALAR_FUN_ATTR f16 futrts_cosh16(f16 x) { return coshf(x); }
SCALAR_FUN_ATTR f16 futrts_sinh16(f16 x) { return sinhf(x); }
SCALAR_FUN_ATTR f16 futrts_tanh16(f16 x) { return tanhf(x); }
SCALAR_FUN_ATTR f16 futrts_acosh16(f16 x) { return acoshf(x); }
SCALAR_FUN_ATTR f16 futrts_asinh16(f16 x) { return asinhf(x); }
SCALAR_FUN_ATTR f16 futrts_atanh16(f16 x) { return atanhf(x); }
SCALAR_FUN_ATTR f16 futrts_atan2_16(f16 x, f16 y) { return (f16)atan2f(x, y); }
SCALAR_FUN_ATTR f16 futrts_atan2pi_16(f16 x, f16 y) { return (f16)atan2f(x, y)/(f16)M_PI; }
SCALAR_FUN_ATTR f16 futrts_hypot16(f16 x, f16 y) { return hypotf(x, y); }
SCALAR_FUN_ATTR f16 futrts_gamma16(f16 x) { return tgammaf(x); }
SCALAR_FUN_ATTR f16 futrts_lgamma16(f16 x) { return lgammaf(x); }
SCALAR_FUN_ATTR f16 futrts_erf16(f16 x) { return erff(x); }
SCALAR_FUN_ATTR f16 futrts_erfc16(f16 x) { return erfcf(x); }
SCALAR_FUN_ATTR f16 fmod16(f16 x, f16 y) { return fmodf(x, y); }
SCALAR_FUN_ATTR f16 futrts_round16(f16 x) { return rintf(x); }
SCALAR_FUN_ATTR f16 futrts_floor16(f16 x) { return hfloor(x); }
SCALAR_FUN_ATTR f16 futrts_ceil16(f16 x) { return hceil(x); }
SCALAR_FUN_ATTR f16 futrts_nextafter16(f16 x, f16 y) { return __ushort_as_half(halfbitsnextafter(__half_as_ushort(x), __half_as_ushort(y))); }
SCALAR_FUN_ATTR f16 futrts_lerp16(f16 v0, f16 v1, f16 t) { return v0 + (v1 - v0) * t; }
SCALAR_FUN_ATTR f16 futrts_ldexp16(f16 x, int32_t y) { return futrts_ldexp32((float)x, y); }
SCALAR_FUN_ATTR f16 futrts_copysign16(f16 x, f16 y) { return futrts_copysign32((float)x, y); }
SCALAR_FUN_ATTR f16 futrts_mad16(f16 a, f16 b, f16 c) { return a * b + c; }
SCALAR_FUN_ATTR f16 futrts_fma16(f16 a, f16 b, f16 c) { return fmaf(a, b, c); }

#endif

// The CUDA __half type cannot be put in unions for some reason, so we
// use bespoke conversion functions instead.
#ifdef __CUDA_ARCH__
SCALAR_FUN_ATTR int16_t fptobits_f16_i16(f16 x) { return __half_as_ushort(x); }
SCALAR_FUN_ATTR f16 bitstofp_i16_f16(int16_t x) { return __ushort_as_half(x); }
#elif defined(ISPC)
SCALAR_FUN_ATTR int16_t fptobits_f16_i16(f16 x) { varying int16_t y = *((varying int16_t * uniform)&x); return y;
}
SCALAR_FUN_ATTR f16 bitstofp_i16_f16(int16_t x) { varying f16 y = *((varying f16 * uniform)&x); return y; }
#else
SCALAR_FUN_ATTR int16_t fptobits_f16_i16(f16 x) {
  union {
    f16 f;
    int16_t t;
  } p;

  p.f = x;
  return p.t;
}

SCALAR_FUN_ATTR f16 bitstofp_i16_f16(int16_t x) {
  union {
    int16_t f;
    f16 t;
  } p;

  p.f = x;
  return p.t;
}
#endif

#else // No native f16 - emulate.

SCALAR_FUN_ATTR f16 fabs16(f16 x) { return fabs32(x); }
SCALAR_FUN_ATTR f16 fmax16(f16 x, f16 y) { return fmax32(x, y); }
SCALAR_FUN_ATTR f16 fmin16(f16 x, f16 y) { return fmin32(x, y); }
SCALAR_FUN_ATTR f16 fpow16(f16 x, f16 y) { return fpow32(x, y); }
SCALAR_FUN_ATTR bool futrts_isnan16(f16 x) { return futrts_isnan32(x); }
SCALAR_FUN_ATTR bool futrts_isinf16(f16 x) { return futrts_isinf32(x); }
SCALAR_FUN_ATTR f16 futrts_log16(f16 x) { return futrts_log32(x); }
SCALAR_FUN_ATTR f16 futrts_log2_16(f16 x) { return futrts_log2_32(x); }
SCALAR_FUN_ATTR f16 futrts_log10_16(f16 x) { return futrts_log10_32(x); }
SCALAR_FUN_ATTR f16 futrts_log1p_16(f16 x) { return futrts_log1p_32(x); }
SCALAR_FUN_ATTR f16 futrts_sqrt16(f16 x) { return futrts_sqrt32(x); }
SCALAR_FUN_ATTR f16 futrts_rsqrt16(f16 x) { return futrts_rsqrt32(x); }
SCALAR_FUN_ATTR f16 futrts_cbrt16(f16 x) { return futrts_cbrt32(x); }
SCALAR_FUN_ATTR f16 futrts_exp16(f16 x) { return futrts_exp32(x); }
SCALAR_FUN_ATTR f16 futrts_cos16(f16 x) { return futrts_cos32(x); }
SCALAR_FUN_ATTR f16 futrts_cospi16(f16 x) { return futrts_cospi32(x); }
SCALAR_FUN_ATTR f16 futrts_sin16(f16 x) { return futrts_sin32(x); }
SCALAR_FUN_ATTR f16 futrts_sinpi16(f16 x) { return futrts_sinpi32(x); }
SCALAR_FUN_ATTR f16 futrts_tan16(f16 x) { return futrts_tan32(x); }
SCALAR_FUN_ATTR f16 futrts_tanpi16(f16 x) { return futrts_tanpi32(x); }
SCALAR_FUN_ATTR f16 futrts_acos16(f16 x) { return futrts_acos32(x); }
SCALAR_FUN_ATTR f16 futrts_acospi16(f16 x) { return futrts_acospi32(x); }
SCALAR_FUN_ATTR f16 futrts_asin16(f16 x) { return futrts_asin32(x); }
SCALAR_FUN_ATTR f16 futrts_asinpi16(f16 x) { return futrts_asinpi32(x); }
SCALAR_FUN_ATTR f16 futrts_atan16(f16 x) { return futrts_atan32(x); }
SCALAR_FUN_ATTR f16 futrts_atanpi16(f16 x) { return futrts_atanpi32(x); }
SCALAR_FUN_ATTR f16 futrts_cosh16(f16 x) { return futrts_cosh32(x); }
SCALAR_FUN_ATTR f16 futrts_sinh16(f16 x) { return futrts_sinh32(x); }
SCALAR_FUN_ATTR f16 futrts_tanh16(f16 x) { return futrts_tanh32(x); }
SCALAR_FUN_ATTR f16 futrts_acosh16(f16 x) { return futrts_acosh32(x); }
SCALAR_FUN_ATTR f16 futrts_asinh16(f16 x) { return futrts_asinh32(x); }
SCALAR_FUN_ATTR f16 futrts_atanh16(f16 x) { return futrts_atanh32(x); }
SCALAR_FUN_ATTR f16 futrts_atan2_16(f16 x, f16 y) { return futrts_atan2_32(x, y); }
SCALAR_FUN_ATTR f16 futrts_atan2pi_16(f16 x, f16 y) { return futrts_atan2pi_32(x, y); }
SCALAR_FUN_ATTR f16 futrts_hypot16(f16 x, f16 y) { return futrts_hypot32(x, y); }
SCALAR_FUN_ATTR f16 futrts_gamma16(f16 x) { return futrts_gamma32(x); }
SCALAR_FUN_ATTR f16 futrts_lgamma16(f16 x) { return futrts_lgamma32(x); }
SCALAR_FUN_ATTR f16 futrts_erf16(f16 x) { return futrts_erf32(x); }
SCALAR_FUN_ATTR f16 futrts_erfc16(f16 x) { return futrts_erfc32(x); }
SCALAR_FUN_ATTR f16 fmod16(f16 x, f16 y) { return fmod32(x, y); }
SCALAR_FUN_ATTR f16 futrts_round16(f16 x) { return futrts_round32(x); }
SCALAR_FUN_ATTR f16 futrts_floor16(f16 x) { return futrts_floor32(x); }
SCALAR_FUN_ATTR f16 futrts_ceil16(f16 x) { return futrts_ceil32(x); }
SCALAR_FUN_ATTR f16 futrts_nextafter16(f16 x, f16 y) { return halfbits2float(halfbitsnextafter(float2halfbits(x), float2halfbits(y))); }
SCALAR_FUN_ATTR f16 futrts_lerp16(f16 v0, f16 v1, f16 t) { return futrts_lerp32(v0, v1, t); }
SCALAR_FUN_ATTR f16 futrts_ldexp16(f16 x, int32_t y) { return futrts_ldexp32(x, y); }
SCALAR_FUN_ATTR f16 futrts_copysign16(f16 x, f16 y) { return futrts_copysign32((float)x, y); }
SCALAR_FUN_ATTR f16 futrts_mad16(f16 a, f16 b, f16 c) { return futrts_mad32(a, b, c); }
SCALAR_FUN_ATTR f16 futrts_fma16(f16 a, f16 b, f16 c) { return futrts_fma32(a, b, c); }

// Even when we are using an OpenCL that does not support cl_khr_fp16,
// it must still support vload_half for actually creating a
// half-precision number, which can then be efficiently converted to a
// float.  Similarly for vstore_half.
#ifdef __OPENCL_VERSION__

SCALAR_FUN_ATTR int16_t fptobits_f16_i16(f16 x) {
  int16_t y;
  // Violating strict aliasing here.
  vstore_half((float)x, 0, (half*)&y);
  return y;
}

SCALAR_FUN_ATTR f16 bitstofp_i16_f16(int16_t x) {
  return (f16)vload_half(0, (half*)&x);
}

#else
SCALAR_FUN_ATTR int16_t fptobits_f16_i16(f16 x) { return (int16_t)float2halfbits(x); }
SCALAR_FUN_ATTR f16 bitstofp_i16_f16(int16_t x) { return halfbits2float((uint16_t)x); }
SCALAR_FUN_ATTR f16 fsignum16(f16 x) { return futrts_isnan16(x) ? x : (x > 0 ? 1 : 0) - (x < 0 ? 1 : 0); }

#endif

#endif

SCALAR_FUN_ATTR float fpconv_f16_f16(f16 x) { return x; }
SCALAR_FUN_ATTR float fpconv_f16_f32(f16 x) { return x; }
SCALAR_FUN_ATTR f16 fpconv_f32_f16(float x) { return (f16) x; }

#ifdef FUTHARK_F64_ENABLED
SCALAR_FUN_ATTR double fpconv_f16_f64(f16 x) { return (double) x; }
#if defined(ISPC)
SCALAR_FUN_ATTR f16 fpconv_f64_f16(double x) { return (f16) ((float)x); }
#else
SCALAR_FUN_ATTR f16 fpconv_f64_f16(double x) { return (f16) x; }
#endif
#endif

// End of scalar_f16.h.

// Start of context_prototypes.h
//
// Prototypes for the functions in context.h, or that will be called
// from those functions, that need to be available very early.

struct futhark_context_config;
struct futhark_context;

struct tuning_param {
  const char *name;
  const char *var; // Z-encoded name.
  const char *class;
  bool set;
  int64_t val;
};

static void set_error(struct futhark_context* ctx, char *error);

// These are called in context/config new/free functions and contain
// shared setup.  They are generated by the compiler itself.
static int init_constants(struct futhark_context*);
static int free_constants(struct futhark_context*);
static void setup_program(struct futhark_context* ctx);
static void teardown_program(struct futhark_context *ctx);

// Allocate host memory.  Must be freed with host_free().
static void host_alloc(struct futhark_context* ctx, size_t size, const char* tag, size_t* size_out, void** mem_out);
// Allocate memory allocated with host_alloc().
static void host_free(struct futhark_context* ctx, size_t size, const char* tag, void* mem);

// Log that a copy has occurred. The provenance may be NULL, if we do not know
// where this came from.
static void log_copy(struct futhark_context* ctx,
                     const char *kind, const char *provenance,
                     int r,
                     int64_t dst_offset, int64_t dst_strides[r],
                     int64_t src_offset, int64_t src_strides[r],
                     int64_t shape[r]);

static void log_transpose(struct futhark_context* ctx,
                          int64_t k, int64_t m, int64_t n);

static bool lmad_map_tr(int64_t *num_arrays_out, int64_t *n_out, int64_t *m_out,
                        int r,
                        const int64_t dst_strides[r],
                        const int64_t src_strides[r],
                        const int64_t shape[r]);

static bool lmad_contiguous(int r, int64_t strides[r], int64_t shape[r]);

static bool lmad_memcpyable(int r,
                            int64_t dst_strides[r], int64_t src_strides[r], int64_t shape[r]);

static void add_event(struct futhark_context* ctx,
                      const char* name,
                      const char* provenance,
                      struct kvs *kvs,
                      void* data,
                      event_report_fn f);

// Functions that must be defined by the backend.
static void backend_context_config_setup(struct futhark_context_config* cfg);
static void backend_context_config_teardown(struct futhark_context_config* cfg);
static int backend_context_setup(struct futhark_context *ctx);
static void backend_context_teardown(struct futhark_context *ctx);

// End of of context_prototypes.h

struct memblock {
    int *references;
    unsigned char *mem;
    int64_t size;
    const char *desc;
};
struct constants {
    int dummy;
    bool defunc_0_reduce_res_32880;
};
#define NUM_TUNING_PARAMS 0
static const char *tuning_param_names[] = {NULL};
static const char *tuning_param_vars[] = {NULL};
static const char *tuning_param_classes[] = {NULL};
static int64_t tuning_param_defaults[] = {0};
static const struct {
                 int dummy;
             } tuning_param_indexes = {0};
// Start of backends/c.h

struct futhark_context_config {
  int in_use;
  int debugging;
  int profiling;
  int logging;
  char *cache_fname;
  struct tuning_param tuning_params[NUM_TUNING_PARAMS];
};

static void backend_context_config_setup(struct futhark_context_config* cfg) {
  (void)cfg;
}

static void backend_context_config_teardown(struct futhark_context_config* cfg) {
  (void)cfg;
}

int futhark_context_config_set_tuning_param(struct futhark_context_config *cfg,
                                            const char *param_name,
                                            size_t new_value) {
  for (int i = 0; i < NUM_TUNING_PARAMS; i++) {
    if (strcmp(param_name, cfg->tuning_params[i].name) == 0) {
      cfg->tuning_params[i].val = new_value;
      cfg->tuning_params[i].set = true;
      return 0;
    }
  }

  return 1;
}

struct futhark_context {
  struct futhark_context_config* cfg;
  int detail_memory;
  int debugging;
  int profiling;
  int profiling_paused;
  int logging;
  lock_t lock;
  char *error;
  lock_t error_lock;
  FILE *log;
  struct constants *constants;
  struct free_list free_list;
  struct event_list event_list;
  int64_t peak_mem_usage_default;
  int64_t cur_mem_usage_default;
  struct program* program;
  bool program_initialised;
};

int backend_context_setup(struct futhark_context* ctx) {
  (void)ctx;
  return 0;
}

void backend_context_teardown(struct futhark_context* ctx) {
  (void)ctx;
}

int futhark_context_sync(struct futhark_context* ctx) {
  (void)ctx;
  return 0;
}

// End of backends/c.h

struct program {
    int dummy;
};
static void setup_program(struct futhark_context *ctx)
{
    (void) ctx;
    
    int error = 0;
    
    (void) error;
    ctx->program = malloc(sizeof(struct program));
}
static void teardown_program(struct futhark_context *ctx)
{
    (void) ctx;
    
    int error = 0;
    
    (void) error;
    free(ctx->program);
}
int memblock_unref(struct futhark_context *ctx, struct memblock *block, const char *desc)
{
    if (block->references != NULL) {
        *block->references -= 1;
        if (ctx->detail_memory)
            fprintf(ctx->log, "Unreferencing block %s (allocated as %s) in %s: %d references remaining.\n", desc, block->desc, "default space", *block->references);
        if (*block->references == 0) {
            ctx->cur_mem_usage_default -= block->size;
            host_free(ctx, (size_t) block->size, desc, (void *) block->mem);
            free(block->references);
            if (ctx->detail_memory)
                fprintf(ctx->log, "%lld bytes freed (now allocated: %lld bytes)\n", (long long) block->size, (long long) ctx->cur_mem_usage_default);
        }
        block->references = NULL;
    }
    return 0;
}
int memblock_alloc(struct futhark_context *ctx, struct memblock *block, int64_t size, const char *desc)
{
    if (size < 0)
        futhark_panic(1, "Negative allocation of %lld bytes attempted for %s in %s.\n", (long long) size, desc, "default space", ctx->cur_mem_usage_default);
    
    int ret = memblock_unref(ctx, block, desc);
    
    if (ret != FUTHARK_SUCCESS)
        return ret;
    if (ctx->detail_memory)
        fprintf(ctx->log, "Allocating %lld bytes for %s in %s (currently allocated: %lld bytes).\n", (long long) size, desc, "default space", (long long) ctx->cur_mem_usage_default);
    host_alloc(ctx, (size_t) size, desc, (size_t *) &size, (void *) &block->mem);
    if (ctx->error == NULL) {
        block->references = (int *) malloc(sizeof(int));
        *block->references = 1;
        block->size = size;
        block->desc = desc;
        
        long long new_usage = ctx->cur_mem_usage_default + size;
        
        if (ctx->detail_memory)
            fprintf(ctx->log, "Received block of %lld bytes; now allocated: %lld bytes", (long long) block->size, new_usage);
        ctx->cur_mem_usage_default = new_usage;
        if (new_usage > ctx->peak_mem_usage_default) {
            ctx->peak_mem_usage_default = new_usage;
            if (ctx->detail_memory)
                fprintf(ctx->log, " (new peak).\n");
        } else if (ctx->detail_memory)
            fprintf(ctx->log, ".\n");
        return FUTHARK_SUCCESS;
    } else {
        // We are naively assuming that any memory allocation error is due to OOM.
        lock_lock(&ctx->error_lock);
        
        char *old_error = ctx->error;
        
        ctx->error = msgprintf("Failed to allocate memory in %s.\nAttempted allocation: %12lld bytes\nCurrently allocated:  %12lld bytes\n%s", "default space", (long long) size, (long long) ctx->cur_mem_usage_default, old_error);
        free(old_error);
        lock_unlock(&ctx->error_lock);
        return FUTHARK_OUT_OF_MEMORY;
    }
}
int memblock_set(struct futhark_context *ctx, struct memblock *lhs, struct memblock *rhs, const char *lhs_desc)
{
    int ret = memblock_unref(ctx, lhs, lhs_desc);
    
    if (rhs->references != NULL)
        (*rhs->references)++;
    *lhs = *rhs;
    return ret;
}
char *futhark_context_report(struct futhark_context *ctx)
{
    if (futhark_context_sync(ctx) != 0)
        return NULL;
    
    struct str_builder builder;
    
    str_builder_init(&builder);
    str_builder_char(&builder, '{');
    str_builder_str(&builder, "\"memory\":{");
    str_builder(&builder, "\"default space\": %lld", (long long) ctx->peak_mem_usage_default);
    str_builder_str(&builder, "},\"events\":[");
    if (report_events_in_list(&ctx->event_list, &builder) != 0) {
        free(builder.str);
        return NULL;
    } else {
        str_builder_str(&builder, "]}");
        return builder.str;
    }
}
int futhark_context_clear_caches(struct futhark_context *ctx)
{
    lock_lock(&ctx->lock);
    ctx->peak_mem_usage_default = 0;
    lock_unlock(&ctx->lock);
    return ctx->error != NULL;
}

// Start of context.h

// Internal functions.

static void set_error(struct futhark_context* ctx, char *error) {
  lock_lock(&ctx->error_lock);
  if (ctx->error == NULL) {
    ctx->error = error;
  } else {
    free(error);
  }
  lock_unlock(&ctx->error_lock);
}

// XXX: should be static, but used in ispc_util.h
void lexical_realloc_error(struct futhark_context* ctx, size_t new_size) {
  set_error(ctx,
            msgprintf("Failed to allocate memory.\nAttempted allocation: %12lld bytes\n",
                      (long long) new_size));
}

static int lexical_realloc(struct futhark_context *ctx,
                           unsigned char **ptr,
                           int64_t *old_size,
                           int64_t new_size) {
  unsigned char *new = realloc(*ptr, (size_t)new_size);
  if (new == NULL) {
    lexical_realloc_error(ctx, new_size);
    return FUTHARK_OUT_OF_MEMORY;
  } else {
    *ptr = new;
    *old_size = new_size;
    return FUTHARK_SUCCESS;
  }
}

static void free_all_in_free_list(struct futhark_context* ctx) {
  fl_mem mem;
  free_list_pack(&ctx->free_list);
  while (free_list_first(&ctx->free_list, (fl_mem*)&mem) == 0) {
    free((void*)mem);
  }
}

static int is_small_alloc(size_t size) {
  return size < 1024*1024;
}

static void host_alloc(struct futhark_context* ctx,
                       size_t size, const char* tag, size_t* size_out, void** mem_out) {
  if (is_small_alloc(size) || free_list_find(&ctx->free_list, size, tag, size_out, (fl_mem*)mem_out) != 0) {
    *size_out = size;
    *mem_out = malloc(size);
  }
}

static void host_free(struct futhark_context* ctx,
                      size_t size, const char* tag, void* mem) {
  // Small allocations are handled by malloc()s own free list.  The
  // threshold here is kind of arbitrary, but seems to work OK.
  // Larger allocations are mmap()ed/munmapped() every time, which is
  // very slow, and Futhark programs tend to use a few very large
  // allocations.
  if (is_small_alloc(size)) {
    free(mem);
  } else {
    free_list_insert(&ctx->free_list, size, (fl_mem)mem, tag);
  }
}

static void add_event(struct futhark_context* ctx,
                      const char* name,
                      const char* provenance,
                      struct kvs *kvs,
                      void* data,
                      event_report_fn f) {
  if (provenance == NULL) {
    provenance = "unknown";
  }
  if (ctx->logging) {
    fprintf(ctx->log, "Event: %s\n  at: %s\n", name, provenance);
    if (kvs) {
      kvs_log(kvs, "  ", ctx->log);
    }
  }
  add_event_to_list(&ctx->event_list, name, provenance, kvs, data, f);
}

char *futhark_context_get_error(struct futhark_context *ctx) {
  char *error = ctx->error;
  ctx->error = NULL;
  return error;
}

void futhark_context_config_set_debugging(struct futhark_context_config *cfg, int flag) {
    cfg->profiling = cfg->logging = cfg->debugging = flag;
}

void futhark_context_config_set_profiling(struct futhark_context_config *cfg, int flag) {
    cfg->profiling = flag;
}

void futhark_context_config_set_logging(struct futhark_context_config *cfg, int flag) {
    cfg->logging = flag;
}

void futhark_context_config_set_cache_file(struct futhark_context_config *cfg, const char *f) {
  cfg->cache_fname = strdup(f);
}

int futhark_get_tuning_param_count(void) {
  return NUM_TUNING_PARAMS;
}

const char *futhark_get_tuning_param_name(int i) {
  return tuning_param_names[i];
}

const char *futhark_get_tuning_param_class(int i) {
    return tuning_param_classes[i];
}

void futhark_context_set_logging_file(struct futhark_context *ctx, FILE *f){
  ctx->log = f;
}

void futhark_context_pause_profiling(struct futhark_context *ctx) {
  ctx->profiling_paused = 1;
}

void futhark_context_unpause_profiling(struct futhark_context *ctx) {
  ctx->profiling_paused = 0;
}

struct futhark_context_config* futhark_context_config_new(void) {
  struct futhark_context_config* cfg = malloc(sizeof(struct futhark_context_config));
  if (cfg == NULL) {
    return NULL;
  }
  cfg->in_use = 0;
  cfg->debugging = 0;
  cfg->profiling = 0;
  cfg->logging = 0;
  cfg->cache_fname = NULL;
  for (int i = 0; i < NUM_TUNING_PARAMS; i++) {
    cfg->tuning_params[i].set = false;
    cfg->tuning_params[i].val = tuning_param_defaults[i];
    cfg->tuning_params[i].name = tuning_param_names[i];
    cfg->tuning_params[i].var = tuning_param_vars[i];
    cfg->tuning_params[i].class = tuning_param_classes[i];
  }
  backend_context_config_setup(cfg);
  return cfg;
}

void futhark_context_config_free(struct futhark_context_config* cfg) {
  assert(!cfg->in_use);
  backend_context_config_teardown(cfg);
  free(cfg->cache_fname);
  free(cfg);
}

struct futhark_context* futhark_context_new(struct futhark_context_config* cfg) {
  struct futhark_context* ctx = malloc(sizeof(struct futhark_context));
  if (ctx == NULL) {
    return NULL;
  }
  assert(!cfg->in_use);
  ctx->cfg = cfg;
  ctx->cfg->in_use = 1;
  ctx->program_initialised = false;
  create_lock(&ctx->error_lock);
  create_lock(&ctx->lock);
  free_list_init(&ctx->free_list);
  event_list_init(&ctx->event_list);
  ctx->peak_mem_usage_default = 0;
  ctx->cur_mem_usage_default = 0;
  ctx->constants = malloc(sizeof(struct constants));
  ctx->debugging = cfg->debugging;
  ctx->logging = cfg->logging;
  ctx->detail_memory = cfg->logging;
  ctx->profiling = cfg->profiling;
  ctx->profiling_paused = 0;
  ctx->error = NULL;
  ctx->log = stderr;
  if (backend_context_setup(ctx) == 0) {
    setup_program(ctx);
    init_constants(ctx);
    ctx->program_initialised = true;
    (void)futhark_context_clear_caches(ctx);
    (void)futhark_context_sync(ctx);
  }
  return ctx;
}

void futhark_context_free(struct futhark_context* ctx) {
  if (ctx->program_initialised) {
    free_constants(ctx);
    teardown_program(ctx);
  }
  backend_context_teardown(ctx);
  free_all_in_free_list(ctx);
  free_list_destroy(&ctx->free_list);
  event_list_free(&ctx->event_list);
  free(ctx->constants);
  free(ctx->error);
  free_lock(&ctx->lock);
  free_lock(&ctx->error_lock);
  ctx->cfg->in_use = 0;
  free(ctx);
}

// End of context.h

// Start of copy.h

// Cache-oblivious map-transpose function.
#define GEN_MAP_TRANSPOSE(NAME, ELEM_TYPE)                              \
  static void map_transpose_##NAME                                      \
  (ELEM_TYPE* dst, ELEM_TYPE* src,                                      \
   int64_t k, int64_t m, int64_t n,                                     \
   int64_t cb, int64_t ce, int64_t rb, int64_t re)                      \
  {                                                                     \
  int32_t r = re - rb;                                                  \
  int32_t c = ce - cb;                                                  \
  if (k == 1) {                                                         \
    if (r <= 64 && c <= 64) {                                           \
      for (int64_t j = 0; j < c; j++) {                                 \
        for (int64_t i = 0; i < r; i++) {                               \
          dst[(j + cb) * n + (i + rb)] = src[(i + rb) * m + (j + cb)];  \
        }                                                               \
      }                                                                 \
    } else if (c <= r) {                                                \
      map_transpose_##NAME(dst, src, k, m, n, cb, ce, rb, rb + r/2);    \
      map_transpose_##NAME(dst, src, k, m, n, cb, ce, rb + r/2, re);    \
    } else {                                                            \
      map_transpose_##NAME(dst, src, k, m, n, cb, cb + c/2, rb, re);    \
      map_transpose_##NAME(dst, src, k, m, n, cb + c/2, ce, rb, re);    \
    }                                                                   \
  } else {                                                              \
  for (int64_t i = 0; i < k; i++) {                                     \
    map_transpose_##NAME(dst + i * m * n, src + i * m * n, 1, m, n, cb, ce, rb, re); \
  }\
} \
}

// Straightforward LMAD copy function.
#define GEN_LMAD_COPY_ELEMENTS(NAME, ELEM_TYPE)                         \
  static void lmad_copy_elements_##NAME(int r,                          \
                                        ELEM_TYPE* dst, int64_t dst_strides[r], \
                                        ELEM_TYPE *src, int64_t src_strides[r], \
                                        int64_t shape[r]) {             \
    if (r == 1) {                                                       \
      for (int i = 0; i < shape[0]; i++) {                              \
        dst[i*dst_strides[0]] = src[i*src_strides[0]];                  \
      }                                                                 \
    } else if (r > 1) {                                                 \
      for (int i = 0; i < shape[0]; i++) {                              \
        lmad_copy_elements_##NAME(r-1,                                  \
                                  dst+i*dst_strides[0], dst_strides+1,  \
                                  src+i*src_strides[0], src_strides+1,  \
                                  shape+1);                             \
      }                                                                 \
    }                                                                   \
  }                                                                     \

// Check whether this LMAD can be seen as a transposed 2D array.  This
// is done by checking every possible splitting point.
static bool lmad_is_tr(int64_t *n_out, int64_t *m_out,
                       int r,
                       const int64_t strides[r],
                       const int64_t shape[r]) {
  for (int i = 1; i < r; i++) {
    int n = 1, m = 1;
    bool ok = true;
    int64_t expected = 1;
    // Check strides before 'i'.
    for (int j = i-1; j >= 0; j--) {
      ok = ok && strides[j] == expected;
      expected *= shape[j];
      n *= shape[j];
    }
    // Check strides after 'i'.
    for (int j = r-1; j >= i; j--) {
      ok = ok && strides[j] == expected;
      expected *= shape[j];
      m *= shape[j];
    }
    if (ok) {
      *n_out = n;
      *m_out = m;
      return true;
    }
  }
  return false;
}

// This function determines whether the a 'dst' LMAD is row-major and
// 'src' LMAD is column-major.  Both LMADs are for arrays of the same
// shape.  Both LMADs are allowed to have additional dimensions "on
// top".  Essentially, this function determines whether a copy from
// 'src' to 'dst' is a "map(transpose)" that we know how to implement
// efficiently.  The LMADs can have arbitrary rank, and the main
// challenge here is checking whether the src LMAD actually
// corresponds to a 2D column-major layout by morally collapsing
// dimensions.  There is a lot of looping here, but the actual trip
// count is going to be very low in practice.
//
// Returns true if this is indeed a map(transpose), and writes the
// number of arrays, and moral array size to appropriate output
// parameters.
static bool lmad_map_tr(int64_t *num_arrays_out, int64_t *n_out, int64_t *m_out,
                        int r,
                        const int64_t dst_strides[r],
                        const int64_t src_strides[r],
                        const int64_t shape[r]) {
  int64_t rowmajor_strides[r];
  rowmajor_strides[r-1] = 1;

  for (int i = r-2; i >= 0; i--) {
    rowmajor_strides[i] = rowmajor_strides[i+1] * shape[i+1];
  }

  // map_r will be the number of mapped dimensions on top.
  int map_r = 0;
  int64_t num_arrays = 1;
  for (int i = 0; i < r; i++) {
    if (dst_strides[i] != rowmajor_strides[i] ||
        src_strides[i] != rowmajor_strides[i]) {
      break;
    } else {
      num_arrays *= shape[i];
      map_r++;
    }
  }

  *num_arrays_out = num_arrays;

  if (r==map_r) {
    return false;
  }

  if (memcmp(&rowmajor_strides[map_r],
             &dst_strides[map_r],
             sizeof(int64_t)*(r-map_r)) == 0) {
    return lmad_is_tr(n_out, m_out, r-map_r, src_strides+map_r, shape+map_r);
  } else if (memcmp(&rowmajor_strides[map_r],
                    &src_strides[map_r],
                    sizeof(int64_t)*(r-map_r)) == 0) {
    return lmad_is_tr(m_out, n_out, r-map_r, dst_strides+map_r, shape+map_r);
  }
  return false;
}

// Check if the strides correspond to row-major strides of *any*
// permutation of the shape.  This is done by recursive search with
// backtracking.  This is worst-case exponential, but hopefully the
// arrays we encounter do not have that many dimensions.
static bool lmad_contiguous_search(int checked, int64_t expected,
                                   int r,
                                   int64_t strides[r], int64_t shape[r], bool used[r]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++) {
      if (!used[j] && strides[j] == expected && strides[j] >= 0) {
        used[j] = true;
        if (checked+1 == r ||
            lmad_contiguous_search(checked+1, expected * shape[j], r, strides, shape, used)) {
          return true;
        }
        used[j] = false;
      }
    }
  }
  return false;
}

// Does this LMAD correspond to an array with positive strides and no
// holes?
static bool lmad_contiguous(int r, int64_t strides[r], int64_t shape[r]) {
  bool used[r];
  for (int i = 0; i < r; i++) {
    used[i] = false;
  }
  return lmad_contiguous_search(0, 1, r, strides, shape, used);
}

// Does this copy correspond to something that could be done with a
// memcpy()-like operation?  I.e. do the LMADs actually represent the
// same in-memory layout and are they contiguous?
static bool lmad_memcpyable(int r,
                            int64_t dst_strides[r], int64_t src_strides[r], int64_t shape[r]) {
  if (!lmad_contiguous(r, dst_strides, shape)) {
    return false;
  }
  for (int i = 0; i < r; i++) {
    if (dst_strides[i] != src_strides[i] && shape[i] != 1) {
      return false;
    }
  }
  return true;
}


static void log_copy(struct futhark_context* ctx,
                     const char *kind, const char *provenance,
                     int r,
                     int64_t dst_offset, int64_t dst_strides[r],
                     int64_t src_offset, int64_t src_strides[r],
                     int64_t shape[r]) {
  if (ctx->logging) {
    fprintf(ctx->log, "\n# Copy %s\n", kind);
    if (provenance) { fprintf(ctx->log, "At: %s\n", provenance); }
    fprintf(ctx->log, "Shape: ");
    for (int i = 0; i < r; i++) { fprintf(ctx->log, "[%ld]", (long int)shape[i]); }
    fprintf(ctx->log, "\n");
    fprintf(ctx->log, "Dst offset: %ld\n", (long int)dst_offset);
    fprintf(ctx->log, "Dst strides:");
    for (int i = 0; i < r; i++) { fprintf(ctx->log, " %ld", (long int)dst_strides[i]); }
    fprintf(ctx->log, "\n");
    fprintf(ctx->log, "Src offset: %ld\n", (long int)src_offset);
    fprintf(ctx->log, "Src strides:");
    for (int i = 0; i < r; i++) { fprintf(ctx->log, " %ld", (long int)src_strides[i]); }
    fprintf(ctx->log, "\n");
  }
}

static void log_transpose(struct futhark_context* ctx,
                          int64_t k, int64_t n, int64_t m) {
  if (ctx->logging) {
    fprintf(ctx->log, "## Transpose\n");
    fprintf(ctx->log, "Arrays     : %ld\n", (long int)k);
    fprintf(ctx->log, "X elements : %ld\n", (long int)m);
    fprintf(ctx->log, "Y elements : %ld\n", (long int)n);
    fprintf(ctx->log, "\n");
  }
}

#define GEN_LMAD_COPY(NAME, ELEM_TYPE)                                  \
  static void lmad_copy_##NAME                                          \
  (struct futhark_context *ctx, int r,                                  \
   ELEM_TYPE* dst, int64_t dst_offset, int64_t dst_strides[r],          \
   ELEM_TYPE *src, int64_t src_offset, int64_t src_strides[r],          \
   int64_t shape[r]) {                                                  \
    log_copy(ctx, "CPU to CPU", NULL, r, dst_offset, dst_strides,       \
             src_offset, src_strides, shape);                           \
    int64_t size = 1;                                                   \
    for (int i = 0; i < r; i++) { size *= shape[i]; }                   \
    if (size == 0) { return; }                                          \
    int64_t k, n, m;                                                    \
    if (lmad_map_tr(&k, &n, &m,                                         \
                    r, dst_strides, src_strides, shape)) {              \
      log_transpose(ctx, k, n, m);                                      \
      map_transpose_##NAME                                              \
        (dst+dst_offset, src+src_offset, k, n, m, 0, n, 0, m);          \
    } else if (lmad_memcpyable(r, dst_strides, src_strides, shape)) {   \
      if (ctx->logging) {fprintf(ctx->log, "## Flat copy\n\n");}          \
      memcpy(dst+dst_offset, src+src_offset, size*sizeof(*dst));        \
    } else {                                                            \
      if (ctx->logging) {fprintf(ctx->log, "## General copy\n\n");}       \
      lmad_copy_elements_##NAME                                         \
        (r,                                                             \
         dst+dst_offset, dst_strides,                                   \
         src+src_offset, src_strides, shape);                           \
    }                                                                   \
  }

GEN_MAP_TRANSPOSE(1b, uint8_t)
GEN_MAP_TRANSPOSE(2b, uint16_t)
GEN_MAP_TRANSPOSE(4b, uint32_t)
GEN_MAP_TRANSPOSE(8b, uint64_t)

GEN_LMAD_COPY_ELEMENTS(1b, uint8_t)
GEN_LMAD_COPY_ELEMENTS(2b, uint16_t)
GEN_LMAD_COPY_ELEMENTS(4b, uint32_t)
GEN_LMAD_COPY_ELEMENTS(8b, uint64_t)

GEN_LMAD_COPY(1b, uint8_t)
GEN_LMAD_COPY(2b, uint16_t)
GEN_LMAD_COPY(4b, uint32_t)
GEN_LMAD_COPY(8b, uint64_t)

// End of copy.h

#define FUTHARK_FUN_ATTR static

FUTHARK_FUN_ATTR int futrts_entry_bench(struct futhark_context *ctx, struct memblock *mem_out_p_35208, struct memblock xs_mem_34878, int64_t nz2080U_26079);
FUTHARK_FUN_ATTR int futrts_entry_is_sorted(struct futhark_context *ctx, bool *out_prim_out_35226, struct memblock arrs_mem_34878, int64_t n_21926, int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927);
FUTHARK_FUN_ATTR int futrts_entry_is_stable(struct futhark_context *ctx, bool *out_prim_out_35244, struct memblock arrs_mem_34878, int64_t n_24423, int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424);
FUTHARK_FUN_ATTR int futrts_entry_main(struct futhark_context *ctx, struct memblock *mem_out_p_35264, int64_t *out_prim_out_35265, struct memblock xss_mem_34878, int64_t n_18037);
FUTHARK_FUN_ATTR int futrts_entry_test_sort_reversed(struct futhark_context *ctx, bool *out_prim_out_35283);
FUTHARK_FUN_ATTR int futrts_get_bit_2473(struct futhark_context *ctx, int32_t *out_prim_out_35284, int32_t bit_16404, int64_t x_16405);

static int init_constants(struct futhark_context *ctx)
{
    (void) ctx;
    
    int err = 0;
    
    #define defunc_0_reduce_res_32880 (ctx->constants->defunc_0_reduce_res_32880)
    
    struct memblock mem_param_tmp_35173;
    
    mem_param_tmp_35173.references = NULL;
    
    struct memblock mem_34874;
    
    mem_34874.references = NULL;
    
    struct memblock mem_param_tmp_35182;
    
    mem_param_tmp_35182.references = NULL;
    
    struct memblock mem_param_tmp_35196;
    
    mem_param_tmp_35196.references = NULL;
    
    struct memblock mem_param_tmp_35195;
    
    mem_param_tmp_35195.references = NULL;
    
    struct memblock mem_34854;
    
    mem_34854.references = NULL;
    
    struct memblock mem_34853;
    
    mem_34853.references = NULL;
    
    struct memblock mem_param_34838;
    
    mem_param_34838.references = NULL;
    
    struct memblock mem_param_34835;
    
    mem_param_34835.references = NULL;
    
    struct memblock ext_mem_34861;
    
    ext_mem_34861.references = NULL;
    
    struct memblock ext_mem_34862;
    
    ext_mem_34862.references = NULL;
    
    struct memblock mem_34829;
    
    mem_34829.references = NULL;
    
    struct memblock mem_param_34809;
    
    mem_param_34809.references = NULL;
    
    struct memblock ext_mem_34866;
    
    ext_mem_34866.references = NULL;
    
    struct memblock mem_param_34785;
    
    mem_param_34785.references = NULL;
    
    struct memblock ext_mem_34877;
    
    ext_mem_34877.references = NULL;
    
    struct memblock mem_34867;
    
    mem_34867.references = NULL;
    
    struct memblock mem_34840;
    
    mem_34840.references = NULL;
    
    struct memblock mem_34839;
    
    mem_34839.references = NULL;
    
    struct memblock mem_34828;
    
    mem_34828.references = NULL;
    
    struct memblock mem_34827;
    
    mem_34827.references = NULL;
    
    struct memblock mem_34826;
    
    mem_34826.references = NULL;
    
    struct memblock mem_34825;
    
    mem_34825.references = NULL;
    
    struct memblock mem_34824;
    
    mem_34824.references = NULL;
    
    struct memblock mem_34811;
    
    mem_34811.references = NULL;
    
    struct memblock mem_34810;
    
    mem_34810.references = NULL;
    
    struct memblock mem_34800;
    
    mem_34800.references = NULL;
    
    struct memblock mem_34787;
    
    mem_34787.references = NULL;
    
    struct memblock mem_34786;
    
    mem_34786.references = NULL;
    
    struct memblock mem_34782;
    
    mem_34782.references = NULL;
    
    struct memblock mem_34781;
    
    mem_34781.references = NULL;
    
    struct memblock mem_34780;
    
    mem_34780.references = NULL;
    
    struct memblock mem_34773;
    
    mem_34773.references = NULL;
    // blocked_v3.fut:182:12-48
    if (memblock_alloc(ctx, &mem_34773, (int64_t) 20480, "mem_34773")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:182:12-48
    for (int64_t i_34623 = 0; i_34623 < (int64_t) 5120; i_34623++) {
        // blocked_v3.fut:182:29-38
        
        int64_t lifted_lambda_res_26454 = sub64((int64_t) 5119, i_34623);
        
        // blocked_v3.fut:182:17-24
        
        int32_t unsign_arg0_26455 = zext_i64_i32(lifted_lambda_res_26454);
        
        ((int32_t *) mem_34773.mem)[i_34623] = unsign_arg0_26455;
    }
    // blocked_v3.fut:88:19-47
    if (memblock_alloc(ctx, &mem_34780, (int64_t) 20480, "mem_34780")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    if (memblock_alloc(ctx, &mem_34781, (int64_t) 512, "mem_34781")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    for (int64_t nest_i_35172 = 0; nest_i_35172 < (int64_t) 256; nest_i_35172++) {
        ((int16_t *) mem_34781.mem)[nest_i_35172] = (int16_t) 0;
    }
    // blocked_v3.fut:87:20-63
    if (memblock_alloc(ctx, &mem_34782, (int64_t) 512, "mem_34782")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:20-63
    // blocked_v3.fut:87:20-63
    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34782.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34781.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
    if (memblock_unref(ctx, &mem_34781, "mem_34781") != 0)
        return 1;
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34786, (int64_t) 20480, "mem_34786")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:21:49-22:21
    if (memblock_alloc(ctx, &mem_34787, (int64_t) 32, "mem_34787")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:45:29-45
    if (memblock_alloc(ctx, &mem_34800, (int64_t) 32, "mem_34800")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (memblock_alloc(ctx, &mem_34810, (int64_t) 512, "mem_34810")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (memblock_alloc(ctx, &mem_34811, (int64_t) 512, "mem_34811")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (memblock_alloc(ctx, &mem_34824, (int64_t) 512, "mem_34824")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (memblock_alloc(ctx, &mem_34825, (int64_t) 512, "mem_34825")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (memblock_alloc(ctx, &mem_34826, (int64_t) 512, "mem_34826")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (memblock_alloc(ctx, &mem_34827, (int64_t) 512, "mem_34827")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:86:33-69
    if (memblock_alloc(ctx, &mem_34828, (int64_t) 2, "mem_34828")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (memblock_alloc(ctx, &mem_34839, (int64_t) 512, "mem_34839")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (memblock_alloc(ctx, &mem_34840, (int64_t) 512, "mem_34840")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:41:5-32
    if (memblock_alloc(ctx, &mem_34867, (int64_t) 128, "mem_34867")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:167:11-169:49
    if (memblock_set(ctx, &mem_param_34785, &mem_34773, "mem_34773") != 0)
        return 1;
    for (int32_t i_27700 = 0; i_27700 < 8; i_27700++) {
        // blocked_v3.fut:169:26-37
        
        int32_t sort_step_arg0_27702 = mul32(4, i_27700);
        
        // blocked_v3.fut:78:14-25
        // blocked_v3.fut:78:14-25
        lmad_copy_4b(ctx, 1, (uint32_t *) mem_34786.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_param_34785.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
        // blocked_v3.fut:21:49-22:21
        for (int64_t nest_i_35175 = 0; nest_i_35175 < (int64_t) 16; nest_i_35175++) {
            ((int16_t *) mem_34787.mem)[nest_i_35175] = (int16_t) 0;
        }
        // blocked_v3.fut:23:8-27:50
        for (int64_t i_27711 = 0; i_27711 < (int64_t) 20; i_27711++) {
            // blocked_v3.fut:26:32-27:50
            for (int64_t iter_34625 = 0; iter_34625 < (int64_t) 256; iter_34625++) {
                // blocked_v3.fut:12:28-36
                
                int64_t lifted_lambda_res_32056 = mul64((int64_t) 20, iter_34625);
                
                // blocked_v3.fut:12:13-23
                
                int64_t lifted_lambda_res_32057 = add64(i_27711, lifted_lambda_res_32056);
                
                // blocked_v3.fut:16:26-31
                
                int32_t lifted_lambda_res_32059 = ((int32_t *) mem_34786.mem)[lifted_lambda_res_32057];
                
                // blocked_v3.fut:35:9-37:47
                
                int32_t zlzb_rhs_32061;
                int32_t acc_32063 = 0;
                
                for (int32_t i_32062 = 0; i_32062 < 4; i_32062++) {
                    // blocked_v3.fut:37:35-38
                    
                    int32_t get_bit_arg0_32064 = add32(sort_step_arg0_27702, i_32062);
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_32065 = ashr32(lifted_lambda_res_32059, get_bit_arg0_32064);
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_32066 = 1 & unsign_arg0_32065;
                    
                    // blocked_v3.fut:37:42-46
                    
                    int32_t zp_rhs_32067 = shl32(unsign_arg0_32066, i_32062);
                    
                    // blocked_v3.fut:37:15-46
                    
                    int32_t loopres_32068 = add32(acc_32063, zp_rhs_32067);
                    int32_t acc_tmp_35178 = loopres_32068;
                    
                    acc_32063 = acc_tmp_35178;
                }
                zlzb_rhs_32061 = acc_32063;
                // blocked_v3.fut:34:5-12
                
                int64_t i32_res_32069 = sext_i32_i64(zlzb_rhs_32061);
                bool less_than_zzero_34629 = slt64(i32_res_32069, (int64_t) 0);
                bool greater_than_sizze_34630 = sle64((int64_t) 16, i32_res_32069);
                bool outside_bounds_dim_34631 = less_than_zzero_34629 || greater_than_sizze_34630;
                
                if (!outside_bounds_dim_34631) {
                    int16_t read_hist_34633 = ((int16_t *) mem_34787.mem)[i32_res_32069];
                    
                    // blocked_v3.fut:27:34-37
                    
                    int16_t defunc_0_f_res_27736 = add16((int16_t) 1, read_hist_34633);
                    
                    ((int16_t *) mem_34787.mem)[i32_res_32069] = defunc_0_f_res_27736;
                }
            }
        }
        // blocked_v3.fut:45:29-45
        for (int64_t nest_i_35179 = 0; nest_i_35179 < (int64_t) 16; nest_i_35179++) {
            ((int16_t *) mem_34800.mem)[nest_i_35179] = (int16_t) 0;
        }
        // blocked_v3.fut:45:6-49:35
        
        int16_t sequential_offsets_res_27741;
        int16_t acc_27744 = (int16_t) 0;
        
        for (int64_t i_27742 = 0; i_27742 < (int64_t) 16; i_27742++) {
            // blocked_v3.fut:48:12-28
            ((int16_t *) mem_34800.mem)[i_27742] = acc_27744;
            // blocked_v3.fut:49:27-34
            
            int16_t zp_rhs_27746 = ((int16_t *) mem_34787.mem)[i_27742];
            
            // blocked_v3.fut:49:25-34
            
            int16_t tmp_27747 = add16(acc_27744, zp_rhs_27746);
            int16_t acc_tmp_35181 = tmp_27747;
            
            acc_27744 = acc_tmp_35181;
        }
        sequential_offsets_res_27741 = acc_27744;
        // blocked_v3.fut:82:7-110:15
        if (memblock_set(ctx, &mem_param_34809, &mem_34786, "mem_34786") != 0)
            return 1;
        for (int32_t i_27749 = 0; i_27749 < 4; i_27749++) {
            // blocked_v3.fut:84:42-51
            
            int32_t get_bit_arg0_27751 = add32(sort_step_arg0_27702, i_27749);
            
            // blocked_v3.fut:55:5-60:60
            for (int64_t i_34640 = 0; i_34640 < (int64_t) 256; i_34640++) {
                // blocked_v3.fut:58:54-65
                
                int64_t c_27755 = mul64((int64_t) 20, i_34640);
                
                // blocked_v3.fut:58:69-72
                
                int64_t zt_lhs_27756 = add64((int64_t) 1, i_34640);
                
                // blocked_v3.fut:58:74-85
                
                int64_t c_27757 = mul64((int64_t) 20, zt_lhs_27756);
                
                // blocked_v3.fut:57:30-59:41
                
                int64_t j_m_i_27758 = sub64(c_27757, c_27755);
                
                // blocked_v3.fut:57:30-59:41
                
                int16_t c_27759;
                int16_t acc_27761 = (int16_t) 0;
                
                for (int64_t i_27760 = 0; i_27760 < j_m_i_27758; i_27760++) {
                    // blocked_v3.fut:55:5-60:60
                    
                    int64_t index_primexp_27762 = c_27755 + i_27760;
                    
                    // blocked_v3.fut:55:5-60:60
                    
                    int32_t v_27763 = ((int32_t *) mem_param_34809.mem)[index_primexp_27762];
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_31744 = ashr32(v_27763, get_bit_arg0_27751);
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_31745 = 1 & unsign_arg0_31744;
                    
                    // blocked_v3.fut:84:19-26
                    
                    int16_t i32_res_27765 = sext_i32_i16(unsign_arg0_31745);
                    
                    // blocked_v3.fut:59:36-41
                    
                    int16_t loopres_27766 = add16(acc_27761, i32_res_27765);
                    int16_t acc_tmp_35186 = loopres_27766;
                    
                    acc_27761 = acc_tmp_35186;
                }
                c_27759 = acc_27761;
                // blocked_v3.fut:60:40-57
                
                int16_t zm_res_27767 = sub16((int16_t) 20, c_27759);
                
                ((int16_t *) mem_34810.mem)[i_34640] = c_27759;
                ((int16_t *) mem_34811.mem)[i_34640] = zm_res_27767;
            }
            // blocked_v3.fut:85:22-51
            // blocked_v3.fut:85:22-51
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34824.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34810.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
            // blocked_v3.fut:85:22-51
            // blocked_v3.fut:85:22-51
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34825.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34811.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
            // blocked_v3.fut:71:18-32
            for (int64_t nest_i_35187 = 0; nest_i_35187 < (int64_t) 256; nest_i_35187++) {
                ((int16_t *) mem_34826.mem)[nest_i_35187] = (int16_t) 0;
            }
            // blocked_v3.fut:71:18-32
            for (int64_t nest_i_35188 = 0; nest_i_35188 < (int64_t) 256; nest_i_35188++) {
                ((int16_t *) mem_34827.mem)[nest_i_35188] = (int16_t) 0;
            }
            // blocked_v3.fut:86:33-69
            for (int64_t nest_i_35189 = 0; nest_i_35189 < (int64_t) 1; nest_i_35189++) {
                ((int16_t *) mem_34828.mem)[nest_i_35189] = (int16_t) 0;
            }
            // blocked_v3.fut:70:13-71:39
            
            bool acc_cert_32256;
            bool acc_cert_32257;
            bool acc_cert_32258;
            
            // blocked_v3.fut:68:21-71:39
            
            int16_t discard_34649;
            int16_t discard_34650;
            int16_t scanacc_34643;
            int16_t scanacc_34644;
            
            scanacc_34643 = (int16_t) 0;
            scanacc_34644 = (int16_t) 0;
            for (int64_t i_34648 = 0; i_34648 < (int64_t) 256; i_34648++) {
                int16_t x_32336 = ((int16_t *) mem_34824.mem)[i_34648];
                int16_t x_32337 = ((int16_t *) mem_34825.mem)[i_34648];
                
                // blocked_v3.fut:68:28-33
                
                int64_t lifted_lambda_res_32342 = add64((int64_t) 1, i_34648);
                
                // blocked_v3.fut:64:9-13
                
                int16_t tmp_32283 = add16(x_32336, scanacc_34643);
                
                // blocked_v3.fut:64:18-22
                
                int16_t tmp_32284 = add16(x_32337, scanacc_34644);
                
                // blocked_v3.fut:70:38-66
                
                bool cond_32323 = i_34648 == (int64_t) 255;
                
                // blocked_v3.fut:70:38-66
                
                int64_t lifted_lambda_res_32324;
                
                if (cond_32323) {
                    lifted_lambda_res_32324 = (int64_t) 0;
                } else {
                    lifted_lambda_res_32324 = (int64_t) -1;
                }
                // blocked_v3.fut:70:13-80
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_32324) && slt64(lifted_lambda_res_32324, (int64_t) 1)) {
                    ((int16_t *) mem_34828.mem)[lifted_lambda_res_32324] = tmp_32284;
                }
                // blocked_v3.fut:71:9-39
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_32342) && slt64(lifted_lambda_res_32342, (int64_t) 256)) {
                    ((int16_t *) mem_34827.mem)[lifted_lambda_res_32342] = tmp_32283;
                }
                // blocked_v3.fut:71:9-39
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_32342) && slt64(lifted_lambda_res_32342, (int64_t) 256)) {
                    ((int16_t *) mem_34826.mem)[lifted_lambda_res_32342] = tmp_32284;
                }
                
                int16_t scanacc_tmp_35190 = tmp_32283;
                int16_t scanacc_tmp_35191 = tmp_32284;
                
                scanacc_34643 = scanacc_tmp_35190;
                scanacc_34644 = scanacc_tmp_35191;
            }
            discard_34649 = scanacc_34643;
            discard_34650 = scanacc_34644;
            // blocked_v3.fut:71:41-45
            
            int16_t tmp_27822 = ((int16_t *) mem_34828.mem)[(int64_t) 0];
            
            // blocked_v3.fut:88:19-47
            if (memblock_alloc(ctx, &mem_34829, (int64_t) 20480, "mem_34829")) {
                err = 1;
                goto cleanup;
            }
            // blocked_v3.fut:88:19-47
            // blocked_v3.fut:88:19-47
            lmad_copy_4b(ctx, 1, (uint32_t *) mem_34829.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_34780.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
            // blocked_v3.fut:90:11-109:27
            if (memblock_set(ctx, &mem_param_34835, &mem_34782, "mem_34782") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34838, &mem_34782, "mem_34782") != 0)
                return 1;
            for (int64_t k_27827 = 0; k_27827 < (int64_t) 20; k_27827++) {
                // blocked_v3.fut:102:15-77
                if (memblock_alloc(ctx, &mem_34853, (int64_t) 512, "mem_34853")) {
                    err = 1;
                    goto cleanup;
                }
                // blocked_v3.fut:102:15-77
                if (memblock_alloc(ctx, &mem_34854, (int64_t) 512, "mem_34854")) {
                    err = 1;
                    goto cleanup;
                }
                // blocked_v3.fut:102:15-77
                
                bool acc_cert_32587;
                
                // blocked_v3.fut:94:15-108:27
                for (int64_t i_34656 = 0; i_34656 < (int64_t) 256; i_34656++) {
                    int16_t eta_p_32675 = ((int16_t *) mem_param_34835.mem)[i_34656];
                    int16_t eta_p_32676 = ((int16_t *) mem_param_34838.mem)[i_34656];
                    int16_t eta_p_32677 = ((int16_t *) mem_34827.mem)[i_34656];
                    int16_t eta_p_32678 = ((int16_t *) mem_34826.mem)[i_34656];
                    
                    // blocked_v3.fut:12:28-36
                    
                    int64_t lifted_lambda_res_32682 = mul64((int64_t) 20, i_34656);
                    
                    // blocked_v3.fut:12:13-23
                    
                    int64_t lifted_lambda_res_32683 = add64(k_27827, lifted_lambda_res_32682);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool x_32684 = sle64((int64_t) 0, lifted_lambda_res_32683);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool y_32685 = slt64(lifted_lambda_res_32683, (int64_t) 5120);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool bounds_check_32686 = x_32684 && y_32685;
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool index_certs_32687;
                    
                    if (!bounds_check_32686) {
                        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) lifted_lambda_res_32683, "] out of bounds for array of shape [", (long long) (int64_t) 5120, "].", "-> #0  blocked_v3.fut:95:38-43\n   #1  blocked_v3.fut:122:7-36\n   #2  blocked_v3.fut:169:13-49\n   #3  blocked_v3.fut:183:16-67\n"));
                        err = FUTHARK_PROGRAM_ERROR;
                        goto cleanup;
                    }
                    // blocked_v3.fut:95:38-43
                    
                    int32_t get_arg0_32688 = ((int32_t *) mem_param_34809.mem)[lifted_lambda_res_32683];
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_32689 = ashr32(get_arg0_32688, get_bit_arg0_27751);
                    
                    // blocked_v3.fut:183:53-64
                    
                    int32_t unsign_arg0_32690 = 1 & unsign_arg0_32689;
                    
                    // blocked_v3.fut:84:19-26
                    
                    int16_t i32_res_32691 = sext_i32_i16(unsign_arg0_32690);
                    
                    // blocked_v3.fut:96:38-98:54
                    
                    bool cond_32692 = i32_res_32691 == (int16_t) 0;
                    
                    // blocked_v3.fut:96:38-98:54
                    
                    int16_t i16_arg0_32693;
                    
                    if (cond_32692) {
                        // blocked_v3.fut:97:46-50
                        
                        int16_t i16_arg0_t_res_32864 = add16(eta_p_32676, eta_p_32678);
                        
                        i16_arg0_32693 = i16_arg0_t_res_32864;
                    } else {
                        // blocked_v3.fut:98:45-49
                        
                        int16_t zp_lhs_32695 = add16(tmp_27822, eta_p_32677);
                        
                        // blocked_v3.fut:98:50-54
                        
                        int16_t i16_arg0_f_res_32696 = add16(eta_p_32675, zp_lhs_32695);
                        
                        i16_arg0_32693 = i16_arg0_f_res_32696;
                    }
                    // blocked_v3.fut:96:29-98:54
                    
                    int64_t i16_res_32697 = sext_i16_i64(i16_arg0_32693);
                    
                    // blocked_v3.fut:102:15-77
                    // UpdateAcc
                    if (sle64((int64_t) 0, i16_res_32697) && slt64(i16_res_32697, (int64_t) 5120)) {
                        ((int32_t *) mem_34829.mem)[i16_res_32697] = get_arg0_32688;
                    }
                    // blocked_v3.fut:107:33-36
                    
                    int16_t tmp_32715 = add16(eta_p_32675, i32_res_32691);
                    
                    // blocked_v3.fut:107:49-52
                    
                    int16_t zp_rhs_32716 = (int16_t) 1 ^ i32_res_32691;
                    
                    // blocked_v3.fut:107:41-52
                    
                    int16_t tmp_32717 = add16(eta_p_32676, zp_rhs_32716);
                    
                    ((int16_t *) mem_34839.mem)[i_34656] = tmp_32715;
                    ((int16_t *) mem_34840.mem)[i_34656] = tmp_32717;
                }
                // blocked_v3.fut:102:15-77
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34853.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34839.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                // blocked_v3.fut:102:15-77
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34854.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34840.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                if (memblock_set(ctx, &mem_param_tmp_35195, &mem_34853, "mem_34853") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_tmp_35196, &mem_34854, "mem_34854") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34835, &mem_param_tmp_35195, "mem_param_tmp_35195") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34838, &mem_param_tmp_35196, "mem_param_tmp_35196") != 0)
                    return 1;
            }
            if (memblock_set(ctx, &ext_mem_34862, &mem_param_34835, "mem_param_34835") != 0)
                return 1;
            if (memblock_set(ctx, &ext_mem_34861, &mem_param_34838, "mem_param_34838") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_tmp_35182, &mem_34829, "mem_34829") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34809, &mem_param_tmp_35182, "mem_param_tmp_35182") != 0)
                return 1;
        }
        if (memblock_set(ctx, &ext_mem_34866, &mem_param_34809, "mem_param_34809") != 0)
            return 1;
        // blocked_v3.fut:41:5-32
        
        int64_t discard_34664;
        int64_t scanacc_34660 = (int64_t) 0;
        
        for (int64_t i_34662 = 0; i_34662 < (int64_t) 16; i_34662++) {
            int16_t eta_p_32021 = ((int16_t *) mem_34787.mem)[i_34662];
            
            // blocked_v3.fut:132:14-21
            
            int64_t i16_res_32022 = sext_i16_i64(eta_p_32021);
            
            // blocked_v3.fut:41:20-23
            
            int64_t defunc_0_op_res_27903 = add64(i16_res_32022, scanacc_34660);
            
            ((int64_t *) mem_34867.mem)[i_34662] = scanacc_34660;
            
            int64_t scanacc_tmp_35203 = defunc_0_op_res_27903;
            
            scanacc_34660 = scanacc_tmp_35203;
        }
        discard_34664 = scanacc_34660;
        if (memblock_alloc(ctx, &mem_34874, (int64_t) 20480, "mem_34874")) {
            err = 1;
            goto cleanup;
        }
        lmad_copy_4b(ctx, 1, (uint32_t *) mem_34874.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) ext_mem_34866.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
        // blocked_v3.fut:145:8-39
        
        bool acc_cert_31839;
        
        // blocked_v3.fut:137:7-145:39
        for (int64_t i_34666 = 0; i_34666 < (int64_t) 5120; i_34666++) {
            int32_t v_31897 = ((int32_t *) ext_mem_34866.mem)[i_34666];
            
            // blocked_v3.fut:169:13-49
            
            int64_t new_index_31902 = squot64(i_34666, (int64_t) 5120);
            
            // blocked_v3.fut:169:13-49
            
            int64_t binop_y_31903 = (int64_t) 5120 * new_index_31902;
            
            // blocked_v3.fut:169:13-49
            
            int64_t new_index_31904 = i_34666 - binop_y_31903;
            int32_t elem_31905 = ((int32_t *) ext_mem_34866.mem)[new_index_31904];
            
            // blocked_v3.fut:35:9-37:47
            
            int32_t zlzb_rhs_31906;
            int32_t acc_31908 = 0;
            
            for (int32_t i_31907 = 0; i_31907 < 4; i_31907++) {
                // blocked_v3.fut:37:35-38
                
                int32_t get_bit_arg0_31909 = add32(sort_step_arg0_27702, i_31907);
                
                // blocked_v3.fut:183:53-64
                
                int32_t unsign_arg0_31910 = ashr32(elem_31905, get_bit_arg0_31909);
                
                // blocked_v3.fut:183:53-64
                
                int32_t unsign_arg0_31911 = 1 & unsign_arg0_31910;
                
                // blocked_v3.fut:37:42-46
                
                int32_t zp_rhs_31912 = shl32(unsign_arg0_31911, i_31907);
                
                // blocked_v3.fut:37:15-46
                
                int32_t loopres_31913 = add32(acc_31908, zp_rhs_31912);
                int32_t acc_tmp_35206 = loopres_31913;
                
                acc_31908 = acc_tmp_35206;
            }
            zlzb_rhs_31906 = acc_31908;
            // blocked_v3.fut:34:5-12
            
            int64_t i32_res_31914 = sext_i32_i64(zlzb_rhs_31906);
            
            // blocked_v3.fut:140:68-93
            
            int64_t block_idx_31915 = sdiv64(i_34666, (int64_t) 5120);
            
            // blocked_v3.fut:141:67-89
            
            bool x_31916 = sle64((int64_t) 0, block_idx_31915);
            
            // blocked_v3.fut:141:67-89
            
            bool y_31917 = slt64(block_idx_31915, (int64_t) 1);
            
            // blocked_v3.fut:141:67-89
            
            bool bounds_check_31918 = x_31916 && y_31917;
            
            // blocked_v3.fut:141:67-89
            
            bool index_certs_31919;
            
            if (!bounds_check_31918) {
                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) block_idx_31915, "] out of bounds for array of shape [", (long long) (int64_t) 1, "].", "-> #0  blocked_v3.fut:141:67-89\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:183:16-67\n"));
                err = FUTHARK_PROGRAM_ERROR;
                goto cleanup;
            }
            // blocked_v3.fut:141:67-94
            
            bool x_31920 = sle64((int64_t) 0, i32_res_31914);
            
            // blocked_v3.fut:141:67-94
            
            bool y_31921 = slt64(i32_res_31914, (int64_t) 16);
            
            // blocked_v3.fut:141:67-94
            
            bool bounds_check_31922 = x_31920 && y_31921;
            
            // blocked_v3.fut:141:67-94
            
            bool index_certs_31923;
            
            if (!bounds_check_31922) {
                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) i32_res_31914, "] out of bounds for array of shape [", (long long) (int64_t) 16, "].", "-> #0  blocked_v3.fut:141:67-94\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:183:16-67\n"));
                err = FUTHARK_PROGRAM_ERROR;
                goto cleanup;
            }
            // blocked_v3.fut:169:13-49
            
            int64_t index_primexp_31924 = i32_res_31914 + block_idx_31915;
            
            // blocked_v3.fut:169:13-49
            
            int64_t new_offset_31925 = ((int64_t *) mem_34867.mem)[index_primexp_31924];
            int16_t i16_arg0_31926 = ((int16_t *) mem_34800.mem)[i32_res_31914];
            
            // blocked_v3.fut:142:73-108
            
            int64_t i16_res_31927 = sext_i16_i64(i16_arg0_31926);
            
            // blocked_v3.fut:143:92-103
            
            int64_t zp_lhs_31928 = mul64((int64_t) 5120, block_idx_31915);
            
            // blocked_v3.fut:143:104-122
            
            int64_t old_offset_31929 = add64(i16_res_31927, zp_lhs_31928);
            
            // blocked_v3.fut:144:56-68
            
            int64_t zp_lhs_31930 = sub64(i_34666, old_offset_31929);
            
            // blocked_v3.fut:144:70-82
            
            int64_t defunc_0_f_res_31931 = add64(new_offset_31925, zp_lhs_31930);
            
            // blocked_v3.fut:145:8-39
            // UpdateAcc
            if (sle64((int64_t) 0, defunc_0_f_res_31931) && slt64(defunc_0_f_res_31931, (int64_t) 5120)) {
                ((int32_t *) mem_34874.mem)[defunc_0_f_res_31931] = v_31897;
            }
        }
        if (memblock_unref(ctx, &ext_mem_34866, "ext_mem_34866") != 0)
            return 1;
        if (memblock_set(ctx, &mem_param_tmp_35173, &mem_34874, "mem_34874") != 0)
            return 1;
        if (memblock_set(ctx, &mem_param_34785, &mem_param_tmp_35173, "mem_param_tmp_35173") != 0)
            return 1;
    }
    if (memblock_set(ctx, &ext_mem_34877, &mem_param_34785, "mem_param_34785") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34773, "mem_34773") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34780, "mem_34780") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34782, "mem_34782") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34786, "mem_34786") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34787, "mem_34787") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34800, "mem_34800") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34810, "mem_34810") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34811, "mem_34811") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34824, "mem_34824") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34825, "mem_34825") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34826, "mem_34826") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34827, "mem_34827") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34828, "mem_34828") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34839, "mem_34839") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34840, "mem_34840") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34867, "mem_34867") != 0)
        return 1;
    // blocked_v3.fut:184:6-52
    
    bool redout_34667 = 1;
    
    for (int64_t i_34668 = 0; i_34668 < (int64_t) 5120; i_34668++) {
        int32_t eta_p_31822 = ((int32_t *) ext_mem_34877.mem)[i_34668];
        
        // blocked_v3.fut:184:28-35
        
        int32_t unsign_arg0_31823 = zext_i64_i32(i_34668);
        
        // blocked_v3.fut:184:11-15
        
        bool defunc_0_f_res_31827 = eta_p_31822 == unsign_arg0_31823;
        
        // blocked_v3.fut:184:49-52
        
        bool x_26583 = defunc_0_f_res_31827 && redout_34667;
        bool redout_tmp_35207 = x_26583;
        
        redout_34667 = redout_tmp_35207;
    }
    defunc_0_reduce_res_32880 = redout_34667;
    if (memblock_unref(ctx, &ext_mem_34877, "ext_mem_34877") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_tmp_35173, "mem_param_tmp_35173") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34874, "mem_34874") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_tmp_35182, "mem_param_tmp_35182") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_tmp_35196, "mem_param_tmp_35196") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_tmp_35195, "mem_param_tmp_35195") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34854, "mem_34854") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34853, "mem_34853") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_34838, "mem_param_34838") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_34835, "mem_param_34835") != 0)
        return 1;
    if (memblock_unref(ctx, &ext_mem_34861, "ext_mem_34861") != 0)
        return 1;
    if (memblock_unref(ctx, &ext_mem_34862, "ext_mem_34862") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34829, "mem_34829") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_34809, "mem_param_34809") != 0)
        return 1;
    if (memblock_unref(ctx, &ext_mem_34866, "ext_mem_34866") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_param_34785, "mem_param_34785") != 0)
        return 1;
    if (memblock_unref(ctx, &ext_mem_34877, "ext_mem_34877") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34867, "mem_34867") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34840, "mem_34840") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34839, "mem_34839") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34828, "mem_34828") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34827, "mem_34827") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34826, "mem_34826") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34825, "mem_34825") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34824, "mem_34824") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34811, "mem_34811") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34810, "mem_34810") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34800, "mem_34800") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34787, "mem_34787") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34786, "mem_34786") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34782, "mem_34782") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34781, "mem_34781") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34780, "mem_34780") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34773, "mem_34773") != 0)
        return 1;
    #undef defunc_0_reduce_res_32880
    
  cleanup:
    return err;
}
static int free_constants(struct futhark_context *ctx)
{
    (void) ctx;
    return 0;
}
struct futhark_u8_2d {
    struct memblock mem;
    int64_t shape[2];
};
struct futhark_u8_2d *futhark_new_u8_2d(struct futhark_context *ctx, const uint8_t *data, int64_t dim0, int64_t dim1)
{
    int err = 0;
    struct futhark_u8_2d *bad = NULL;
    struct futhark_u8_2d *arr = (struct futhark_u8_2d *) malloc(sizeof(struct futhark_u8_2d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    if (memblock_alloc(ctx, &arr->mem, arr->shape[0] * arr->shape[1] * 1, "arr->mem"))
        err = 1;
    if ((size_t) (dim0 * dim1) * 1 > 0)
        memmove(arr->mem.mem + 0, (const unsigned char *) data + 0, (size_t) (dim0 * dim1) * 1);
    lock_unlock(&ctx->lock);
    if (err != 0) {
        free(arr);
        return bad;
    }
    return arr;
}
struct futhark_u8_2d *futhark_new_raw_u8_2d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1)
{
    int err = 0;
    struct futhark_u8_2d *bad = NULL;
    struct futhark_u8_2d *arr = (struct futhark_u8_2d *) malloc(sizeof(struct futhark_u8_2d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->mem.mem = data;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    lock_unlock(&ctx->lock);
    return arr;
}
int futhark_free_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr)
{
    lock_lock(&ctx->lock);
    if (memblock_unref(ctx, &arr->mem, "arr->mem") != 0)
        return 1;
    lock_unlock(&ctx->lock);
    free(arr);
    return 0;
}
int futhark_values_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr, uint8_t *data)
{
    int err = 0;
    
    lock_lock(&ctx->lock);
    if ((size_t) (arr->shape[0] * arr->shape[1]) * 1 > 0)
        memmove((unsigned char *) data + 0, arr->mem.mem + 0, (size_t) (arr->shape[0] * arr->shape[1]) * 1);
    lock_unlock(&ctx->lock);
    return err;
}
int futhark_index_u8_2d(struct futhark_context *ctx, uint8_t *out, struct futhark_u8_2d *arr, int64_t i0, int64_t i1)
{
    int err = 0;
    
    if ((i0 >= 0 && i0 < arr->shape[0]) && (i1 >= 0 && i1 < arr->shape[1])) {
        lock_lock(&ctx->lock);
        if (1 > 0)
            memmove((unsigned char *) out + 0, arr->mem.mem + 1 * (i0 * arr->shape[1] + i1 * 1), 1);
        lock_unlock(&ctx->lock);
    } else {
        err = 1;
        set_error(ctx, strdup("Index out of bounds."));
    }
    return err;
}
unsigned char *futhark_values_raw_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr)
{
    (void) ctx;
    return arr->mem.mem;
}
const int64_t *futhark_shape_u8_2d(struct futhark_context *ctx, struct futhark_u8_2d *arr)
{
    (void) ctx;
    return arr->shape;
}
struct futhark_u32_1d {
    struct memblock mem;
    int64_t shape[1];
};
struct futhark_u32_1d *futhark_new_u32_1d(struct futhark_context *ctx, const uint32_t *data, int64_t dim0)
{
    int err = 0;
    struct futhark_u32_1d *bad = NULL;
    struct futhark_u32_1d *arr = (struct futhark_u32_1d *) malloc(sizeof(struct futhark_u32_1d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->shape[0] = dim0;
    if (memblock_alloc(ctx, &arr->mem, arr->shape[0] * 4, "arr->mem"))
        err = 1;
    if ((size_t) dim0 * 4 > 0)
        memmove(arr->mem.mem + 0, (const unsigned char *) data + 0, (size_t) dim0 * 4);
    lock_unlock(&ctx->lock);
    if (err != 0) {
        free(arr);
        return bad;
    }
    return arr;
}
struct futhark_u32_1d *futhark_new_raw_u32_1d(struct futhark_context *ctx, unsigned char *data, int64_t dim0)
{
    int err = 0;
    struct futhark_u32_1d *bad = NULL;
    struct futhark_u32_1d *arr = (struct futhark_u32_1d *) malloc(sizeof(struct futhark_u32_1d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->mem.mem = data;
    arr->shape[0] = dim0;
    lock_unlock(&ctx->lock);
    return arr;
}
int futhark_free_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr)
{
    lock_lock(&ctx->lock);
    if (memblock_unref(ctx, &arr->mem, "arr->mem") != 0)
        return 1;
    lock_unlock(&ctx->lock);
    free(arr);
    return 0;
}
int futhark_values_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr, uint32_t *data)
{
    int err = 0;
    
    lock_lock(&ctx->lock);
    if ((size_t) arr->shape[0] * 4 > 0)
        memmove((unsigned char *) data + 0, arr->mem.mem + 0, (size_t) arr->shape[0] * 4);
    lock_unlock(&ctx->lock);
    return err;
}
int futhark_index_u32_1d(struct futhark_context *ctx, uint32_t *out, struct futhark_u32_1d *arr, int64_t i0)
{
    int err = 0;
    
    if (i0 >= 0 && i0 < arr->shape[0]) {
        lock_lock(&ctx->lock);
        if (4 > 0)
            memmove((unsigned char *) out + 0, arr->mem.mem + 4 * (i0 * 1), 4);
        lock_unlock(&ctx->lock);
    } else {
        err = 1;
        set_error(ctx, strdup("Index out of bounds."));
    }
    return err;
}
unsigned char *futhark_values_raw_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr)
{
    (void) ctx;
    return arr->mem.mem;
}
const int64_t *futhark_shape_u32_1d(struct futhark_context *ctx, struct futhark_u32_1d *arr)
{
    (void) ctx;
    return arr->shape;
}
struct futhark_u32_2d {
    struct memblock mem;
    int64_t shape[2];
};
struct futhark_u32_2d *futhark_new_u32_2d(struct futhark_context *ctx, const uint32_t *data, int64_t dim0, int64_t dim1)
{
    int err = 0;
    struct futhark_u32_2d *bad = NULL;
    struct futhark_u32_2d *arr = (struct futhark_u32_2d *) malloc(sizeof(struct futhark_u32_2d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    if (memblock_alloc(ctx, &arr->mem, arr->shape[0] * arr->shape[1] * 4, "arr->mem"))
        err = 1;
    if ((size_t) (dim0 * dim1) * 4 > 0)
        memmove(arr->mem.mem + 0, (const unsigned char *) data + 0, (size_t) (dim0 * dim1) * 4);
    lock_unlock(&ctx->lock);
    if (err != 0) {
        free(arr);
        return bad;
    }
    return arr;
}
struct futhark_u32_2d *futhark_new_raw_u32_2d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1)
{
    int err = 0;
    struct futhark_u32_2d *bad = NULL;
    struct futhark_u32_2d *arr = (struct futhark_u32_2d *) malloc(sizeof(struct futhark_u32_2d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->mem.mem = data;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    lock_unlock(&ctx->lock);
    return arr;
}
int futhark_free_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr)
{
    lock_lock(&ctx->lock);
    if (memblock_unref(ctx, &arr->mem, "arr->mem") != 0)
        return 1;
    lock_unlock(&ctx->lock);
    free(arr);
    return 0;
}
int futhark_values_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr, uint32_t *data)
{
    int err = 0;
    
    lock_lock(&ctx->lock);
    if ((size_t) (arr->shape[0] * arr->shape[1]) * 4 > 0)
        memmove((unsigned char *) data + 0, arr->mem.mem + 0, (size_t) (arr->shape[0] * arr->shape[1]) * 4);
    lock_unlock(&ctx->lock);
    return err;
}
int futhark_index_u32_2d(struct futhark_context *ctx, uint32_t *out, struct futhark_u32_2d *arr, int64_t i0, int64_t i1)
{
    int err = 0;
    
    if ((i0 >= 0 && i0 < arr->shape[0]) && (i1 >= 0 && i1 < arr->shape[1])) {
        lock_lock(&ctx->lock);
        if (4 > 0)
            memmove((unsigned char *) out + 0, arr->mem.mem + 4 * (i0 * arr->shape[1] + i1 * 1), 4);
        lock_unlock(&ctx->lock);
    } else {
        err = 1;
        set_error(ctx, strdup("Index out of bounds."));
    }
    return err;
}
unsigned char *futhark_values_raw_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr)
{
    (void) ctx;
    return arr->mem.mem;
}
const int64_t *futhark_shape_u32_2d(struct futhark_context *ctx, struct futhark_u32_2d *arr)
{
    (void) ctx;
    return arr->shape;
}
struct futhark_i64_1d {
    struct memblock mem;
    int64_t shape[1];
};
struct futhark_i64_1d *futhark_new_i64_1d(struct futhark_context *ctx, const int64_t *data, int64_t dim0)
{
    int err = 0;
    struct futhark_i64_1d *bad = NULL;
    struct futhark_i64_1d *arr = (struct futhark_i64_1d *) malloc(sizeof(struct futhark_i64_1d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->shape[0] = dim0;
    if (memblock_alloc(ctx, &arr->mem, arr->shape[0] * 8, "arr->mem"))
        err = 1;
    if ((size_t) dim0 * 8 > 0)
        memmove(arr->mem.mem + 0, (const unsigned char *) data + 0, (size_t) dim0 * 8);
    lock_unlock(&ctx->lock);
    if (err != 0) {
        free(arr);
        return bad;
    }
    return arr;
}
struct futhark_i64_1d *futhark_new_raw_i64_1d(struct futhark_context *ctx, unsigned char *data, int64_t dim0)
{
    int err = 0;
    struct futhark_i64_1d *bad = NULL;
    struct futhark_i64_1d *arr = (struct futhark_i64_1d *) malloc(sizeof(struct futhark_i64_1d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->mem.mem = data;
    arr->shape[0] = dim0;
    lock_unlock(&ctx->lock);
    return arr;
}
int futhark_free_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr)
{
    lock_lock(&ctx->lock);
    if (memblock_unref(ctx, &arr->mem, "arr->mem") != 0)
        return 1;
    lock_unlock(&ctx->lock);
    free(arr);
    return 0;
}
int futhark_values_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr, int64_t *data)
{
    int err = 0;
    
    lock_lock(&ctx->lock);
    if ((size_t) arr->shape[0] * 8 > 0)
        memmove((unsigned char *) data + 0, arr->mem.mem + 0, (size_t) arr->shape[0] * 8);
    lock_unlock(&ctx->lock);
    return err;
}
int futhark_index_i64_1d(struct futhark_context *ctx, int64_t *out, struct futhark_i64_1d *arr, int64_t i0)
{
    int err = 0;
    
    if (i0 >= 0 && i0 < arr->shape[0]) {
        lock_lock(&ctx->lock);
        if (8 > 0)
            memmove((unsigned char *) out + 0, arr->mem.mem + 8 * (i0 * 1), 8);
        lock_unlock(&ctx->lock);
    } else {
        err = 1;
        set_error(ctx, strdup("Index out of bounds."));
    }
    return err;
}
unsigned char *futhark_values_raw_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr)
{
    (void) ctx;
    return arr->mem.mem;
}
const int64_t *futhark_shape_i64_1d(struct futhark_context *ctx, struct futhark_i64_1d *arr)
{
    (void) ctx;
    return arr->shape;
}
struct futhark_i64_3d {
    struct memblock mem;
    int64_t shape[3];
};
struct futhark_i64_3d *futhark_new_i64_3d(struct futhark_context *ctx, const int64_t *data, int64_t dim0, int64_t dim1, int64_t dim2)
{
    int err = 0;
    struct futhark_i64_3d *bad = NULL;
    struct futhark_i64_3d *arr = (struct futhark_i64_3d *) malloc(sizeof(struct futhark_i64_3d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    arr->shape[2] = dim2;
    if (memblock_alloc(ctx, &arr->mem, arr->shape[0] * arr->shape[1] * arr->shape[2] * 8, "arr->mem"))
        err = 1;
    if ((size_t) (dim0 * dim1 * dim2) * 8 > 0)
        memmove(arr->mem.mem + 0, (const unsigned char *) data + 0, (size_t) (dim0 * dim1 * dim2) * 8);
    lock_unlock(&ctx->lock);
    if (err != 0) {
        free(arr);
        return bad;
    }
    return arr;
}
struct futhark_i64_3d *futhark_new_raw_i64_3d(struct futhark_context *ctx, unsigned char *data, int64_t dim0, int64_t dim1, int64_t dim2)
{
    int err = 0;
    struct futhark_i64_3d *bad = NULL;
    struct futhark_i64_3d *arr = (struct futhark_i64_3d *) malloc(sizeof(struct futhark_i64_3d));
    
    if (arr == NULL)
        return bad;
    lock_lock(&ctx->lock);
    arr->mem.references = NULL;
    arr->mem.mem = data;
    arr->shape[0] = dim0;
    arr->shape[1] = dim1;
    arr->shape[2] = dim2;
    lock_unlock(&ctx->lock);
    return arr;
}
int futhark_free_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr)
{
    lock_lock(&ctx->lock);
    if (memblock_unref(ctx, &arr->mem, "arr->mem") != 0)
        return 1;
    lock_unlock(&ctx->lock);
    free(arr);
    return 0;
}
int futhark_values_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr, int64_t *data)
{
    int err = 0;
    
    lock_lock(&ctx->lock);
    if ((size_t) (arr->shape[0] * arr->shape[1] * arr->shape[2]) * 8 > 0)
        memmove((unsigned char *) data + 0, arr->mem.mem + 0, (size_t) (arr->shape[0] * arr->shape[1] * arr->shape[2]) * 8);
    lock_unlock(&ctx->lock);
    return err;
}
int futhark_index_i64_3d(struct futhark_context *ctx, int64_t *out, struct futhark_i64_3d *arr, int64_t i0, int64_t i1, int64_t i2)
{
    int err = 0;
    
    if ((i0 >= 0 && i0 < arr->shape[0]) && ((i1 >= 0 && i1 < arr->shape[1]) && (i2 >= 0 && i2 < arr->shape[2]))) {
        lock_lock(&ctx->lock);
        if (8 > 0)
            memmove((unsigned char *) out + 0, arr->mem.mem + 8 * (i0 * (arr->shape[1] * arr->shape[2]) + i1 * arr->shape[2] + i2 * 1), 8);
        lock_unlock(&ctx->lock);
    } else {
        err = 1;
        set_error(ctx, strdup("Index out of bounds."));
    }
    return err;
}
unsigned char *futhark_values_raw_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr)
{
    (void) ctx;
    return arr->mem.mem;
}
const int64_t *futhark_shape_i64_3d(struct futhark_context *ctx, struct futhark_i64_3d *arr)
{
    (void) ctx;
    return arr->shape;
}

FUTHARK_FUN_ATTR int futrts_entry_bench(struct futhark_context *ctx, struct memblock *mem_out_p_35208, struct memblock xs_mem_34878, int64_t nz2080U_26079)
{
    (void) ctx;
    
    int err = 0;
    int64_t mem_34881_cached_sizze_35209 = 0;
    unsigned char *mem_34881 = NULL;
    int64_t mem_34882_cached_sizze_35210 = 0;
    unsigned char *mem_34882 = NULL;
    int64_t mem_34889_cached_sizze_35211 = 0;
    unsigned char *mem_34889 = NULL;
    int64_t mem_34892_cached_sizze_35212 = 0;
    unsigned char *mem_34892 = NULL;
    int64_t mem_34895_cached_sizze_35213 = 0;
    unsigned char *mem_34895 = NULL;
    int64_t mem_34909_cached_sizze_35214 = 0;
    unsigned char *mem_34909 = NULL;
    int64_t mem_34922_cached_sizze_35215 = 0;
    unsigned char *mem_34922 = NULL;
    int64_t mem_34932_cached_sizze_35216 = 0;
    unsigned char *mem_34932 = NULL;
    int64_t mem_34933_cached_sizze_35217 = 0;
    unsigned char *mem_34933 = NULL;
    int64_t mem_34946_cached_sizze_35218 = 0;
    unsigned char *mem_34946 = NULL;
    int64_t mem_34947_cached_sizze_35219 = 0;
    unsigned char *mem_34947 = NULL;
    int64_t mem_34948_cached_sizze_35220 = 0;
    unsigned char *mem_34948 = NULL;
    int64_t mem_34949_cached_sizze_35221 = 0;
    unsigned char *mem_34949 = NULL;
    int64_t mem_34950_cached_sizze_35222 = 0;
    unsigned char *mem_34950 = NULL;
    int64_t mem_34961_cached_sizze_35223 = 0;
    unsigned char *mem_34961 = NULL;
    int64_t mem_34962_cached_sizze_35224 = 0;
    unsigned char *mem_34962 = NULL;
    int64_t mem_35006_cached_sizze_35225 = 0;
    unsigned char *mem_35006 = NULL;
    struct memblock mem_param_tmp_35121;
    
    mem_param_tmp_35121.references = NULL;
    
    struct memblock mem_35014;
    
    mem_35014.references = NULL;
    
    struct memblock mem_param_tmp_35133;
    
    mem_param_tmp_35133.references = NULL;
    
    struct memblock mem_param_tmp_35147;
    
    mem_param_tmp_35147.references = NULL;
    
    struct memblock mem_param_tmp_35146;
    
    mem_param_tmp_35146.references = NULL;
    
    struct memblock mem_34976;
    
    mem_34976.references = NULL;
    
    struct memblock mem_34975;
    
    mem_34975.references = NULL;
    
    struct memblock mem_param_34960;
    
    mem_param_34960.references = NULL;
    
    struct memblock mem_param_34957;
    
    mem_param_34957.references = NULL;
    
    struct memblock ext_mem_34983;
    
    ext_mem_34983.references = NULL;
    
    struct memblock ext_mem_34984;
    
    ext_mem_34984.references = NULL;
    
    struct memblock mem_34951;
    
    mem_34951.references = NULL;
    
    struct memblock mem_param_34931;
    
    mem_param_34931.references = NULL;
    
    struct memblock ext_mem_34988;
    
    ext_mem_34988.references = NULL;
    
    struct memblock mem_param_34886;
    
    mem_param_34886.references = NULL;
    
    struct memblock ext_mem_35017;
    
    ext_mem_35017.references = NULL;
    
    struct memblock mem_34908;
    
    mem_34908.references = NULL;
    
    struct memblock mem_34883;
    
    mem_34883.references = NULL;
    
    struct memblock mem_34880;
    
    mem_34880.references = NULL;
    
    struct memblock mem_out_35119;
    
    mem_out_35119.references = NULL;
    
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    
    // blocked_v3.fut:163:17-77
    
    bool cond_28260 = nz2080U_26079 == (int64_t) 0;
    
    // blocked_v3.fut:163:17-77
    
    int32_t iters_28261;
    
    if (cond_28260) {
        iters_28261 = 0;
    } else {
        iters_28261 = 8;
    }
    // blocked_v3.fut:164:22-47
    
    int64_t n_blocks_28265 = sdiv64(nz2080U_26079, (int64_t) 5120);
    
    // blocked_v3.fut:165:21-56
    
    int64_t dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266 = mul64((int64_t) 5120, n_blocks_28265);
    
    // blocked_v3.fut:165:14-60
    
    bool dim_match_28267 = dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266 == nz2080U_26079;
    
    // blocked_v3.fut:165:14-60
    
    bool empty_or_match_cert_28268;
    
    if (!dim_match_28267) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) nz2080U_26079, "] cannot match shape of type \"[", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266, "]u32\".", "-> #0  blocked_v3.fut:165:14-60\n   #1  blocked_v3.fut:218:3-51\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:218:3-51
    
    int64_t bytes_34879 = (int64_t) 20480 * n_blocks_28265;
    
    // blocked_v3.fut:218:3-51
    
    bool loop_nonempty_28273 = slt32(0, iters_28261);
    
    // blocked_v3.fut:118:24-121:20
    
    bool binop_x_28275 = sle64((int64_t) 0, n_blocks_28265);
    
    // blocked_v3.fut:218:3-51
    
    bool loop_not_taken_28277 = !loop_nonempty_28273;
    
    // blocked_v3.fut:218:3-51
    
    bool protect_assert_disj_28278 = binop_x_28275 || loop_not_taken_28277;
    
    // blocked_v3.fut:118:24-121:20
    
    bool dim_ok_cert_28279;
    
    if (!protect_assert_disj_28278) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s%lld%s\n\nBacktrace:\n%s", "Cannot unflatten array of shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266, "] to array of shape [", (long long) n_blocks_28265, "][", (long long) (int64_t) 5120, "]", "-> #0  blocked_v3.fut:118:24-121:20\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:218:3-51\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34891 = (int64_t) 32 * n_blocks_28265;
    
    // blocked_v3.fut:41:5-32
    
    int64_t bytes_35005 = (int64_t) 128 * n_blocks_28265;
    
    // blocked_v3.fut:166:8-13
    
    bool dim_match_28551 = nz2080U_26079 == dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266;
    
    // blocked_v3.fut:166:8-13
    
    bool empty_or_match_cert_28552;
    
    if (!dim_match_28551) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266, "] cannot match shape of type \"[", (long long) nz2080U_26079, "]u32\".", "-> #0  blocked_v3.fut:166:8-13\n   #1  blocked_v3.fut:167:8-169:49\n   #2  blocked_v3.fut:218:3-51\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:218:3-51
    if (memblock_alloc(ctx, &mem_34880, bytes_34879, "mem_34880")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:218:3-51
    // blocked_v3.fut:218:3-51
    lmad_copy_4b(ctx, 1, (uint32_t *) mem_34880.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) xs_mem_34878.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266});
    // blocked_v3.fut:169:13-49
    
    int64_t dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_28274 = mul64((int64_t) 16, n_blocks_28265);
    
    // blocked_v3.fut:88:19-47
    if (mem_34881_cached_sizze_35209 < (int64_t) 20480) {
        err = lexical_realloc(ctx, &mem_34881, &mem_34881_cached_sizze_35209, (int64_t) 20480);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    if (mem_34882_cached_sizze_35210 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34882, &mem_34882_cached_sizze_35210, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    for (int64_t nest_i_35120 = 0; nest_i_35120 < (int64_t) 256; nest_i_35120++) {
        ((int16_t *) mem_34882)[nest_i_35120] = (int16_t) 0;
    }
    // blocked_v3.fut:87:20-63
    if (memblock_alloc(ctx, &mem_34883, (int64_t) 512, "mem_34883")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:20-63
    // blocked_v3.fut:87:20-63
    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34883.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34882, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
    // blocked_v3.fut:122:7-36
    if (mem_34889_cached_sizze_35211 < bytes_34879) {
        err = lexical_realloc(ctx, &mem_34889, &mem_34889_cached_sizze_35211, bytes_34879);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34892_cached_sizze_35212 < bytes_34891) {
        err = lexical_realloc(ctx, &mem_34892, &mem_34892_cached_sizze_35212, bytes_34891);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34895_cached_sizze_35213 < bytes_34891) {
        err = lexical_realloc(ctx, &mem_34895, &mem_34895_cached_sizze_35213, bytes_34891);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34908, (int64_t) 20480, "mem_34908")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:21:49-22:21
    if (mem_34909_cached_sizze_35214 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34909, &mem_34909_cached_sizze_35214, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:45:29-45
    if (mem_34922_cached_sizze_35215 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34922, &mem_34922_cached_sizze_35215, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34932_cached_sizze_35216 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34932, &mem_34932_cached_sizze_35216, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34933_cached_sizze_35217 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34933, &mem_34933_cached_sizze_35217, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34946_cached_sizze_35218 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34946, &mem_34946_cached_sizze_35218, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34947_cached_sizze_35219 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34947, &mem_34947_cached_sizze_35219, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34948_cached_sizze_35220 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34948, &mem_34948_cached_sizze_35220, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34949_cached_sizze_35221 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34949, &mem_34949_cached_sizze_35221, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:86:33-69
    if (mem_34950_cached_sizze_35222 < (int64_t) 2) {
        err = lexical_realloc(ctx, &mem_34950, &mem_34950_cached_sizze_35222, (int64_t) 2);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34961_cached_sizze_35223 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34961, &mem_34961_cached_sizze_35223, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34962_cached_sizze_35224 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34962, &mem_34962_cached_sizze_35224, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:41:5-32
    if (mem_35006_cached_sizze_35225 < bytes_35005) {
        err = lexical_realloc(ctx, &mem_35006, &mem_35006_cached_sizze_35225, bytes_35005);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:167:11-169:49
    if (memblock_set(ctx, &mem_param_34886, &mem_34880, "mem_34880") != 0)
        return 1;
    for (int32_t i_28294 = 0; i_28294 < iters_28261; i_28294++) {
        // blocked_v3.fut:169:26-37
        
        int32_t sort_step_arg0_28296 = mul32(4, i_28294);
        
        // blocked_v3.fut:122:7-36
        for (int64_t i_34709 = 0; i_34709 < n_blocks_28265; i_34709++) {
            // blocked_v3.fut:78:14-25
            // blocked_v3.fut:78:14-25
            lmad_copy_4b(ctx, 1, (uint32_t *) mem_34908.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_param_34886.mem, (int64_t) 0 + i_34709 * ((int64_t) 1 * (int64_t) 5120), (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
            // blocked_v3.fut:21:49-22:21
            for (int64_t nest_i_35126 = 0; nest_i_35126 < (int64_t) 16; nest_i_35126++) {
                ((int16_t *) mem_34909)[nest_i_35126] = (int16_t) 0;
            }
            // blocked_v3.fut:23:8-27:50
            for (int64_t i_28305 = 0; i_28305 < (int64_t) 20; i_28305++) {
                // blocked_v3.fut:26:32-27:50
                for (int64_t iter_34669 = 0; iter_34669 < (int64_t) 256; iter_34669++) {
                    // blocked_v3.fut:12:28-36
                    
                    int64_t lifted_lambda_res_33102 = mul64((int64_t) 20, iter_34669);
                    
                    // blocked_v3.fut:12:13-23
                    
                    int64_t lifted_lambda_res_33103 = add64(i_28305, lifted_lambda_res_33102);
                    
                    // blocked_v3.fut:16:26-31
                    
                    int32_t lifted_lambda_res_33105 = ((int32_t *) mem_34908.mem)[lifted_lambda_res_33103];
                    
                    // blocked_v3.fut:35:9-37:47
                    
                    int32_t zlzb_rhs_33107;
                    int32_t acc_33109 = 0;
                    
                    for (int32_t i_33108 = 0; i_33108 < 4; i_33108++) {
                        // blocked_v3.fut:37:35-38
                        
                        int32_t get_bit_arg0_33110 = add32(sort_step_arg0_28296, i_33108);
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_33111 = ashr32(lifted_lambda_res_33105, get_bit_arg0_33110);
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_33112 = 1 & unsign_arg0_33111;
                        
                        // blocked_v3.fut:37:42-46
                        
                        int32_t zp_rhs_33113 = shl32(unsign_arg0_33112, i_33108);
                        
                        // blocked_v3.fut:37:15-46
                        
                        int32_t loopres_33114 = add32(acc_33109, zp_rhs_33113);
                        int32_t acc_tmp_35129 = loopres_33114;
                        
                        acc_33109 = acc_tmp_35129;
                    }
                    zlzb_rhs_33107 = acc_33109;
                    // blocked_v3.fut:34:5-12
                    
                    int64_t i32_res_33115 = sext_i32_i64(zlzb_rhs_33107);
                    bool less_than_zzero_34673 = slt64(i32_res_33115, (int64_t) 0);
                    bool greater_than_sizze_34674 = sle64((int64_t) 16, i32_res_33115);
                    bool outside_bounds_dim_34675 = less_than_zzero_34673 || greater_than_sizze_34674;
                    
                    if (!outside_bounds_dim_34675) {
                        int16_t read_hist_34677 = ((int16_t *) mem_34909)[i32_res_33115];
                        
                        // blocked_v3.fut:27:34-37
                        
                        int16_t defunc_0_f_res_28330 = add16((int16_t) 1, read_hist_34677);
                        
                        ((int16_t *) mem_34909)[i32_res_33115] = defunc_0_f_res_28330;
                    }
                }
            }
            // blocked_v3.fut:45:29-45
            for (int64_t nest_i_35130 = 0; nest_i_35130 < (int64_t) 16; nest_i_35130++) {
                ((int16_t *) mem_34922)[nest_i_35130] = (int16_t) 0;
            }
            // blocked_v3.fut:45:6-49:35
            
            int16_t sequential_offsets_res_28335;
            int16_t acc_28338 = (int16_t) 0;
            
            for (int64_t i_28336 = 0; i_28336 < (int64_t) 16; i_28336++) {
                // blocked_v3.fut:48:12-28
                ((int16_t *) mem_34922)[i_28336] = acc_28338;
                // blocked_v3.fut:49:27-34
                
                int16_t zp_rhs_28340 = ((int16_t *) mem_34909)[i_28336];
                
                // blocked_v3.fut:49:25-34
                
                int16_t tmp_28341 = add16(acc_28338, zp_rhs_28340);
                int16_t acc_tmp_35132 = tmp_28341;
                
                acc_28338 = acc_tmp_35132;
            }
            sequential_offsets_res_28335 = acc_28338;
            // blocked_v3.fut:82:7-110:15
            if (memblock_set(ctx, &mem_param_34931, &mem_34908, "mem_34908") != 0)
                return 1;
            for (int32_t i_28343 = 0; i_28343 < 4; i_28343++) {
                // blocked_v3.fut:84:42-51
                
                int32_t get_bit_arg0_28345 = add32(sort_step_arg0_28296, i_28343);
                
                // blocked_v3.fut:55:5-60:60
                for (int64_t i_34684 = 0; i_34684 < (int64_t) 256; i_34684++) {
                    // blocked_v3.fut:58:54-65
                    
                    int64_t c_28349 = mul64((int64_t) 20, i_34684);
                    
                    // blocked_v3.fut:58:69-72
                    
                    int64_t zt_lhs_28350 = add64((int64_t) 1, i_34684);
                    
                    // blocked_v3.fut:58:74-85
                    
                    int64_t c_28351 = mul64((int64_t) 20, zt_lhs_28350);
                    
                    // blocked_v3.fut:57:30-59:41
                    
                    int64_t j_m_i_28352 = sub64(c_28351, c_28349);
                    
                    // blocked_v3.fut:57:30-59:41
                    
                    int16_t c_28353;
                    int16_t acc_28355 = (int16_t) 0;
                    
                    for (int64_t i_28354 = 0; i_28354 < j_m_i_28352; i_28354++) {
                        // blocked_v3.fut:55:5-60:60
                        
                        int64_t index_primexp_28356 = c_28349 + i_28354;
                        
                        // blocked_v3.fut:55:5-60:60
                        
                        int32_t v_28357 = ((int32_t *) mem_param_34931.mem)[index_primexp_28356];
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_31771 = ashr32(v_28357, get_bit_arg0_28345);
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_31772 = 1 & unsign_arg0_31771;
                        
                        // blocked_v3.fut:84:19-26
                        
                        int16_t i32_res_28359 = sext_i32_i16(unsign_arg0_31772);
                        
                        // blocked_v3.fut:59:36-41
                        
                        int16_t loopres_28360 = add16(acc_28355, i32_res_28359);
                        int16_t acc_tmp_35137 = loopres_28360;
                        
                        acc_28355 = acc_tmp_35137;
                    }
                    c_28353 = acc_28355;
                    // blocked_v3.fut:60:40-57
                    
                    int16_t zm_res_28361 = sub16((int16_t) 20, c_28353);
                    
                    ((int16_t *) mem_34932)[i_34684] = c_28353;
                    ((int16_t *) mem_34933)[i_34684] = zm_res_28361;
                }
                // blocked_v3.fut:85:22-51
                // blocked_v3.fut:85:22-51
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34946, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34932, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                // blocked_v3.fut:85:22-51
                // blocked_v3.fut:85:22-51
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34947, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34933, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                // blocked_v3.fut:71:18-32
                for (int64_t nest_i_35138 = 0; nest_i_35138 < (int64_t) 256; nest_i_35138++) {
                    ((int16_t *) mem_34948)[nest_i_35138] = (int16_t) 0;
                }
                // blocked_v3.fut:71:18-32
                for (int64_t nest_i_35139 = 0; nest_i_35139 < (int64_t) 256; nest_i_35139++) {
                    ((int16_t *) mem_34949)[nest_i_35139] = (int16_t) 0;
                }
                // blocked_v3.fut:86:33-69
                for (int64_t nest_i_35140 = 0; nest_i_35140 < (int64_t) 1; nest_i_35140++) {
                    ((int16_t *) mem_34950)[nest_i_35140] = (int16_t) 0;
                }
                // blocked_v3.fut:70:13-71:39
                
                bool acc_cert_33302;
                bool acc_cert_33303;
                bool acc_cert_33304;
                
                // blocked_v3.fut:68:21-71:39
                
                int16_t discard_34693;
                int16_t discard_34694;
                int16_t scanacc_34687;
                int16_t scanacc_34688;
                
                scanacc_34687 = (int16_t) 0;
                scanacc_34688 = (int16_t) 0;
                for (int64_t i_34692 = 0; i_34692 < (int64_t) 256; i_34692++) {
                    int16_t x_33382 = ((int16_t *) mem_34946)[i_34692];
                    int16_t x_33383 = ((int16_t *) mem_34947)[i_34692];
                    
                    // blocked_v3.fut:68:28-33
                    
                    int64_t lifted_lambda_res_33388 = add64((int64_t) 1, i_34692);
                    
                    // blocked_v3.fut:64:9-13
                    
                    int16_t tmp_33329 = add16(x_33382, scanacc_34687);
                    
                    // blocked_v3.fut:64:18-22
                    
                    int16_t tmp_33330 = add16(x_33383, scanacc_34688);
                    
                    // blocked_v3.fut:70:38-66
                    
                    bool cond_33369 = i_34692 == (int64_t) 255;
                    
                    // blocked_v3.fut:70:38-66
                    
                    int64_t lifted_lambda_res_33370;
                    
                    if (cond_33369) {
                        lifted_lambda_res_33370 = (int64_t) 0;
                    } else {
                        lifted_lambda_res_33370 = (int64_t) -1;
                    }
                    // blocked_v3.fut:70:13-80
                    // UpdateAcc
                    if (sle64((int64_t) 0, lifted_lambda_res_33370) && slt64(lifted_lambda_res_33370, (int64_t) 1)) {
                        ((int16_t *) mem_34950)[lifted_lambda_res_33370] = tmp_33330;
                    }
                    // blocked_v3.fut:71:9-39
                    // UpdateAcc
                    if (sle64((int64_t) 0, lifted_lambda_res_33388) && slt64(lifted_lambda_res_33388, (int64_t) 256)) {
                        ((int16_t *) mem_34949)[lifted_lambda_res_33388] = tmp_33329;
                    }
                    // blocked_v3.fut:71:9-39
                    // UpdateAcc
                    if (sle64((int64_t) 0, lifted_lambda_res_33388) && slt64(lifted_lambda_res_33388, (int64_t) 256)) {
                        ((int16_t *) mem_34948)[lifted_lambda_res_33388] = tmp_33330;
                    }
                    
                    int16_t scanacc_tmp_35141 = tmp_33329;
                    int16_t scanacc_tmp_35142 = tmp_33330;
                    
                    scanacc_34687 = scanacc_tmp_35141;
                    scanacc_34688 = scanacc_tmp_35142;
                }
                discard_34693 = scanacc_34687;
                discard_34694 = scanacc_34688;
                // blocked_v3.fut:71:41-45
                
                int16_t tmp_28416 = ((int16_t *) mem_34950)[(int64_t) 0];
                
                // blocked_v3.fut:88:19-47
                if (memblock_alloc(ctx, &mem_34951, (int64_t) 20480, "mem_34951")) {
                    err = 1;
                    goto cleanup;
                }
                // blocked_v3.fut:88:19-47
                // blocked_v3.fut:88:19-47
                lmad_copy_4b(ctx, 1, (uint32_t *) mem_34951.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_34881, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                // blocked_v3.fut:90:11-109:27
                if (memblock_set(ctx, &mem_param_34957, &mem_34883, "mem_34883") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34960, &mem_34883, "mem_34883") != 0)
                    return 1;
                for (int64_t k_28421 = 0; k_28421 < (int64_t) 20; k_28421++) {
                    // blocked_v3.fut:102:15-77
                    if (memblock_alloc(ctx, &mem_34975, (int64_t) 512, "mem_34975")) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:102:15-77
                    if (memblock_alloc(ctx, &mem_34976, (int64_t) 512, "mem_34976")) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:102:15-77
                    
                    bool acc_cert_33633;
                    
                    // blocked_v3.fut:94:15-108:27
                    for (int64_t i_34700 = 0; i_34700 < (int64_t) 256; i_34700++) {
                        int16_t eta_p_33721 = ((int16_t *) mem_param_34957.mem)[i_34700];
                        int16_t eta_p_33722 = ((int16_t *) mem_param_34960.mem)[i_34700];
                        int16_t eta_p_33723 = ((int16_t *) mem_34949)[i_34700];
                        int16_t eta_p_33724 = ((int16_t *) mem_34948)[i_34700];
                        
                        // blocked_v3.fut:12:28-36
                        
                        int64_t lifted_lambda_res_33728 = mul64((int64_t) 20, i_34700);
                        
                        // blocked_v3.fut:12:13-23
                        
                        int64_t lifted_lambda_res_33729 = add64(k_28421, lifted_lambda_res_33728);
                        
                        // blocked_v3.fut:95:38-43
                        
                        bool x_33730 = sle64((int64_t) 0, lifted_lambda_res_33729);
                        
                        // blocked_v3.fut:95:38-43
                        
                        bool y_33731 = slt64(lifted_lambda_res_33729, (int64_t) 5120);
                        
                        // blocked_v3.fut:95:38-43
                        
                        bool bounds_check_33732 = x_33730 && y_33731;
                        
                        // blocked_v3.fut:95:38-43
                        
                        bool index_certs_33733;
                        
                        if (!bounds_check_33732) {
                            set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) lifted_lambda_res_33729, "] out of bounds for array of shape [", (long long) (int64_t) 5120, "].", "-> #0  blocked_v3.fut:95:38-43\n   #1  blocked_v3.fut:122:7-36\n   #2  blocked_v3.fut:169:13-49\n   #3  blocked_v3.fut:218:3-51\n"));
                            err = FUTHARK_PROGRAM_ERROR;
                            goto cleanup;
                        }
                        // blocked_v3.fut:95:38-43
                        
                        int32_t get_arg0_33734 = ((int32_t *) mem_param_34931.mem)[lifted_lambda_res_33729];
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_33735 = ashr32(get_arg0_33734, get_bit_arg0_28345);
                        
                        // blocked_v3.fut:218:40-51
                        
                        int32_t unsign_arg0_33736 = 1 & unsign_arg0_33735;
                        
                        // blocked_v3.fut:84:19-26
                        
                        int16_t i32_res_33737 = sext_i32_i16(unsign_arg0_33736);
                        
                        // blocked_v3.fut:96:38-98:54
                        
                        bool cond_33738 = i32_res_33737 == (int16_t) 0;
                        
                        // blocked_v3.fut:96:38-98:54
                        
                        int16_t i16_arg0_33739;
                        
                        if (cond_33738) {
                            // blocked_v3.fut:97:46-50
                            
                            int16_t i16_arg0_t_res_33917 = add16(eta_p_33722, eta_p_33724);
                            
                            i16_arg0_33739 = i16_arg0_t_res_33917;
                        } else {
                            // blocked_v3.fut:98:45-49
                            
                            int16_t zp_lhs_33741 = add16(tmp_28416, eta_p_33723);
                            
                            // blocked_v3.fut:98:50-54
                            
                            int16_t i16_arg0_f_res_33742 = add16(eta_p_33721, zp_lhs_33741);
                            
                            i16_arg0_33739 = i16_arg0_f_res_33742;
                        }
                        // blocked_v3.fut:96:29-98:54
                        
                        int64_t i16_res_33743 = sext_i16_i64(i16_arg0_33739);
                        
                        // blocked_v3.fut:102:15-77
                        // UpdateAcc
                        if (sle64((int64_t) 0, i16_res_33743) && slt64(i16_res_33743, (int64_t) 5120)) {
                            ((int32_t *) mem_34951.mem)[i16_res_33743] = get_arg0_33734;
                        }
                        // blocked_v3.fut:107:33-36
                        
                        int16_t tmp_33761 = add16(eta_p_33721, i32_res_33737);
                        
                        // blocked_v3.fut:107:49-52
                        
                        int16_t zp_rhs_33762 = (int16_t) 1 ^ i32_res_33737;
                        
                        // blocked_v3.fut:107:41-52
                        
                        int16_t tmp_33763 = add16(eta_p_33722, zp_rhs_33762);
                        
                        ((int16_t *) mem_34961)[i_34700] = tmp_33761;
                        ((int16_t *) mem_34962)[i_34700] = tmp_33763;
                    }
                    // blocked_v3.fut:102:15-77
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34975.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34961, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    // blocked_v3.fut:102:15-77
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34976.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34962, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    if (memblock_set(ctx, &mem_param_tmp_35146, &mem_34975, "mem_34975") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_tmp_35147, &mem_34976, "mem_34976") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34957, &mem_param_tmp_35146, "mem_param_tmp_35146") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34960, &mem_param_tmp_35147, "mem_param_tmp_35147") != 0)
                        return 1;
                }
                if (memblock_set(ctx, &ext_mem_34984, &mem_param_34957, "mem_param_34957") != 0)
                    return 1;
                if (memblock_set(ctx, &ext_mem_34983, &mem_param_34960, "mem_param_34960") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_tmp_35133, &mem_34951, "mem_34951") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34931, &mem_param_tmp_35133, "mem_param_tmp_35133") != 0)
                    return 1;
            }
            if (memblock_set(ctx, &ext_mem_34988, &mem_param_34931, "mem_param_34931") != 0)
                return 1;
            lmad_copy_4b(ctx, 1, (uint32_t *) mem_34889, i_34709 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (uint32_t *) ext_mem_34988.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
            if (memblock_unref(ctx, &ext_mem_34988, "ext_mem_34988") != 0)
                return 1;
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34892, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34922, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34895, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34909, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
        }
        // blocked_v3.fut:41:5-32
        
        int64_t discard_34718;
        int64_t scanacc_34714 = (int64_t) 0;
        
        for (int64_t i_34716 = 0; i_34716 < dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_28274; i_34716++) {
            int64_t new_index_34755 = squot64(i_34716, n_blocks_28265);
            int64_t binop_y_34757 = n_blocks_28265 * new_index_34755;
            int64_t new_index_34758 = i_34716 - binop_y_34757;
            int16_t eta_p_33067 = ((int16_t *) mem_34895)[new_index_34758 * (int64_t) 16 + new_index_34755];
            
            // blocked_v3.fut:132:14-21
            
            int64_t i16_res_33068 = sext_i16_i64(eta_p_33067);
            
            // blocked_v3.fut:41:20-23
            
            int64_t defunc_0_op_res_28497 = add64(i16_res_33068, scanacc_34714);
            
            ((int64_t *) mem_35006)[i_34716] = scanacc_34714;
            
            int64_t scanacc_tmp_35154 = defunc_0_op_res_28497;
            
            scanacc_34714 = scanacc_tmp_35154;
        }
        discard_34718 = scanacc_34714;
        // blocked_v3.fut:145:17-28
        if (memblock_alloc(ctx, &mem_35014, bytes_34879, "mem_35014")) {
            err = 1;
            goto cleanup;
        }
        lmad_copy_4b(ctx, 2, (uint32_t *) mem_35014.mem, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (uint32_t *) mem_34889, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (int64_t []) {n_blocks_28265, (int64_t) 5120});
        // blocked_v3.fut:145:8-39
        
        bool acc_cert_32882;
        
        // blocked_v3.fut:137:7-145:39
        for (int64_t i_34720 = 0; i_34720 < dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266; i_34720++) {
            int64_t new_index_34749 = squot64(i_34720, (int64_t) 5120);
            int64_t binop_y_34751 = (int64_t) 5120 * new_index_34749;
            int64_t new_index_34752 = i_34720 - binop_y_34751;
            int32_t v_32941 = ((int32_t *) mem_34889)[new_index_34749 * (int64_t) 5120 + new_index_34752];
            
            // blocked_v3.fut:35:9-37:47
            
            int32_t zlzb_rhs_32950;
            int32_t acc_32952 = 0;
            
            for (int32_t i_32951 = 0; i_32951 < 4; i_32951++) {
                // blocked_v3.fut:37:35-38
                
                int32_t get_bit_arg0_32953 = add32(sort_step_arg0_28296, i_32951);
                
                // blocked_v3.fut:218:40-51
                
                int32_t unsign_arg0_32954 = ashr32(v_32941, get_bit_arg0_32953);
                
                // blocked_v3.fut:218:40-51
                
                int32_t unsign_arg0_32955 = 1 & unsign_arg0_32954;
                
                // blocked_v3.fut:37:42-46
                
                int32_t zp_rhs_32956 = shl32(unsign_arg0_32955, i_32951);
                
                // blocked_v3.fut:37:15-46
                
                int32_t loopres_32957 = add32(acc_32952, zp_rhs_32956);
                int32_t acc_tmp_35157 = loopres_32957;
                
                acc_32952 = acc_tmp_35157;
            }
            zlzb_rhs_32950 = acc_32952;
            // blocked_v3.fut:34:5-12
            
            int64_t i32_res_32958 = sext_i32_i64(zlzb_rhs_32950);
            
            // blocked_v3.fut:140:68-93
            
            int64_t block_idx_32959 = sdiv64(i_34720, (int64_t) 5120);
            
            // blocked_v3.fut:141:67-89
            
            bool x_32960 = sle64((int64_t) 0, block_idx_32959);
            
            // blocked_v3.fut:141:67-89
            
            bool y_32961 = slt64(block_idx_32959, n_blocks_28265);
            
            // blocked_v3.fut:141:67-89
            
            bool bounds_check_32962 = x_32960 && y_32961;
            
            // blocked_v3.fut:141:67-89
            
            bool index_certs_32963;
            
            if (!bounds_check_32962) {
                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) block_idx_32959, "] out of bounds for array of shape [", (long long) n_blocks_28265, "].", "-> #0  blocked_v3.fut:141:67-89\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:218:3-51\n"));
                err = FUTHARK_PROGRAM_ERROR;
                goto cleanup;
            }
            // blocked_v3.fut:141:67-94
            
            bool x_32964 = sle64((int64_t) 0, i32_res_32958);
            
            // blocked_v3.fut:141:67-94
            
            bool y_32965 = slt64(i32_res_32958, (int64_t) 16);
            
            // blocked_v3.fut:141:67-94
            
            bool bounds_check_32966 = x_32964 && y_32965;
            
            // blocked_v3.fut:141:67-94
            
            bool index_certs_32967;
            
            if (!bounds_check_32966) {
                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) i32_res_32958, "] out of bounds for array of shape [", (long long) (int64_t) 16, "].", "-> #0  blocked_v3.fut:141:67-94\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:218:3-51\n"));
                err = FUTHARK_PROGRAM_ERROR;
                goto cleanup;
            }
            // blocked_v3.fut:169:13-49
            
            int64_t binop_x_32968 = n_blocks_28265 * i32_res_32958;
            
            // blocked_v3.fut:169:13-49
            
            int64_t index_primexp_32969 = block_idx_32959 + binop_x_32968;
            
            // blocked_v3.fut:169:13-49
            
            int64_t new_offset_32970 = ((int64_t *) mem_35006)[index_primexp_32969];
            
            // blocked_v3.fut:137:7-144:83
            
            int16_t i16_arg0_32971 = ((int16_t *) mem_34892)[block_idx_32959 * (int64_t) 16 + i32_res_32958];
            
            // blocked_v3.fut:142:73-108
            
            int64_t i16_res_32972 = sext_i16_i64(i16_arg0_32971);
            
            // blocked_v3.fut:143:92-103
            
            int64_t zp_lhs_32973 = mul64((int64_t) 5120, block_idx_32959);
            
            // blocked_v3.fut:143:104-122
            
            int64_t old_offset_32974 = add64(i16_res_32972, zp_lhs_32973);
            
            // blocked_v3.fut:144:56-68
            
            int64_t zp_lhs_32975 = sub64(i_34720, old_offset_32974);
            
            // blocked_v3.fut:144:70-82
            
            int64_t defunc_0_f_res_32976 = add64(new_offset_32970, zp_lhs_32975);
            
            // blocked_v3.fut:145:8-39
            // UpdateAcc
            if (sle64((int64_t) 0, defunc_0_f_res_32976) && slt64(defunc_0_f_res_32976, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_28266)) {
                ((int32_t *) mem_35014.mem)[defunc_0_f_res_32976] = v_32941;
            }
        }
        if (memblock_set(ctx, &mem_param_tmp_35121, &mem_35014, "mem_35014") != 0)
            return 1;
        if (memblock_set(ctx, &mem_param_34886, &mem_param_tmp_35121, "mem_param_tmp_35121") != 0)
            return 1;
    }
    if (memblock_set(ctx, &ext_mem_35017, &mem_param_34886, "mem_param_34886") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34883, "mem_34883") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34908, "mem_34908") != 0)
        return 1;
    if (memblock_set(ctx, &mem_out_35119, &ext_mem_35017, "ext_mem_35017") != 0)
        return 1;
    if (memblock_set(ctx, &*mem_out_p_35208, &mem_out_35119, "mem_out_35119") != 0)
        return 1;
    
  cleanup:
    {
        free(mem_34881);
        free(mem_34882);
        free(mem_34889);
        free(mem_34892);
        free(mem_34895);
        free(mem_34909);
        free(mem_34922);
        free(mem_34932);
        free(mem_34933);
        free(mem_34946);
        free(mem_34947);
        free(mem_34948);
        free(mem_34949);
        free(mem_34950);
        free(mem_34961);
        free(mem_34962);
        free(mem_35006);
        if (memblock_unref(ctx, &mem_param_tmp_35121, "mem_param_tmp_35121") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35014, "mem_35014") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35133, "mem_param_tmp_35133") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35147, "mem_param_tmp_35147") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35146, "mem_param_tmp_35146") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34976, "mem_34976") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34975, "mem_34975") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34960, "mem_param_34960") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34957, "mem_param_34957") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34983, "ext_mem_34983") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34984, "ext_mem_34984") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34951, "mem_34951") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34931, "mem_param_34931") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34988, "ext_mem_34988") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34886, "mem_param_34886") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35017, "ext_mem_35017") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34908, "mem_34908") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34883, "mem_34883") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_out_35119, "mem_out_35119") != 0)
            return 1;
    }
    return err;
}
FUTHARK_FUN_ATTR int futrts_entry_is_sorted(struct futhark_context *ctx, bool *out_prim_out_35226, struct memblock arrs_mem_34878, int64_t n_21926, int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927)
{
    (void) ctx;
    
    int err = 0;
    int64_t mem_34879_cached_sizze_35227 = 0;
    unsigned char *mem_34879 = NULL;
    int64_t mem_34880_cached_sizze_35228 = 0;
    unsigned char *mem_34880 = NULL;
    int64_t mem_34888_cached_sizze_35229 = 0;
    unsigned char *mem_34888 = NULL;
    int64_t mem_34891_cached_sizze_35230 = 0;
    unsigned char *mem_34891 = NULL;
    int64_t mem_34894_cached_sizze_35231 = 0;
    unsigned char *mem_34894 = NULL;
    int64_t mem_34908_cached_sizze_35232 = 0;
    unsigned char *mem_34908 = NULL;
    int64_t mem_34921_cached_sizze_35233 = 0;
    unsigned char *mem_34921 = NULL;
    int64_t mem_34931_cached_sizze_35234 = 0;
    unsigned char *mem_34931 = NULL;
    int64_t mem_34932_cached_sizze_35235 = 0;
    unsigned char *mem_34932 = NULL;
    int64_t mem_34945_cached_sizze_35236 = 0;
    unsigned char *mem_34945 = NULL;
    int64_t mem_34946_cached_sizze_35237 = 0;
    unsigned char *mem_34946 = NULL;
    int64_t mem_34947_cached_sizze_35238 = 0;
    unsigned char *mem_34947 = NULL;
    int64_t mem_34948_cached_sizze_35239 = 0;
    unsigned char *mem_34948 = NULL;
    int64_t mem_34949_cached_sizze_35240 = 0;
    unsigned char *mem_34949 = NULL;
    int64_t mem_34960_cached_sizze_35241 = 0;
    unsigned char *mem_34960 = NULL;
    int64_t mem_34961_cached_sizze_35242 = 0;
    unsigned char *mem_34961 = NULL;
    int64_t mem_35005_cached_sizze_35243 = 0;
    unsigned char *mem_35005 = NULL;
    struct memblock mem_param_tmp_35122;
    
    mem_param_tmp_35122.references = NULL;
    
    struct memblock mem_35013;
    
    mem_35013.references = NULL;
    
    struct memblock mem_param_tmp_35135;
    
    mem_param_tmp_35135.references = NULL;
    
    struct memblock mem_param_tmp_35149;
    
    mem_param_tmp_35149.references = NULL;
    
    struct memblock mem_param_tmp_35148;
    
    mem_param_tmp_35148.references = NULL;
    
    struct memblock mem_34975;
    
    mem_34975.references = NULL;
    
    struct memblock mem_34974;
    
    mem_34974.references = NULL;
    
    struct memblock mem_param_34959;
    
    mem_param_34959.references = NULL;
    
    struct memblock mem_param_34956;
    
    mem_param_34956.references = NULL;
    
    struct memblock ext_mem_34982;
    
    ext_mem_34982.references = NULL;
    
    struct memblock ext_mem_34983;
    
    ext_mem_34983.references = NULL;
    
    struct memblock mem_34950;
    
    mem_34950.references = NULL;
    
    struct memblock mem_param_34930;
    
    mem_param_34930.references = NULL;
    
    struct memblock ext_mem_34987;
    
    ext_mem_34987.references = NULL;
    
    struct memblock mem_param_34884;
    
    mem_param_34884.references = NULL;
    
    struct memblock ext_mem_35016;
    
    ext_mem_35016.references = NULL;
    
    struct memblock mem_34907;
    
    mem_34907.references = NULL;
    
    struct memblock mem_34881;
    
    mem_34881.references = NULL;
    
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    bool prim_out_35119;
    bool assert_cond_29772 = (int64_t) 5120 == dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927;
    bool assert_c_29773;
    
    if (!assert_cond_29772) {
        set_error(ctx, msgprintf("Error: %s\n\nBacktrace:\n%s", "Assertion is false: entry point arguments have invalid sizes.", "-> #0  unknown location\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:163:17-77
    
    bool cond_29774 = dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 == (int64_t) 0;
    
    // blocked_v3.fut:163:17-77
    
    int32_t iters_29775;
    
    if (cond_29774) {
        iters_29775 = 0;
    } else {
        iters_29775 = 8;
    }
    // blocked_v3.fut:164:22-47
    
    int64_t n_blocks_29776 = sdiv64(dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927, (int64_t) 5120);
    
    // blocked_v3.fut:165:21-56
    
    int64_t dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777 = mul64((int64_t) 5120, n_blocks_29776);
    
    // blocked_v3.fut:165:14-60
    
    bool dim_match_29778 = dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777 == dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927;
    
    // blocked_v3.fut:165:14-60
    
    bool empty_or_match_cert_29779;
    
    if (!dim_match_29778) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927, "] cannot match shape of type \"[", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777, "]u32\".", "-> #0  blocked_v3.fut:165:14-60\n   #1  blocked_v3.fut:193:23-75\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:193:23-75
    
    bool loop_nonempty_29780 = slt32(0, iters_29775);
    
    // blocked_v3.fut:118:24-121:20
    
    bool binop_x_29782 = sle64((int64_t) 0, n_blocks_29776);
    
    // blocked_v3.fut:193:23-75
    
    bool loop_not_taken_29783 = !loop_nonempty_29780;
    
    // blocked_v3.fut:193:23-75
    
    bool protect_assert_disj_29784 = binop_x_29782 || loop_not_taken_29783;
    
    // blocked_v3.fut:118:24-121:20
    
    bool dim_ok_cert_29785;
    
    if (!protect_assert_disj_29784) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s%lld%s\n\nBacktrace:\n%s", "Cannot unflatten array of shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777, "] to array of shape [", (long long) n_blocks_29776, "][", (long long) (int64_t) 5120, "]", "-> #0  blocked_v3.fut:118:24-121:20\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:193:23-75\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:166:8-13
    
    bool dim_match_29792 = dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 == dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777;
    
    // blocked_v3.fut:166:8-13
    
    bool empty_or_match_cert_29793;
    
    if (!dim_match_29792) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777, "] cannot match shape of type \"[", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927, "]u32\".", "-> #0  blocked_v3.fut:166:8-13\n   #1  blocked_v3.fut:167:8-169:49\n   #2  blocked_v3.fut:193:23-75\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34887 = (int64_t) 20480 * n_blocks_29776;
    
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34890 = (int64_t) 32 * n_blocks_29776;
    
    // blocked_v3.fut:41:5-32
    
    int64_t bytes_35004 = (int64_t) 128 * n_blocks_29776;
    
    // blocked_v3.fut:169:13-49
    
    int64_t dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_29781 = mul64((int64_t) 16, n_blocks_29776);
    
    // blocked_v3.fut:88:19-47
    if (mem_34879_cached_sizze_35227 < (int64_t) 20480) {
        err = lexical_realloc(ctx, &mem_34879, &mem_34879_cached_sizze_35227, (int64_t) 20480);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    if (mem_34880_cached_sizze_35228 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34880, &mem_34880_cached_sizze_35228, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    for (int64_t nest_i_35120 = 0; nest_i_35120 < (int64_t) 256; nest_i_35120++) {
        ((int16_t *) mem_34880)[nest_i_35120] = (int16_t) 0;
    }
    // blocked_v3.fut:87:20-63
    if (memblock_alloc(ctx, &mem_34881, (int64_t) 512, "mem_34881")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:20-63
    // blocked_v3.fut:87:20-63
    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34881.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34880, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
    // blocked_v3.fut:122:7-36
    if (mem_34888_cached_sizze_35229 < bytes_34887) {
        err = lexical_realloc(ctx, &mem_34888, &mem_34888_cached_sizze_35229, bytes_34887);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34891_cached_sizze_35230 < bytes_34890) {
        err = lexical_realloc(ctx, &mem_34891, &mem_34891_cached_sizze_35230, bytes_34890);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34894_cached_sizze_35231 < bytes_34890) {
        err = lexical_realloc(ctx, &mem_34894, &mem_34894_cached_sizze_35231, bytes_34890);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34907, (int64_t) 20480, "mem_34907")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:21:49-22:21
    if (mem_34908_cached_sizze_35232 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34908, &mem_34908_cached_sizze_35232, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:45:29-45
    if (mem_34921_cached_sizze_35233 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34921, &mem_34921_cached_sizze_35233, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34931_cached_sizze_35234 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34931, &mem_34931_cached_sizze_35234, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34932_cached_sizze_35235 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34932, &mem_34932_cached_sizze_35235, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34945_cached_sizze_35236 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34945, &mem_34945_cached_sizze_35236, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34946_cached_sizze_35237 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34946, &mem_34946_cached_sizze_35237, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34947_cached_sizze_35238 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34947, &mem_34947_cached_sizze_35238, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34948_cached_sizze_35239 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34948, &mem_34948_cached_sizze_35239, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:86:33-69
    if (mem_34949_cached_sizze_35240 < (int64_t) 2) {
        err = lexical_realloc(ctx, &mem_34949, &mem_34949_cached_sizze_35240, (int64_t) 2);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34960_cached_sizze_35241 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34960, &mem_34960_cached_sizze_35241, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34961_cached_sizze_35242 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34961, &mem_34961_cached_sizze_35242, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:41:5-32
    if (mem_35005_cached_sizze_35243 < bytes_35004) {
        err = lexical_realloc(ctx, &mem_35005, &mem_35005_cached_sizze_35243, bytes_35004);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:192:3-196:11
    
    bool defunc_0_reduce_res_34328;
    bool redout_34723 = 1;
    
    for (int64_t i_34724 = 0; i_34724 < n_21926; i_34724++) {
        // blocked_v3.fut:167:11-169:49
        
        int64_t lmad_arg_34885 = dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 * i_34724;
        
        // blocked_v3.fut:167:11-169:49
        
        int64_t ext_35015;
        int64_t ctx_param_ext_34882;
        
        if (memblock_set(ctx, &mem_param_34884, &arrs_mem_34878, "arrs_mem_34878") != 0)
            return 1;
        ctx_param_ext_34882 = lmad_arg_34885;
        for (int32_t i_32890 = 0; i_32890 < iters_29775; i_32890++) {
            // blocked_v3.fut:169:26-37
            
            int32_t sort_step_arg0_32892 = mul32(4, i_32890);
            
            // blocked_v3.fut:122:7-36
            for (int64_t i_34709 = 0; i_34709 < n_blocks_29776; i_34709++) {
                // blocked_v3.fut:78:14-25
                // blocked_v3.fut:78:14-25
                lmad_copy_4b(ctx, 1, (uint32_t *) mem_34907.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_param_34884.mem, ctx_param_ext_34882 + i_34709 * ((int64_t) 1 * (int64_t) 5120), (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                // blocked_v3.fut:21:49-22:21
                for (int64_t nest_i_35128 = 0; nest_i_35128 < (int64_t) 16; nest_i_35128++) {
                    ((int16_t *) mem_34908)[nest_i_35128] = (int16_t) 0;
                }
                // blocked_v3.fut:23:8-27:50
                for (int64_t i_32901 = 0; i_32901 < (int64_t) 20; i_32901++) {
                    // blocked_v3.fut:26:32-27:50
                    for (int64_t iter_34669 = 0; iter_34669 < (int64_t) 256; iter_34669++) {
                        // blocked_v3.fut:12:28-36
                        
                        int64_t lifted_lambda_res_33422 = mul64((int64_t) 20, iter_34669);
                        
                        // blocked_v3.fut:12:13-23
                        
                        int64_t lifted_lambda_res_33423 = add64(i_32901, lifted_lambda_res_33422);
                        
                        // blocked_v3.fut:16:26-31
                        
                        int32_t lifted_lambda_res_33425 = ((int32_t *) mem_34907.mem)[lifted_lambda_res_33423];
                        
                        // blocked_v3.fut:35:9-37:47
                        
                        int32_t zlzb_rhs_33427;
                        int32_t acc_33429 = 0;
                        
                        for (int32_t i_33428 = 0; i_33428 < 4; i_33428++) {
                            // blocked_v3.fut:37:35-38
                            
                            int32_t get_bit_arg0_33430 = add32(sort_step_arg0_32892, i_33428);
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_33431 = ashr32(lifted_lambda_res_33425, get_bit_arg0_33430);
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_33432 = 1 & unsign_arg0_33431;
                            
                            // blocked_v3.fut:37:42-46
                            
                            int32_t zp_rhs_33433 = shl32(unsign_arg0_33432, i_33428);
                            
                            // blocked_v3.fut:37:15-46
                            
                            int32_t loopres_33434 = add32(acc_33429, zp_rhs_33433);
                            int32_t acc_tmp_35131 = loopres_33434;
                            
                            acc_33429 = acc_tmp_35131;
                        }
                        zlzb_rhs_33427 = acc_33429;
                        // blocked_v3.fut:34:5-12
                        
                        int64_t i32_res_33435 = sext_i32_i64(zlzb_rhs_33427);
                        bool less_than_zzero_34673 = slt64(i32_res_33435, (int64_t) 0);
                        bool greater_than_sizze_34674 = sle64((int64_t) 16, i32_res_33435);
                        bool outside_bounds_dim_34675 = less_than_zzero_34673 || greater_than_sizze_34674;
                        
                        if (!outside_bounds_dim_34675) {
                            int16_t read_hist_34677 = ((int16_t *) mem_34908)[i32_res_33435];
                            
                            // blocked_v3.fut:27:34-37
                            
                            int16_t defunc_0_f_res_32927 = add16((int16_t) 1, read_hist_34677);
                            
                            ((int16_t *) mem_34908)[i32_res_33435] = defunc_0_f_res_32927;
                        }
                    }
                }
                // blocked_v3.fut:45:29-45
                for (int64_t nest_i_35132 = 0; nest_i_35132 < (int64_t) 16; nest_i_35132++) {
                    ((int16_t *) mem_34921)[nest_i_35132] = (int16_t) 0;
                }
                // blocked_v3.fut:45:6-49:35
                
                int16_t sequential_offsets_res_32932;
                int16_t acc_32935 = (int16_t) 0;
                
                for (int64_t i_32933 = 0; i_32933 < (int64_t) 16; i_32933++) {
                    // blocked_v3.fut:48:12-28
                    ((int16_t *) mem_34921)[i_32933] = acc_32935;
                    // blocked_v3.fut:49:27-34
                    
                    int16_t zp_rhs_32937 = ((int16_t *) mem_34908)[i_32933];
                    
                    // blocked_v3.fut:49:25-34
                    
                    int16_t tmp_32938 = add16(acc_32935, zp_rhs_32937);
                    int16_t acc_tmp_35134 = tmp_32938;
                    
                    acc_32935 = acc_tmp_35134;
                }
                sequential_offsets_res_32932 = acc_32935;
                // blocked_v3.fut:82:7-110:15
                if (memblock_set(ctx, &mem_param_34930, &mem_34907, "mem_34907") != 0)
                    return 1;
                for (int32_t i_32940 = 0; i_32940 < 4; i_32940++) {
                    // blocked_v3.fut:84:42-51
                    
                    int32_t get_bit_arg0_32942 = add32(sort_step_arg0_32892, i_32940);
                    
                    // blocked_v3.fut:55:5-60:60
                    for (int64_t i_34684 = 0; i_34684 < (int64_t) 256; i_34684++) {
                        // blocked_v3.fut:58:54-65
                        
                        int64_t c_32946 = mul64((int64_t) 20, i_34684);
                        
                        // blocked_v3.fut:58:69-72
                        
                        int64_t zt_lhs_32947 = add64((int64_t) 1, i_34684);
                        
                        // blocked_v3.fut:58:74-85
                        
                        int64_t c_32948 = mul64((int64_t) 20, zt_lhs_32947);
                        
                        // blocked_v3.fut:57:30-59:41
                        
                        int64_t j_m_i_32949 = sub64(c_32948, c_32946);
                        
                        // blocked_v3.fut:57:30-59:41
                        
                        int16_t c_32950;
                        int16_t acc_32952 = (int16_t) 0;
                        
                        for (int64_t i_32951 = 0; i_32951 < j_m_i_32949; i_32951++) {
                            // blocked_v3.fut:55:5-60:60
                            
                            int64_t index_primexp_32953 = c_32946 + i_32951;
                            
                            // blocked_v3.fut:55:5-60:60
                            
                            int32_t v_32954 = ((int32_t *) mem_param_34930.mem)[index_primexp_32953];
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_32955 = ashr32(v_32954, get_bit_arg0_32942);
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_32956 = 1 & unsign_arg0_32955;
                            
                            // blocked_v3.fut:84:19-26
                            
                            int16_t i32_res_32957 = sext_i32_i16(unsign_arg0_32956);
                            
                            // blocked_v3.fut:59:36-41
                            
                            int16_t loopres_32958 = add16(acc_32952, i32_res_32957);
                            int16_t acc_tmp_35139 = loopres_32958;
                            
                            acc_32952 = acc_tmp_35139;
                        }
                        c_32950 = acc_32952;
                        // blocked_v3.fut:60:40-57
                        
                        int16_t zm_res_32959 = sub16((int16_t) 20, c_32950);
                        
                        ((int16_t *) mem_34931)[i_34684] = c_32950;
                        ((int16_t *) mem_34932)[i_34684] = zm_res_32959;
                    }
                    // blocked_v3.fut:85:22-51
                    // blocked_v3.fut:85:22-51
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34945, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34931, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    // blocked_v3.fut:85:22-51
                    // blocked_v3.fut:85:22-51
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34946, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34932, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    // blocked_v3.fut:71:18-32
                    for (int64_t nest_i_35140 = 0; nest_i_35140 < (int64_t) 256; nest_i_35140++) {
                        ((int16_t *) mem_34947)[nest_i_35140] = (int16_t) 0;
                    }
                    // blocked_v3.fut:71:18-32
                    for (int64_t nest_i_35141 = 0; nest_i_35141 < (int64_t) 256; nest_i_35141++) {
                        ((int16_t *) mem_34948)[nest_i_35141] = (int16_t) 0;
                    }
                    // blocked_v3.fut:86:33-69
                    for (int64_t nest_i_35142 = 0; nest_i_35142 < (int64_t) 1; nest_i_35142++) {
                        ((int16_t *) mem_34949)[nest_i_35142] = (int16_t) 0;
                    }
                    // blocked_v3.fut:70:13-71:39
                    
                    bool acc_cert_33622;
                    bool acc_cert_33623;
                    bool acc_cert_33624;
                    
                    // blocked_v3.fut:68:21-71:39
                    
                    int16_t discard_34693;
                    int16_t discard_34694;
                    int16_t scanacc_34687;
                    int16_t scanacc_34688;
                    
                    scanacc_34687 = (int16_t) 0;
                    scanacc_34688 = (int16_t) 0;
                    for (int64_t i_34692 = 0; i_34692 < (int64_t) 256; i_34692++) {
                        int16_t x_33702 = ((int16_t *) mem_34945)[i_34692];
                        int16_t x_33703 = ((int16_t *) mem_34946)[i_34692];
                        
                        // blocked_v3.fut:68:28-33
                        
                        int64_t lifted_lambda_res_33708 = add64((int64_t) 1, i_34692);
                        
                        // blocked_v3.fut:64:9-13
                        
                        int16_t tmp_33649 = add16(x_33702, scanacc_34687);
                        
                        // blocked_v3.fut:64:18-22
                        
                        int16_t tmp_33650 = add16(x_33703, scanacc_34688);
                        
                        // blocked_v3.fut:70:38-66
                        
                        bool cond_33689 = i_34692 == (int64_t) 255;
                        
                        // blocked_v3.fut:70:38-66
                        
                        int64_t lifted_lambda_res_33690;
                        
                        if (cond_33689) {
                            lifted_lambda_res_33690 = (int64_t) 0;
                        } else {
                            lifted_lambda_res_33690 = (int64_t) -1;
                        }
                        // blocked_v3.fut:70:13-80
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33690) && slt64(lifted_lambda_res_33690, (int64_t) 1)) {
                            ((int16_t *) mem_34949)[lifted_lambda_res_33690] = tmp_33650;
                        }
                        // blocked_v3.fut:71:9-39
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33708) && slt64(lifted_lambda_res_33708, (int64_t) 256)) {
                            ((int16_t *) mem_34948)[lifted_lambda_res_33708] = tmp_33649;
                        }
                        // blocked_v3.fut:71:9-39
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33708) && slt64(lifted_lambda_res_33708, (int64_t) 256)) {
                            ((int16_t *) mem_34947)[lifted_lambda_res_33708] = tmp_33650;
                        }
                        
                        int16_t scanacc_tmp_35143 = tmp_33649;
                        int16_t scanacc_tmp_35144 = tmp_33650;
                        
                        scanacc_34687 = scanacc_tmp_35143;
                        scanacc_34688 = scanacc_tmp_35144;
                    }
                    discard_34693 = scanacc_34687;
                    discard_34694 = scanacc_34688;
                    // blocked_v3.fut:71:41-45
                    
                    int16_t tmp_33014 = ((int16_t *) mem_34949)[(int64_t) 0];
                    
                    // blocked_v3.fut:88:19-47
                    if (memblock_alloc(ctx, &mem_34950, (int64_t) 20480, "mem_34950")) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:88:19-47
                    // blocked_v3.fut:88:19-47
                    lmad_copy_4b(ctx, 1, (uint32_t *) mem_34950.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint32_t *) mem_34879, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                    // blocked_v3.fut:90:11-109:27
                    if (memblock_set(ctx, &mem_param_34956, &mem_34881, "mem_34881") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34959, &mem_34881, "mem_34881") != 0)
                        return 1;
                    for (int64_t k_33019 = 0; k_33019 < (int64_t) 20; k_33019++) {
                        // blocked_v3.fut:102:15-77
                        if (memblock_alloc(ctx, &mem_34974, (int64_t) 512, "mem_34974")) {
                            err = 1;
                            goto cleanup;
                        }
                        // blocked_v3.fut:102:15-77
                        if (memblock_alloc(ctx, &mem_34975, (int64_t) 512, "mem_34975")) {
                            err = 1;
                            goto cleanup;
                        }
                        // blocked_v3.fut:102:15-77
                        
                        bool acc_cert_33953;
                        
                        // blocked_v3.fut:94:15-108:27
                        for (int64_t i_34700 = 0; i_34700 < (int64_t) 256; i_34700++) {
                            int16_t eta_p_34041 = ((int16_t *) mem_param_34956.mem)[i_34700];
                            int16_t eta_p_34042 = ((int16_t *) mem_param_34959.mem)[i_34700];
                            int16_t eta_p_34043 = ((int16_t *) mem_34948)[i_34700];
                            int16_t eta_p_34044 = ((int16_t *) mem_34947)[i_34700];
                            
                            // blocked_v3.fut:12:28-36
                            
                            int64_t lifted_lambda_res_34048 = mul64((int64_t) 20, i_34700);
                            
                            // blocked_v3.fut:12:13-23
                            
                            int64_t lifted_lambda_res_34049 = add64(k_33019, lifted_lambda_res_34048);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool x_34050 = sle64((int64_t) 0, lifted_lambda_res_34049);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool y_34051 = slt64(lifted_lambda_res_34049, (int64_t) 5120);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool bounds_check_34052 = x_34050 && y_34051;
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool index_certs_34053;
                            
                            if (!bounds_check_34052) {
                                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) lifted_lambda_res_34049, "] out of bounds for array of shape [", (long long) (int64_t) 5120, "].", "-> #0  blocked_v3.fut:95:38-43\n   #1  blocked_v3.fut:122:7-36\n   #2  blocked_v3.fut:169:13-49\n   #3  blocked_v3.fut:193:23-75\n"));
                                err = FUTHARK_PROGRAM_ERROR;
                                goto cleanup;
                            }
                            // blocked_v3.fut:95:38-43
                            
                            int32_t get_arg0_34054 = ((int32_t *) mem_param_34930.mem)[lifted_lambda_res_34049];
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_34055 = ashr32(get_arg0_34054, get_bit_arg0_32942);
                            
                            // blocked_v3.fut:193:60-71
                            
                            int32_t unsign_arg0_34056 = 1 & unsign_arg0_34055;
                            
                            // blocked_v3.fut:84:19-26
                            
                            int16_t i32_res_34057 = sext_i32_i16(unsign_arg0_34056);
                            
                            // blocked_v3.fut:96:38-98:54
                            
                            bool cond_34058 = i32_res_34057 == (int16_t) 0;
                            
                            // blocked_v3.fut:96:38-98:54
                            
                            int16_t i16_arg0_34059;
                            
                            if (cond_34058) {
                                // blocked_v3.fut:97:46-50
                                
                                int16_t i16_arg0_t_res_34313 = add16(eta_p_34042, eta_p_34044);
                                
                                i16_arg0_34059 = i16_arg0_t_res_34313;
                            } else {
                                // blocked_v3.fut:98:45-49
                                
                                int16_t zp_lhs_34061 = add16(tmp_33014, eta_p_34043);
                                
                                // blocked_v3.fut:98:50-54
                                
                                int16_t i16_arg0_f_res_34062 = add16(eta_p_34041, zp_lhs_34061);
                                
                                i16_arg0_34059 = i16_arg0_f_res_34062;
                            }
                            // blocked_v3.fut:96:29-98:54
                            
                            int64_t i16_res_34063 = sext_i16_i64(i16_arg0_34059);
                            
                            // blocked_v3.fut:102:15-77
                            // UpdateAcc
                            if (sle64((int64_t) 0, i16_res_34063) && slt64(i16_res_34063, (int64_t) 5120)) {
                                ((int32_t *) mem_34950.mem)[i16_res_34063] = get_arg0_34054;
                            }
                            // blocked_v3.fut:107:33-36
                            
                            int16_t tmp_34081 = add16(eta_p_34041, i32_res_34057);
                            
                            // blocked_v3.fut:107:49-52
                            
                            int16_t zp_rhs_34082 = (int16_t) 1 ^ i32_res_34057;
                            
                            // blocked_v3.fut:107:41-52
                            
                            int16_t tmp_34083 = add16(eta_p_34042, zp_rhs_34082);
                            
                            ((int16_t *) mem_34960)[i_34700] = tmp_34081;
                            ((int16_t *) mem_34961)[i_34700] = tmp_34083;
                        }
                        // blocked_v3.fut:102:15-77
                        lmad_copy_2b(ctx, 1, (uint16_t *) mem_34974.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34960, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                        // blocked_v3.fut:102:15-77
                        lmad_copy_2b(ctx, 1, (uint16_t *) mem_34975.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34961, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                        if (memblock_set(ctx, &mem_param_tmp_35148, &mem_34974, "mem_34974") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_tmp_35149, &mem_34975, "mem_34975") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_34956, &mem_param_tmp_35148, "mem_param_tmp_35148") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_34959, &mem_param_tmp_35149, "mem_param_tmp_35149") != 0)
                            return 1;
                    }
                    if (memblock_set(ctx, &ext_mem_34983, &mem_param_34956, "mem_param_34956") != 0)
                        return 1;
                    if (memblock_set(ctx, &ext_mem_34982, &mem_param_34959, "mem_param_34959") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_tmp_35135, &mem_34950, "mem_34950") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34930, &mem_param_tmp_35135, "mem_param_tmp_35135") != 0)
                        return 1;
                }
                if (memblock_set(ctx, &ext_mem_34987, &mem_param_34930, "mem_param_34930") != 0)
                    return 1;
                lmad_copy_4b(ctx, 1, (uint32_t *) mem_34888, i_34709 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (uint32_t *) ext_mem_34987.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                if (memblock_unref(ctx, &ext_mem_34987, "ext_mem_34987") != 0)
                    return 1;
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34891, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34921, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34894, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34908, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
            }
            // blocked_v3.fut:41:5-32
            
            int64_t discard_34718;
            int64_t scanacc_34714 = (int64_t) 0;
            
            for (int64_t i_34716 = 0; i_34716 < dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_29781; i_34716++) {
                int64_t new_index_34757 = squot64(i_34716, n_blocks_29776);
                int64_t binop_y_34759 = n_blocks_29776 * new_index_34757;
                int64_t new_index_34760 = i_34716 - binop_y_34759;
                int16_t eta_p_33387 = ((int16_t *) mem_34894)[new_index_34760 * (int64_t) 16 + new_index_34757];
                
                // blocked_v3.fut:132:14-21
                
                int64_t i16_res_33388 = sext_i16_i64(eta_p_33387);
                
                // blocked_v3.fut:41:20-23
                
                int64_t defunc_0_op_res_33094 = add64(i16_res_33388, scanacc_34714);
                
                ((int64_t *) mem_35005)[i_34716] = scanacc_34714;
                
                int64_t scanacc_tmp_35156 = defunc_0_op_res_33094;
                
                scanacc_34714 = scanacc_tmp_35156;
            }
            discard_34718 = scanacc_34714;
            // blocked_v3.fut:145:17-28
            if (memblock_alloc(ctx, &mem_35013, bytes_34887, "mem_35013")) {
                err = 1;
                goto cleanup;
            }
            lmad_copy_4b(ctx, 2, (uint32_t *) mem_35013.mem, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (uint32_t *) mem_34888, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (int64_t []) {n_blocks_29776, (int64_t) 5120});
            // blocked_v3.fut:145:8-39
            
            bool acc_cert_33202;
            
            // blocked_v3.fut:137:7-145:39
            for (int64_t i_34720 = 0; i_34720 < dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777; i_34720++) {
                int64_t new_index_34751 = squot64(i_34720, (int64_t) 5120);
                int64_t binop_y_34753 = (int64_t) 5120 * new_index_34751;
                int64_t new_index_34754 = i_34720 - binop_y_34753;
                int32_t v_33261 = ((int32_t *) mem_34888)[new_index_34751 * (int64_t) 5120 + new_index_34754];
                
                // blocked_v3.fut:35:9-37:47
                
                int32_t zlzb_rhs_33270;
                int32_t acc_33272 = 0;
                
                for (int32_t i_33271 = 0; i_33271 < 4; i_33271++) {
                    // blocked_v3.fut:37:35-38
                    
                    int32_t get_bit_arg0_33273 = add32(sort_step_arg0_32892, i_33271);
                    
                    // blocked_v3.fut:193:60-71
                    
                    int32_t unsign_arg0_33274 = ashr32(v_33261, get_bit_arg0_33273);
                    
                    // blocked_v3.fut:193:60-71
                    
                    int32_t unsign_arg0_33275 = 1 & unsign_arg0_33274;
                    
                    // blocked_v3.fut:37:42-46
                    
                    int32_t zp_rhs_33276 = shl32(unsign_arg0_33275, i_33271);
                    
                    // blocked_v3.fut:37:15-46
                    
                    int32_t loopres_33277 = add32(acc_33272, zp_rhs_33276);
                    int32_t acc_tmp_35159 = loopres_33277;
                    
                    acc_33272 = acc_tmp_35159;
                }
                zlzb_rhs_33270 = acc_33272;
                // blocked_v3.fut:34:5-12
                
                int64_t i32_res_33278 = sext_i32_i64(zlzb_rhs_33270);
                
                // blocked_v3.fut:140:68-93
                
                int64_t block_idx_33279 = sdiv64(i_34720, (int64_t) 5120);
                
                // blocked_v3.fut:141:67-89
                
                bool x_33280 = sle64((int64_t) 0, block_idx_33279);
                
                // blocked_v3.fut:141:67-89
                
                bool y_33281 = slt64(block_idx_33279, n_blocks_29776);
                
                // blocked_v3.fut:141:67-89
                
                bool bounds_check_33282 = x_33280 && y_33281;
                
                // blocked_v3.fut:141:67-89
                
                bool index_certs_33283;
                
                if (!bounds_check_33282) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) block_idx_33279, "] out of bounds for array of shape [", (long long) n_blocks_29776, "].", "-> #0  blocked_v3.fut:141:67-89\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:193:23-75\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:141:67-94
                
                bool x_33284 = sle64((int64_t) 0, i32_res_33278);
                
                // blocked_v3.fut:141:67-94
                
                bool y_33285 = slt64(i32_res_33278, (int64_t) 16);
                
                // blocked_v3.fut:141:67-94
                
                bool bounds_check_33286 = x_33284 && y_33285;
                
                // blocked_v3.fut:141:67-94
                
                bool index_certs_33287;
                
                if (!bounds_check_33286) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) i32_res_33278, "] out of bounds for array of shape [", (long long) (int64_t) 16, "].", "-> #0  blocked_v3.fut:141:67-94\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:193:23-75\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:169:13-49
                
                int64_t binop_x_33288 = n_blocks_29776 * i32_res_33278;
                
                // blocked_v3.fut:169:13-49
                
                int64_t index_primexp_33289 = block_idx_33279 + binop_x_33288;
                
                // blocked_v3.fut:169:13-49
                
                int64_t new_offset_33290 = ((int64_t *) mem_35005)[index_primexp_33289];
                
                // blocked_v3.fut:137:7-144:83
                
                int16_t i16_arg0_33291 = ((int16_t *) mem_34891)[block_idx_33279 * (int64_t) 16 + i32_res_33278];
                
                // blocked_v3.fut:142:73-108
                
                int64_t i16_res_33292 = sext_i16_i64(i16_arg0_33291);
                
                // blocked_v3.fut:143:92-103
                
                int64_t zp_lhs_33293 = mul64((int64_t) 5120, block_idx_33279);
                
                // blocked_v3.fut:143:104-122
                
                int64_t old_offset_33294 = add64(i16_res_33292, zp_lhs_33293);
                
                // blocked_v3.fut:144:56-68
                
                int64_t zp_lhs_33295 = sub64(i_34720, old_offset_33294);
                
                // blocked_v3.fut:144:70-82
                
                int64_t defunc_0_f_res_33296 = add64(new_offset_33290, zp_lhs_33295);
                
                // blocked_v3.fut:145:8-39
                // UpdateAcc
                if (sle64((int64_t) 0, defunc_0_f_res_33296) && slt64(defunc_0_f_res_33296, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_29777)) {
                    ((int32_t *) mem_35013.mem)[defunc_0_f_res_33296] = v_33261;
                }
            }
            if (memblock_set(ctx, &mem_param_tmp_35122, &mem_35013, "mem_35013") != 0)
                return 1;
            
            int64_t ctx_param_ext_tmp_35123 = (int64_t) 0;
            
            if (memblock_set(ctx, &mem_param_34884, &mem_param_tmp_35122, "mem_param_tmp_35122") != 0)
                return 1;
            ctx_param_ext_34882 = ctx_param_ext_tmp_35123;
        }
        if (memblock_set(ctx, &ext_mem_35016, &mem_param_34884, "mem_param_34884") != 0)
            return 1;
        ext_35015 = ctx_param_ext_34882;
        // blocked_v3.fut:194:13-195:19
        
        bool defunc_0_reduce_res_34327;
        bool redout_34721 = 1;
        
        for (int64_t i_34722 = 0; i_34722 < dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927; i_34722++) {
            // blocked_v3.fut:194:54-90
            
            bool cond_33183 = i_34722 == (int64_t) 0;
            
            // blocked_v3.fut:194:54-90
            
            bool lifted_lambda_res_33184;
            
            if (cond_33183) {
                lifted_lambda_res_33184 = 1;
            } else {
                // blocked_v3.fut:194:73-76
                
                int64_t zlze_lhs_33185 = sub64(i_34722, (int64_t) 1);
                
                // blocked_v3.fut:194:64-77
                
                bool x_33186 = sle64((int64_t) 0, zlze_lhs_33185);
                
                // blocked_v3.fut:194:64-77
                
                bool y_33187 = slt64(zlze_lhs_33185, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927);
                
                // blocked_v3.fut:194:64-77
                
                bool bounds_check_33188 = x_33186 && y_33187;
                
                // blocked_v3.fut:194:64-77
                
                bool index_certs_33189;
                
                if (!bounds_check_33188) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) zlze_lhs_33185, "] out of bounds for array of shape [", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927, "].", "-> #0  blocked_v3.fut:194:64-77\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:194:64-77
                
                int32_t zlze_lhs_33190 = ((int32_t *) ext_mem_35016.mem)[ext_35015 + zlze_lhs_33185];
                
                // blocked_v3.fut:194:81-90
                
                int32_t zlze_rhs_33195 = ((int32_t *) ext_mem_35016.mem)[ext_35015 + i_34722];
                
                // blocked_v3.fut:194:78-90
                
                bool lifted_lambda_res_f_res_33196 = ule32(zlze_lhs_33190, zlze_rhs_33195);
                
                lifted_lambda_res_33184 = lifted_lambda_res_f_res_33196;
            }
            // blocked_v3.fut:195:16-19
            
            bool x_33170 = lifted_lambda_res_33184 && redout_34721;
            bool redout_tmp_35160 = x_33170;
            
            redout_34721 = redout_tmp_35160;
        }
        defunc_0_reduce_res_34327 = redout_34721;
        if (memblock_unref(ctx, &ext_mem_35016, "ext_mem_35016") != 0)
            return 1;
        // blocked_v3.fut:192:3-196:11
        
        bool x_30083 = defunc_0_reduce_res_34327 && redout_34723;
        bool redout_tmp_35121 = x_30083;
        
        redout_34723 = redout_tmp_35121;
    }
    defunc_0_reduce_res_34328 = redout_34723;
    if (memblock_unref(ctx, &mem_34881, "mem_34881") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34907, "mem_34907") != 0)
        return 1;
    prim_out_35119 = defunc_0_reduce_res_34328;
    *out_prim_out_35226 = prim_out_35119;
    
  cleanup:
    {
        free(mem_34879);
        free(mem_34880);
        free(mem_34888);
        free(mem_34891);
        free(mem_34894);
        free(mem_34908);
        free(mem_34921);
        free(mem_34931);
        free(mem_34932);
        free(mem_34945);
        free(mem_34946);
        free(mem_34947);
        free(mem_34948);
        free(mem_34949);
        free(mem_34960);
        free(mem_34961);
        free(mem_35005);
        if (memblock_unref(ctx, &mem_param_tmp_35122, "mem_param_tmp_35122") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35013, "mem_35013") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35135, "mem_param_tmp_35135") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35149, "mem_param_tmp_35149") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35148, "mem_param_tmp_35148") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34975, "mem_34975") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34974, "mem_34974") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34959, "mem_param_34959") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34956, "mem_param_34956") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34982, "ext_mem_34982") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34983, "ext_mem_34983") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34950, "mem_34950") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34930, "mem_param_34930") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34987, "ext_mem_34987") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34884, "mem_param_34884") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35016, "ext_mem_35016") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34907, "mem_34907") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34881, "mem_34881") != 0)
            return 1;
    }
    return err;
}
FUTHARK_FUN_ATTR int futrts_entry_is_stable(struct futhark_context *ctx, bool *out_prim_out_35244, struct memblock arrs_mem_34878, int64_t n_24423, int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424)
{
    (void) ctx;
    
    int err = 0;
    int64_t mem_34881_cached_sizze_35245 = 0;
    unsigned char *mem_34881 = NULL;
    int64_t mem_34882_cached_sizze_35246 = 0;
    unsigned char *mem_34882 = NULL;
    int64_t mem_34883_cached_sizze_35247 = 0;
    unsigned char *mem_34883 = NULL;
    int64_t mem_34900_cached_sizze_35248 = 0;
    unsigned char *mem_34900 = NULL;
    int64_t mem_34902_cached_sizze_35249 = 0;
    unsigned char *mem_34902 = NULL;
    int64_t mem_34905_cached_sizze_35250 = 0;
    unsigned char *mem_34905 = NULL;
    int64_t mem_34908_cached_sizze_35251 = 0;
    unsigned char *mem_34908 = NULL;
    int64_t mem_34927_cached_sizze_35252 = 0;
    unsigned char *mem_34927 = NULL;
    int64_t mem_34940_cached_sizze_35253 = 0;
    unsigned char *mem_34940 = NULL;
    int64_t mem_34953_cached_sizze_35254 = 0;
    unsigned char *mem_34953 = NULL;
    int64_t mem_34954_cached_sizze_35255 = 0;
    unsigned char *mem_34954 = NULL;
    int64_t mem_34967_cached_sizze_35256 = 0;
    unsigned char *mem_34967 = NULL;
    int64_t mem_34968_cached_sizze_35257 = 0;
    unsigned char *mem_34968 = NULL;
    int64_t mem_34969_cached_sizze_35258 = 0;
    unsigned char *mem_34969 = NULL;
    int64_t mem_34970_cached_sizze_35259 = 0;
    unsigned char *mem_34970 = NULL;
    int64_t mem_34971_cached_sizze_35260 = 0;
    unsigned char *mem_34971 = NULL;
    int64_t mem_34986_cached_sizze_35261 = 0;
    unsigned char *mem_34986 = NULL;
    int64_t mem_34987_cached_sizze_35262 = 0;
    unsigned char *mem_34987 = NULL;
    int64_t mem_35044_cached_sizze_35263 = 0;
    unsigned char *mem_35044 = NULL;
    struct memblock mem_param_tmp_35126;
    
    mem_param_tmp_35126.references = NULL;
    
    struct memblock mem_param_tmp_35125;
    
    mem_param_tmp_35125.references = NULL;
    
    struct memblock mem_35053;
    
    mem_35053.references = NULL;
    
    struct memblock mem_35052;
    
    mem_35052.references = NULL;
    
    struct memblock mem_param_tmp_35141;
    
    mem_param_tmp_35141.references = NULL;
    
    struct memblock mem_param_tmp_35140;
    
    mem_param_tmp_35140.references = NULL;
    
    struct memblock mem_param_tmp_35156;
    
    mem_param_tmp_35156.references = NULL;
    
    struct memblock mem_param_tmp_35155;
    
    mem_param_tmp_35155.references = NULL;
    
    struct memblock mem_35001;
    
    mem_35001.references = NULL;
    
    struct memblock mem_35000;
    
    mem_35000.references = NULL;
    
    struct memblock mem_param_34985;
    
    mem_param_34985.references = NULL;
    
    struct memblock mem_param_34982;
    
    mem_param_34982.references = NULL;
    
    struct memblock ext_mem_35010;
    
    ext_mem_35010.references = NULL;
    
    struct memblock ext_mem_35011;
    
    ext_mem_35011.references = NULL;
    
    struct memblock mem_34973;
    
    mem_34973.references = NULL;
    
    struct memblock mem_34972;
    
    mem_34972.references = NULL;
    
    struct memblock mem_param_34952;
    
    mem_param_34952.references = NULL;
    
    struct memblock mem_param_34949;
    
    mem_param_34949.references = NULL;
    
    struct memblock ext_mem_35018;
    
    ext_mem_35018.references = NULL;
    
    struct memblock ext_mem_35019;
    
    ext_mem_35019.references = NULL;
    
    struct memblock mem_param_34897;
    
    mem_param_34897.references = NULL;
    
    struct memblock mem_param_34894;
    
    mem_param_34894.references = NULL;
    
    struct memblock ext_mem_35058;
    
    ext_mem_35058.references = NULL;
    
    struct memblock ext_mem_35059;
    
    ext_mem_35059.references = NULL;
    
    struct memblock mem_34926;
    
    mem_34926.references = NULL;
    
    struct memblock mem_34925;
    
    mem_34925.references = NULL;
    
    struct memblock mem_34885;
    
    mem_34885.references = NULL;
    
    struct memblock mem_34884;
    
    mem_34884.references = NULL;
    
    struct memblock mem_34880;
    
    mem_34880.references = NULL;
    
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    bool prim_out_35119;
    bool assert_cond_31364 = (int64_t) 5120 == dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424;
    bool assert_c_31365;
    
    if (!assert_cond_31364) {
        set_error(ctx, msgprintf("Error: %s\n\nBacktrace:\n%s", "Assertion is false: entry point arguments have invalid sizes.", "-> #0  unknown location\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:163:17-77
    
    bool cond_31366 = dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 == (int64_t) 0;
    
    // blocked_v3.fut:163:17-77
    
    int32_t iters_31367;
    
    if (cond_31366) {
        iters_31367 = 0;
    } else {
        iters_31367 = 2;
    }
    // blocked_v3.fut:164:22-47
    
    int64_t n_blocks_31368 = sdiv64(dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, (int64_t) 5120);
    
    // blocked_v3.fut:165:21-56
    
    int64_t dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369 = mul64((int64_t) 5120, n_blocks_31368);
    
    // blocked_v3.fut:165:14-60
    
    bool dim_match_31370 = dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369 == dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424;
    
    // blocked_v3.fut:165:14-60
    
    bool empty_or_match_cert_31371;
    
    if (!dim_match_31370) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, "] cannot match shape of type \"[", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369, "](u8, i64)\".", "-> #0  blocked_v3.fut:165:14-60\n   #1  blocked_v3.fut:207:12-84\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:207:12-84
    
    int64_t bytes_34879 = (int64_t) 40960 * n_blocks_31368;
    
    // blocked_v3.fut:207:12-84
    
    bool loop_nonempty_31373 = slt32(0, iters_31367);
    
    // blocked_v3.fut:118:24-121:20
    
    bool binop_x_31375 = sle64((int64_t) 0, n_blocks_31368);
    
    // blocked_v3.fut:207:12-84
    
    bool loop_not_taken_31376 = !loop_nonempty_31373;
    
    // blocked_v3.fut:207:12-84
    
    bool protect_assert_disj_31377 = binop_x_31375 || loop_not_taken_31376;
    
    // blocked_v3.fut:118:24-121:20
    
    bool dim_ok_cert_31378;
    
    if (!protect_assert_disj_31377) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s%lld%s\n\nBacktrace:\n%s", "Cannot unflatten array of shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369, "] to array of shape [", (long long) n_blocks_31368, "][", (long long) (int64_t) 5120, "]", "-> #0  blocked_v3.fut:118:24-121:20\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:207:12-84\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:166:8-13
    
    bool dim_match_31385 = dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 == dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369;
    
    // blocked_v3.fut:166:8-13
    
    bool empty_or_match_cert_31386;
    
    if (!dim_match_31385) {
        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Value of (desugared) shape [", (long long) dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369, "] cannot match shape of type \"[", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, "](u8, i64)\".", "-> #0  blocked_v3.fut:166:8-13\n   #1  blocked_v3.fut:167:8-169:49\n   #2  blocked_v3.fut:207:12-84\n"));
        err = FUTHARK_PROGRAM_ERROR;
        goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34904 = (int64_t) 32 * n_blocks_31368;
    
    // blocked_v3.fut:41:5-32
    
    int64_t bytes_35043 = (int64_t) 128 * n_blocks_31368;
    
    // blocked_v3.fut:207:12-84
    if (memblock_alloc(ctx, &mem_34880, bytes_34879, "mem_34880")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:207:12-84
    for (int64_t i_35120 = 0; i_35120 < dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369; i_35120++) {
        int64_t x_35121 = (int64_t) 0 + i_35120 * (int64_t) 1;
        
        ((int64_t *) mem_34880.mem)[i_35120] = x_35121;
    }
    // blocked_v3.fut:169:13-49
    
    int64_t dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_31374 = mul64((int64_t) 16, n_blocks_31368);
    
    // blocked_v3.fut:88:19-47
    if (mem_34881_cached_sizze_35245 < (int64_t) 5120) {
        err = lexical_realloc(ctx, &mem_34881, &mem_34881_cached_sizze_35245, (int64_t) 5120);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:88:19-47
    if (mem_34882_cached_sizze_35246 < (int64_t) 40960) {
        err = lexical_realloc(ctx, &mem_34882, &mem_34882_cached_sizze_35246, (int64_t) 40960);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    if (mem_34883_cached_sizze_35247 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34883, &mem_34883_cached_sizze_35247, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    for (int64_t nest_i_35122 = 0; nest_i_35122 < (int64_t) 256; nest_i_35122++) {
        ((int16_t *) mem_34883)[nest_i_35122] = (int16_t) 0;
    }
    // blocked_v3.fut:87:20-63
    if (memblock_alloc(ctx, &mem_34884, (int64_t) 512, "mem_34884")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:20-63
    // blocked_v3.fut:87:20-63
    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34884.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34883, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
    // blocked_v3.fut:206:17-30
    if (memblock_alloc(ctx, &mem_34885, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, "mem_34885")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34900_cached_sizze_35248 < bytes_34879) {
        err = lexical_realloc(ctx, &mem_34900, &mem_34900_cached_sizze_35248, bytes_34879);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34902_cached_sizze_35249 < dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369) {
        err = lexical_realloc(ctx, &mem_34902, &mem_34902_cached_sizze_35249, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34905_cached_sizze_35250 < bytes_34904) {
        err = lexical_realloc(ctx, &mem_34905, &mem_34905_cached_sizze_35250, bytes_34904);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34908_cached_sizze_35251 < bytes_34904) {
        err = lexical_realloc(ctx, &mem_34908, &mem_34908_cached_sizze_35251, bytes_34904);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34925, (int64_t) 5120, "mem_34925")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34926, (int64_t) 40960, "mem_34926")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:21:49-22:21
    if (mem_34927_cached_sizze_35252 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34927, &mem_34927_cached_sizze_35252, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:45:29-45
    if (mem_34940_cached_sizze_35253 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34940, &mem_34940_cached_sizze_35253, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34953_cached_sizze_35254 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34953, &mem_34953_cached_sizze_35254, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34954_cached_sizze_35255 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34954, &mem_34954_cached_sizze_35255, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34967_cached_sizze_35256 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34967, &mem_34967_cached_sizze_35256, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34968_cached_sizze_35257 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34968, &mem_34968_cached_sizze_35257, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34969_cached_sizze_35258 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34969, &mem_34969_cached_sizze_35258, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34970_cached_sizze_35259 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34970, &mem_34970_cached_sizze_35259, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:86:33-69
    if (mem_34971_cached_sizze_35260 < (int64_t) 2) {
        err = lexical_realloc(ctx, &mem_34971, &mem_34971_cached_sizze_35260, (int64_t) 2);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34986_cached_sizze_35261 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34986, &mem_34986_cached_sizze_35261, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34987_cached_sizze_35262 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34987, &mem_34987_cached_sizze_35262, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:41:5-32
    if (mem_35044_cached_sizze_35263 < bytes_35043) {
        err = lexical_realloc(ctx, &mem_35044, &mem_35044_cached_sizze_35263, bytes_35043);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:204:3-212:11
    
    bool defunc_0_reduce_res_34620;
    bool redout_34732 = 1;
    
    for (int64_t i_34733 = 0; i_34733 < n_24423; i_34733++) {
        // blocked_v3.fut:206:17-30
        for (int64_t i_34671 = 0; i_34671 < dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424; i_34671++) {
            int8_t eta_p_32890 = ((int8_t *) arrs_mem_34878.mem)[i_34733 * dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 + i_34671];
            
            // blocked_v3.fut:206:21-26
            
            int8_t lifted_lambda_res_32891 = umod8(eta_p_32890, (int8_t) 5);
            
            ((int8_t *) mem_34885.mem)[i_34671] = lifted_lambda_res_32891;
        }
        // blocked_v3.fut:167:11-169:49
        if (memblock_set(ctx, &mem_param_34894, &mem_34885, "mem_34885") != 0)
            return 1;
        if (memblock_set(ctx, &mem_param_34897, &mem_34880, "mem_34880") != 0)
            return 1;
        for (int32_t i_32896 = 0; i_32896 < iters_31367; i_32896++) {
            // blocked_v3.fut:169:26-37
            
            int32_t sort_step_arg0_32899 = mul32(4, i_32896);
            
            // blocked_v3.fut:122:7-36
            for (int64_t i_34716 = 0; i_34716 < n_blocks_31368; i_34716++) {
                // blocked_v3.fut:78:14-25
                // blocked_v3.fut:78:14-25
                lmad_copy_1b(ctx, 1, (uint8_t *) mem_34925.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint8_t *) mem_param_34894.mem, (int64_t) 0 + i_34716 * ((int64_t) 1 * (int64_t) 5120), (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                // blocked_v3.fut:78:14-25
                // blocked_v3.fut:78:14-25
                lmad_copy_8b(ctx, 1, (uint64_t *) mem_34926.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint64_t *) mem_param_34897.mem, (int64_t) 0 + i_34716 * ((int64_t) 1 * (int64_t) 5120), (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                // blocked_v3.fut:21:49-22:21
                for (int64_t nest_i_35133 = 0; nest_i_35133 < (int64_t) 16; nest_i_35133++) {
                    ((int16_t *) mem_34927)[nest_i_35133] = (int16_t) 0;
                }
                // blocked_v3.fut:23:8-27:50
                for (int64_t i_32912 = 0; i_32912 < (int64_t) 20; i_32912++) {
                    // blocked_v3.fut:26:32-27:50
                    for (int64_t iter_34673 = 0; iter_34673 < (int64_t) 256; iter_34673++) {
                        // blocked_v3.fut:12:28-36
                        
                        int64_t lifted_lambda_res_33537 = mul64((int64_t) 20, iter_34673);
                        
                        // blocked_v3.fut:12:13-23
                        
                        int64_t lifted_lambda_res_33538 = add64(i_32912, lifted_lambda_res_33537);
                        
                        // blocked_v3.fut:16:26-31
                        
                        int8_t lifted_lambda_res_33540 = ((int8_t *) mem_34925.mem)[lifted_lambda_res_33538];
                        
                        // blocked_v3.fut:35:9-37:47
                        
                        int32_t zlzb_rhs_33542;
                        int32_t acc_33544 = 0;
                        
                        for (int32_t i_33543 = 0; i_33543 < 4; i_33543++) {
                            // blocked_v3.fut:37:35-38
                            
                            int32_t get_bit_arg0_33545 = add32(sort_step_arg0_32899, i_33543);
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_33546 = zext_i32_i8(get_bit_arg0_33545);
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_33547 = ashr8(lifted_lambda_res_33540, unsign_arg0_33546);
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_33548 = (int8_t) 1 & unsign_arg0_33547;
                            
                            // blocked_v3.fut:207:67-83
                            
                            int32_t to_i32_res_33549 = zext_i8_i32(unsign_arg0_33548);
                            
                            // blocked_v3.fut:37:42-46
                            
                            int32_t zp_rhs_33550 = shl32(to_i32_res_33549, i_33543);
                            
                            // blocked_v3.fut:37:15-46
                            
                            int32_t loopres_33551 = add32(acc_33544, zp_rhs_33550);
                            int32_t acc_tmp_35136 = loopres_33551;
                            
                            acc_33544 = acc_tmp_35136;
                        }
                        zlzb_rhs_33542 = acc_33544;
                        // blocked_v3.fut:34:5-12
                        
                        int64_t i32_res_33552 = sext_i32_i64(zlzb_rhs_33542);
                        bool less_than_zzero_34677 = slt64(i32_res_33552, (int64_t) 0);
                        bool greater_than_sizze_34678 = sle64((int64_t) 16, i32_res_33552);
                        bool outside_bounds_dim_34679 = less_than_zzero_34677 || greater_than_sizze_34678;
                        
                        if (!outside_bounds_dim_34679) {
                            int16_t read_hist_34681 = ((int16_t *) mem_34927)[i32_res_33552];
                            
                            // blocked_v3.fut:27:34-37
                            
                            int16_t defunc_0_f_res_32940 = add16((int16_t) 1, read_hist_34681);
                            
                            ((int16_t *) mem_34927)[i32_res_33552] = defunc_0_f_res_32940;
                        }
                    }
                }
                // blocked_v3.fut:45:29-45
                for (int64_t nest_i_35137 = 0; nest_i_35137 < (int64_t) 16; nest_i_35137++) {
                    ((int16_t *) mem_34940)[nest_i_35137] = (int16_t) 0;
                }
                // blocked_v3.fut:45:6-49:35
                
                int16_t sequential_offsets_res_32945;
                int16_t acc_32948 = (int16_t) 0;
                
                for (int64_t i_32946 = 0; i_32946 < (int64_t) 16; i_32946++) {
                    // blocked_v3.fut:48:12-28
                    ((int16_t *) mem_34940)[i_32946] = acc_32948;
                    // blocked_v3.fut:49:27-34
                    
                    int16_t zp_rhs_32950 = ((int16_t *) mem_34927)[i_32946];
                    
                    // blocked_v3.fut:49:25-34
                    
                    int16_t tmp_32951 = add16(acc_32948, zp_rhs_32950);
                    int16_t acc_tmp_35139 = tmp_32951;
                    
                    acc_32948 = acc_tmp_35139;
                }
                sequential_offsets_res_32945 = acc_32948;
                // blocked_v3.fut:82:7-110:15
                if (memblock_set(ctx, &mem_param_34949, &mem_34925, "mem_34925") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34952, &mem_34926, "mem_34926") != 0)
                    return 1;
                for (int32_t i_32954 = 0; i_32954 < 4; i_32954++) {
                    // blocked_v3.fut:84:42-51
                    
                    int32_t get_bit_arg0_32957 = add32(sort_step_arg0_32899, i_32954);
                    
                    // blocked_v3.fut:207:67-83
                    
                    int8_t unsign_arg0_32958 = zext_i32_i8(get_bit_arg0_32957);
                    
                    // blocked_v3.fut:55:5-60:60
                    for (int64_t i_34688 = 0; i_34688 < (int64_t) 256; i_34688++) {
                        // blocked_v3.fut:58:54-65
                        
                        int64_t c_32962 = mul64((int64_t) 20, i_34688);
                        
                        // blocked_v3.fut:58:69-72
                        
                        int64_t zt_lhs_32963 = add64((int64_t) 1, i_34688);
                        
                        // blocked_v3.fut:58:74-85
                        
                        int64_t c_32964 = mul64((int64_t) 20, zt_lhs_32963);
                        
                        // blocked_v3.fut:57:30-59:41
                        
                        int64_t j_m_i_32965 = sub64(c_32964, c_32962);
                        
                        // blocked_v3.fut:57:30-59:41
                        
                        int16_t c_32966;
                        int16_t acc_32968 = (int16_t) 0;
                        
                        for (int64_t i_32967 = 0; i_32967 < j_m_i_32965; i_32967++) {
                            // blocked_v3.fut:55:5-60:60
                            
                            int64_t index_primexp_32969 = c_32962 + i_32967;
                            
                            // blocked_v3.fut:55:5-60:60
                            
                            int8_t v_32970 = ((int8_t *) mem_param_34949.mem)[index_primexp_32969];
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_32971 = ashr8(v_32970, unsign_arg0_32958);
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_32972 = (int8_t) 1 & unsign_arg0_32971;
                            
                            // blocked_v3.fut:207:67-83
                            
                            int32_t to_i32_res_32973 = zext_i8_i32(unsign_arg0_32972);
                            
                            // blocked_v3.fut:84:19-26
                            
                            int16_t i32_res_32974 = sext_i32_i16(to_i32_res_32973);
                            
                            // blocked_v3.fut:59:36-41
                            
                            int16_t loopres_32975 = add16(acc_32968, i32_res_32974);
                            int16_t acc_tmp_35146 = loopres_32975;
                            
                            acc_32968 = acc_tmp_35146;
                        }
                        c_32966 = acc_32968;
                        // blocked_v3.fut:60:40-57
                        
                        int16_t zm_res_32976 = sub16((int16_t) 20, c_32966);
                        
                        ((int16_t *) mem_34953)[i_34688] = c_32966;
                        ((int16_t *) mem_34954)[i_34688] = zm_res_32976;
                    }
                    // blocked_v3.fut:85:22-51
                    // blocked_v3.fut:85:22-51
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34967, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34953, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    // blocked_v3.fut:85:22-51
                    // blocked_v3.fut:85:22-51
                    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34968, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34954, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                    // blocked_v3.fut:71:18-32
                    for (int64_t nest_i_35147 = 0; nest_i_35147 < (int64_t) 256; nest_i_35147++) {
                        ((int16_t *) mem_34969)[nest_i_35147] = (int16_t) 0;
                    }
                    // blocked_v3.fut:71:18-32
                    for (int64_t nest_i_35148 = 0; nest_i_35148 < (int64_t) 256; nest_i_35148++) {
                        ((int16_t *) mem_34970)[nest_i_35148] = (int16_t) 0;
                    }
                    // blocked_v3.fut:86:33-69
                    for (int64_t nest_i_35149 = 0; nest_i_35149 < (int64_t) 1; nest_i_35149++) {
                        ((int16_t *) mem_34971)[nest_i_35149] = (int16_t) 0;
                    }
                    // blocked_v3.fut:70:13-71:39
                    
                    bool acc_cert_33739;
                    bool acc_cert_33740;
                    bool acc_cert_33741;
                    
                    // blocked_v3.fut:68:21-71:39
                    
                    int16_t discard_34697;
                    int16_t discard_34698;
                    int16_t scanacc_34691;
                    int16_t scanacc_34692;
                    
                    scanacc_34691 = (int16_t) 0;
                    scanacc_34692 = (int16_t) 0;
                    for (int64_t i_34696 = 0; i_34696 < (int64_t) 256; i_34696++) {
                        int16_t x_33819 = ((int16_t *) mem_34967)[i_34696];
                        int16_t x_33820 = ((int16_t *) mem_34968)[i_34696];
                        
                        // blocked_v3.fut:68:28-33
                        
                        int64_t lifted_lambda_res_33825 = add64((int64_t) 1, i_34696);
                        
                        // blocked_v3.fut:64:9-13
                        
                        int16_t tmp_33766 = add16(x_33819, scanacc_34691);
                        
                        // blocked_v3.fut:64:18-22
                        
                        int16_t tmp_33767 = add16(x_33820, scanacc_34692);
                        
                        // blocked_v3.fut:70:38-66
                        
                        bool cond_33806 = i_34696 == (int64_t) 255;
                        
                        // blocked_v3.fut:70:38-66
                        
                        int64_t lifted_lambda_res_33807;
                        
                        if (cond_33806) {
                            lifted_lambda_res_33807 = (int64_t) 0;
                        } else {
                            lifted_lambda_res_33807 = (int64_t) -1;
                        }
                        // blocked_v3.fut:70:13-80
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33807) && slt64(lifted_lambda_res_33807, (int64_t) 1)) {
                            ((int16_t *) mem_34971)[lifted_lambda_res_33807] = tmp_33767;
                        }
                        // blocked_v3.fut:71:9-39
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33825) && slt64(lifted_lambda_res_33825, (int64_t) 256)) {
                            ((int16_t *) mem_34970)[lifted_lambda_res_33825] = tmp_33766;
                        }
                        // blocked_v3.fut:71:9-39
                        // UpdateAcc
                        if (sle64((int64_t) 0, lifted_lambda_res_33825) && slt64(lifted_lambda_res_33825, (int64_t) 256)) {
                            ((int16_t *) mem_34969)[lifted_lambda_res_33825] = tmp_33767;
                        }
                        
                        int16_t scanacc_tmp_35150 = tmp_33766;
                        int16_t scanacc_tmp_35151 = tmp_33767;
                        
                        scanacc_34691 = scanacc_tmp_35150;
                        scanacc_34692 = scanacc_tmp_35151;
                    }
                    discard_34697 = scanacc_34691;
                    discard_34698 = scanacc_34692;
                    // blocked_v3.fut:71:41-45
                    
                    int16_t tmp_33031 = ((int16_t *) mem_34971)[(int64_t) 0];
                    
                    // blocked_v3.fut:88:19-47
                    if (memblock_alloc(ctx, &mem_34972, (int64_t) 5120, "mem_34972")) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:88:19-47
                    // blocked_v3.fut:88:19-47
                    lmad_copy_1b(ctx, 1, (uint8_t *) mem_34972.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint8_t *) mem_34881, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                    // blocked_v3.fut:88:19-47
                    if (memblock_alloc(ctx, &mem_34973, (int64_t) 40960, "mem_34973")) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:88:19-47
                    // blocked_v3.fut:88:19-47
                    lmad_copy_8b(ctx, 1, (uint64_t *) mem_34973.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint64_t *) mem_34882, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                    // blocked_v3.fut:90:11-109:27
                    if (memblock_set(ctx, &mem_param_34982, &mem_34884, "mem_34884") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34985, &mem_34884, "mem_34884") != 0)
                        return 1;
                    for (int64_t k_33038 = 0; k_33038 < (int64_t) 20; k_33038++) {
                        // blocked_v3.fut:102:15-77
                        if (memblock_alloc(ctx, &mem_35000, (int64_t) 512, "mem_35000")) {
                            err = 1;
                            goto cleanup;
                        }
                        // blocked_v3.fut:102:15-77
                        if (memblock_alloc(ctx, &mem_35001, (int64_t) 512, "mem_35001")) {
                            err = 1;
                            goto cleanup;
                        }
                        // blocked_v3.fut:102:15-77
                        
                        bool acc_cert_34163;
                        bool acc_cert_34164;
                        
                        // blocked_v3.fut:94:15-108:27
                        for (int64_t i_34705 = 0; i_34705 < (int64_t) 256; i_34705++) {
                            int16_t eta_p_34275 = ((int16_t *) mem_param_34982.mem)[i_34705];
                            int16_t eta_p_34276 = ((int16_t *) mem_param_34985.mem)[i_34705];
                            int16_t eta_p_34277 = ((int16_t *) mem_34970)[i_34705];
                            int16_t eta_p_34278 = ((int16_t *) mem_34969)[i_34705];
                            
                            // blocked_v3.fut:12:28-36
                            
                            int64_t lifted_lambda_res_34283 = mul64((int64_t) 20, i_34705);
                            
                            // blocked_v3.fut:12:13-23
                            
                            int64_t lifted_lambda_res_34284 = add64(k_33038, lifted_lambda_res_34283);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool x_34285 = sle64((int64_t) 0, lifted_lambda_res_34284);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool y_34286 = slt64(lifted_lambda_res_34284, (int64_t) 5120);
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool bounds_check_34287 = x_34285 && y_34286;
                            
                            // blocked_v3.fut:95:38-43
                            
                            bool index_certs_34288;
                            
                            if (!bounds_check_34287) {
                                set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) lifted_lambda_res_34284, "] out of bounds for array of shape [", (long long) (int64_t) 5120, "].", "-> #0  blocked_v3.fut:95:38-43\n   #1  blocked_v3.fut:122:7-36\n   #2  blocked_v3.fut:169:13-49\n   #3  blocked_v3.fut:207:12-84\n"));
                                err = FUTHARK_PROGRAM_ERROR;
                                goto cleanup;
                            }
                            // blocked_v3.fut:95:38-43
                            
                            int8_t get_arg0_34289 = ((int8_t *) mem_param_34949.mem)[lifted_lambda_res_34284];
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_34290 = ashr8(get_arg0_34289, unsign_arg0_32958);
                            
                            // blocked_v3.fut:207:67-83
                            
                            int8_t unsign_arg0_34291 = (int8_t) 1 & unsign_arg0_34290;
                            
                            // blocked_v3.fut:207:67-83
                            
                            int32_t to_i32_res_34292 = zext_i8_i32(unsign_arg0_34291);
                            
                            // blocked_v3.fut:84:19-26
                            
                            int16_t i32_res_34293 = sext_i32_i16(to_i32_res_34292);
                            
                            // blocked_v3.fut:96:38-98:54
                            
                            bool cond_34294 = i32_res_34293 == (int16_t) 0;
                            
                            // blocked_v3.fut:96:38-98:54
                            
                            int16_t i16_arg0_34295;
                            
                            if (cond_34294) {
                                // blocked_v3.fut:97:46-50
                                
                                int16_t i16_arg0_t_res_34600 = add16(eta_p_34276, eta_p_34278);
                                
                                i16_arg0_34295 = i16_arg0_t_res_34600;
                            } else {
                                // blocked_v3.fut:98:45-49
                                
                                int16_t zp_lhs_34297 = add16(tmp_33031, eta_p_34277);
                                
                                // blocked_v3.fut:98:50-54
                                
                                int16_t i16_arg0_f_res_34298 = add16(eta_p_34275, zp_lhs_34297);
                                
                                i16_arg0_34295 = i16_arg0_f_res_34298;
                            }
                            // blocked_v3.fut:96:29-98:54
                            
                            int64_t i16_res_34299 = sext_i16_i64(i16_arg0_34295);
                            
                            // blocked_v3.fut:16:26-31
                            
                            int64_t lifted_lambda_res_34301 = ((int64_t *) mem_param_34952.mem)[lifted_lambda_res_34284];
                            
                            // blocked_v3.fut:102:15-77
                            // UpdateAcc
                            if (sle64((int64_t) 0, i16_res_34299) && slt64(i16_res_34299, (int64_t) 5120)) {
                                ((int8_t *) mem_34972.mem)[i16_res_34299] = get_arg0_34289;
                            }
                            // blocked_v3.fut:102:15-77
                            // UpdateAcc
                            if (sle64((int64_t) 0, i16_res_34299) && slt64(i16_res_34299, (int64_t) 5120)) {
                                ((int64_t *) mem_34973.mem)[i16_res_34299] = lifted_lambda_res_34301;
                            }
                            // blocked_v3.fut:107:33-36
                            
                            int16_t tmp_34322 = add16(eta_p_34275, i32_res_34293);
                            
                            // blocked_v3.fut:107:49-52
                            
                            int16_t zp_rhs_34323 = (int16_t) 1 ^ i32_res_34293;
                            
                            // blocked_v3.fut:107:41-52
                            
                            int16_t tmp_34324 = add16(eta_p_34276, zp_rhs_34323);
                            
                            ((int16_t *) mem_34986)[i_34705] = tmp_34322;
                            ((int16_t *) mem_34987)[i_34705] = tmp_34324;
                        }
                        // blocked_v3.fut:102:15-77
                        lmad_copy_2b(ctx, 1, (uint16_t *) mem_35000.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34986, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                        // blocked_v3.fut:102:15-77
                        lmad_copy_2b(ctx, 1, (uint16_t *) mem_35001.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34987, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                        if (memblock_set(ctx, &mem_param_tmp_35155, &mem_35000, "mem_35000") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_tmp_35156, &mem_35001, "mem_35001") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_34982, &mem_param_tmp_35155, "mem_param_tmp_35155") != 0)
                            return 1;
                        if (memblock_set(ctx, &mem_param_34985, &mem_param_tmp_35156, "mem_param_tmp_35156") != 0)
                            return 1;
                    }
                    if (memblock_set(ctx, &ext_mem_35011, &mem_param_34982, "mem_param_34982") != 0)
                        return 1;
                    if (memblock_set(ctx, &ext_mem_35010, &mem_param_34985, "mem_param_34985") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_tmp_35140, &mem_34972, "mem_34972") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_tmp_35141, &mem_34973, "mem_34973") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34949, &mem_param_tmp_35140, "mem_param_tmp_35140") != 0)
                        return 1;
                    if (memblock_set(ctx, &mem_param_34952, &mem_param_tmp_35141, "mem_param_tmp_35141") != 0)
                        return 1;
                }
                if (memblock_set(ctx, &ext_mem_35019, &mem_param_34949, "mem_param_34949") != 0)
                    return 1;
                if (memblock_set(ctx, &ext_mem_35018, &mem_param_34952, "mem_param_34952") != 0)
                    return 1;
                lmad_copy_8b(ctx, 1, (uint64_t *) mem_34900, i_34716 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (uint64_t *) ext_mem_35018.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                if (memblock_unref(ctx, &ext_mem_35018, "ext_mem_35018") != 0)
                    return 1;
                lmad_copy_1b(ctx, 1, (uint8_t *) mem_34902, i_34716 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (uint8_t *) ext_mem_35019.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
                if (memblock_unref(ctx, &ext_mem_35019, "ext_mem_35019") != 0)
                    return 1;
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34905, i_34716 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34940, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34908, i_34716 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34927, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
            }
            // blocked_v3.fut:41:5-32
            
            int64_t discard_34726;
            int64_t scanacc_34722 = (int64_t) 0;
            
            for (int64_t i_34724 = 0; i_34724 < dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_31374; i_34724++) {
                int64_t new_index_34761 = squot64(i_34724, n_blocks_31368);
                int64_t binop_y_34763 = n_blocks_31368 * new_index_34761;
                int64_t new_index_34764 = i_34724 - binop_y_34763;
                int16_t eta_p_33498 = ((int16_t *) mem_34908)[new_index_34764 * (int64_t) 16 + new_index_34761];
                
                // blocked_v3.fut:132:14-21
                
                int64_t i16_res_33499 = sext_i16_i64(eta_p_33498);
                
                // blocked_v3.fut:41:20-23
                
                int64_t defunc_0_op_res_33129 = add64(i16_res_33499, scanacc_34722);
                
                ((int64_t *) mem_35044)[i_34724] = scanacc_34722;
                
                int64_t scanacc_tmp_35165 = defunc_0_op_res_33129;
                
                scanacc_34722 = scanacc_tmp_35165;
            }
            discard_34726 = scanacc_34722;
            // blocked_v3.fut:207:12-84
            if (memblock_alloc(ctx, &mem_35052, bytes_34879, "mem_35052")) {
                err = 1;
                goto cleanup;
            }
            lmad_copy_8b(ctx, 2, (uint64_t *) mem_35052.mem, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (uint64_t *) mem_34900, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (int64_t []) {n_blocks_31368, (int64_t) 5120});
            // blocked_v3.fut:207:12-84
            if (memblock_alloc(ctx, &mem_35053, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369, "mem_35053")) {
                err = 1;
                goto cleanup;
            }
            lmad_copy_1b(ctx, 2, (uint8_t *) mem_35053.mem, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (uint8_t *) mem_34902, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (int64_t []) {n_blocks_31368, (int64_t) 5120});
            // blocked_v3.fut:145:8-39
            
            bool acc_cert_33277;
            bool acc_cert_33278;
            
            // blocked_v3.fut:137:7-145:39
            for (int64_t i_34729 = 0; i_34729 < dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369; i_34729++) {
                int64_t new_index_34751 = squot64(i_34729, (int64_t) 5120);
                int64_t binop_y_34753 = (int64_t) 5120 * new_index_34751;
                int64_t new_index_34754 = i_34729 - binop_y_34753;
                int8_t v_33352 = ((int8_t *) mem_34902)[new_index_34751 * (int64_t) 5120 + new_index_34754];
                int64_t v_33353 = ((int64_t *) mem_34900)[new_index_34751 * (int64_t) 5120 + new_index_34754];
                
                // blocked_v3.fut:207:12-84
                
                int64_t index_primexp_33360 = i_34729 - binop_y_34753;
                
                // blocked_v3.fut:207:12-84
                
                int8_t elem_33361 = ((int8_t *) mem_34902)[new_index_34751 * (int64_t) 5120 + index_primexp_33360];
                
                // blocked_v3.fut:35:9-37:47
                
                int32_t zlzb_rhs_33362;
                int32_t acc_33364 = 0;
                
                for (int32_t i_33363 = 0; i_33363 < 4; i_33363++) {
                    // blocked_v3.fut:37:35-38
                    
                    int32_t get_bit_arg0_33365 = add32(sort_step_arg0_32899, i_33363);
                    
                    // blocked_v3.fut:207:67-83
                    
                    int8_t unsign_arg0_33366 = zext_i32_i8(get_bit_arg0_33365);
                    
                    // blocked_v3.fut:207:67-83
                    
                    int8_t unsign_arg0_33367 = ashr8(elem_33361, unsign_arg0_33366);
                    
                    // blocked_v3.fut:207:67-83
                    
                    int8_t unsign_arg0_33368 = (int8_t) 1 & unsign_arg0_33367;
                    
                    // blocked_v3.fut:207:67-83
                    
                    int32_t to_i32_res_33369 = zext_i8_i32(unsign_arg0_33368);
                    
                    // blocked_v3.fut:37:42-46
                    
                    int32_t zp_rhs_33370 = shl32(to_i32_res_33369, i_33363);
                    
                    // blocked_v3.fut:37:15-46
                    
                    int32_t loopres_33371 = add32(acc_33364, zp_rhs_33370);
                    int32_t acc_tmp_35169 = loopres_33371;
                    
                    acc_33364 = acc_tmp_35169;
                }
                zlzb_rhs_33362 = acc_33364;
                // blocked_v3.fut:34:5-12
                
                int64_t i32_res_33372 = sext_i32_i64(zlzb_rhs_33362);
                
                // blocked_v3.fut:140:68-93
                
                int64_t block_idx_33373 = sdiv64(i_34729, (int64_t) 5120);
                
                // blocked_v3.fut:141:67-89
                
                bool x_33374 = sle64((int64_t) 0, block_idx_33373);
                
                // blocked_v3.fut:141:67-89
                
                bool y_33375 = slt64(block_idx_33373, n_blocks_31368);
                
                // blocked_v3.fut:141:67-89
                
                bool bounds_check_33376 = x_33374 && y_33375;
                
                // blocked_v3.fut:141:67-89
                
                bool index_certs_33377;
                
                if (!bounds_check_33376) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) block_idx_33373, "] out of bounds for array of shape [", (long long) n_blocks_31368, "].", "-> #0  blocked_v3.fut:141:67-89\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:207:12-84\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:141:67-94
                
                bool x_33378 = sle64((int64_t) 0, i32_res_33372);
                
                // blocked_v3.fut:141:67-94
                
                bool y_33379 = slt64(i32_res_33372, (int64_t) 16);
                
                // blocked_v3.fut:141:67-94
                
                bool bounds_check_33380 = x_33378 && y_33379;
                
                // blocked_v3.fut:141:67-94
                
                bool index_certs_33381;
                
                if (!bounds_check_33380) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) i32_res_33372, "] out of bounds for array of shape [", (long long) (int64_t) 16, "].", "-> #0  blocked_v3.fut:141:67-94\n   #1  blocked_v3.fut:169:13-49\n   #2  blocked_v3.fut:207:12-84\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:207:12-84
                
                int64_t binop_x_33382 = n_blocks_31368 * i32_res_33372;
                
                // blocked_v3.fut:207:12-84
                
                int64_t index_primexp_33383 = block_idx_33373 + binop_x_33382;
                
                // blocked_v3.fut:207:12-84
                
                int64_t new_offset_33384 = ((int64_t *) mem_35044)[index_primexp_33383];
                
                // blocked_v3.fut:207:12-84
                
                int16_t i16_arg0_33385 = ((int16_t *) mem_34905)[block_idx_33373 * (int64_t) 16 + i32_res_33372];
                
                // blocked_v3.fut:142:73-108
                
                int64_t i16_res_33386 = sext_i16_i64(i16_arg0_33385);
                
                // blocked_v3.fut:143:92-103
                
                int64_t zp_lhs_33387 = mul64((int64_t) 5120, block_idx_33373);
                
                // blocked_v3.fut:143:104-122
                
                int64_t old_offset_33388 = add64(i16_res_33386, zp_lhs_33387);
                
                // blocked_v3.fut:144:56-68
                
                int64_t zp_lhs_33389 = sub64(i_34729, old_offset_33388);
                
                // blocked_v3.fut:144:70-82
                
                int64_t defunc_0_f_res_33390 = add64(new_offset_33384, zp_lhs_33389);
                
                // blocked_v3.fut:145:8-39
                // UpdateAcc
                if (sle64((int64_t) 0, defunc_0_f_res_33390) && slt64(defunc_0_f_res_33390, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369)) {
                    ((int8_t *) mem_35053.mem)[defunc_0_f_res_33390] = v_33352;
                }
                // blocked_v3.fut:145:8-39
                // UpdateAcc
                if (sle64((int64_t) 0, defunc_0_f_res_33390) && slt64(defunc_0_f_res_33390, dzlz7bUZLztZRz20Un_blocksz20UZLZLztZRz20Unum_elemsz20Ublock_sizzeZRz7dUzg_31369)) {
                    ((int64_t *) mem_35052.mem)[defunc_0_f_res_33390] = v_33353;
                }
            }
            if (memblock_set(ctx, &mem_param_tmp_35125, &mem_35053, "mem_35053") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_tmp_35126, &mem_35052, "mem_35052") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34894, &mem_param_tmp_35125, "mem_param_tmp_35125") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34897, &mem_param_tmp_35126, "mem_param_tmp_35126") != 0)
                return 1;
        }
        if (memblock_set(ctx, &ext_mem_35059, &mem_param_34894, "mem_param_34894") != 0)
            return 1;
        if (memblock_set(ctx, &ext_mem_35058, &mem_param_34897, "mem_param_34897") != 0)
            return 1;
        // blocked_v3.fut:209:13-211:19
        
        bool defunc_0_reduce_res_34619;
        bool redout_34730 = 1;
        
        for (int64_t i_34731 = 0; i_34731 < dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424; i_34731++) {
            // blocked_v3.fut:210:15-70
            
            bool cond_33243 = i_34731 == (int64_t) 0;
            
            // blocked_v3.fut:210:15-70
            
            bool cond_33244;
            
            if (cond_33243) {
                cond_33244 = 1;
            } else {
                // blocked_v3.fut:210:32-35
                
                int64_t znze_lhs_33245 = sub64(i_34731, (int64_t) 1);
                
                // blocked_v3.fut:210:25-36
                
                bool x_33246 = sle64((int64_t) 0, znze_lhs_33245);
                
                // blocked_v3.fut:210:25-36
                
                bool y_33247 = slt64(znze_lhs_33245, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424);
                
                // blocked_v3.fut:210:25-36
                
                bool bounds_check_33248 = x_33246 && y_33247;
                
                // blocked_v3.fut:210:25-36
                
                bool index_certs_33249;
                
                if (!bounds_check_33248) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) znze_lhs_33245, "] out of bounds for array of shape [", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, "].", "-> #0  blocked_v3.fut:210:25-36\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:204:3-212:11
                
                int8_t znze_lhs_33250 = ((int8_t *) ext_mem_35059.mem)[znze_lhs_33245];
                
                // blocked_v3.fut:204:3-212:11
                
                int8_t znze_rhs_33255 = ((int8_t *) ext_mem_35059.mem)[i_34731];
                
                // blocked_v3.fut:210:37-47
                
                bool cond_f_res_33256 = znze_lhs_33250 == znze_rhs_33255;
                
                // blocked_v3.fut:210:37-47
                
                bool cond_f_res_33257 = !cond_f_res_33256;
                
                cond_33244 = cond_f_res_33257;
            }
            // blocked_v3.fut:210:15-70
            
            bool lifted_lambda_res_33258;
            
            if (cond_33244) {
                lifted_lambda_res_33258 = 1;
            } else {
                // blocked_v3.fut:210:57-60
                
                int64_t zl_lhs_33259 = sub64(i_34731, (int64_t) 1);
                
                // blocked_v3.fut:210:51-61
                
                bool x_33260 = sle64((int64_t) 0, zl_lhs_33259);
                
                // blocked_v3.fut:210:51-61
                
                bool y_33261 = slt64(zl_lhs_33259, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424);
                
                // blocked_v3.fut:210:51-61
                
                bool bounds_check_33262 = x_33260 && y_33261;
                
                // blocked_v3.fut:210:51-61
                
                bool index_certs_33263;
                
                if (!bounds_check_33262) {
                    set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) zl_lhs_33259, "] out of bounds for array of shape [", (long long) dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424, "].", "-> #0  blocked_v3.fut:210:51-61\n"));
                    err = FUTHARK_PROGRAM_ERROR;
                    goto cleanup;
                }
                // blocked_v3.fut:204:3-212:11
                
                int64_t zl_lhs_33264 = ((int64_t *) ext_mem_35058.mem)[zl_lhs_33259];
                
                // blocked_v3.fut:204:3-212:11
                
                int64_t zl_rhs_33269 = ((int64_t *) ext_mem_35058.mem)[i_34731];
                
                // blocked_v3.fut:210:62-70
                
                bool lifted_lambda_res_f_res_33270 = slt64(zl_lhs_33264, zl_rhs_33269);
                
                lifted_lambda_res_33258 = lifted_lambda_res_f_res_33270;
            }
            // blocked_v3.fut:211:16-19
            
            bool x_33230 = lifted_lambda_res_33258 && redout_34730;
            bool redout_tmp_35170 = x_33230;
            
            redout_34730 = redout_tmp_35170;
        }
        defunc_0_reduce_res_34619 = redout_34730;
        if (memblock_unref(ctx, &ext_mem_35058, "ext_mem_35058") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35059, "ext_mem_35059") != 0)
            return 1;
        // blocked_v3.fut:204:3-212:11
        
        bool x_31737 = defunc_0_reduce_res_34619 && redout_34732;
        bool redout_tmp_35123 = x_31737;
        
        redout_34732 = redout_tmp_35123;
    }
    defunc_0_reduce_res_34620 = redout_34732;
    if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34884, "mem_34884") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34885, "mem_34885") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34925, "mem_34925") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34926, "mem_34926") != 0)
        return 1;
    prim_out_35119 = defunc_0_reduce_res_34620;
    *out_prim_out_35244 = prim_out_35119;
    
  cleanup:
    {
        free(mem_34881);
        free(mem_34882);
        free(mem_34883);
        free(mem_34900);
        free(mem_34902);
        free(mem_34905);
        free(mem_34908);
        free(mem_34927);
        free(mem_34940);
        free(mem_34953);
        free(mem_34954);
        free(mem_34967);
        free(mem_34968);
        free(mem_34969);
        free(mem_34970);
        free(mem_34971);
        free(mem_34986);
        free(mem_34987);
        free(mem_35044);
        if (memblock_unref(ctx, &mem_param_tmp_35126, "mem_param_tmp_35126") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35125, "mem_param_tmp_35125") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35053, "mem_35053") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35052, "mem_35052") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35141, "mem_param_tmp_35141") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35140, "mem_param_tmp_35140") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35156, "mem_param_tmp_35156") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35155, "mem_param_tmp_35155") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35001, "mem_35001") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_35000, "mem_35000") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34985, "mem_param_34985") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34982, "mem_param_34982") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35010, "ext_mem_35010") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35011, "ext_mem_35011") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34973, "mem_34973") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34972, "mem_34972") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34952, "mem_param_34952") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34949, "mem_param_34949") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35018, "ext_mem_35018") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35019, "ext_mem_35019") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34897, "mem_param_34897") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34894, "mem_param_34894") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35058, "ext_mem_35058") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_35059, "ext_mem_35059") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34926, "mem_34926") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34925, "mem_34925") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34885, "mem_34885") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34884, "mem_34884") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
            return 1;
    }
    return err;
}
FUTHARK_FUN_ATTR int futrts_entry_main(struct futhark_context *ctx, struct memblock *mem_out_p_35264, int64_t *out_prim_out_35265, struct memblock xss_mem_34878, int64_t n_18037)
{
    (void) ctx;
    
    int err = 0;
    int64_t mem_34879_cached_sizze_35266 = 0;
    unsigned char *mem_34879 = NULL;
    int64_t mem_34881_cached_sizze_35267 = 0;
    unsigned char *mem_34881 = NULL;
    int64_t mem_34884_cached_sizze_35268 = 0;
    unsigned char *mem_34884 = NULL;
    int64_t mem_34887_cached_sizze_35269 = 0;
    unsigned char *mem_34887 = NULL;
    int64_t mem_34890_cached_sizze_35270 = 0;
    unsigned char *mem_34890 = NULL;
    int64_t mem_34904_cached_sizze_35271 = 0;
    unsigned char *mem_34904 = NULL;
    int64_t mem_34917_cached_sizze_35272 = 0;
    unsigned char *mem_34917 = NULL;
    int64_t mem_34927_cached_sizze_35273 = 0;
    unsigned char *mem_34927 = NULL;
    int64_t mem_34928_cached_sizze_35274 = 0;
    unsigned char *mem_34928 = NULL;
    int64_t mem_34941_cached_sizze_35275 = 0;
    unsigned char *mem_34941 = NULL;
    int64_t mem_34942_cached_sizze_35276 = 0;
    unsigned char *mem_34942 = NULL;
    int64_t mem_34943_cached_sizze_35277 = 0;
    unsigned char *mem_34943 = NULL;
    int64_t mem_34944_cached_sizze_35278 = 0;
    unsigned char *mem_34944 = NULL;
    int64_t mem_34945_cached_sizze_35279 = 0;
    unsigned char *mem_34945 = NULL;
    int64_t mem_34956_cached_sizze_35280 = 0;
    unsigned char *mem_34956 = NULL;
    int64_t mem_34957_cached_sizze_35281 = 0;
    unsigned char *mem_34957 = NULL;
    int64_t mem_35001_cached_sizze_35282 = 0;
    unsigned char *mem_35001 = NULL;
    struct memblock mem_35009;
    
    mem_35009.references = NULL;
    
    struct memblock mem_param_tmp_35132;
    
    mem_param_tmp_35132.references = NULL;
    
    struct memblock mem_param_tmp_35146;
    
    mem_param_tmp_35146.references = NULL;
    
    struct memblock mem_param_tmp_35145;
    
    mem_param_tmp_35145.references = NULL;
    
    struct memblock mem_34971;
    
    mem_34971.references = NULL;
    
    struct memblock mem_34970;
    
    mem_34970.references = NULL;
    
    struct memblock mem_param_34955;
    
    mem_param_34955.references = NULL;
    
    struct memblock mem_param_34952;
    
    mem_param_34952.references = NULL;
    
    struct memblock ext_mem_34978;
    
    ext_mem_34978.references = NULL;
    
    struct memblock ext_mem_34979;
    
    ext_mem_34979.references = NULL;
    
    struct memblock mem_34946;
    
    mem_34946.references = NULL;
    
    struct memblock mem_param_34926;
    
    mem_param_34926.references = NULL;
    
    struct memblock ext_mem_34983;
    
    ext_mem_34983.references = NULL;
    
    struct memblock mem_34903;
    
    mem_34903.references = NULL;
    
    struct memblock mem_34880;
    
    mem_34880.references = NULL;
    
    struct memblock mem_out_35119;
    
    mem_out_35119.references = NULL;
    
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    int64_t prim_out_35120;
    
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34883 = (int64_t) 40960 * n_18037;
    
    // blocked_v3.fut:122:7-36
    
    int64_t bytes_34886 = (int64_t) 32 * n_18037;
    
    // blocked_v3.fut:41:5-32
    
    int64_t bytes_35000 = (int64_t) 128 * n_18037;
    
    // blocked_v3.fut:87:30-63
    if (mem_34879_cached_sizze_35266 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34879, &mem_34879_cached_sizze_35266, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:87:30-63
    for (int64_t nest_i_35121 = 0; nest_i_35121 < (int64_t) 256; nest_i_35121++) {
        ((int16_t *) mem_34879)[nest_i_35121] = (int16_t) 0;
    }
    // blocked_v3.fut:87:20-63
    if (memblock_alloc(ctx, &mem_34880, (int64_t) 512, "mem_34880")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:87:20-63
    // blocked_v3.fut:87:20-63
    lmad_copy_2b(ctx, 1, (uint16_t *) mem_34880.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34879, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
    // blocked_v3.fut:88:19-47
    if (mem_34881_cached_sizze_35267 < (int64_t) 40960) {
        err = lexical_realloc(ctx, &mem_34881, &mem_34881_cached_sizze_35267, (int64_t) 40960);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34884_cached_sizze_35268 < bytes_34883) {
        err = lexical_realloc(ctx, &mem_34884, &mem_34884_cached_sizze_35268, bytes_34883);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34887_cached_sizze_35269 < bytes_34886) {
        err = lexical_realloc(ctx, &mem_34887, &mem_34887_cached_sizze_35269, bytes_34886);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    if (mem_34890_cached_sizze_35270 < bytes_34886) {
        err = lexical_realloc(ctx, &mem_34890, &mem_34890_cached_sizze_35270, bytes_34886);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:78:14-25
    if (memblock_alloc(ctx, &mem_34903, (int64_t) 40960, "mem_34903")) {
        err = 1;
        goto cleanup;
    }
    // blocked_v3.fut:21:49-22:21
    if (mem_34904_cached_sizze_35271 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34904, &mem_34904_cached_sizze_35271, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:45:29-45
    if (mem_34917_cached_sizze_35272 < (int64_t) 32) {
        err = lexical_realloc(ctx, &mem_34917, &mem_34917_cached_sizze_35272, (int64_t) 32);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34927_cached_sizze_35273 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34927, &mem_34927_cached_sizze_35273, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:55:5-60:60
    if (mem_34928_cached_sizze_35274 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34928, &mem_34928_cached_sizze_35274, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34941_cached_sizze_35275 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34941, &mem_34941_cached_sizze_35275, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:85:22-51
    if (mem_34942_cached_sizze_35276 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34942, &mem_34942_cached_sizze_35276, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34943_cached_sizze_35277 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34943, &mem_34943_cached_sizze_35277, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:71:18-32
    if (mem_34944_cached_sizze_35278 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34944, &mem_34944_cached_sizze_35278, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:86:33-69
    if (mem_34945_cached_sizze_35279 < (int64_t) 2) {
        err = lexical_realloc(ctx, &mem_34945, &mem_34945_cached_sizze_35279, (int64_t) 2);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34956_cached_sizze_35280 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34956, &mem_34956_cached_sizze_35280, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:94:15-108:27
    if (mem_34957_cached_sizze_35281 < (int64_t) 512) {
        err = lexical_realloc(ctx, &mem_34957, &mem_34957_cached_sizze_35281, (int64_t) 512);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:122:7-36
    for (int64_t i_34709 = 0; i_34709 < n_18037; i_34709++) {
        // blocked_v3.fut:78:14-25
        // blocked_v3.fut:78:14-25
        lmad_copy_8b(ctx, 1, (uint64_t *) mem_34903.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint64_t *) xss_mem_34878.mem, i_34709 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
        // blocked_v3.fut:21:49-22:21
        for (int64_t nest_i_35125 = 0; nest_i_35125 < (int64_t) 16; nest_i_35125++) {
            ((int16_t *) mem_34904)[nest_i_35125] = (int16_t) 0;
        }
        // blocked_v3.fut:23:8-27:50
        for (int64_t i_27979 = 0; i_27979 < (int64_t) 20; i_27979++) {
            // blocked_v3.fut:26:32-27:50
            for (int64_t iter_34669 = 0; iter_34669 < (int64_t) 256; iter_34669++) {
                // blocked_v3.fut:12:28-36
                
                int64_t lifted_lambda_res_33092 = mul64((int64_t) 20, iter_34669);
                
                // blocked_v3.fut:12:13-23
                
                int64_t lifted_lambda_res_33093 = add64(i_27979, lifted_lambda_res_33092);
                
                // blocked_v3.fut:16:26-31
                
                int64_t lifted_lambda_res_33095 = ((int64_t *) mem_34903.mem)[lifted_lambda_res_33093];
                
                // blocked_v3.fut:35:9-37:47
                
                int32_t zlzb_rhs_33097;
                int32_t acc_33099 = 0;
                
                for (int32_t i_33098 = 0; i_33098 < 4; i_33098++) {
                    // blocked_v3.fut:173:34-45
                    
                    int32_t defunc_0_get_bit_res_33100;
                    
                    if (futrts_get_bit_2473(ctx, &defunc_0_get_bit_res_33100, i_33098, lifted_lambda_res_33095) != 0) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:37:42-46
                    
                    int32_t zp_rhs_33101 = shl32(defunc_0_get_bit_res_33100, i_33098);
                    
                    // blocked_v3.fut:37:15-46
                    
                    int32_t loopres_33102 = add32(acc_33099, zp_rhs_33101);
                    int32_t acc_tmp_35128 = loopres_33102;
                    
                    acc_33099 = acc_tmp_35128;
                }
                zlzb_rhs_33097 = acc_33099;
                // blocked_v3.fut:34:5-12
                
                int64_t i32_res_33103 = sext_i32_i64(zlzb_rhs_33097);
                bool less_than_zzero_34673 = slt64(i32_res_33103, (int64_t) 0);
                bool greater_than_sizze_34674 = sle64((int64_t) 16, i32_res_33103);
                bool outside_bounds_dim_34675 = less_than_zzero_34673 || greater_than_sizze_34674;
                
                if (!outside_bounds_dim_34675) {
                    int16_t read_hist_34677 = ((int16_t *) mem_34904)[i32_res_33103];
                    
                    // blocked_v3.fut:27:34-37
                    
                    int16_t defunc_0_f_res_28003 = add16((int16_t) 1, read_hist_34677);
                    
                    ((int16_t *) mem_34904)[i32_res_33103] = defunc_0_f_res_28003;
                }
            }
        }
        // blocked_v3.fut:45:29-45
        for (int64_t nest_i_35129 = 0; nest_i_35129 < (int64_t) 16; nest_i_35129++) {
            ((int16_t *) mem_34917)[nest_i_35129] = (int16_t) 0;
        }
        // blocked_v3.fut:45:6-49:35
        
        int16_t sequential_offsets_res_28008;
        int16_t acc_28011 = (int16_t) 0;
        
        for (int64_t i_28009 = 0; i_28009 < (int64_t) 16; i_28009++) {
            // blocked_v3.fut:48:12-28
            ((int16_t *) mem_34917)[i_28009] = acc_28011;
            // blocked_v3.fut:49:27-34
            
            int16_t zp_rhs_28013 = ((int16_t *) mem_34904)[i_28009];
            
            // blocked_v3.fut:49:25-34
            
            int16_t tmp_28014 = add16(acc_28011, zp_rhs_28013);
            int16_t acc_tmp_35131 = tmp_28014;
            
            acc_28011 = acc_tmp_35131;
        }
        sequential_offsets_res_28008 = acc_28011;
        // blocked_v3.fut:82:7-110:15
        if (memblock_set(ctx, &mem_param_34926, &mem_34903, "mem_34903") != 0)
            return 1;
        for (int32_t i_28016 = 0; i_28016 < 4; i_28016++) {
            // blocked_v3.fut:55:5-60:60
            for (int64_t i_34684 = 0; i_34684 < (int64_t) 256; i_34684++) {
                // blocked_v3.fut:58:54-65
                
                int64_t c_28021 = mul64((int64_t) 20, i_34684);
                
                // blocked_v3.fut:58:69-72
                
                int64_t zt_lhs_28022 = add64((int64_t) 1, i_34684);
                
                // blocked_v3.fut:58:74-85
                
                int64_t c_28023 = mul64((int64_t) 20, zt_lhs_28022);
                
                // blocked_v3.fut:57:30-59:41
                
                int64_t j_m_i_28024 = sub64(c_28023, c_28021);
                
                // blocked_v3.fut:57:30-59:41
                
                int16_t c_28025;
                int16_t acc_28027 = (int16_t) 0;
                
                for (int64_t i_28026 = 0; i_28026 < j_m_i_28024; i_28026++) {
                    // blocked_v3.fut:55:5-60:60
                    
                    int64_t index_primexp_28028 = c_28021 + i_28026;
                    
                    // blocked_v3.fut:55:5-60:60
                    
                    int64_t v_28029 = ((int64_t *) mem_param_34926.mem)[index_primexp_28028];
                    
                    // blocked_v3.fut:173:34-45
                    
                    int32_t defunc_0_f_res_28030;
                    
                    if (futrts_get_bit_2473(ctx, &defunc_0_f_res_28030, i_28016, v_28029) != 0) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:84:19-26
                    
                    int16_t i32_res_28031 = sext_i32_i16(defunc_0_f_res_28030);
                    
                    // blocked_v3.fut:59:36-41
                    
                    int16_t loopres_28032 = add16(acc_28027, i32_res_28031);
                    int16_t acc_tmp_35136 = loopres_28032;
                    
                    acc_28027 = acc_tmp_35136;
                }
                c_28025 = acc_28027;
                // blocked_v3.fut:60:40-57
                
                int16_t zm_res_28033 = sub16((int16_t) 20, c_28025);
                
                ((int16_t *) mem_34927)[i_34684] = c_28025;
                ((int16_t *) mem_34928)[i_34684] = zm_res_28033;
            }
            // blocked_v3.fut:85:22-51
            // blocked_v3.fut:85:22-51
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34941, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34927, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
            // blocked_v3.fut:85:22-51
            // blocked_v3.fut:85:22-51
            lmad_copy_2b(ctx, 1, (uint16_t *) mem_34942, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34928, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
            // blocked_v3.fut:71:18-32
            for (int64_t nest_i_35137 = 0; nest_i_35137 < (int64_t) 256; nest_i_35137++) {
                ((int16_t *) mem_34943)[nest_i_35137] = (int16_t) 0;
            }
            // blocked_v3.fut:71:18-32
            for (int64_t nest_i_35138 = 0; nest_i_35138 < (int64_t) 256; nest_i_35138++) {
                ((int16_t *) mem_34944)[nest_i_35138] = (int16_t) 0;
            }
            // blocked_v3.fut:86:33-69
            for (int64_t nest_i_35139 = 0; nest_i_35139 < (int64_t) 1; nest_i_35139++) {
                ((int16_t *) mem_34945)[nest_i_35139] = (int16_t) 0;
            }
            // blocked_v3.fut:70:13-71:39
            
            bool acc_cert_33290;
            bool acc_cert_33291;
            bool acc_cert_33292;
            
            // blocked_v3.fut:68:21-71:39
            
            int16_t discard_34693;
            int16_t discard_34694;
            int16_t scanacc_34687;
            int16_t scanacc_34688;
            
            scanacc_34687 = (int16_t) 0;
            scanacc_34688 = (int16_t) 0;
            for (int64_t i_34692 = 0; i_34692 < (int64_t) 256; i_34692++) {
                int16_t x_33370 = ((int16_t *) mem_34941)[i_34692];
                int16_t x_33371 = ((int16_t *) mem_34942)[i_34692];
                
                // blocked_v3.fut:68:28-33
                
                int64_t lifted_lambda_res_33376 = add64((int64_t) 1, i_34692);
                
                // blocked_v3.fut:64:9-13
                
                int16_t tmp_33317 = add16(x_33370, scanacc_34687);
                
                // blocked_v3.fut:64:18-22
                
                int16_t tmp_33318 = add16(x_33371, scanacc_34688);
                
                // blocked_v3.fut:70:38-66
                
                bool cond_33357 = i_34692 == (int64_t) 255;
                
                // blocked_v3.fut:70:38-66
                
                int64_t lifted_lambda_res_33358;
                
                if (cond_33357) {
                    lifted_lambda_res_33358 = (int64_t) 0;
                } else {
                    lifted_lambda_res_33358 = (int64_t) -1;
                }
                // blocked_v3.fut:70:13-80
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_33358) && slt64(lifted_lambda_res_33358, (int64_t) 1)) {
                    ((int16_t *) mem_34945)[lifted_lambda_res_33358] = tmp_33318;
                }
                // blocked_v3.fut:71:9-39
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_33376) && slt64(lifted_lambda_res_33376, (int64_t) 256)) {
                    ((int16_t *) mem_34944)[lifted_lambda_res_33376] = tmp_33317;
                }
                // blocked_v3.fut:71:9-39
                // UpdateAcc
                if (sle64((int64_t) 0, lifted_lambda_res_33376) && slt64(lifted_lambda_res_33376, (int64_t) 256)) {
                    ((int16_t *) mem_34943)[lifted_lambda_res_33376] = tmp_33318;
                }
                
                int16_t scanacc_tmp_35140 = tmp_33317;
                int16_t scanacc_tmp_35141 = tmp_33318;
                
                scanacc_34687 = scanacc_tmp_35140;
                scanacc_34688 = scanacc_tmp_35141;
            }
            discard_34693 = scanacc_34687;
            discard_34694 = scanacc_34688;
            // blocked_v3.fut:71:41-45
            
            int16_t tmp_28088 = ((int16_t *) mem_34945)[(int64_t) 0];
            
            // blocked_v3.fut:88:19-47
            if (memblock_alloc(ctx, &mem_34946, (int64_t) 40960, "mem_34946")) {
                err = 1;
                goto cleanup;
            }
            // blocked_v3.fut:88:19-47
            // blocked_v3.fut:88:19-47
            lmad_copy_8b(ctx, 1, (uint64_t *) mem_34946.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint64_t *) mem_34881, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
            // blocked_v3.fut:90:11-109:27
            if (memblock_set(ctx, &mem_param_34952, &mem_34880, "mem_34880") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34955, &mem_34880, "mem_34880") != 0)
                return 1;
            for (int64_t k_28093 = 0; k_28093 < (int64_t) 20; k_28093++) {
                // blocked_v3.fut:102:15-77
                if (memblock_alloc(ctx, &mem_34970, (int64_t) 512, "mem_34970")) {
                    err = 1;
                    goto cleanup;
                }
                // blocked_v3.fut:102:15-77
                if (memblock_alloc(ctx, &mem_34971, (int64_t) 512, "mem_34971")) {
                    err = 1;
                    goto cleanup;
                }
                // blocked_v3.fut:102:15-77
                
                bool acc_cert_33617;
                
                // blocked_v3.fut:94:15-108:27
                for (int64_t i_34700 = 0; i_34700 < (int64_t) 256; i_34700++) {
                    int16_t eta_p_33703 = ((int16_t *) mem_param_34952.mem)[i_34700];
                    int16_t eta_p_33704 = ((int16_t *) mem_param_34955.mem)[i_34700];
                    int16_t eta_p_33705 = ((int16_t *) mem_34944)[i_34700];
                    int16_t eta_p_33706 = ((int16_t *) mem_34943)[i_34700];
                    
                    // blocked_v3.fut:12:28-36
                    
                    int64_t lifted_lambda_res_33710 = mul64((int64_t) 20, i_34700);
                    
                    // blocked_v3.fut:12:13-23
                    
                    int64_t lifted_lambda_res_33711 = add64(k_28093, lifted_lambda_res_33710);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool x_33712 = sle64((int64_t) 0, lifted_lambda_res_33711);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool y_33713 = slt64(lifted_lambda_res_33711, (int64_t) 5120);
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool bounds_check_33714 = x_33712 && y_33713;
                    
                    // blocked_v3.fut:95:38-43
                    
                    bool index_certs_33715;
                    
                    if (!bounds_check_33714) {
                        set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) lifted_lambda_res_33711, "] out of bounds for array of shape [", (long long) (int64_t) 5120, "].", "-> #0  blocked_v3.fut:95:38-43\n   #1  blocked_v3.fut:122:7-36\n   #2  blocked_v3.fut:173:3-73\n"));
                        err = FUTHARK_PROGRAM_ERROR;
                        goto cleanup;
                    }
                    // blocked_v3.fut:95:38-43
                    
                    int64_t get_arg0_33716 = ((int64_t *) mem_param_34926.mem)[lifted_lambda_res_33711];
                    
                    // blocked_v3.fut:173:34-45
                    
                    int32_t defunc_0_f_res_33717;
                    
                    if (futrts_get_bit_2473(ctx, &defunc_0_f_res_33717, i_28016, get_arg0_33716) != 0) {
                        err = 1;
                        goto cleanup;
                    }
                    // blocked_v3.fut:84:19-26
                    
                    int16_t i32_res_33718 = sext_i32_i16(defunc_0_f_res_33717);
                    
                    // blocked_v3.fut:96:38-98:54
                    
                    bool cond_33719 = i32_res_33718 == (int16_t) 0;
                    
                    // blocked_v3.fut:96:38-98:54
                    
                    int16_t i16_arg0_33720;
                    
                    if (cond_33719) {
                        // blocked_v3.fut:97:46-50
                        
                        int16_t i16_arg0_t_res_33876 = add16(eta_p_33704, eta_p_33706);
                        
                        i16_arg0_33720 = i16_arg0_t_res_33876;
                    } else {
                        // blocked_v3.fut:98:45-49
                        
                        int16_t zp_lhs_33722 = add16(tmp_28088, eta_p_33705);
                        
                        // blocked_v3.fut:98:50-54
                        
                        int16_t i16_arg0_f_res_33723 = add16(eta_p_33703, zp_lhs_33722);
                        
                        i16_arg0_33720 = i16_arg0_f_res_33723;
                    }
                    // blocked_v3.fut:96:29-98:54
                    
                    int64_t i16_res_33724 = sext_i16_i64(i16_arg0_33720);
                    
                    // blocked_v3.fut:102:15-77
                    // UpdateAcc
                    if (sle64((int64_t) 0, i16_res_33724) && slt64(i16_res_33724, (int64_t) 5120)) {
                        ((int64_t *) mem_34946.mem)[i16_res_33724] = get_arg0_33716;
                    }
                    // blocked_v3.fut:107:33-36
                    
                    int16_t tmp_33741 = add16(eta_p_33703, i32_res_33718);
                    
                    // blocked_v3.fut:107:49-52
                    
                    int16_t zp_rhs_33742 = (int16_t) 1 ^ i32_res_33718;
                    
                    // blocked_v3.fut:107:41-52
                    
                    int16_t tmp_33743 = add16(eta_p_33704, zp_rhs_33742);
                    
                    ((int16_t *) mem_34956)[i_34700] = tmp_33741;
                    ((int16_t *) mem_34957)[i_34700] = tmp_33743;
                }
                // blocked_v3.fut:102:15-77
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34970.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34956, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                // blocked_v3.fut:102:15-77
                lmad_copy_2b(ctx, 1, (uint16_t *) mem_34971.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34957, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 256});
                if (memblock_set(ctx, &mem_param_tmp_35145, &mem_34970, "mem_34970") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_tmp_35146, &mem_34971, "mem_34971") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34952, &mem_param_tmp_35145, "mem_param_tmp_35145") != 0)
                    return 1;
                if (memblock_set(ctx, &mem_param_34955, &mem_param_tmp_35146, "mem_param_tmp_35146") != 0)
                    return 1;
            }
            if (memblock_set(ctx, &ext_mem_34979, &mem_param_34952, "mem_param_34952") != 0)
                return 1;
            if (memblock_set(ctx, &ext_mem_34978, &mem_param_34955, "mem_param_34955") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_tmp_35132, &mem_34946, "mem_34946") != 0)
                return 1;
            if (memblock_set(ctx, &mem_param_34926, &mem_param_tmp_35132, "mem_param_tmp_35132") != 0)
                return 1;
        }
        if (memblock_set(ctx, &ext_mem_34983, &mem_param_34926, "mem_param_34926") != 0)
            return 1;
        lmad_copy_8b(ctx, 1, (uint64_t *) mem_34884, i_34709 * (int64_t) 5120, (int64_t []) {(int64_t) 1}, (uint64_t *) ext_mem_34983.mem, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 5120});
        if (memblock_unref(ctx, &ext_mem_34983, "ext_mem_34983") != 0)
            return 1;
        lmad_copy_2b(ctx, 1, (uint16_t *) mem_34887, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34917, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
        lmad_copy_2b(ctx, 1, (uint16_t *) mem_34890, i_34709 * (int64_t) 16, (int64_t []) {(int64_t) 1}, (uint16_t *) mem_34904, (int64_t) 0, (int64_t []) {(int64_t) 1}, (int64_t []) {(int64_t) 16});
    }
    if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
        return 1;
    if (memblock_unref(ctx, &mem_34903, "mem_34903") != 0)
        return 1;
    // blocked_v3.fut:173:47-71
    
    int64_t flat_dim_27963 = (int64_t) 5120 * n_18037;
    
    // blocked_v3.fut:173:3-73
    
    int64_t dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_27964 = mul64((int64_t) 16, n_18037);
    
    // blocked_v3.fut:41:5-32
    if (mem_35001_cached_sizze_35282 < bytes_35000) {
        err = lexical_realloc(ctx, &mem_35001, &mem_35001_cached_sizze_35282, bytes_35000);
        if (err != FUTHARK_SUCCESS)
            goto cleanup;
    }
    // blocked_v3.fut:41:5-32
    
    int64_t discard_34718;
    int64_t scanacc_34714 = (int64_t) 0;
    
    for (int64_t i_34716 = 0; i_34716 < dzlz7bUZLztZRz20Unum_binsz20Unz7dUzg_27964; i_34716++) {
        int64_t new_index_34755 = squot64(i_34716, n_18037);
        int64_t binop_y_34757 = n_18037 * new_index_34755;
        int64_t new_index_34758 = i_34716 - binop_y_34757;
        int16_t eta_p_33061 = ((int16_t *) mem_34890)[new_index_34758 * (int64_t) 16 + new_index_34755];
        
        // blocked_v3.fut:132:14-21
        
        int64_t i16_res_33062 = sext_i16_i64(eta_p_33061);
        
        // blocked_v3.fut:41:20-23
        
        int64_t defunc_0_op_res_28167 = add64(i16_res_33062, scanacc_34714);
        
        ((int64_t *) mem_35001)[i_34716] = scanacc_34714;
        
        int64_t scanacc_tmp_35153 = defunc_0_op_res_28167;
        
        scanacc_34714 = scanacc_tmp_35153;
    }
    discard_34718 = scanacc_34714;
    // blocked_v3.fut:145:17-28
    if (memblock_alloc(ctx, &mem_35009, bytes_34883, "mem_35009")) {
        err = 1;
        goto cleanup;
    }
    lmad_copy_8b(ctx, 2, (uint64_t *) mem_35009.mem, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (uint64_t *) mem_34884, (int64_t) 0, (int64_t []) {(int64_t) 5120, (int64_t) 1}, (int64_t []) {n_18037, (int64_t) 5120});
    // blocked_v3.fut:145:8-39
    
    bool acc_cert_32882;
    
    // blocked_v3.fut:137:7-145:39
    for (int64_t i_34720 = 0; i_34720 < flat_dim_27963; i_34720++) {
        int64_t new_index_34749 = squot64(i_34720, (int64_t) 5120);
        int64_t binop_y_34751 = (int64_t) 5120 * new_index_34749;
        int64_t new_index_34752 = i_34720 - binop_y_34751;
        int64_t v_32939 = ((int64_t *) mem_34884)[new_index_34749 * (int64_t) 5120 + new_index_34752];
        
        // blocked_v3.fut:35:9-37:47
        
        int32_t zlzb_rhs_32948;
        int32_t acc_32950 = 0;
        
        for (int32_t i_32949 = 0; i_32949 < 4; i_32949++) {
            // blocked_v3.fut:173:34-45
            
            int32_t defunc_0_get_bit_res_32951;
            
            if (futrts_get_bit_2473(ctx, &defunc_0_get_bit_res_32951, i_32949, v_32939) != 0) {
                err = 1;
                goto cleanup;
            }
            // blocked_v3.fut:37:42-46
            
            int32_t zp_rhs_32952 = shl32(defunc_0_get_bit_res_32951, i_32949);
            
            // blocked_v3.fut:37:15-46
            
            int32_t loopres_32953 = add32(acc_32950, zp_rhs_32952);
            int32_t acc_tmp_35156 = loopres_32953;
            
            acc_32950 = acc_tmp_35156;
        }
        zlzb_rhs_32948 = acc_32950;
        // blocked_v3.fut:34:5-12
        
        int64_t i32_res_32954 = sext_i32_i64(zlzb_rhs_32948);
        
        // blocked_v3.fut:140:68-93
        
        int64_t block_idx_32955 = sdiv64(i_34720, (int64_t) 5120);
        
        // blocked_v3.fut:141:67-89
        
        bool x_32956 = sle64((int64_t) 0, block_idx_32955);
        
        // blocked_v3.fut:141:67-89
        
        bool y_32957 = slt64(block_idx_32955, n_18037);
        
        // blocked_v3.fut:141:67-89
        
        bool bounds_check_32958 = x_32956 && y_32957;
        
        // blocked_v3.fut:141:67-89
        
        bool index_certs_32959;
        
        if (!bounds_check_32958) {
            set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) block_idx_32955, "] out of bounds for array of shape [", (long long) n_18037, "].", "-> #0  blocked_v3.fut:141:67-89\n   #1  blocked_v3.fut:173:3-73\n"));
            err = FUTHARK_PROGRAM_ERROR;
            goto cleanup;
        }
        // blocked_v3.fut:141:67-94
        
        bool x_32960 = sle64((int64_t) 0, i32_res_32954);
        
        // blocked_v3.fut:141:67-94
        
        bool y_32961 = slt64(i32_res_32954, (int64_t) 16);
        
        // blocked_v3.fut:141:67-94
        
        bool bounds_check_32962 = x_32960 && y_32961;
        
        // blocked_v3.fut:141:67-94
        
        bool index_certs_32963;
        
        if (!bounds_check_32962) {
            set_error(ctx, msgprintf("Error: %s%lld%s%lld%s\n\nBacktrace:\n%s", "Index [", (long long) i32_res_32954, "] out of bounds for array of shape [", (long long) (int64_t) 16, "].", "-> #0  blocked_v3.fut:141:67-94\n   #1  blocked_v3.fut:173:3-73\n"));
            err = FUTHARK_PROGRAM_ERROR;
            goto cleanup;
        }
        // blocked_v3.fut:173:3-73
        
        int64_t binop_x_32964 = n_18037 * i32_res_32954;
        
        // blocked_v3.fut:173:3-73
        
        int64_t index_primexp_32965 = block_idx_32955 + binop_x_32964;
        
        // blocked_v3.fut:173:3-73
        
        int64_t new_offset_32966 = ((int64_t *) mem_35001)[index_primexp_32965];
        
        // blocked_v3.fut:137:7-144:83
        
        int16_t i16_arg0_32967 = ((int16_t *) mem_34887)[block_idx_32955 * (int64_t) 16 + i32_res_32954];
        
        // blocked_v3.fut:142:73-108
        
        int64_t i16_res_32968 = sext_i16_i64(i16_arg0_32967);
        
        // blocked_v3.fut:143:92-103
        
        int64_t zp_lhs_32969 = mul64((int64_t) 5120, block_idx_32955);
        
        // blocked_v3.fut:143:104-122
        
        int64_t old_offset_32970 = add64(i16_res_32968, zp_lhs_32969);
        
        // blocked_v3.fut:144:56-68
        
        int64_t zp_lhs_32971 = sub64(i_34720, old_offset_32970);
        
        // blocked_v3.fut:144:70-82
        
        int64_t defunc_0_f_res_32972 = add64(new_offset_32966, zp_lhs_32971);
        
        // blocked_v3.fut:145:8-39
        // UpdateAcc
        if (sle64((int64_t) 0, defunc_0_f_res_32972) && slt64(defunc_0_f_res_32972, flat_dim_27963)) {
            ((int64_t *) mem_35009.mem)[defunc_0_f_res_32972] = v_32939;
        }
    }
    if (memblock_set(ctx, &mem_out_35119, &mem_35009, "mem_35009") != 0)
        return 1;
    prim_out_35120 = flat_dim_27963;
    if (memblock_set(ctx, &*mem_out_p_35264, &mem_out_35119, "mem_out_35119") != 0)
        return 1;
    *out_prim_out_35265 = prim_out_35120;
    
  cleanup:
    {
        free(mem_34879);
        free(mem_34881);
        free(mem_34884);
        free(mem_34887);
        free(mem_34890);
        free(mem_34904);
        free(mem_34917);
        free(mem_34927);
        free(mem_34928);
        free(mem_34941);
        free(mem_34942);
        free(mem_34943);
        free(mem_34944);
        free(mem_34945);
        free(mem_34956);
        free(mem_34957);
        free(mem_35001);
        if (memblock_unref(ctx, &mem_35009, "mem_35009") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35132, "mem_param_tmp_35132") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35146, "mem_param_tmp_35146") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_tmp_35145, "mem_param_tmp_35145") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34971, "mem_34971") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34970, "mem_34970") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34955, "mem_param_34955") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34952, "mem_param_34952") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34978, "ext_mem_34978") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34979, "ext_mem_34979") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34946, "mem_34946") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_param_34926, "mem_param_34926") != 0)
            return 1;
        if (memblock_unref(ctx, &ext_mem_34983, "ext_mem_34983") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34903, "mem_34903") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_34880, "mem_34880") != 0)
            return 1;
        if (memblock_unref(ctx, &mem_out_35119, "mem_out_35119") != 0)
            return 1;
    }
    return err;
}
FUTHARK_FUN_ATTR int futrts_entry_test_sort_reversed(struct futhark_context *ctx, bool *out_prim_out_35283)
{
    (void) ctx;
    
    int err = 0;
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    bool prim_out_35119;
    
    prim_out_35119 = defunc_0_reduce_res_32880;
    *out_prim_out_35283 = prim_out_35119;
    
  cleanup:
    { }
    return err;
}
FUTHARK_FUN_ATTR int futrts_get_bit_2473(struct futhark_context *ctx, int32_t *out_prim_out_35284, int32_t bit_16404, int64_t x_16405)
{
    (void) ctx;
    
    int err = 0;
    bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
    int32_t prim_out_35119;
    int64_t i32_res_26132 = sext_i32_i64(bit_16404);
    int64_t zgzg_res_26135 = ashr64(x_16405, i32_res_26132);
    int64_t za_res_26140 = (int64_t) 1 & zgzg_res_26135;
    int32_t to_i32_res_26142 = sext_i64_i32(za_res_26140);
    
    prim_out_35119 = to_i32_res_26142;
    *out_prim_out_35284 = prim_out_35119;
    
  cleanup:
    { }
    return err;
}

int futhark_entry_bench(struct futhark_context *ctx, struct futhark_u32_1d **out, const struct futhark_u32_1d *in0)
{
    int64_t nz2080U_26079 = (int64_t) 0;
    int ret = 0;
    
    lock_lock(&ctx->lock);
    
    struct memblock mem_out_35119;
    
    mem_out_35119.references = NULL;
    
    struct memblock xs_mem_34878;
    
    xs_mem_34878.references = NULL;
    xs_mem_34878 = in0->mem;
    nz2080U_26079 = in0->shape[0];
    if (!(nz2080U_26079 == in0->shape[0])) {
        ret = 1;
        set_error(ctx, msgprintf("Error: entry point arguments have invalid sizes.\n"));
    }
    if (ret == 0) {
        ret = futrts_entry_bench(ctx, &mem_out_35119, xs_mem_34878, nz2080U_26079);
        if (ret == 0) {
            bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
            
            assert((*out = (struct futhark_u32_1d *) malloc(sizeof(struct futhark_u32_1d))) != NULL);
            (*out)->mem = mem_out_35119;
            (*out)->shape[0] = nz2080U_26079;
        }
    }
    lock_unlock(&ctx->lock);
    return ret;
}
int futhark_entry_is_sorted(struct futhark_context *ctx, bool *out, const struct futhark_u32_2d *in0)
{
    int64_t n_21926 = (int64_t) 0;
    int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 = (int64_t) 0;
    bool prim_out_35119 = 0;
    int ret = 0;
    
    lock_lock(&ctx->lock);
    
    struct memblock arrs_mem_34878;
    
    arrs_mem_34878.references = NULL;
    arrs_mem_34878 = in0->mem;
    n_21926 = in0->shape[0];
    dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 = in0->shape[1];
    if (!(n_21926 == in0->shape[0] && dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927 == in0->shape[1])) {
        ret = 1;
        set_error(ctx, msgprintf("Error: entry point arguments have invalid sizes.\n"));
    }
    if (ret == 0) {
        ret = futrts_entry_is_sorted(ctx, &prim_out_35119, arrs_mem_34878, n_21926, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_21927);
        if (ret == 0) {
            bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
            
            *out = prim_out_35119;
        }
    }
    lock_unlock(&ctx->lock);
    return ret;
}
int futhark_entry_is_stable(struct futhark_context *ctx, bool *out, const struct futhark_u8_2d *in0)
{
    int64_t n_24423 = (int64_t) 0;
    int64_t dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 = (int64_t) 0;
    bool prim_out_35119 = 0;
    int ret = 0;
    
    lock_lock(&ctx->lock);
    
    struct memblock arrs_mem_34878;
    
    arrs_mem_34878.references = NULL;
    arrs_mem_34878 = in0->mem;
    n_24423 = in0->shape[0];
    dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 = in0->shape[1];
    if (!(n_24423 == in0->shape[0] && dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424 == in0->shape[1])) {
        ret = 1;
        set_error(ctx, msgprintf("Error: entry point arguments have invalid sizes.\n"));
    }
    if (ret == 0) {
        ret = futrts_entry_is_stable(ctx, &prim_out_35119, arrs_mem_34878, n_24423, dzlz7bUZLztZRz20Unum_elemsz20Ublock_sizzez7dUzg_24424);
        if (ret == 0) {
            bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
            
            *out = prim_out_35119;
        }
    }
    lock_unlock(&ctx->lock);
    return ret;
}
int futhark_entry_main(struct futhark_context *ctx, struct futhark_i64_1d **out, const struct futhark_i64_3d *in0)
{
    int64_t n_18037 = (int64_t) 0;
    int64_t prim_out_35120 = (int64_t) 0;
    int ret = 0;
    
    lock_lock(&ctx->lock);
    
    struct memblock mem_out_35119;
    
    mem_out_35119.references = NULL;
    
    struct memblock xss_mem_34878;
    
    xss_mem_34878.references = NULL;
    xss_mem_34878 = in0->mem;
    n_18037 = in0->shape[0];
    if (!(n_18037 == in0->shape[0] && ((int64_t) 20 == in0->shape[1] && (int64_t) 256 == in0->shape[2]))) {
        ret = 1;
        set_error(ctx, msgprintf("Error: entry point arguments have invalid sizes.\n"));
    }
    if (ret == 0) {
        ret = futrts_entry_main(ctx, &mem_out_35119, &prim_out_35120, xss_mem_34878, n_18037);
        if (ret == 0) {
            bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
            
            assert((*out = (struct futhark_i64_1d *) malloc(sizeof(struct futhark_i64_1d))) != NULL);
            (*out)->mem = mem_out_35119;
            (*out)->shape[0] = prim_out_35120;
        }
    }
    lock_unlock(&ctx->lock);
    return ret;
}
int futhark_entry_test_sort_reversed(struct futhark_context *ctx, bool *out)
{
    bool prim_out_35119 = 0;
    int ret = 0;
    
    lock_lock(&ctx->lock);
    if (ret == 0) {
        ret = futrts_entry_test_sort_reversed(ctx, &prim_out_35119);
        if (ret == 0) {
            bool defunc_0_reduce_res_32880 = ctx->constants->defunc_0_reduce_res_32880;
            
            *out = prim_out_35119;
        }
    }
    lock_unlock(&ctx->lock);
    return ret;
}
  
