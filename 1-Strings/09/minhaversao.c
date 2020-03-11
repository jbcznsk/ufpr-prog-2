#include <stdio.h>

#define MAX 10000
#define LOOPS 1000000

int strlen_2(char *s);
int strcpy_2(char *dest, char *src);
int strcat_2(char *dest, char *src);

int main(){

    for (int i = 0; i < LOOPS; i++){

        char s1[MAX] = "JORGE LUCAS";
        char s2[MAX] = "VICILLI JABCZENSKI";

        int tam1, tam2;

        tam1 = strlen_2(s1);
        tam2 = strlen_2(s2);

        strcat_2(s1, s2);
        tam1 = strlen_2(s1);
        tam2 = strlen_2(s2);

        strcpy_2(s2, s1);
        tam1 = strlen_2(s1);
        tam2 = strlen_2(s2);

        tam1 += tam2;
    }

    return 0;
}

int strlen_2(char *s){
    int count = 0;

    while(s[count] != '\0')
        count++;
    
    return count;
}

int strcpy_2(char *dest, char *src){

    for (int i = 0; i < strlen_2(src) + 1; i++)
        dest[i] = src[i];

    return 0;
}

int strcat_2(char *dest, char *src){
    int size_dest = strlen_2(dest);

    for (int i = 0; i < strlen_2(src) + 1; i++)
        dest[size_dest + i] = src[i];

    return 0;
}