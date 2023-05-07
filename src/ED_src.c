#include "ED_src.h"

char * massage_ED(int ED_active, int E_OR_D, char * massage_str, char ** key){
    char * massage_output;
    if(E_OR_D == 0){
        switch(ED_active){
            case 0:
                return caesar_code_encryption(massage_str, *key);
            case 1:
                return affine_encryption(massage_str, *key, *(key + 1));
            case 2:                
                return des_encryption_and_deciphering(massage_str, *key, ENCRYPTION_MODE);
            case 3:
                return sma(massage_str, *key, *(key + 1));
            case 4:
                return rsa_encrypt(massage_str, key);
            default:
                printf("功能尚未完善2");
        }
    }else{
        switch (ED_active){
            case 0:
                return caesar_code_deciphering(massage_str, *key);
            case 1:
                return affine_deciphering(massage_str, *key, *(key + 1));
            case 2:                
                return des_encryption_and_deciphering(massage_str, *key, DECRYPTION_MODE);
            case 3:
                return sma(massage_str, *key, *(key + 1));
            case 4:
                return rsa_decrypt(massage_str, key);
            default:
                printf("功能尚未完善3");
        }
    }

    return "hello";
}