#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int **allocated;
int **need;
int **max;
int *resource;
pthread_t *tid;
void * re

int main()
{
	int p_n;
	int r_n;
	printf("Enter number of resources: ");
	scanf("%d", &p_n);
	tid = malloc(p_n * sizeof *tid);
	printf("Enter reources number: ");
	scanf("%d", &r_n);
	resource = malloc(r_n * sizeof *resource);
	for(int i = 0; i < r_n; i++) {
		printf("Enter number of instances of %d reource");
		scanf("%d", &resouce[i]);
	}
	
	return 0;
}
