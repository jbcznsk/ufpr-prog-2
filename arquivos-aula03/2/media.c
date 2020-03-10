
#include <stdio.h>
#include <stdlib.h>

int main(){

    float media = 0;
    int counter = 0;
    int line_size = 0;
    size_t size = 100;
    char *linha = malloc(size);
    FILE *arquivo;
    arquivo = fopen("numeros", "r");

    if (!arquivo){
        perror("deu probrema");
        exit(1);
    }

    
    line_size = getline(&linha, &size, arquivo);
    
    while(line_size > 0){
    
        printf("%s", linha);
        media += strtof(linha, NULL);
        counter++;
        line_size = getline(&linha, &size, arquivo); 
    
    }

    printf("Media : %f\n", media/counter);
   
    free(linha);

    fclose(arquivo);

    return 0;
}
