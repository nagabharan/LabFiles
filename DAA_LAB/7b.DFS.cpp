#include <iostream>
#include <stdlib.h>

using namespace std;

void DFS(int s,int v[],int g[][5],int n);

int main()
{
    int n,v[10],g[5][5],s;

    cout<<"Enter the number of vertices:";
    cin>>n;

    cout<<"\nEnter the graph co-ordinates:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    cout<<"\nThe Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<g[i][j]<<" ";
        cout<<"\n";
    }

    for(int i=0;i<n;i++)
        v[i]=0;

    cout<<"\nEnter the source:";
    cin>>s;


    DFS(s,v,g,n);

    for(int i=0;i<n;i++)
        if(v[i]==0)
        {
            cout<<"\nGraph is not connected";
            exit(0);
        }

    cout<<"\nGraph is connected";

}
void DFS(int s,int v[],int g[][5],int n)
{
    v[s]=1;
    for(int i=0;i<n;i++)
        if(g[s][i] && !v[i])
            DFS(i,v,g,n);
}
