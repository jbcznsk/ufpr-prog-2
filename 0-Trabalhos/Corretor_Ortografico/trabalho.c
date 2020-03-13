
#include "dicionario.h"

#define TAM_PALAVRA 50

int buscaBinaria(String *dic, char *palavra);

int main ()
{

    setlocale (LC_CTYPE, "pt_BR.ISO-8859-15") ;

    String *dicionario;
    FILE *dic;
    unsigned long int tamanho_dicionario;
    int contador;
    char *palavra;
    int c;

    dic = fopen("brazilian", "r"); // Abre o dicionario
  
    if (!dic) // Teste para verificar se o dicionario foi aberto com sucesso
    { 
        perror("Dicionario nao aberto");
        exit(1);
    }

    dicionario = carregaDicionario(dic, &tamanho_dicionario); // Dicionario carregado em RAM

    // Carregar TEXTO
    // Procurar as palavras (transformar em minuscula antes)
    // -- Ler letra por letra ou por fscanf??
    

    printf("tamanho : %ld\n", tamanho_dicionario);

    palavra =  malloc (TAM_PALAVRA*sizeof(unsigned char));
    if (!palavra)
    {
        perror("MALLOC FAILED");
        exit(1);
    }
    
    contador = 0;
    c = getchar();
    while(c != EOF){
        
        if (!isalpha(c) && c != ' ')
        {
            putchar(c);
        } else {
            if (!(c = ' '))
            {
                palavra[contador++] = c;
            } else {
                palavra[contador] = '\0';
                contador = 0;
            }
        }
        
        c = getc(stdin);
    }

   // for (unsigned long int i = 0; i < 275502; i++)
   //     printf("%s ", dicionario[i]);
    
    // Desaloca todo o espaço usado
    for (int i = 0; i  < tamanho_dicionario; i++)
        free(dicionario[i]);
    free(dicionario);

    fclose (dic); // Fecha o arquivo
    return (0) ;
}


