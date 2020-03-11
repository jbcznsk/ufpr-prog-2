// GRR20190372 JORGE LUCAS

#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
    int i;

    char frase[MAX];
    
    scanf("%[^\n]", frase);
    getchar();

    for (i=strlen(frase); i >= 0; i--)
        printf("%c", frase[i]);
    printf("\n");

    return 0;
}
