#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define MAX 10
#define MAX_NUM 100


int compar(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv){

	int MAX = atoi(argv[1]);
	int key = atoi(argv[2]);

	srand(time(NULL));

	int v[MAX];

	for (int i = 0; i<MAX; i++)
		v[i] = rand()%MAX_NUM;

	for (int i = 0; i<MAX; i++)
		printf("%d ",v[i]);
	printf("\n");


	qsort(v,MAX,sizeof(int), compar);
	
	for (int i = 0; i<MAX; i++)
		printf("%d ",v[i]);
	printf("\n");
	
	if(bsearch(&key, v, MAX, sizeof(int),compar))
		printf("Achou o nr %d\n", key);
	else
		printf("Nao achou :/ \n");


	return 1;
}
