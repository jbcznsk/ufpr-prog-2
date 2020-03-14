#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


#define MAX_PALAVRAS 10000

typedef char *String;

String *carregaDicionario(FILE *dic, unsigned long int *contador);



int buscaBinaria(String *dic, char *palavra, int inicio, int fim);
