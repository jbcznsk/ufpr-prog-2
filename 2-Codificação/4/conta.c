#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define BYTE1 0b00000000
#define BYTE2 0b00000110
#define BYTE3 0b00001110
#define BYTE4 0b00011110

char *utf8strn(char *s, int n){
	
	int tam = strlen(s);
	int index = 0;
	int count = 0;

	while(count < n){
		if ((s[index] >> 7) == BYTE1){
			index++;
			count++;
		}
		else if (((s[index] >> 5) & BYTE2) == BYTE2){
			index+=2;
			count++;
		}
		else if (((s[index] >> 4) & BYTE3) == BYTE3){
			index+=3;
			count++;
		}
		else if (((s[index] >> 3) & BYTE4) == BYTE4){
			index+=4;
			count++;
		}
	}
	return &s[index];
}

int main(){

	setlocale(LC_CTYPE, "UTF-8");

	char texto[100];

	scanf("%[^\n]", &texto);

	printf("tamanho: %d\n", strlen(texto));

	char *que = utf8strn(texto, 4);

	printf("%s", que);

	return 0;
}
