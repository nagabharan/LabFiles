#include<iostream>
using namespace std;

void kruskal(int cost[10][10], int n)
{
	int p[10],i,j,a,b,u,v,min,count=1,sum=0;
	for(i=1;i<=n;i++)
	{
	    p[i]=0;
	}
	while(count!=n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
		    for(j=1;j<=n;j++)
			{
			    if(cost[i][j]<min)
				{
					min=cost[i][j];
					u=a=i;
					v=b=j;
				}
			}
		}
		while(p[u]!=0)
			u=p[u];
		while(p[v]!=0)
			v=p[v];
		if(u!=v)
		{
			count++;
			sum=sum+cost[a][b];
			cout<<"\nEdge: "<<a<<","<<b<<" Cost = "<<cost[a][b];
			p[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"\nCost:"<<sum<<endl;
}

int main()
{
	int cost[10][10],i,j,n;
	cout<<"No. of vertices:\n";
	cin>>n;
	cout<<"Cost matrix\n";
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
		{
		    cin>>cost[i][j];
		}
	}
	kruskal(cost,n);
	return 0;
}
