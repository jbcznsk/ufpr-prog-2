#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

	size_t line_buffer = 200;
	char *line = (char*) malloc (line_buffer*sizeof(char));
	int line_size = 0;
	FILE *arquivo;

	if (argc != 2){
		printf("Faltam argumentos\n");
		exit(1);
	}

	arquivo = fopen("texto.txt", "r");
	if (!arquivo){
		perror("Arquivo Inexistente");
		exit(1);
	}	


	line_size = getline(&line, &line_buffer, arquivo);

	while(line_size > 0){
	
		if (strstr(line, argv[1])){
			printf("%s", line);
		}

		line_size = getline(&line, &line_buffer, arquivo);
	}
	
	free(line);
	fclose(arquivo);

	return 0;
}
