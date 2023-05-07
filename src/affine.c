#include "affine.h"

int extendedeuclid(int m,int b)
{
    int a1, a2, a3;
    int b1, b2, b3;
    int t1, t2, t3;
    a1 = 1; a2 = 0; a3 = m;
    b1 = 0; b2 = 1; b3 = b;
    while(1)
    {
        if(b3 == 0) return 0;
        if(b3 == 1)
        {
            if(b2 < 0) b2 = m + b2;
            return b2;
        }
        
        int q = a3 / b3;
        t1 = a1 - q * b1;
        t2 = a2 - q * b2;
        t3 = a3 - q * b3;
        
        a1=b1;
        a2=b2;
        a3=b3;
        b1=t1;
        b2=t2;
        b3=t3;
    }
    return 0;
}

char * affine_encryption(char* text, char * addkey_str, char * mulkey_str){
    int len = strlen(text);
    
    int addkey = atoi(addkey_str);
    int mulkey = atoi(mulkey_str);

    if(!extendedeuclid(26, mulkey)){
        return "密钥2在26内无逆元";
    }

    char * password = text;

    for(int i=0; i < len; i++)
    {
        int code = text[i]-'a';
        password[i] = (code*mulkey+addkey)%26+'a';
    }

    return password;
}

char * affine_deciphering(char* password, char * addkey_str, char * mulkey_str){
    int len = strlen(password);
    int addkey = atoi(addkey_str);
    int mulkey = atoi(mulkey_str);

    if(!extendedeuclid(26, mulkey)){
        return "密钥2在26内无逆元";
    }

    char* text = password;
    
    for(int i = 0; i < len; i++)
    {
        int code = password[i]-'a';
        text[i]=((code-addkey+ 26) * extendedeuclid(26,mulkey))% 26 + 'a';
    }
    
    return text;
}