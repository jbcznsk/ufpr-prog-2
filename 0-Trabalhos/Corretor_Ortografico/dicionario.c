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