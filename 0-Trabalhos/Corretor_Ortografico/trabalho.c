
#include "dicionario.h"

#define TAM_PALAVRA 50

int main ()
{
    setlocale (LC_ALL, "pt_BR.ISO-8859-1") ;

    String *dicionario;
    FILE *dic;
    unsigned long int tamanho_dicionario;
    int contador, c;
    char *palavra;

    dic = fopen("brazilian", "r"); // Abre o dicionario
    if (!dic) // Teste para verificar se o dicionario foi aberto com sucesso
    { 
        perror("Dicionario nao aberto");
        exit(1);
    }

    dicionario = carregaDicionario(dic, &tamanho_dicionario); // Dicionario carregado em RAM

    palavra =  malloc (TAM_PALAVRA*sizeof(unsigned char));
    if (!palavra)
    {
        perror("MALLOC FAILED");
        exit(1);
    }
    
    contador = 0;
    c = getchar();
    while(c != EOF){   
        if (isalpha(c)){
            palavra[contador++] = c;
        } else {
            palavra[contador] = '\0';
            contador = 0;
            if (buscaBinaria(dicionario, palavra,0,tamanho_dicionario)){
                printf("%s", palavra);
            } else {
                printf("[%s]", palavra);
            }
            printf("%c", c);
        }
        c = getchar();
    }

    // Desaloca todo o espaço usado
    for (int i = 0; i  < tamanho_dicionario; i++)
        free(dicionario[i]);
    free(dicionario);

    free(palavra);

    fclose (dic); // Fecha o arquivo
    return (0) ;
}


