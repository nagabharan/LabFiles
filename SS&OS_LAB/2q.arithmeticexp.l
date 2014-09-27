%{
	#include<stdio.h>
	int a[]={0,0,0,0},i,f=1,op=0;
%}
%x oper
%%
[a-z0-9A-Z]+		{BEGIN oper;op++;}
<oper>"+"		{if(f){f=0;i=0;}else ext();}
<oper>"-"		{if(f){f=0;i=1;}else ext();}
<oper>"*"		{if(f){f=0;i=2;}else ext();}
<oper>"/"		{if(f){f=0;i=3;}else ext();}
<oper>[a-zA-Z0-9]+	{op++;if(f==0){f=1;a[i]++;}else ext();}
<oper>\n		{if(f==0)ext();else return 0;}
.			{ext();}
\n			{ext();}
[a-zA-Z0-9]*"="[a-zA-Z0-9]*	{ext();}
%%
ext()
{
	printf("Invalid expression\n");
	exit(0);
}
main()
{	
	printf("Enter an expression:");
	yylex();
	printf("\nValid expression\n");	
	printf("The no. of +s = %d\nThe no. of -s = %d\nThe no. of *s = %d\nThe no. of /s = %d\nThe no. of operands = %d\n",a[0],a[1],a[2],a[3],op);
}
