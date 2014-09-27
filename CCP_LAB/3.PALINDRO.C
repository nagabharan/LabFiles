#include<stdio.h>
#include<conio.h>
void main()
{
	int org,rev=0,temp,rem;

	clrscr();

	printf("\n\tEnter a four digit number: ");
	scanf("%d",&org);

	temp=org;

	while(org>0)
	{
		rem=org%10;
		org/=10;
		rev=rev*10+rem;
	}

	printf("\n\tThe original number:%d\n\tThe reversed number:%d",temp,rev);

	if(rev==temp)
		printf("\n\tThe number is a palindrome");

	else
		printf("\n\tThe number is not palindrome");

	getch();
}