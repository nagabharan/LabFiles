%{
	#include<stdio.h>
	int c=0;
%}
id 	[a-zA-Z]+([a-zA-Z]|[0-9])*
decl	"int "|"float "|"double "|"char "
%x 	def

%%
{decl}		{ECHO;BEGIN def;}
<def>{id}","	{ECHO;c++;}
<def>{id}";"	{ECHO;c++;BEGIN 0;}
.|\n ;
%%

main(int argc,char* argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	printf("\nNo. of identifiers: %d\n",c);
}
