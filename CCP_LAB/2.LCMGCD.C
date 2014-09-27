#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,c,gcd=1,lcm=1,i;

	clrscr();

	printf("WELCOME");

	printf("\nEnter the values for a and b:");
	scanf("%d%d",&a,&b);

	printf("\n\tWhat do you want to do?(1/2):");
	printf("\n\t1-Find GCD");
	printf("\n\t2-Find LCM");
	printf("\n\tYour choice:");
	scanf("%d",&c);

	switch(c)
	{
		case 1: for(i=2;i<=a&&i<=b;i++)
								if(a%i==0&&b%i==0)
										gcd=i;

						printf("GCD of %d and %d is %d",a,b,gcd);

						break;

		case 2: for(i=a;i<=a*b;i++)
								if(i%b==0)
										 lcm=i;
						printf("\n\tLCM of %d and %d is %d",a,b,lcm);

						break;

		default:printf("Invalid Option");
	}

	getch();

}
