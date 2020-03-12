#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100000

typedef char *String;

String *carregaDicionario(FILE *dic){
    
    String *p;
    unsigned long int contador = 0, volta = 1;

    p = (String *) malloc (sizeof(String)*TAM);
    if (!p){
        perror("MALLOC FOI PRAS CUCUIA");
        exit(1);
    }

    fscanf(dic, "%ms", &p[contador]);
    while(p[contador] != NULL){
        contador++;
        if (contador >= volta*TAM){
            volta++;
            p = realloc (p, volta*TAM*sizeof(String));
        }
        fscanf(dic, "%ms", &p[contador]);
    }

    return p;
}

int main ()
{
    String *dicionario;
    FILE *dic;
  
    dic = fopen("brazilian", "r"); // Abre o dicionario
  
    if (!dic){ // Teste para verificar se o dicionario foi aberto com sucesso
        perror("Dicionario nao aberto");
        exit(1);
    }

    dicionario = carregaDicionario(dic); // Dicionario carregado em RAM

    // Carregar TEXTO
    // Procurar as palavras (transformar em minuscula antes)
    // -- Ler letra por letra ou por fscanf??
    
    for (unsigned long int i = 0; i < 275502; i++)
        printf("%s ", dicionario[i]);


    fclose (dic);
    return (0) ;
}

