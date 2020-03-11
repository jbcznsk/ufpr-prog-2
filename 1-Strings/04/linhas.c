#include <stdio.h>
#include <string.h>

#define NRFRASES 5
#define MAX 100

int main(){
    
    char frases[NRFRASES][MAX], temp[MAX];
    int menorTamanho;
    int i, j, k, l;

    // Recebe as frases
    for (i = 0; i < NRFRASES; i++){
        scanf("%[^\n]", frases[i]);
        getchar();
    }

    for (i = 0; i < NRFRASES; i++){
        for (j = 0; j < NRFRASES-1; j++){
            printf("Comparando %s com %s\n", frases[j], frases[j+1]);
            
            // Descobre a menor das palavras
            if (strlen(frases[j]) < strlen(frases[j+1]))
                menorTamanho = strlen(frases[j]);
            else
                menorTamanho = strlen(frases[j+1]);
            
            // Para funcionar com casos de palavras que tem varias letras iguais
            for (l = 0; l < menorTamanho; l++){
                if(frases[j][l] > frases[j+1][l]){ // Caso seja menor, troca e para
                    printf("Trocou %c // %c \n", frases[j][0], frases[j+1][0]);
                    strcpy(temp, frases[j]);
                    strcpy(frases[j], frases[j+1]);
                    strcpy(frases[j+1], temp);
                    break;
                }  else if (frases[j][l] < frases[j+1][l]){
                    break; // Caso seja maior, apenas para
                }
                // Continua para a proxima letra
            }
        }
    }

    for (i = 0; i < NRFRASES; i++)
        printf("%s\n", frases[i]);
    
    return 0;
}
