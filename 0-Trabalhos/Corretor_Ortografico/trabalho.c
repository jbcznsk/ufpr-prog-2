#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 10000

typedef char *String;

String *carregaDicionario(FILE *dic, unsigned long int *contador){
    
    String *p;
    int iteracao = 1;

    *contador = 0;

    p = (String *) malloc (sizeof(String)*MAX_PALAVRAS);
    if (!p){
        perror("MALLOC FOI PRAS CUCUIA");
        exit(1);
    }

    fscanf(dic, "%ms", &p[(*contador)]);
    while(p[*contador] != NULL){
        (*contador)++;
        if ((*contador) >= iteracao*MAX_PALAVRAS){
            iteracao++;
            p = realloc (p, iteracao*MAX_PALAVRAS*sizeof(String));
        }
        fscanf(dic, "%ms", &p[(*contador)]);
    }

    return p;
}

int main ()
{
    String *dicionario;
    FILE *dic;
    unsigned long int tamanho_dicionario;
  
    dic = fopen("brazilian", "r"); // Abre o dicionario
  
    if (!dic){ // Teste para verificar se o dicionario foi aberto com sucesso
        perror("Dicionario nao aberto");
        exit(1);
    }

    dicionario = carregaDicionario(dic, &tamanho_dicionario); // Dicionario carregado em RAM

    // Carregar TEXTO
    // Procurar as palavras (transformar em minuscula antes)
    // -- Ler letra por letra ou por fscanf??
    
   // for (unsigned long int i = 0; i < 275502; i++)
   //     printf("%s ", dicionario[i]);


    
    printf("tamanho : %ld", tamanho_dicionario);

    for (int i = 0; i  < tamanho_dicionario; i++)
        free(dicionario[i]);
    free(dicionario);

    fclose (dic);
    return (0) ;
}

