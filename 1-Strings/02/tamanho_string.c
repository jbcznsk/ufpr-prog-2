#include <stdio.h>
#define MAX 100

int main(){

    char frase[MAX];
    int tamanho = 0, i;

    scanf("%[^\n]", frase);

    i = 0;
    while(frase[i] != '\0'){
        tamanho++;
        i++;
    }

   printf("Tamanho : %d\n", tamanho);

    return 0;
}
