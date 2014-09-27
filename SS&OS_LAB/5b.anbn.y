%{
	#include<stdio.h>
	int na=0,nb=0,f=1;
%}
%token A B NUM
%%
VAR:	 A 	{na++;}
	|B	{nb++;}
	|VAR A	{na++;}
	|VAR B	{nb++;}
	|NUM	{f=0;}
	|VAR NUM {f=0;}
   ;
%%
main()
{
	yyparse();
	if(na==nb && f==1)
		printf("Valid");
	else
		printf("Invalid");
}
