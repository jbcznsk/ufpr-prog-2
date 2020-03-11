#include <stdio.h>
#include <string.h>

#define MAX 100

int testaPalindromo(char *frase);

int main(){

    char frase[MAX];

    scanf("%[^\n]", frase);

    puts(frase);

    printf("%d\n", testaPalindromo(frase));


    return 0;
}

int testaPalindromo(char *frase){

    for (int i = 0; i < strlen(frase); i++){
        printf("comparando %c com %c\n",frase[i] , frase[strlen(frase)-i-1] );
        if (frase[i] != frase[strlen(frase)-i-1])
            return 0;
    }
    return 1;
}