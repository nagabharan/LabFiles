#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
	float r1,r2,p1,p2,a,b,c,disc;

	clrscr();

	printf("\n\n\tEnter the coefficients: ");
	scanf("%f%f%f",&a,&b,&c);

	if(a==0)
	{
		printf("\n\tThe co-efficients are zero(Re-enter):");
		scanf("%f%f%f",&a,&b,&c);
	}

	disc=b*b-4*a*c;

	if(disc>0)
	{
		r1=(-b+sqrt(disc))/(2*a);
		r2=(-b-sqrt(disc))/(2*a);

		printf("\n\tThe roots are distinct\n\tr1=%f\n\tr2=%f\n",r1,r2);
	}

	else if(disc==0)
	{
		r1=r2=-b/(2*a);

		printf("\n\tThe roots are equal\n\tr1=%f\n\tr2=%f",r1,r2);
	}

	else
	{
		p1=-b/(2*a);
		p2=(sqrt(fabs(disc)))/(2*a);
		printf("\n\tThe roots of the quadratic equation are imaginary");
		printf("\n\tRoot 1=%f+i%f\n\tRoot 2=%f-i%f",p1,p2,p1,p2);

	}

	getch();
}

