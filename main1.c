

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int pmax;
int rmax;
int prores[3][3];
int local[3][3];
int Avail[pmax];
int MaxR[3][3]= {{8,8,8},{7,7,7},{10,10,10}};
int Alloc[3][3]={{3,2,1},{1,1,1},{2,2,2}};
int Need[3][3];
int countp=0, countr=0;
int threadp=3, threadm=3;

void * count_add(void * re);
void * count_stay(void * re);

pthread_mutex_t locking;
	


int main()
{
	printf("/n Enter the maximum number of Processes:  ");
	scanf("%d\n",&pmax);
	
	printf("/n Enter the maximum number of Resources:  ");
	scanf("%d\n",&rmax);

	pthread_t prores[3][3];
	int i,j;
	int res1=3, res2=2, res3=2;
	
	if(pthread_mutex_init(&locking, NULL) < 0)
	{
		printf("\nError Occured.\n");
		exit(0);
	}
	else
	{
		printf("\n Mutex Lock Initialized\n");
	}
		pthread_create(&prores[0][0], NULL, &count_stay, (void *)r1);
		pthread_create(&prores[1][0], NULL, &count_add, (void *)r2);
		pthread_create(&prores[2][0], NULL, &count_add, (void *)r3);

		
		for(i=0; i<thread1; i++)
		{
			for(j=0; j<thread2; j++)
			{
				pthread_join(prores[0][0], NULL);
				pthread_join(prores[1][0], NULL);
				pthread_join(prores[2][0], NULL);
				
			}
		}
}


void * count_stay(void * re)
{
	int t_no = (int) re;
	int x,y;
	
	printf("\n Thread Start with number: %d\n", t_no);

	while(countp < pmax && countr < rmax)
	{
		pthread_mutex_lock(&locking);
		Avail[x] = Max[x][y]-Alloc[countp++][countr++];
	}
	
}


void * count_add(void * re)
{
	
}

