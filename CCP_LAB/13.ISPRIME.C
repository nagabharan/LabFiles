#include<stdio.h>
#include<conio.h>
int isprime(int );
void main()
{
	int x,res;

	clrscr();

	printf("Enter the number: ");
	scanf("%d",&x);

	res=isprime(x);

	if(res==1)
		printf("The number %d is prime",x);
	else
		printf("The number %d is not prime",x);

	getch();

}
int isprime(int a)
{
	int i;

	for(i=a-1;i>1;i--)
	{
		if(a%i==0)
				return 0;
	}

	return 1;
}