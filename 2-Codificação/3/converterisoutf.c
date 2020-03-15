#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main(){

	setlocale(LC_CTYPE, "UTF-8");
//	setlocale(LC_CTYPE, "pt_BR.ISO-8859-15");

	unsigned char texto[500];
	unsigned char utf8[1000];
	int cont = 0;

	fgets(texto, 500,stdin);

	for (int i = 0; i < strlen(texto); i++){
		if ((texto[i] > 127)){
			unsigned char c = texto[i];
			utf8[cont+1] = (c | 0b10000000) & 0b10111111;
			utf8[cont] = ((c >> 6) | 0b11000000);
			cont+=2;
		} else {
			utf8[cont++] = texto[i];
		}
	}
	
	puts (utf8);
	
	return 0;
}
