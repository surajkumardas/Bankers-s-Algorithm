
/*
						Banker's Algorithm

This program is based on Linux based Programming. The Program implements Banker's Algorihtm.
Here the request is only accepted if the request results is the safe state after allocation else the request is not granted.
*/

// Header Files

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


// Global Variables

int pmax=10,rmax=10;
int safe_state = 0;
pthread_t bankers[3][3];
int Avail[3];
int Max_Resource[3][3]={{7,5,3},{6,2,2},{9,0,2}};
int Alloc[3][3]={{0,1,0},{2,0,1},{3,0,2}};
int Need[3][3];
int cp=0, cr=0, tp=3, tr=3;

pthread_mutex_t locking;

void * locate_function(void * re);

void * check_function(void * re);


int main()
{
	
	printf("\n \t\t\t\t *************** Banker's Algorithm ****************** \t\t\t\t \n");	

	pthread_mutex_init(&locking, NULL);	

	printf("\n Enter the maximum number of Processes: \n ");
	scanf("%d",&pmax);
	
	printf("\n Enter the maximum number of Resources:  \n");
	scanf("%d",&rmax);

	printf("\nThe Max Resources entered is: \n");	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d",Max_Resource[i][j]);
		}

		printf("\n");	
	}

	printf("\nThe Allocated Resources are: \n");	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%d",Alloc[i][j]);
		}

		printf("\n");	
	}
	

	Avail[rmax];

	int i,j;
	int res1=3, res2=2, res3=2;
	
	
	
		printf("\n Mutex Lock Initialized\n");
	
		pthread_create(&bankers[0][0], NULL, &check_function, (void *)res1);
		pthread_create(&bankers[1][0], NULL, &locate_function, (void *)res2);
		pthread_create(&bankers[2][0], NULL, &locate_function, (void *)res3);

		
		for(i=0; i<tp; i++)
		{
			for(j=0; j<tr; j++)
			{
				pthread_join(bankers[0][0], NULL);
				pthread_join(bankers[1][0], NULL);
				pthread_join(bankers[2][0], NULL);
				
			}
		}
	return 0;
}


void * check_function(void * re)
{
	int t_no = (int) re;
	int x,y;
	
	printf("\n Thread Start with number: %d\n", t_no);

	while(cp<pmax && cr<rmax)
	{
		pthread_mutex_lock(&locking);
		printf("\n Mutex Lock Enabled \n");
		printf("\n Checking Availablity List: \n");
		Avail[x] = Max_Resource[x][y]-Alloc[cp++][cr++];
		printf("\n Availabe is: %d\n",Avail[x]);
		printf("check_function:\n thread : %d,\n Available : %d.\n Signalling done and Received.\n",t_no,Avail[y]);
		cr++;
		printf("check_function:\n thread : %d,\n New Need Now : %d.\n",t_no,Need[cp][cr]);
	}
	
	pthread_mutex_unlock(&locking);
	printf("\n Mutex Lock Released \n");
}


void * locate_function(void * re)
{
	int x,y,i,j;
	int t_no = (int) re;
	
	for(i=0;i<pmax;i++)
	{
		for(j=0;j<rmax;j++)
		{
			printf("\n Calculating Need for Location \n");			
			Need[i][j] = Max_Resource[i][j]-Alloc[i][j];
			printf("\n Allocation : %d,\n Need : %d\n",Alloc[i][j],Need[i][j]);
			
			if(Need[i][j] <= Avail[i])
			{
				pthread_mutex_lock(&locking);	
				printf("\n Mutex Lock Enabled \n");			
				safe_state = 1;
				printf("\n Resource is allocated.\n");
				printf("\n After Resource is Free.The New Avail is : \n");
				Avail[i] = Avail[i]+Alloc[i][j];
				printf("%d\n",Avail[i]);
				pthread_mutex_unlock(&locking);
				printf("\n Mutex Lock Released \n");
			}
			else
			{
				printf("\n Unsafe State.\n Resource can't be allocated.\n");
				safe_state = 0;
				break;
			}
		}
	
		pthread_mutex_lock(&locking);
    
		if(cp==pmax && cr==rmax)
		{
		       printf("\nlocate_function:\n thread %d,\n Need = %d.\n Limit Reached.\n",t_no,Need[i][j]);
       		}

    		pthread_mutex_unlock(&locking);
		printf("\n locate_function:\n thread %d,\n nNeed = %d.\n Locking Mutex Unlocked.\n",t_no,Need[i][j]);
    		sleep(1);
    		
		printf("\n Going to Check Function...\n");
		check_function(re);
	}

	/*printf("\n Going to Check Function...\n");
	check_function(re);*/
	
}

