%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token NUM NAME
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '(' ')'
%%
expr: exp { printf("=%d\n",$1);}
exp: exp '+' exp	{$$ = $1 + $3;}
    |exp '-' exp	{$$=$1-$3;}
    |exp '*' exp	{$$=$1*$3;}
    |exp '/' exp	
	{if($3==0){
		yyerror("Divide by zero");exit(0);}
	 else
		$$=$1/$3;
	}
    |'-'exp %prec UMINUS {$$=-$2;}
    |'('exp')'		{$$=$2;}
    |NUM		{$$=$1;}
    ;
%%
yyerror(char *s)
{
	printf("%s",s);
}
main()
{
yyparse();
}
