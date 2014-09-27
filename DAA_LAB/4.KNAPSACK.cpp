#include <iostream>
#define MAX 30
using namespace std;


int values[MAX],weights[MAX],v[MAX][MAX],x[MAX],n,m;

int max(int a, int b)
{
    return (a>b)?a:b;
}
int MFKS(int i,int j)
{
    int val;
    if (v[i][j] == -1)
    {
        if (j<weights[i])
        {
            val = MFKS(i-1,j);
            v[i][j] = val;
        }
			else
				val = max(MFKS(i-1,j),MFKS(i-1,j - weights[i]) + values[i]);\
				v[i][j] = val;
		}
		return v[i][j];
	}
	void svector()
	{
		int i,j = m;
		for (i = n;i>=0;i--)
			if (v[i][j]!=v[i-1][j])
			{
				x[i] = 1;
				j = j - weights[i];
			}
		cout<<"{";
		for (j=1;j<=n;j++)
			cout<<x[j]<<"\t";
		cout<<"}\n";
	}

	int main()
	{
		int optsol;
		cout<<"Enter the Number of items\n";
		cin>>n;
		cout<<"Enter the Weights\n";
		for(int i=1;i<=n;i++)
			cin>>weights[i];
		cout<<"Enter the Values\n";
		for(int i=1;i<=n;i++)
			cin>>values[i];
		cout<<"Enter the Knapsack Capacity\n";
		cin>>m;
		for(int i=0;i<=m;i++)
			v[0][i] = 0;
		for(int i=0;i<=n;i++)
			v[i][0] = 0;
		for(int i=1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				v[i][j] = -1;
		optsol = MFKS(n,m);
		cout<<"Optimal Solution is "<<optsol<<endl;
		cout<<"The Optimal Solution Vector is\n";
		for (int i=1;i<=n;i++)
			x[i] = 0;
		svector();
	}

