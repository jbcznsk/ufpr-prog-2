#include <stdio.h>
#include <string.h>
#define NRFRASES 5
#define MAX 100


int main(){
    
    char frases[NRFRASES][MAX];
    char temp[MAX];
    int i, j;

    for (i = 0; i < NRFRASES; i++){
        scanf("%[^\n]", frases[i]);
        getchar();
    }

    for (i = 0; i < NRFRASES; i++){
        for (j = 0; j < NRFRASES; j++){
            if(frases[i][0] > frases[j][0]){
                strcpy(temp, frases[i]);
                strcpy(frases[i], frases[j]);
                strcpy(frases[j], temp);
            
            }  
        }
    }

    for (i = 0; i < NRFRASES; i++){
        printf("%s\n", frases[i]);
    }
    return 0;
}
