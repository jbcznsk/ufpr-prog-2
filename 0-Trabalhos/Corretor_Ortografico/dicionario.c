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

    fscanf(dic, "%ms", &p[(*contador)]);                 // Lê a primeira palavra
    while(p[*contador] != NULL)                          // Continua lendo as palavras até chegar no NULL
    {                         
        (*contador)++;                                   // Aumenta o número de palavras lidas   
        if ((*contador) >= iteracao*MAX_PALAVRAS)        // Caso o número de palavras ultrapasse o número de alocações
        {       
            iteracao++;                                  // Aumenta a quantidade de vezes que foi feita a realocação
            p = realloc (p, iteracao*MAX_PALAVRAS*sizeof(String)); // Realoca mais 10000 lugares de palavras
        }
        fscanf(dic, "%ms", &p[(*contador)]);             // Lê uma nova palavra
    }

    return p;
}



int buscaBinaria(String *dic, char *palavra, int inicio, int fim){

    int meio = (inicio + fim) / 2, busca;
	char *palavra_busca, *palavra_dic;

	palavra_busca = (char*) malloc (sizeof(palavra)   * sizeof(char));
	//palavra_dic   = (char*) malloc (sizeof(dic[meio]) * sizeof(char));

    //printf("comparando %s com %s \nMeio = %d\n", palavra, dic[meio], meio);
	//getchar();
	//dic[meio][0] = tolower(dic[meio][0]);
	for(int i = 0; i < strlen(palavra); i++)
		palavra_busca[i] = tolower(palavra[i]);

    //busca = strcmp(palavra_busca, palavra_dic);
	busca = strcasecmp(palavra, dic[meio]);
	
	free(palavra_busca);

	if ((fim-inicio) <= 0)
		return 0;

	if (!busca)
		return 1;
	else if (busca < 0)
		return buscaBinaria(dic, palavra,inicio, meio);
	else 
		return buscaBinaria(dic, palavra, meio+1, fim);
	
}
