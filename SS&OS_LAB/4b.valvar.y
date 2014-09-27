%{
	#include<stdio.h>
	int f=1;
%}
%token	ALPHA DIGIT
%%
VAR:ALPHA|VAR ALPHA|VAR DIGIT ;
%%
yyerror()
{
	f=0;
}
main()
{
	printf("Enter a variable:\n");
	yyparse();
	if(f)
		printf("\nValid variable name");
	else
		printf("\nInvalid variable name");
}
