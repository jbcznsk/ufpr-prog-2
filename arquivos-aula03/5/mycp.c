#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	FILE *arquivo1, *arquivo2;
	char c;

	if (argc != 3){
		printf("Numero incorreto de argumentos\n");
		exit(1);
	}
	
	arquivo1 = fopen(argv[1], "r");
	if (!arquivo1){
		perror("Arquivo 1 Inexistente");
		exit(1);
	}	
	
	arquivo2 = fopen(argv[2], "r");
	if (arquivo2){
		printf("Arquivo 2 Já Existente\n");
		fclose(arquivo2);
		exit(1);
	} else {
		arquivo2 = fopen(argv[2], "w");
	}

	c = fgetc(arquivo1);
	while(c != EOF){
		fputc(c, arquivo2);
		c = fgetc(arquivo1);
	}

	fclose(arquivo1);
	fclose(arquivo2);

	return 0;
}
