#include <stdio.h>
#include <string.h>

#define MAX 100

int busca(char *agulha, char *palheiro);

int main(){

    char string1[MAX], string2[MAX];
    int resultado;

    printf("Entrada: ");
    scanf("%[^\n]", string1);
    getchar();
    printf("Procurar: ");
    scanf("%[^\n]", string2);
    getchar();

    resultado = busca(string2, string1);

    printf("Resultado: %d \n", resultado);

    return 0;
}

int busca(char *agulha, char *palheiro){

    int tamanho, contador;
    int i, j;

    tamanho = strlen(palheiro) - strlen(agulha);

    if (agulha[0] == '\0' || palheiro[0] == '\0'){
        return -2;
    } else if (tamanho < 0){
        return -1;
    } else {
        for (i = 0; i < tamanho+1; i++){
            contador = 0;
            for (j = 0; j < strlen(agulha); j++){
                if (agulha[j] != palheiro[i+j]){
                    break;
                }
                contador++;
            }
            if (contador == strlen(agulha))
                return i;
        }
    }
    return -1;
}