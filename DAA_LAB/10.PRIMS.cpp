#include <iostream>

using namespace std;

void prims(int [][10],int [][10],int ,int [][10]);

int main()
{
    int n;

    cout<<"Enter the number of vertices:";
    cin>>n;

    int ar[10][10],cost[10][10],t[10][10]={0};

    cout<<"Enter the adjacency matrix:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>ar[i][j];

    cout<<"Enter the cost matrix:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];

    prims(ar,cost,n,t);

    return 0;

}

void prims(int ar[][10],int cost[][10],int n,int t[][10])
{
    int u=0,v=0,min=cost[0][0],near[10];

    for(int i=0;i<n;i++)
    {
        near[i]=0;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    u=i;v=j;
                    min=cost[i][j];
                }
            }

    t[1][1]=u;
    t[1][2]=v;
    for(int i=0;i<n;i++)
    {
        if(cost[i][v]<cost[i][u])
            near[i]=v;
        else
            near[i]=u;
    }
    near[u]=near[v]=0;
    int j=0;
    for(int i=1;i<n;i++)
    {
        while((near[j]) && cost[j][near[j]]<min)
        {
            t[i][1]=j;
            t[i][2]=near[j];
            j++;
        }
        min+=cost[j][near[j]];
        near[j]=0;
        for(int k=1;k<n;k++)
        {
            if((near[k]) && cost[k][near[k]]>cost[k][j])
                near[k]=j;
        }
    }
    cout<<min;
}
