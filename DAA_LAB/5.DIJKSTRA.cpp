#include <iostream>
using namespace std;

void dijkstra(int src,int cost[][10],int n)
{
    int v[10],p[10],d[10],min,i,u,c=0;
    for(i=0;i<n;i++)
    {
        v[i]=0;
        d[i]=cost[src][i];
        p[i]=src;
    }
    d[src]=0;
    v[src]=1;
    c++;
    while(c!=n)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(d[i]<min && !v[i])
            {
                min=d[i];
                u=i;
            }
        }

        v[u]=1;
        c++;
        for(i=0;i<n;i++)
        {
            if(min+cost[u][i]<d[i] && !v[i])
            {
                d[i]=min+cost[u][i];
                p[i]=u;
            }
        }
    }
    cout<<"\n";
    cout<<"Shortest distance wrt "<<src<<":";
    for(i=0;i<n;i++)
    {
        cout<<src<<"->"<<i<<"="<<d[i]<<"\n";
    }
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        cout<<i<<" ";
    }    
    for(i=0;i<n;i++)
    {
        cout<<p[i]<<"->";
    }

}

int main()
{
    int c[10][10],n,i,j,src,dest;

    cout<<"Enter the number of vertices:";
    cin>>n;

    cout<<"Enter cost matrix:\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cin>>c[i][j];
        }

    cout<<"Enter the source:";
    cin>>src;
	
    for(i=0;i<n;i++)
	    dijkstra(i,c,n);

    return 0;
}
