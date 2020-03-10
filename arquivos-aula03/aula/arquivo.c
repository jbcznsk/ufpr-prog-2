#include <stdio.h>

int main(){
    
    FILE *dicionario;
    dicionario = fopen("brazilian", "r");

    if (!dicionario){
        printf("ERROU\n");
        perror("erro ao abrir o arquivo");
        return 1;
    } else {
        printf("carregado\n");
    }
    char *jorge;

    fscanf(dicionario, jorge);
    puts(jorge);
    fclose (dicionario);

    return 0;
}
