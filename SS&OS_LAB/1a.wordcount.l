%{

	#include<stdio.h>
	int cc=0,wc=0,sc=0,lc=0;

%}

%%
[\n]		{lc++;cc++;}
[^ \t\n]+	{wc++,cc+=yyleng;}
" "		{sc++;cc++;}
.		{cc++;}
%%

main(int argc,char * argv[])
{
	if(argc>1)
	{
		FILE *f = fopen(argv[1],"r");
		if(!f)
		{
			printf("Error openning in file");
			exit(1);
		}
		yyin=f;
	}
	yylex();
	printf("Line count=%d\nWord count=%d\nChar count=%d\nSpace count=%d\n",lc,wc,cc,sc);
}
