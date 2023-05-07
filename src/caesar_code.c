#include "caesar_code.h"

char * caesar_code_encryption(char * massage, char * k){
    int tmp, i;
    int key = atoi(k);
	
	if(key == 0){
		return "请输入数字并且数字大于0";
	}

	static char massage_pass[100];

	for(i = 0; i < strlen(massage); i++){
		tmp = (massage[i] - 97 + key) % 26;
		massage_pass[i] = (char) (tmp + 97);
	}
	
	return massage_pass;
}

char * caesar_code_deciphering(char * massage_pass, char * k){
	int tmp, i;
    int key = atoi(k);
	static char massage[100];
	
	for(i = 0; i < strlen(massage_pass); i++){
		tmp = (massage_pass[i] - 'z' - key) % 26;
		printf("%d\n", tmp);
		massage[i] = (char) (tmp + 'z');
	}
	
	return massage;
}