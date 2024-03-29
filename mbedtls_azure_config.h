// ----------------------------------------------------------------------------
// Copyright 2016-2019 ARM Ltd.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------

#ifndef AZURE_MBEDTLS_CONFIG_H
#define AZURE_MBEDTLS_CONFIG_H

/*! Size optimized TLS config to connect to Azure IoT Hub using RSA X.509 Certificates */

/* Platform has time function to provide time for certificates verifications */
#if 0 //Please set to 1 if you are using secure time
#ifndef MBEDTLS_HAVE_TIME
    #define MBEDTLS_HAVE_TIME
#endif //MBEDTLS_HAVE_TIME

#ifndef MBEDTLS_HAVE_TIME_DATE
    #define MBEDTLS_HAVE_TIME_DATE
#endif //MBEDTLS_HAVE_TIME_DATE

#ifndef MBEDTLS_PLATFORM_TIME_ALT
    #define MBEDTLS_PLATFORM_TIME_ALT
#endif //MBEDTLS_PLATFORM_TIME_ALT

/* System support */
#ifndef MBEDTLS_HAVE_ASM
    #define MBEDTLS_HAVE_ASM
#endif //MBEDTLS_HAVE_ASM
#endif
/* mbed TLS feature support */
#ifndef MBEDTLS_ECP_DP_SECP256R1_ENABLED
    #define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#endif //MBEDTLS_ECP_DP_SECP256R1_ENABLED

#ifndef MBEDTLS_ECP_NIST_OPTIM
    #define MBEDTLS_ECP_NIST_OPTIM
#endif //MBEDTLS_ECP_NIST_OPTIM

#ifndef MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
    #define MBEDTLS_SSL_MAX_FRAGMENT_LENGTH
#endif //MBEDTLS_SSL_MAX_FRAGMENT_LENGTH

#ifndef MBEDTLS_SSL_PROTO_TLS1_2
    #define MBEDTLS_SSL_PROTO_TLS1_2
#endif //MBEDTLS_SSL_PROTO_TLS1_2

#ifndef MBEDTLS_SSL_EXPORT_KEYS
    #define MBEDTLS_SSL_EXPORT_KEYS
#endif //MBEDTLS_SSL_EXPORT_KEYS

/* mbed TLS modules */
#ifndef MBEDTLS_AES_C
    #define MBEDTLS_AES_C
#endif //MBEDTLS_AES_C

/* Disable some of the speed optimizations on AES code to save
 * ~6200 bytes of ROM. According to comments on the mbedtls PR 394,
 * the speed on Cortex M4 is not even reduced by this. */
#ifndef MBEDTLS_AES_FEWER_TABLES
    #define MBEDTLS_AES_FEWER_TABLES
#endif // MBEDTLS_AES_FEWER_TABLES


#ifndef MBEDTLS_BIGNUM_C
    #define MBEDTLS_BIGNUM_C
#endif //MBEDTLS_BIGNUM_C

#ifndef MBEDTLS_CIPHER_C
    #define MBEDTLS_CIPHER_C
#endif //MBEDTLS_CIPHER_C

#ifndef MBEDTLS_CTR_DRBG_C
    #define MBEDTLS_CTR_DRBG_C
#endif //MBEDTLS_CTR_DRBG_C

#ifndef MBEDTLS_ECP_C
    #define MBEDTLS_ECP_C
#endif //MBEDTLS_ECP_C

#ifndef MBEDTLS_ENTROPY_C
    #define MBEDTLS_ENTROPY_C
#endif //MBEDTLS_ENTROPY_C

#ifndef MBEDTLS_MD_C
    #define MBEDTLS_MD_C
#endif //MBEDTLS_MD_C

#ifndef MBEDTLS_OID_C
    #define MBEDTLS_OID_C
#endif //MBEDTLS_OID_C

#ifndef MBEDTLS_PK_C
    #define MBEDTLS_PK_C
#endif //MBEDTLS_PK_C

#ifndef MBEDTLS_PK_PARSE_C
    #define MBEDTLS_PK_PARSE_C
#endif //MBEDTLS_PK_PARSE_C

#ifndef MBEDTLS_SHA256_C
    #define MBEDTLS_SHA256_C
#endif //MBEDTLS_SHA256_C

// Disable the speed optimizations of SHA256, makes binary size smaller
// on Cortex-M by 1800B with ARMCC5 and 1384B with GCC 6.3.
#ifndef MBEDTLS_SHA256_SMALLER
    #define MBEDTLS_SHA256_SMALLER
#endif // MBEDTLS_SHA256_SMALLER

#ifndef MBEDTLS_SSL_COOKIE_C
    #define MBEDTLS_SSL_COOKIE_C
#endif //MBEDTLS_SSL_COOKIE_C

#ifndef MBEDTLS_SSL_CLI_C
    #define MBEDTLS_SSL_CLI_C
#endif //MBEDTLS_SSL_CLI_C

#ifndef MBEDTLS_SSL_TLS_C
    #define MBEDTLS_SSL_TLS_C
#endif //MBEDTLS_SSL_TLS_C
// XXX mbedclient needs these: mbedtls_x509_crt_free, mbedtls_x509_crt_init, mbedtls_x509_crt_parse
#ifndef MBEDTLS_X509_USE_C
    #define MBEDTLS_X509_USE_C
#endif //MBEDTLS_X509_USE_C

#ifndef MBEDTLS_X509_CRT_PARSE_C
    #define MBEDTLS_X509_CRT_PARSE_C
#endif //MBEDTLS_X509_CRT_PARSE_C
// a bit wrong way to get mbedtls_ssl_conf_psk:
#ifndef MBEDTLS_CMAC_C
    #define MBEDTLS_CMAC_C
#endif //MBEDTLS_CMAC_C

#ifndef MBEDTLS_ECDH_C
    #define MBEDTLS_ECDH_C
#endif //MBEDTLS_ECDH_C

#ifndef MBEDTLS_ECDSA_C
    #define MBEDTLS_ECDSA_C
#endif //MBEDTLS_ECDSA_C

#ifndef MBEDTLS_GCM_C
    #define MBEDTLS_GCM_C
#endif //MBEDTLS_GCM_C

#ifndef MBEDTLS_X509_CRT_PARSE_C
    #define MBEDTLS_X509_CRT_PARSE_C
#endif //MBEDTLS_X509_CRT_PARSE_C

#ifndef MBEDTLS_X509_CSR_PARSE_C
    #define MBEDTLS_X509_CSR_PARSE_C
#endif //MBEDTLS_X509_CSR_PARSE_C

#ifndef MBEDTLS_SHA1_C
    #define MBEDTLS_SHA1_C
#endif

// /*! All of the following definitions are optimizations (reduce mbedTLS memory usage and size),
// *   changing them is on the user responsibility since they can enlarge
// *   the binary footprint and the memory usage
// */

// define to save 8KB RAM at the expense of ROM
#ifndef MBEDTLS_AES_ROM_TABLES
    #define MBEDTLS_AES_ROM_TABLES
#endif //MBEDTLS_AES_ROM_TABLES

// Reduce IO buffer to save RAM, default is 16KB
#ifndef MBEDTLS_SSL_MAX_CONTENT_LEN
    #define MBEDTLS_SSL_MAX_CONTENT_LEN (5*1024)
#endif //MBEDTLS_SSL_MAX_CONTENT_LEN

// Multiple Precision Integers when using RSA can be smaller
#define MBEDTLS_MPI_MAX_SIZE 512
#define MBEDTLS_MPI_WINDOW_SIZE 1

// Remove error messages, save 10KB of ROM
// #undef MBEDTLS_ERROR_C

// Remove selftesting and save 11KB of ROM
#undef MBEDTLS_SELF_TEST

#undef MBEDTLS_CERTS_C

// Reduces ROM size by 30 kB
#undef MBEDTLS_ERROR_STRERROR_DUMMY

#undef MBEDTLS_VERSION_FEATURES

// You can disable debug as long as you disable MBED_CONF_TLS_SOCKET_DEBUG_LEVEL
// #undef MBEDTLS_DEBUG_C

#undef MBEDTLS_SHA512_C

#undef MBEDTLS_SSL_SRV_C

#undef MBEDTLS_ECP_DP_SECP192R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP224R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP384R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP521R1_ENABLED
#undef MBEDTLS_ECP_DP_SECP192K1_ENABLED
#undef MBEDTLS_ECP_DP_SECP224K1_ENABLED
#undef MBEDTLS_ECP_DP_SECP256K1_ENABLED
#undef MBEDTLS_ECP_DP_BP256R1_ENABLED
#undef MBEDTLS_ECP_DP_BP384R1_ENABLED
#undef MBEDTLS_ECP_DP_BP512R1_ENABLED
#undef MBEDTLS_ECP_DP_CURVE25519_ENABLED

// Reduces size particularly in case PSA crypto is used
#undef MBEDTLS_CHACHA20_C
#undef MBEDTLS_CHACHAPOLY_C
#undef MBEDTLS_POLY1305_C

#include "mbedtls/check_config.h"

#endif /* AZURE_MBEDTLS_CONFIG_H */
