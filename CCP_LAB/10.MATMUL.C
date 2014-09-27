#include<stdio.h>
#include<conio.h>
void main()
{
	static int a1[10][10],a2[10][10],a3[10][10],i,j,k,s1,s2,s3,s4;

	clrscr();

	printf("\nEnter the size of array1(m,n): ");
	scanf("%d%d",&s1,&s2);

	for(i=0;i<s1;i++)
	{
		for(j=0;j<s2;j++)
		{
			printf("Enter:");
			scanf("%d",&a1[i][j]);
		}
	}
	printf("\nThe matrix:\n");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s2;j++)
		{
			printf("%d ",a1[i][j]);
		}
		printf("\n");
	}


	printf("\nEnter the size of array2(m,n): ");
	scanf("%d%d",&s3,&s4);

	for(i=0;i<s3;i++)
	{
		for(j=0;j<s4;j++)
		{
			printf("Enter:");
			scanf("%d",&a2[i][j]);
		}

	}
	printf("\nThe matrix:\n");
	for(i=0;i<s3;i++)
	{
		for(j=0;j<s4;j++)
		{
			printf("%d ",a2[i][j]);
		}
		printf("\n");
	}

	if(s2==s3)
	{
		for(i=0;i<s1;i++)
		{
			for(j=0;j<s4;j++)
			{
				a3[i][j]=0;
				for(k=0;k<s2;k++)
				{
					a3[i][j]+=a1[i][k]*a2[k][j];
				}
			}
		}
	}
	else
		printf("MATRIX not compatible for multiplication");

	printf("\nProduct:\n");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s4;j++)
			printf("%d ",a3[i][j]);
		printf("\n");
	}


	getch();
}
