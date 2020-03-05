#include <stdio.h>
#include <string.h>

#define MAX 15

int IsLetter(int n);
int IsNumber(int n);
int IsSpace(int n);

int main(){

    char frase[MAX];
    int i, j;
    int contador = 0, tamanho_original;

    scanf("%[^\n]", frase);
    getchar();

    tamanho_original = strlen(frase)+1;

    for (i = 0; i < strlen(frase); i++){
        if (!IsLetter(frase[i]) && !IsNumber(frase[i]) && !IsSpace(frase[i])){
            if ((tamanho_original + contador*2) < MAX-1){  
                for (j = strlen(frase)+3; j > i; j--)
                    frase[j] = frase[j-2];
            
                frase[i+1] = frase[i];
                frase[i] = '[';
                frase[i+2] = ']';
   
                i+=2;
                contador++;
            }
        }
    }

    puts(frase);

    return 0;
}

int IsLetter(int n){
    if ((n >= 97 && n <= 122) || (n >= 65 && n <= 90))
        return 1;
    return 0;
}

int IsNumber(int n){
    if (n >= 48 && n <= 57)
        return 1;
    return 0;
}

int IsSpace(int n){
    if (n == 32)
        return 1;
    return 0;
}
