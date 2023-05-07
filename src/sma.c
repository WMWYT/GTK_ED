#include "sma.h"

char * sma(char * x_c, char * H_c,  char * n_c){
    long x = strtol(x_c, NULL, 10);
    long H = strtol(H_c, NULL, 10);
    long n = strtol(n_c, NULL, 10);
    long h;
	unsigned long long r;
	int bin[32];
	int i;
    char * ans = (char *)malloc(10 * sizeof(char));

	r = x;
	i = 0;

	/* Converts H in Binary */
	while( H > 0 ){
		if (H % 2 == 0){
			bin[i] = 0;
		}else{
			bin[i] = 1;
		}
		H = H/2;
		i++;
	}

	i--; //t-1

	while(i>0){
		r = (r * r) % n;
		if( bin[--i] == 1 ){
			r = (r * x) % n;
		}
	}

    sprintf(ans, "%lld", r);

	return ans;
}