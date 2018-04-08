

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int pmax;
int rmax;
pthread_t bankers[3][3];
int local[3][3];
int Avail[pmax];
int Max_Resource[3][3]= {{8,8,8},{7,7,7},{10,10,10}};
int Alloc[3][3]={{3,2,1},{1,1,1},{2,2,2}};
int Need[3][3];
int countp=0, countr=0;
int threadp=3, threadm=3;

void * locate_function(void * re);
void * check_function(void * re);

pthread_mutex_t locking;
	


int main()
{
	
	pthread_mutex_init(&locking, NULL);	

	printf("/n Enter the maximum number of Processes:  ");
	scanf("%d\n",&pmax);
	
	printf("/n Enter the maximum number of Resources:  ");
	scanf("%d\n",&rmax);

	int i,j;
	int res1=3, res2=2, res3=2;
	
	else
	{
		printf("\n Mutex Lock Initialized\n");
	}
		pthread_create(&bankers[0][0], NULL, &check_function, (void *)r1);
		pthread_create(&bankers[1][0], NULL, &locate_function, (void *)r2);
		pthread_create(&bankers[2][0], NULL, &locate_function, (void *)r3);

		
		for(i=0;i<threadp;i++)
		{
			for(j=0;j<threadm;j++)
			{
				pthread_join(bankers[0][0], NULL);
				pthread_join(bankers[1][0], NULL);
				pthread_join(bankers[2][0], NULL);
				
			}
		}
}


void * check_function(void * re)
{
	int t_no = (int) re;
	int x,y;
	
	printf("\n Thread Start with number: %d\n", t_no);

	while(countp < pmax && countr < rmax)
	{
		pthread_mutex_lock(&locking);
		Avail[x] = Max[x][y]-Alloc[countp++][countr++];
		printf("\n Availabe is: %d\n",Avail[x]);
		printf("check_function:\n thread : %d,\n Available : %d.\n Signalling done and Received.\n",t_no,Avail[y]);
		countr++;
		printf("check_function:\n thread : %d,\n New Need Now : %d.\n",t_no,Need[countp][countr]);
	}
	
	pthread_mutex_unlock(&locking);
}


void * locate_function(void * re)
{
	int a,b,x,y;
	int t_no = (int) re;
	
	for(i=0;i<pmax;i++)
	{
		for(j=0;j<rmax;j++)
		{
			Need[x][y]=Max[x][y]-Alloc[i][j];
			printf("\n Allocation : %d,\n Need : %d\n",Alloc[i][j],Need[x][y]);
		}
	
		pthread_mutex_lock(&mutex);
    
		if(countp==pmax && countr==rmax)
		{
		       printf("\nlocate_function:\n thread %d,\n Need = %d.\n Limit Reached.\n",t_no,Need[x][y]);
       		}

    		pthread_mutex_unlock(&mutex);
		printf("\n locate_function:\n thread %d,\n nNeed = %d.\n Locking Mutex Unlocked.\n",t_no,Need[x][y]);
    		sleep(5);
    		
		printf("\n Going to Check Function...\n");
		check_function(void * re);
	}

	printf("\n Going to Check Function...\n");
	check_function(void * re);
	
}

