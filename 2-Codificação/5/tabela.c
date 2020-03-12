#include <stdio.h>
#include <locale.h>

int main(){

	setlocale(LC_CTYPE, "pt_BR.ISO-8859-1");
	
	printf("Imprimindo Tabela ASCII\n");
	for (int i = 32; i < 127; i++){
		printf("%c", i);
		if (!(i%10)) printf("\n");
	}	

	printf("\n Imprimindo Table ISO\n");

	for (int i = 32; i < 255; i++){
		printf("%c", i);
		if (!(i%10)) printf("\n");
	}	

		printf("\n");
	return 0;
}
