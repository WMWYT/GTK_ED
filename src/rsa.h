#ifndef RSA_H
#define RSA_H

#include <stdint.h>

char *rsa_encrypt(char * message, char ** key);

char *rsa_decrypt(char * message, char ** key);

#endif