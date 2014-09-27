/*wap to calculate the approx value of e^0.5 using the talyor series expansion
for the exponential function use the term in the expansion until the last term
is less than the machine epsilon defined as FLT_epsilon in the header file
float.h, print the value returned by the mathematical fn exp() also.*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<float.h>

void main()
{
	float x=0.5,n=1,sum=1,count=1,term=1;

	clrscr();

	while(n<=100)
	{
		term*=(x/n);
		sum+=term;
		count++;

		if(term<FLT_EPSILON)
			n=999;
		else
			n++;
	}

	printf("\n\t\tTS=%f",sum);
	printf("\n\t\tResult of exp()=%f",exp(0.5));
	printf("\n\t\tNo. of terms=%f",count);

	getch();
}


