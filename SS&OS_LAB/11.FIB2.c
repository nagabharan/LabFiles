#include<stdio.h>
#include<omp.h>
int main()
{
	int a[100],i,v,j;
	omp_set_num_threads(2);
	
	printf("\n\tEnter the last term:");
	scanf("%d",&v);
	
	a[0]=0;
	a[1]=1;
	#pragma omp parallel
	{
		#pragma omp single
		for(i=2;;i++)
		{
			a[i]=a[i-2]+a[i-1];
			if(a[i]>v)
				break;
			printf("\n\tId of thread:%d Number generated:%d",omp_get_thread_num(),a[i]);
		}
		#pragma omp barrier
		#pragma omp single
		{
			printf("\n\n\tFibonacci series generated:\n");
			for(j=0;j<i;j++)
			{
				printf("\tNo:%d Thread:%d Value:%d\n",j+1,omp_get_thread_num(),a[j]);
			}
		}
	}	
	printf("\n");
}
