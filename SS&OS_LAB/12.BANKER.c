#include<stdio.h>
int main()
{
	int clm[7][5],req[7][5],alloc[7][5],rsrc[5],avail[5],comp[7],work[5],flag[7],safe[7];
	int p,r,i,j,c,t,k,x;
	c=0;

	printf("\n\tEnter the no. of processes:");
	scanf("%d",&p);
	
	for(i=0;i<p;i++)
		comp[i]=0;
	
	printf("\tNo. of resources:");
	scanf("%d",&r);
	
	printf("\n\tClaim:\n");
	for(i=0;i<p;i++)
	{
		printf("\tProcess %d:",i);
		for(j=0;j<r;j++)
			scanf("%d",&clm[i][j]);
	}
	
	printf("\n\tAllocation for each process:\n");
	for(i=0;i<p;i++)
	{
		printf("\tProcess %d:",i);
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	}

	printf("\n\tTotal no. of resources:");
	for(j=0;j<r;j++)
		scanf("%d",&rsrc[j]);
		
	for(j=0;j<r;j++)
	{
		int tot=0;
		avail[j]=0;
		for(i=0;i<p;i++)
			tot+=alloc[i][j];
		avail[j]=rsrc[j]-tot;
	}
	
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			req[i][j]=clm[i][j]-alloc[i][j];

	printf("\n\tAvailable resources:");
	for(j=0;j<r;j++)
	{
		work[j]=avail[j];
		printf("%d ",avail[j]);
	}
	
	printf("\n\n\t:Claim:\t\t\t:Allocation:\t\t:Need:\n\t  ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
			printf("%d",clm[i][j]);
		printf("\t\t\t");
		for(j=0;j<r;j++)
			printf("%d",alloc[i][j]);
		printf("\t\t\t");
		for(j=0;j<r;j++)
			printf("%d",req[i][j]);
		printf("\n\t  ");
	}
	
	k=0;
	x=0;
	do
	{
		k++;
		for(i=0;i<p;i++)
			flag[i]=0;
		for(i=0;i<p;i++)
		{
			if(comp[i]==0)
			{
				for(j=0;j<r;j++)
					if(req[i][j]>work[j])
					{
						flag[i]=1;
						break;
					}
				if(flag[i]==0)
				{
					for(j=0;j<r;j++)
					{
						work[j]=work[j]+alloc[i][j];
						alloc[i][j]=0;
						clm[i][j]=0;
					}
					comp[i]=1;
					++c;
					safe[x]=i;
					printf("\n\tSafe=%d",safe[x]);
					x++;
				}
			}
		}
	}while(c!=p && k<p);
	
	printf("\n\n\tk=%d\tCount=%d\n",k,c);
	if(c==p)
	{
		printf("\n\tSystem is in safe state with sequence:");
		for(j=0;j<p;j++)
			printf("P%d ",safe[j]);
		printf("\n\n");
	}
	else
		printf("\n\tSystem is in unsafe state\n\n");
}
