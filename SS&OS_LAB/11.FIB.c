#include<stdio.h>
#include<omp.h>
int main()
{
	int a[100],i,n;
	omp_set_num_threads(2);
	
	printf("\n\tEnter the no. of terms:");
	scanf("%d",&n);
	
	a[0]=0;
	a[1]=1;
	#pragma omp parallel
	{
		#pragma omp single
		for(i=2;i<n;i++)
		{
			a[i]=a[i-2]+a[i-1];
			printf("\n\tId of thread:%d Number generated:%d",omp_get_thread_num(),a[i]);
		}
		#pragma omp barrier
		#pragma omp single
		{
			printf("\n\n\tFibonacci series generated:\n");
			for(i=0;i<n;i++)
			{
				printf("\tNo:%d Thread:%d Value:%d\n",i+1,omp_get_thread_num(),a[i]);
			}
		}
	}	
	printf("\n");
}
