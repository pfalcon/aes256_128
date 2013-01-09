/*  
*   Byte-oriented AES-256 implementation.
*   All lookup tables replaced with 'on the fly' calculations. 
*
*   Copyright (c) 2007-2009 Ilya O. Levin, http://www.literatecode.com
*   Other contributors: Hal Finney
*   AES128 support (c) 2013 Paul Sokolovsky
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#ifndef uint8_t
#define uint8_t  unsigned char
#endif

// Undefine for AES256
#define AES128

#ifdef AES128
#define KEY_SIZE 16
#define N_ROUNDS 10
#define DEC_KEY_ROUNDS 11
#define DEC_RCON 0x6c
#else
#define KEY_SIZE 32
#define N_ROUNDS 14
#define DEC_KEY_ROUNDS 8
#define DEC_RCON 0x80
#endif

#ifdef __cplusplus
extern "C" { 
#endif

    typedef struct {
        uint8_t key[KEY_SIZE]; 
        uint8_t enckey[KEY_SIZE]; 
        uint8_t deckey[KEY_SIZE];
    } aes256_context; 


    void aes256_init(aes256_context *, uint8_t * /* key */);
    void aes256_done(aes256_context *);
    void aes256_encrypt_ecb(aes256_context *, uint8_t * /* plaintext */);
    void aes256_decrypt_ecb(aes256_context *, uint8_t * /* cipertext */);

#ifdef __cplusplus
}
#endif
