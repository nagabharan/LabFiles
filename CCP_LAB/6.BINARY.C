#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	clrscr();

	int i,j,f,l,m,x,n,temp,ar[100];

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


	f=ar[0];
	l=ar[n-1];

	printf("ENTER ELEMENT TO BE SEARCHED");
	scanf("%d",&x);

	while(f<=l)
	{
		m=(f+l)/2;
		if(m==x)
		{
			printf("Success!");
			getch();
			exit(0);
		}
		else if(m>x)
			l=m-1;
		else if(m<x)
			f=m+1;
 .	}
	printf("FAILURE");

	getch();
}