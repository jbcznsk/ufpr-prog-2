#include <stdio.h>
#define NRFRASES 5
#define MAX 100


int main(){
    
    char frases[NRFRASES][MAX];
    int i, j;

    for (i = 0; i < NRFRASES; i++){
        scanf("%[^\n]", frases[i]);
        getchar();
    }

    for (i = 0; i < NRFRASES; i++){
        for (j = 0; j < NRFRASES; j++){
            if  
        }
    }

    for (i = 0; i < NRFRASES; i++){
        printf("%s\n", frases[i]);
    }
    return 0;
}
