#ifndef _DES_H_
#define _DES_H_

#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 0

typedef struct {
	unsigned char k[8];
	unsigned char c[4];
	unsigned char d[4];
} key_set;

char * des_encryption_and_deciphering(char * massage, char * key, int process_mode);

#endif
