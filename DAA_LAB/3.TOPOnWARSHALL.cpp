#include <iostream>
using namespace std;
int ar[10][10];
int deg[10];
int n;
void TopoOrder();
void war();
int main()
{
    int i,j;
    cout<<"\nenter the no. of vertices";
    cin>>n;
	cout<<"enter the adjacency matrix\n";
	for(i=0;i<n;i++)
    	{
        	for(j=0;j<n;j++)
            	{
            	    cin>>ar[i][j];
            	}

    	}
	TopoOrder();
	war();
    	return 0;
}
void TopoOrder()
{
    	int u,v,t[10],s[10],top=-1,k=0;
    	for(int i=0;i<n;i++)
    	{
    	    int sum=0;
    	    for(int j=0;j<n;j++)
                sum+=ar[j][i];
            deg[i]=sum;
    	}
    for(int i=0;i<n;i++)
    {
        if(deg[i]==0)
            s[++top]=i;
    }
    while(top!=-1)
    {
        u=s[top--];
        t[k++]=u;
        for(v=0;v<n;v++)
        {
            if(ar[u][v]==1)
            {
                deg[v]--;
                if(deg[v]==0)
                    s[++top]=v;
            }
        }
    }
	cout<<"\nTopological Ordering:\n";
	for(int i=0;i<n;i++)
        	cout<<t[i]+1<<" ";
}
void war()
{
	for(int k=0;k<n;k++)
        {
		for(int i=0;i<n;i++)
            	{
			for(int j=0;j<n;j++)
                	{
				if(ar[i][k]==1 && ar[k][j]==1)
                   		{
					ar[i][j]=1;
				}
			}
		}
	}
	cout<<"\nWarshall Ordering:\n";
	for(int i=0;i<n;i++)
        {
		for(int j=0;j<n;j++)
           	{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}
