#ifndef AFFINE_H
#define AFFINE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * affine_encryption(char* text, char * addkey_str, char * mulkey_str);

char * affine_deciphering(char* password, char * addkey_str, char * mulkey_str);

#endif