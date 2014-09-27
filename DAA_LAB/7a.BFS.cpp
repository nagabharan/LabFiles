#include <iostream>

using namespace std;

class bfs
{
    int v[10],g[5][5],n,f,r,q[10];
    public:
            bfs();
            ~bfs();
            void getd();
            void calc(int);
            void enq(int);
            int deq();
};
bfs::bfs()
{
    f=0;
    r=0;
    cout<<"Enter the no of vertices:";
    cin>>n;
}
bfs::~bfs()
{
    cout<<"\nThank you";
}
void bfs::getd()
{
    cout<<"\nEnter the co-ordinates:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];

    for(int i=0;i<n;i++)
        v[i]=0;

}
void bfs::calc(int s)
{
    int frnt;
    v[s]=1;
    enq(s);
    while(f<r)
    {
        frnt=deq();
        for(int i=0;i<n;i++)
        {
            if(g[frnt][i] && !v[i])
            {
                v[i]=1;
                enq(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
            if(v[i])
                cout<<i<<" is reachable from "<<s;
            else
                cout<<i<<" is not reachable from "<<s;
            cout<<"\n";
        }
    }
}
void bfs::enq(int a)
{
    if(r==n)
        r=r%n;
    q[r++]=a;
}
int bfs::deq()
{
    if(f==r)
        f=f%n;
    return q[f++];
}
int main()
{
    bfs a;
    int i;
    a.getd();
    cout<<"\nEnter the source:";
    cin>>i;
    a.calc(i);
}
