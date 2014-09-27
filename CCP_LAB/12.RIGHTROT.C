#include<stdio.h>
#include<math.h>
#include<conio.h>
int rightrot(int ,int );
void main()
{
	int x,n,res;

	clrscr();

	printf("Enter the value of x & n: ");
	scanf("%d%d",&x,&n);

	res=rightrot(x,n);

	printf("The new value of x(%d) after right shifting by n(%d) is %d",x,n,res);

	getch();

}
int rightrot(int x,int n)
{
	int r;

	r=x/pow(2,n);

	return r;
}

