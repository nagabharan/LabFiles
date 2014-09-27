%{
	#include<stdio.h>
	int f=1;
%}
%token	NUM ID
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
exp: exp '+' exp
    |exp '-' exp
    |exp '*' exp
    |exp '/' exp
    |'('exp')'
    |NUM
    |ID
    ;
%%
yyerror(char *s)
{
	f=0;
	printf("\n%s is an invalid arithmetic expression\n",s);
}
main()
{
	printf("\nEnter expression:");
	yyparse();
	if(f)
		printf("\nValid arithmetic expression\n");
}
