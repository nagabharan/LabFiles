#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int insert_heap(int item,int a[], int n)
{
    int c,p;
    if(n==MAX_SIZE)
    {
        printf("Heap FULL!!!\n");
        return n;
    }
    c=n;//initial position
    p=(c-1)/2;//initial position of parent
    while(c!=0 && item>a[p])
    {
        a[c]=a[p];//move parent down to child position
        c=p;//make parent as child
        p=(c-1)/2;//obtain position of new parent
    }
    a[c+1]=item;//insert item at child's position
    return (n+1);
}
void display(int a[], int n)
{
    int i;
    if(n==0)
    {
        printf("Heap EMPTY!!!\n");
        return ;
    }
    printf("Heap Contains:\n");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n");
}
int main()
{
    int a[MAX_SIZE],n=0,choice,item;
    while(1)
    {
        printf("Enter your choice: 1: Insert 2:Display else to exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the Item to be Inserted\n");
                    scanf("%d",&item);
                    n=insert_heap(item,a,n);
                    break;
            case 2: display(a,n);
                    break;

            default: exit(0);
        }
    }
    return 0;
}
