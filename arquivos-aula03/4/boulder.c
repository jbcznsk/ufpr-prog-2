#include <stdio.h>
#include <stdlib.h>

int main(){

	char **matriz;
	int linhas, colunas, contador;
	char leitura[20], c;

	FILE *arquivo;
	arquivo = fopen("mapa.txt", "r");

	if (!arquivo){
		perror("PROBLEMINHA");
		exit(1);
	}

	contador = 0;
	c = fgetc(arquivo);
	while(c != ' ' && c != '\n'){
		leitura[contador++] = c;
		c = fgetc(arquivo);
	}
	linhas = atoi(leitura);

	contador = 0;
	c = fgetc(arquivo);
	while(c != ' ' && c != '\n'){
		leitura[contador++] = c;
		c = fgetc(arquivo);
	}
	colunas = atoi(leitura);

	printf("linhas : %d, colunas = %d\n", linhas, colunas);

	matriz = (char **)malloc(linhas * sizeof(char*));
	for (int i = 0; i < linhas; i++)
		matriz[i] = (char*) malloc (colunas * sizeof(char));

	int k,l;
	k = 0;
	while(k < linhas){
		l = 0;
		c = fgetc(arquivo);
		while(c != '\n'){
			matriz[k][l++] = c;
			c = fgetc(arquivo);
		}
		k++;
	}


	for(int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			printf("%c", matriz[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < linhas; i++)
		free(matriz[i]);
	free(matriz);

	fclose (arquivo);

	return 0;
}
