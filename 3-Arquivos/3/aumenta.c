#include <stdio.h>

int main(){

    FILE *arquivo1, *arquivo2;
    arquivo1 = fopen("minusc.txt", "r");
    arquivo2 = fopen("maiusc.txt", "w");
    
    char c;

    c = fgetc(arquivo1);
    
    while(c != EOF){
    
        if (c != 32 && c != '\n')
            fputc(c-32, arquivo2);
        else 
            fputc(c, arquivo2);
        c = fgetc(arquivo1);
    
    }

    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}
