#include <stdio.h>
#include <string.h>

#define MAX 10000
#define LOOPS 1000000

int main(){

    for (int i = 0; i < LOOPS; i++){
        char s1[MAX] = "JORGE LUCAS";
        char s2[MAX] = "VICILLI JABCZENSKI";

        int tam1, tam2;

        tam1 = strlen(s1);
        tam2 = strlen(s2);

        strcat(s1, s2);
        tam1 = strlen(s1);
        tam2 = strlen(s2);

        strcpy(s2, s1);
        tam1 = strlen(s1);
        tam2 = strlen(s2);

        tam1 += tam2;
    }

    return 0;
}
