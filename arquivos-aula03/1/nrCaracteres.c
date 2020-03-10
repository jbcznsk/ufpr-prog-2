#include <stdio.h>

int main(){

    int tamanho = 0;

    FILE *arquivo;
    arquivo = fopen("texto.txt", "w"); // Abre o arquivo como escrita

    fprintf(arquivo, "jorge lucas\n"); // Enche o arquivo

    arquivo = freopen("texto.txt", "r", arquivo); // Reabre o arquivo como leitura

    while(fgetc(arquivo) != EOF){
        printf("%d \n", tamanho);
        tamanho++;
    }

    printf("tamanho = %d", tamanho);
    
    fclose(arquivo);
    return 0;
}
