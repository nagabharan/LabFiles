#include<stdio.h>
#include<omp.h>
int main()
{
	int tid;
	int n,i;
	int a[100],b[100],c[100];

	printf("Enter the size of the array:\n");
	scanf("%d",&n);

	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("Enter the elements of array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	omp_set_num_threads(8);

	#pragma omp parallel
	{
		tid=omp_get_thread_num();
		#pragma omp for 
		//add and display the results along with thread id

		for(i=0;i<n;i++)
		{
			c[i]=a[i]+b[i];
			printf("\nThread %d:c(%d)=%d",tid,i,c[i]);

		}
	}//end of pragma
}