#include <stdio.h>
#define MAX 100

int main(){

    char frase[MAX];
    int i;

    scanf("%[^\n]", frase);

    i = 0;
    while(frase[i] != '\0'){
        if (frase[i] >= 97 && frase[i] <  122)
            frase[i] -= 32;
        i++;
    }

   printf("%s\n", frase);

    return 0;
}
