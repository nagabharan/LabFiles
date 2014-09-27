#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r,c,v;
}spmtx;

spmtx sp[20];

int main()
{
    int ar[10][10],i,j,m,n,k=1,key;

    printf("Enter the size of the matrix(m,n):");
    scanf("%d%d",&m,&n);

    printf("Enter the elements of the matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&ar[i][j]);

    printf("The Matrix entered is:\n");
    for(i=0;i<m;i++)
    {
            for(j=0;j<n;j++)
                printf("%d\t",ar[i][j]);
            printf("\n");
    }

    printf("Determining Sparse Matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(ar[i][j]!=0)
            {
                sp[k].r=i;
                sp[k].c=j;
                sp[k].v=ar[i][j];
                k++;
            }
    sp[0].r=i;
    sp[0].c=j;
    sp[0].v=k-1;

    for(i=0;i<=sp[0].v;i++)
        printf("sp[%d] is %d  %d  %d\n",i,sp[i].r,sp[i].c,sp[i].v);

    printf("\nEnter the element to be search:\n");
    scanf("%d",&key);

    for(i=1;i<=sp[0].v;i++)
        if(sp[i].v==key)
        {
            printf("The element is found in row %d and column %d",sp[i].r,sp[i].c);
            exit(0);
        }


    printf("The element is not found!");

    return 0;
}
