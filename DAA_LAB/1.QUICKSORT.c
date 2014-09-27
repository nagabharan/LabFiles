#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int quick_sort(int a[100],int l,int r);
int partition(int a[100],int l,int r);

int quick_sort(int a[100],int l,int r)
{

    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quick_sort(a,l,s-1);
        quick_sort(a,s+1,r);
    }
}

int partition(int a[100],int l,int r)
{
    int i,j,p,temp;
    p=a[l];
    i=l+1;
    j=r;
    while(i<=j)
    {
        while(a[i]<=p)
        {
            i++;
        }
        while(a[j]>p)
        {
            j--;
        }
        if(i<j)
        {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        }
    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}

int main()
{
    int a[1000000],i;
    struct timeval tv;
    double start,end,elapse_time;
    FILE *f;
    f=fopen("quick.txt","w");
    for(i=0;i<500000;i=i+1000)
    {
        generate(a,i);
        gettimeofday(&tv,NULL);
        start=tv.tv_sec+(tv.tv_usec/1000000.0);

        quick_sort(a,0,i-1);

        gettimeofday(&tv,NULL);
        end=tv.tv_sec+(tv.tv_usec/1000000.0);

        elapse_time=(end-start);
        fprintf(f,"%i\t%f\n",i,elapse_time);
    }

    fclose(f);
    return 0;

}

int generate(int a[],int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=rand()%10000;
    }
}

