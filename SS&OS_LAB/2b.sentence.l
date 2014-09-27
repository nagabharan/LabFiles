%{
	#include<stdio.h>
	int f=1;
%}
id [a-zA-Z0-9]
%%
{id}" and "|" or "|" but "|" because "{id}	{f=0;}
.						;
\n						;
%%
main()
{
	printf("Enter a sentence(CTRL+D to exit):");
	yylex();
	if(f==1)
		printf("It is a Simple sentence\n");
	else
		printf("It is a Compound sentence\n");
}
