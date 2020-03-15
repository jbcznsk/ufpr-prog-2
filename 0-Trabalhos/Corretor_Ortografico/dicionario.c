// GRR20190372 Jorge Lucas Vicilli Jabczenski

#include "dicionario.h"

String *carregaDicionario(FILE *dic, unsigned long int *contador){
    
    String *p;
    int iteracao = 1;

    *contador = 0;

    p = (String *) malloc (sizeof(String)*MAX_PALAVRAS); // Aloca dinamicamente o local das palavras
    if (!p)
    {                                             // Confere se a alocação ocorreu com sucesso
        perror("MALLOC FAILED");
        exit(1);
    }

    fscanf(dic, "%ms", &p[*contador]);                   // Lê a primeira palavra
    while(p[*contador] != NULL)                          // Continua lendo as palavras até chegar no NULL
    {                         
        (*contador)++;                                   // Aumenta o número de palavras lidas   
        if ((*contador) >= iteracao*MAX_PALAVRAS)        // Caso o número de palavras ultrapasse o número de alocações
        {       
            iteracao++;                                  // Aumenta a quantidade de vezes que foi feita a realocação
            p = realloc (p, iteracao*MAX_PALAVRAS*sizeof(String)); // Realoca mais MAX_PALAVRAS lugares de palavras
        }
        fscanf(dic, "%ms", &p[(*contador)]);             // Lê uma nova palavra
    }

    return p;
}

int funcaoComparacao(const void *p1,const void *p2) {
	return strcasecmp(*(char **) p1, *(char **) p2);       
}

int buscaBinaria(String *dic, char *palavra, int inicio, int fim){

    int meio = (inicio + fim) / 2, busca;

	if (fim <= inicio)
		return 0;

	busca = strcasecmp(palavra, dic[meio]);
	
	if (!busca)
		return 1;
	else if (busca < 0)
		return buscaBinaria(dic, palavra,inicio, meio);
	else 
		return buscaBinaria(dic, palavra, meio+1, fim);
	
}


void processaTexto(String *dicionario, int tamanho_dicionario){
    
    int contador;
    char *palavra, c;

    palavra = (char*) malloc (TAM_PALAVRA*sizeof(char)); // Aloca a palavra que será usada como comparação
    if (!palavra) // Verifica se foi alocada corretamente
    {
        perror("MALLOC FAILED");
        exit(1);
    }

    contador = 0;
    c = getchar();
    while(c != EOF){   
        while(!isalpha(c) && c != EOF){
            printf("%c", c);
			c = getchar();
  		}
       	while(isalpha(c) && c != EOF){
			palavra[contador++] = c;
			c = getchar();
		}
        palavra[contador] = '\0';
		if (strcmp(palavra, "")){
        	if (buscaBinaria(dicionario, palavra, 0, tamanho_dicionario))
				printf("%s", palavra);
			else
				printf("[%s]", palavra);
        contador = 0;
		}
    }
    free(palavra);
}