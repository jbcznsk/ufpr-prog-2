#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){

    char frase[MAX];
    int i, j;

    scanf("%[^\n]", frase);
    getchar();


    for (i = 0; i < strlen(frase); i++){
        if (frase[i] == frase[i+1]){
            for (j = i; j < strlen(frase); j++){
                frase[j] = frase[j+1];
            }
            i--;
        }
    }

    puts(frase);

    return 0;
}