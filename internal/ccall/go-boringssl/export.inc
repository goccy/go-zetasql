#ifndef BORINGSSL_EXPORT_H
#define BORINGSSL_EXPORT_H

#include "openssl/md5.h"

int MD5_Init(MD5_CTX *md5) {
  return 0;
}

int MD5_Update(MD5_CTX *md5, const void *data, size_t len) {
  return 0;
}

int MD5_Final(uint8_t out[MD5_DIGEST_LENGTH], MD5_CTX *md5) {
  return 0;
}

uint8_t *MD5(const uint8_t *data, size_t len, uint8_t out[MD5_DIGEST_LENGTH]) {
  return nullptr;
}

void MD5_Transform(MD5_CTX *md5, const uint8_t block[MD5_CBLOCK]) {

}

#include "openssl/sha.h"

int SHA1_Init(SHA_CTX *sha) {
  return 0;
}

int SHA1_Update(SHA_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA1_Final(uint8_t out[SHA_DIGEST_LENGTH], SHA_CTX *sha) {
  return 0;
}

uint8_t *SHA1(const uint8_t *data, size_t len, uint8_t out[SHA_DIGEST_LENGTH]) {
  return nullptr;
}

void SHA1_Transform(SHA_CTX *sha, const uint8_t block[SHA_CBLOCK]) {

}

int SHA224_Init(SHA256_CTX *sha) {
  return 0;
}

int SHA224_Update(SHA256_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA224_Final(uint8_t out[SHA224_DIGEST_LENGTH], SHA256_CTX *sha) {
  return 0;
}

uint8_t *SHA224(const uint8_t *data, size_t len, uint8_t out[SHA224_DIGEST_LENGTH]) {
  return nullptr;
}

int SHA256_Init(SHA256_CTX *sha) {
  return 0;
}

int SHA256_Update(SHA256_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA256_Final(uint8_t out[SHA256_DIGEST_LENGTH], SHA256_CTX *sha) {
  return 0;
}

uint8_t *SHA256(const uint8_t *data, size_t len, uint8_t out[SHA256_DIGEST_LENGTH]) {
  return nullptr;
}

void SHA256_Transform(SHA256_CTX *sha, const uint8_t block[SHA256_CBLOCK]) {

}

void SHA256_TransformBlocks(uint32_t state[8], const uint8_t *data, size_t num_blocks) {

}

int SHA384_Init(SHA512_CTX *sha) {
  return 0;
}

int SHA384_Update(SHA512_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA384_Final(uint8_t out[SHA384_DIGEST_LENGTH], SHA512_CTX *sha) {
  return 0;
}

uint8_t *SHA384(const uint8_t *data, size_t len, uint8_t out[SHA384_DIGEST_LENGTH]) {
  return nullptr;
}

int SHA512_Init(SHA512_CTX *sha) {
  return 0;
}

int SHA512_Update(SHA512_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA512_Final(uint8_t out[SHA512_DIGEST_LENGTH], SHA512_CTX *sha) {
  return 0;
}

uint8_t *SHA512(const uint8_t *data, size_t len, uint8_t out[SHA512_DIGEST_LENGTH]) {
  return nullptr;
}

void SHA512_Transform(SHA512_CTX *sha, const uint8_t block[SHA512_CBLOCK]) {

}

int SHA512_256_Init(SHA512_CTX *sha) {
  return 0;
}

int SHA512_256_Update(SHA512_CTX *sha, const void *data, size_t len) {
  return 0;
}

int SHA512_256_Final(uint8_t out[SHA512_256_DIGEST_LENGTH], SHA512_CTX *sha) {
  return 0;
}

uint8_t *SHA512_256(const uint8_t *data, size_t len, uint8_t out[SHA512_256_DIGEST_LENGTH]) {
  return nullptr;
}

#endif
