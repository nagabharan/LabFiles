#include <iostream>
#include "stdlib.h"

using namespace std;

int x[10];
int place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    }
    return 1;
}
void nq(int k,int n)
{
    int mat[10][10]={0},c=1;
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(int j=1;j<=n;j++)
                {
                    if(x[j]>0)
                        mat[c][x[j]]=1;
                    cout<<x[j];
                    c++;
                }
                cout<<"\nPosition Matrix:\n";
                for(int x=1;x<=n;x++)
                    {
                        for(int y=1;y<=n;y++)
                            cout<<mat[x][y];
                        cout<<"\n";
                    }
                cout<<"\n";
            }
            else
                nq(k+1,n);
        }

    }
}


int main()
{
    int n;
    cout<<"Enter the no. of queens:";
    cin>>n;
    nq(1,n);
    return 0;
}
