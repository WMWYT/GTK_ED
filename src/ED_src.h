#ifndef ED_SRC_H
#define ED_SRC_H

#include <stdio.h>
#include "caesar_code.h"
#include "affine.h"
#include "des.h"
#include "sma.h"
#include "rsa.h"

char * massage_ED(int ED_active, int E_OR_D, char * massage_str, char ** key);

#endif