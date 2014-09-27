#include<omp.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int a[200];
	int n,i,k;
	printf("Enter the value of n");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		a[i]=i;//fill numbers(1-100) in thr array a and call it as sieve of eratoshenes
	}
	#pragma omp parallel
	{
		for(k=2;k<=sqrt(n);k++)
		{
			if (a[k]!=0)
			{
				#pragma omp for
				for(i=k*k;i<=n;i=i+k) //eliminate multiples of k
				{
					a[i]=0;
				} //end of for i
			}//end of if
		}end of for k
	}//end of pragma
	printf("Prime numbers are\n");
	for(i=2;i<=n;i++)
	{
		if(a[i]>0)printf("%d\t",a[i]);
	}
}//end of main