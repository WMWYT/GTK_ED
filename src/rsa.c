#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


char buffer[1024];
const int MAX_DIGITS = 50;
int i,j = 0;

struct public_key_class{
  long long modulus;
  long long exponent;
};

struct private_key_class{
  long long modulus;
  long long exponent;
};

struct public_key_class pub;
struct private_key_class priv;

// This should totally be in the math library.
long long gcd(long long a, long long b)
{
  long long c;
  while ( a != 0 ) {
    c = a; a = b%a;  b = c;
  }
  return b;
}


long long ExtEuclid(long long a, long long b)
{
 long long x = 0, y = 1, u = 1, v = 0, gcd = b, m, n, q, r;
 while (a!=0) {
   q = gcd/a; r = gcd % a;
   m = x-u*q; n = y-v*q;
   gcd = a; a = r; x = u; y = v; u = m; v = n;
   }
   return y;
}
static inline long long modmult(long long a,long long b,long long mod)
{
   // this is necessary since we will be dividing by a
   if (a == 0 ){
         return 0;
   }
   register long long product = a * b;
    //if multiplication does not overflow, we can use it
   if (product / a == b){
          return product % mod;
   }
   // if a % 2 == 1 i. e. a >> 1 is not a / 2
   if ( a & 1 ) {
         product = modmult((a>>1), b, mod);
         if ((product << 1) > product ){
         return ((( product << 1 ) % mod ) + b) % mod;
      }
   }
   //implicit else
   product = modmult((a >> 1), b, mod);
   if ((product << 1) > product){
         return (product << 1) % mod ;
         }
   //implicit else: this is about 10x slower than the code above, but it will not overflow
    long long sum;
    sum = 0;
    while(b>0)
    {
        if(b&1)
            sum = (sum + a) % mod;
        a = (2*a) % mod;
        b>>=1;
    }
    return sum;
}
long long rsa_modExp(long long b, long long e, long long m)
{
      long long product;
      product = 1;
      if (b < 0 || e < 0 || m <= 0){
            return -1;
      }
      b = b % m;
      while ( e > 0){
            if (e & 1){
                  product = modmult(product, b, m);
            }
            b = modmult(b, b, m);
            e >>= 1;
      }
      return product;
}

//验证p q e是否合法，并计算其他条件
int info_verification(int p, int q, int e){
    long long phi_max = 0;
    long long max = 0;
    long long d = 0;
    max = p*q;
    phi_max = (p-1)*(q-1);
    if(!(p && q) || (p == q) || (gcd(phi_max, e) != 1)){
        return 0;
    }

    d = ExtEuclid(phi_max,e);
    //printf("d:%lld\n", d);
    while(d < 0){
        d = d+phi_max;
    }

    pub.modulus = max;
    pub.exponent = e;

    priv.modulus = max;
    priv.exponent = d;
}

char *rsa_encrypt(char * message, char ** key){
    int p = atoi(*key);
    int q = atoi(*(key + 1));
    int e = atoi(*(key + 2));

    long long message_ll = strtoll(message, NULL, 10);
    long long encrypted;

    char * encrypted_str = (char *) malloc(10 * sizeof(char));
    
    if(!info_verification(p, q, e)){
        return "输入的p、q、e不合法";
    }

    if(message == NULL){
        return "明文不能为空";
    }

    if ((encrypted = rsa_modExp(message_ll, pub.exponent, pub.modulus)) == -1)
        return "有问题";

    sprintf(encrypted_str, "%lld", encrypted);

    return encrypted_str;
}

char *rsa_decrypt(char * message, char ** key){
    int p = atoi(*key);
    int q = atoi(*(key + 1));
    int e = atoi(*(key + 2));

    if(!info_verification(p, q, e)){
        return "输入的p、q、e不合法";
    }

    long long message_ll = strtoll(message, NULL, 10);
    long long decrypted;
    char * decrypted_str = (char *) malloc(10 * sizeof(char));
    if((decrypted = rsa_modExp(message_ll, priv.exponent, priv.modulus)) == -1){
        return "有问题";
    }

    sprintf(decrypted_str, "%lld", decrypted);
    return decrypted_str;
}