#include <iostream>
#include<iomanip>
#define MAX 10
using namespace std;

int path[MAX];
static int k=0;
int count=0;
int perm[120][7];
int tourcost[120];
void swap(int *x,int *y)
{
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
}
void DFS(int c,int v[MAX],int g[MAX][MAX],int n)
{
        int i;
        v[c]=1;
        path[k++]=c;
        for(i=0;i<n;i++)
        {
                if(g[c][i] && !v[i])
                {
                        DFS(i,v,g,n);
                }
        }
}
void permute(int a[],int i,int n)
{
        int j,k;
        if(i==n)
        {
                for(k=0;k<=n;k++)
                        perm[count][k+1]=a[k];
                count++;
        }
        else
        {
                for(j=i;j<=n;j++)
                {
                        swap((a+i),(a+j));
                        permute(a,i+1,n);
                        swap((a+i),(a+j));
                }
        }
}

int apptsp(int n,int cost[MAX][MAX])
{
        int i,j,u,v,min,excost=0;
        int sum,k,t[MAX][2],p[MAX],d[MAX],s[MAX],tree[MAX][MAX];
        int source,count;
        int visited[MAX]={0};
        min=999;
        source=0;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        if(cost[i][j]!=0&&cost[i][j]<=min)
                        {
                                min=cost[i][j];
                                source=i;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                d[i]=cost[source][i];
                s[i]=0;
                p[i]=source;
        }
        s[source]=1;
        sum=0;
        k=0;
        count=0;
        while(count!=n-1)
        {
                min=999;
                u=-1;
                for(j=0;j<n;j++)
                {
                        if(s[j]==0)
                        {
                                if(d[j]<=min)
                                {
                                        min=d[j];
                                        u=j;
                                }
                        }
                }
                t[k][0]=u;
                t[k][1]=p[u];
                k++;
                count++;
                sum+=cost[u][p[u]];
                s[u]=1;
                for(v=0;v<n;v++)
                {
                        if(s[v]==0&&cost[u][v]<d[v])
                        {
                                d[v]=cost[u][v];
                                p[v]=u;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        tree[i][j]=0;
                }
        }
        if(sum>=999)
                cout<<"\nNo min cost span tree\n";
        else
        {
                for(i=0;i<k;i++)
                {
                        tree[t[i][0]][t[i][1]]=tree[t[i][1]][t[i][0]]=1;
                }
        }
        DFS(0,visited,tree,n);
        cout<<"\n\nApproximate cost tour is"<<endl;
        for(i=0;i<=k;i++)
        {
                cout<<path[i]<<" -> ";
                excost+=cost[path[i]][path[i+1]];
        }
        cout<<path[0];
        excost+=cost[path[i]][path[0]];
        cout<<"\nCost(Approx):"<<excost;
        return excost;
}
int main(void)
{
        int a[MAX][MAX];
	cout<<"Enter a 5X5 matrix:\n";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
        int numofcities=5;
        int intercities=4,i,j;
        int mct=999,mctindex,appmct;
        int city[4]={1,2,3,4};
        permute(city,0,intercities-1);
        for(i=0;i<24;i++)
        {
                for(j=0;j<5;j++)
                {
                        tourcost[i]+=a[perm[i][j]][perm[i][j+1]];
                }
                if(mct>tourcost[i])
                {
                        mct=tourcost[i];
                        mctindex=i;
                }
        }
        cout<<"The exact cost tour is:\n";
        for(i=0;i<numofcities;i++)
                cout<<perm[mctindex][i]<<" -> ";
        cout<<perm[mctindex][i];
        cout<<"\nCost(Exact): "<<mct;
        appmct=apptsp(numofcities,a);
        cout<<"\n\nError: "<<appmct-mct;
        cout<<"\nAccuracy ratio: "<<(float)appmct/mct;
        cout<<"\nApproximate tour is "<<(((float)appmct/mct)-1)*100<<"% longer than optimal tour\n";
        return 0;
}
