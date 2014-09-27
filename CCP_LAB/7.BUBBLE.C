#include<stdio.h>
#include<conio.h>
void main()
{
	int i,ar[100],n,temp,j;

	clrscr();

	printf("ENTER array size:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter value");
		scanf("%d",&ar[i]);
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(ar[j]>ar[j+1])
			{
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}

	for(i=0;i<n;i++)
		printf("%d",ar[i]);

		getch();
}