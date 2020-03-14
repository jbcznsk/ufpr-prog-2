
#include "dicionario.h"

#define TAM_PALAVRA 50

int cmpstringp(const void *p1, const void *p2);

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
	
	//for(int i = 0; i < tamanho_dicionario; i++)
	//	dicionario[i][0] = tolower(dicionario[i][0]);

	qsort(dicionario, tamanho_dicionario, sizeof(char*), cmpstringp);


	//for(int i = 0; i < tamanho_dicionario; i++)
	//	printf("%s\n", dicionario[i]);

    palavra =  malloc (TAM_PALAVRA*sizeof(unsigned char));
    if (!palavra)
    {
        perror("MALLOC FAILED");
        exit(1);
    }
    
    contador = 0;
    c = getchar();
    while(c != -1){   
        while(!isalpha(c) && c != EOF){
            printf("%c", c);
			c = getchar();
  		}
       	while(isalpha(c) && c != EOF){
			palavra[contador++] = c;
			c = getchar();
		}
        palavra[contador] = '\0';
        contador = 0;
		if (strcmp(palavra, "")){
        	if (buscaBinaria(dicionario, palavra, 0, tamanho_dicionario))
				printf("%s", palavra);
			else
				printf("[%s]", palavra);
		}
    }

    // Desaloca todo o espaço usado
    for (int i = 0; i  < tamanho_dicionario; i++)
        free(dicionario[i]);
    free(dicionario);

    free(palavra);

    fclose (dic); // Fecha o arquivo
    return (0) ;
}



int cmpstringp(const void *p1,const void *p2) {
	return strcasecmp(* (char * const *) p1, * (char * const *) p2);       
}
