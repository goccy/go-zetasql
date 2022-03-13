#include "openssl/bn.h"

#if defined(__cplusplus)
extern "C" {
#endif

BN_CTX *BN_CTX_new(void) {
  return nullptr;
}

void BN_CTX_free(BN_CTX *ctx) {

}

int BN_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) {
  return 0;
}

int BN_add_word(BIGNUM *a, BN_ULONG w) {
  return 0;
}

char *BN_bn2dec(const BIGNUM *a) {
  return nullptr;
}

BIGNUM *BN_copy(BIGNUM *dest, const BIGNUM *src) {
  return nullptr;
}

int BN_count_low_zero_bits(const BIGNUM *bn) {
  return 0;
}

int BN_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx) {
  return 0;
}

int BN_get_u64(const BIGNUM *bn, uint64_t *out) {
  return 0;
}

void BN_init(BIGNUM *bn) {
}

int BN_is_bit_set(const BIGNUM *a, int n) {
  return 0;
}

int BN_is_negative(const BIGNUM *bn) {
  return 0;
}

int BN_is_odd(const BIGNUM *bn) {
  return 0;
}

int BN_is_zero(const BIGNUM *bn) {
  return 0;
}

int BN_lshift(BIGNUM *r, const BIGNUM *a, int n) {
  return 0;
}

int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx) {
  return 0;
}

BIGNUM *BN_new(void) {
  return nullptr;
}

unsigned BN_num_bits(const BIGNUM *bn) {
  return 0;
}

int BN_rshift(BIGNUM *r, const BIGNUM *a, int n) {
  return 0;
}

void BN_set_negative(BIGNUM *bn, int sign) {
}

int BN_set_u64(BIGNUM *bn, uint64_t value) {
  return 0;
}

int BN_set_word(BIGNUM *bn, BN_ULONG value) {
  return 0;
}

int BN_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) {
  return 0;
}

int BN_ucmp(const BIGNUM *a, const BIGNUM *b) {
  return 0;
}

void BN_zero(BIGNUM *bn) {
}

void BN_free(BIGNUM *bn) {

}

void OPENSSL_free(void *orig_ptr) {

}

#if defined(__cplusplus)
}
#endif


/*
void BN_clear_free(BIGNUM *bn);
BIGNUM *BN_dup(const BIGNUM *src);
void BN_clear(BIGNUM *bn);
const BIGNUM *BN_value_one(void);
unsigned BN_num_bytes(const BIGNUM *bn);
int BN_one(BIGNUM *bn);
BIGNUM *BN_bin2bn(const uint8_t *in, size_t len, BIGNUM *ret);
size_t BN_bn2bin(const BIGNUM *in, uint8_t *out);
BIGNUM *BN_le2bn(const uint8_t *in, size_t len, BIGNUM *ret);
int BN_bn2le_padded(uint8_t *out, size_t len, const BIGNUM *in);
int BN_bn2bin_padded(uint8_t *out, size_t len, const BIGNUM *in);
int BN_bn2cbb_padded(CBB *out, size_t len, const BIGNUM *in);
char *BN_bn2hex(const BIGNUM *bn);
int BN_hex2bn(BIGNUM **outp, const char *in);
int BN_dec2bn(BIGNUM **outp, const char *in);
int BN_asc2bn(BIGNUM **outp, const char *in);
int BN_print(BIO *bio, const BIGNUM *a);
int BN_print_fp(FILE *fp, const BIGNUM *a);
BN_ULONG BN_get_word(const BIGNUM *bn);
OPENSSL_EXPORT int BN_parse_asn1_unsigned(CBS *cbs, BIGNUM *ret);
OPENSSL_EXPORT int BN_marshal_asn1(CBB *cbb, const BIGNUM *bn);
OPENSSL_EXPORT void BN_CTX_start(BN_CTX *ctx);
OPENSSL_EXPORT BIGNUM *BN_CTX_get(BN_CTX *ctx);
OPENSSL_EXPORT void BN_CTX_end(BN_CTX *ctx);
OPENSSL_EXPORT int BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
OPENSSL_EXPORT int BN_usub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
OPENSSL_EXPORT int BN_sub_word(BIGNUM *a, BN_ULONG w);
OPENSSL_EXPORT int BN_mul_word(BIGNUM *bn, BN_ULONG w);
OPENSSL_EXPORT int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
OPENSSL_EXPORT int BN_div(BIGNUM *quotient, BIGNUM *rem,
                          const BIGNUM *numerator, const BIGNUM *divisor,
                          BN_CTX *ctx);
OPENSSL_EXPORT BN_ULONG BN_div_word(BIGNUM *numerator, BN_ULONG divisor);
OPENSSL_EXPORT int BN_sqrt(BIGNUM *out_sqrt, const BIGNUM *in, BN_CTX *ctx);
OPENSSL_EXPORT int BN_cmp(const BIGNUM *a, const BIGNUM *b);
OPENSSL_EXPORT int BN_cmp_word(const BIGNUM *a, BN_ULONG b);
OPENSSL_EXPORT int BN_equal_consttime(const BIGNUM *a, const BIGNUM *b);
OPENSSL_EXPORT int BN_abs_is_word(const BIGNUM *bn, BN_ULONG w);
OPENSSL_EXPORT int BN_is_one(const BIGNUM *bn);
OPENSSL_EXPORT int BN_is_word(const BIGNUM *bn, BN_ULONG w);
OPENSSL_EXPORT int BN_is_pow2(const BIGNUM *a);
OPENSSL_EXPORT int BN_lshift1(BIGNUM *r, const BIGNUM *a);
OPENSSL_EXPORT int BN_rshift1(BIGNUM *r, const BIGNUM *a);
OPENSSL_EXPORT int BN_set_bit(BIGNUM *a, int n);
OPENSSL_EXPORT int BN_clear_bit(BIGNUM *a, int n);
OPENSSL_EXPORT int BN_mask_bits(BIGNUM *a, int n);
OPENSSL_EXPORT BN_ULONG BN_mod_word(const BIGNUM *a, BN_ULONG w);
OPENSSL_EXPORT int BN_mod_pow2(BIGNUM *r, const BIGNUM *a, size_t e);
OPENSSL_EXPORT int BN_nnmod_pow2(BIGNUM *r, const BIGNUM *a, size_t e);
OPENSSL_EXPORT int BN_nnmod(BIGNUM *rem, const BIGNUM *numerator,
                            const BIGNUM *divisor, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                              const BIGNUM *m, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_add_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                                    const BIGNUM *m);
OPENSSL_EXPORT int BN_mod_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                              const BIGNUM *m, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_sub_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                                    const BIGNUM *m);
OPENSSL_EXPORT int BN_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                              const BIGNUM *m, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m,
                              BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_lshift(BIGNUM *r, const BIGNUM *a, int n,
                                 const BIGNUM *m, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_lshift_quick(BIGNUM *r, const BIGNUM *a, int n,
                                       const BIGNUM *m);
OPENSSL_EXPORT int BN_mod_lshift1(BIGNUM *r, const BIGNUM *a, const BIGNUM *m,
                                  BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_lshift1_quick(BIGNUM *r, const BIGNUM *a,
                                        const BIGNUM *m);
OPENSSL_EXPORT BIGNUM *BN_mod_sqrt(BIGNUM *in, const BIGNUM *a, const BIGNUM *p,
                                   BN_CTX *ctx);
OPENSSL_EXPORT int BN_rand(BIGNUM *rnd, int bits, int top, int bottom);
OPENSSL_EXPORT int BN_pseudo_rand(BIGNUM *rnd, int bits, int top, int bottom);
OPENSSL_EXPORT int BN_rand_range(BIGNUM *rnd, const BIGNUM *range);
OPENSSL_EXPORT int BN_rand_range_ex(BIGNUM *r, BN_ULONG min_inclusive,
                                    const BIGNUM *max_exclusive);
OPENSSL_EXPORT int BN_pseudo_rand_range(BIGNUM *rnd, const BIGNUM *range);
OPENSSL_EXPORT void BN_GENCB_set(BN_GENCB *callback,
                                 int (*f)(int event, int n, BN_GENCB *),
                                 void *arg);
OPENSSL_EXPORT int BN_GENCB_call(BN_GENCB *callback, int event, int n);
OPENSSL_EXPORT int BN_generate_prime_ex(BIGNUM *ret, int bits, int safe,
                                        const BIGNUM *add, const BIGNUM *rem,
                                        BN_GENCB *cb);


OPENSSL_EXPORT int BN_enhanced_miller_rabin_primality_test(
    enum bn_primality_result_t *out_result, const BIGNUM *w, int checks,
    BN_CTX *ctx, BN_GENCB *cb);
OPENSSL_EXPORT int BN_primality_test(int *is_probably_prime,
                                     const BIGNUM *candidate, int checks,
                                     BN_CTX *ctx, int do_trial_division,
                                     BN_GENCB *cb);
OPENSSL_EXPORT int BN_is_prime_fasttest_ex(const BIGNUM *candidate, int checks,
                                           BN_CTX *ctx, int do_trial_division,
                                           BN_GENCB *cb);
OPENSSL_EXPORT int BN_is_prime_ex(const BIGNUM *candidate, int checks,
                                  BN_CTX *ctx, BN_GENCB *cb);

OPENSSL_EXPORT int BN_gcd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                          BN_CTX *ctx);
OPENSSL_EXPORT BIGNUM *BN_mod_inverse(BIGNUM *out, const BIGNUM *a,
                                      const BIGNUM *n, BN_CTX *ctx);
int BN_mod_inverse_blinded(BIGNUM *out, int *out_no_inverse, const BIGNUM *a,
                           const BN_MONT_CTX *mont, BN_CTX *ctx);
int BN_mod_inverse_odd(BIGNUM *out, int *out_no_inverse, const BIGNUM *a,
                       const BIGNUM *n, BN_CTX *ctx);
OPENSSL_EXPORT BN_MONT_CTX *BN_MONT_CTX_new_for_modulus(const BIGNUM *mod,
                                                        BN_CTX *ctx);
OPENSSL_EXPORT BN_MONT_CTX *BN_MONT_CTX_new_consttime(const BIGNUM *mod,
                                                      BN_CTX *ctx);
OPENSSL_EXPORT void BN_MONT_CTX_free(BN_MONT_CTX *mont);
OPENSSL_EXPORT BN_MONT_CTX *BN_MONT_CTX_copy(BN_MONT_CTX *to,
                                             const BN_MONT_CTX *from);
int BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, CRYPTO_MUTEX *lock,
                           const BIGNUM *mod, BN_CTX *bn_ctx);
OPENSSL_EXPORT int BN_to_montgomery(BIGNUM *ret, const BIGNUM *a,
                                    const BN_MONT_CTX *mont, BN_CTX *ctx);
OPENSSL_EXPORT int BN_from_montgomery(BIGNUM *ret, const BIGNUM *a,
                                      const BN_MONT_CTX *mont, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_mul_montgomery(BIGNUM *r, const BIGNUM *a,
                                         const BIGNUM *b,
                                         const BN_MONT_CTX *mont, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                              const BIGNUM *m, BN_CTX *ctx);
OPENSSL_EXPORT int BN_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                                   const BIGNUM *m, BN_CTX *ctx,
                                   const BN_MONT_CTX *mont);
OPENSSL_EXPORT int BN_mod_exp_mont_consttime(BIGNUM *rr, const BIGNUM *a,
                                             const BIGNUM *p, const BIGNUM *m,
                                             BN_CTX *ctx,
                                             const BN_MONT_CTX *mont);
OPENSSL_EXPORT size_t BN_bn2mpi(const BIGNUM *in, uint8_t *out);
OPENSSL_EXPORT BIGNUM *BN_mpi2bn(const uint8_t *in, size_t len, BIGNUM *out);
OPENSSL_EXPORT int BN_mod_exp_mont_word(BIGNUM *r, BN_ULONG a, const BIGNUM *p,
                                        const BIGNUM *m, BN_CTX *ctx,
                                        const BN_MONT_CTX *mont);
OPENSSL_EXPORT int BN_mod_exp2_mont(BIGNUM *r, const BIGNUM *a1,
                                    const BIGNUM *p1, const BIGNUM *a2,
                                    const BIGNUM *p2, const BIGNUM *m,
                                    BN_CTX *ctx, const BN_MONT_CTX *mont);
OPENSSL_EXPORT BN_MONT_CTX *BN_MONT_CTX_new(void);
OPENSSL_EXPORT int BN_MONT_CTX_set(BN_MONT_CTX *mont, const BIGNUM *mod,
                                   BN_CTX *ctx);
OPENSSL_EXPORT int BN_bn2binpad(const BIGNUM *in, uint8_t *out, int len);
OPENSSL_EXPORT unsigned BN_num_bits_word(BN_ULONG l);
*/
