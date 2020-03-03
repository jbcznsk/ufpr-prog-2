#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){

    char frase[MAX];
    int i, j;

    scanf("%[^\n]", frase);
    getchar();

    for (i = 0; i < strlen(frase); i++){
        if (frase[i] != 32 && (frase[i] < 65 || (frase[i] > 90 && frase[i] < 97) || frase[i] > 122)){
            printf("retirando o caractece %c \n", frase[i]);
            for (j = i; j < strlen(frase); j++){
                frase[j] = frase[j+1];
            }
            i--; // Retorna um caractere para checar ele de novo
        }
    }

    puts(frase);

    return 0;
}