#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double st,et,elapse1,elapse2;
int ar[5][5];
int main()
{
	int n, i, j, k, adj[5][5];

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i==j)
			{
				ar[i][j]=0;
			}
			else
			{
				ar[i][j]=rand()%100;
			}
			adj[i][j]=ar[i][j];
		}
	}

	printf("\nDoing Normal Floyd:\n\a");
    	for(k=0;k<5;k++)
	{
		st=(double)omp_get_wtime();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				printf("\ni=%d\tj=%d\tk=%d\n",i,j,k);
				ar[i][j] = (ar[i][j] < (ar[i][k] + ar[k][j]))?(ar[i][j]):(ar[i][k] + ar[k][j]);
				printf("\nFloyd[%d][%d]=%d\n",i,j,ar[i][j]);

			}
		}
		et=(double) omp_get_wtime();
	}
        elapse1=et-st;

   	printf("\nInput Graph:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}

	printf("\nAll Pair Shortest Path Matrix\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",ar[i][j]);
		}
		printf("\n");
	}

   	printf("\nDoing Parallel Floyd\n\a");
	omp_set_num_threads(5);
	#pragma omp parallel for private(k) shared(ar,n)
	for(k=0;k<5;k++)
	{
		st=(double)omp_get_wtime();
		//#pragma omp parallel for private(i) shared(ar,n)
		for(i=0;i<5;i++)
		{
			//#pragma omp parallel for private(j) shared(ar,n)
			for(j=0;j<5;j++)
			{
				printf("\ni=%d\tj=%d\tk=%d\n",i,j,k);
				ar[i][j] = (ar[i][j] < (ar[i][k] + ar[k][j]))?(ar[i][j]):(ar[i][k] + ar[k][j]);
				printf("\nFloyd[%d][%d]=%d,thread id=%d\n",i,j,ar[i][j],omp_get_thread_num());

			}
		}
		et=(double) omp_get_wtime();
	}

    elapse2=et-st;
    printf("\nTotal time using normal=%f",elapse1);
    printf("\nTotal time using threads=%f",elapse2);
    printf("\nSpeed up=%f",(elapse2/elapse1));

	printf("\nInput Graph:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}

	printf("\nAll Pair Shortest Path Matrix\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",ar[i][j]);
		}
		printf("\n");
	}

	return 0;
}
