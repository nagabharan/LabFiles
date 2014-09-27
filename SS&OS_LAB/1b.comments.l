%{
	#include<stdio.h>
	int sc=0,mc=0;
%}
%x cmnt
%%
"//".* {sc++;}
"/*" {BEGIN cmnt;mc++;}
<cmnt>.	;
<cmnt>\n;
<cmnt>"*/" {BEGIN 0;}
%%

main (int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("No files");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("Single line comment count:%d\n",sc);
	printf("Multi line comment count:%d\n",mc);
	printf("Total comment count:%d\n",sc+mc);
}
