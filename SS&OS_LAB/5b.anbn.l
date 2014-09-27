%{
	#include"y.tab.h"
%}
%%
a	return A;
b	return B;
[0-9]	{yylval=atoi(yytext);return NUM;}
\t	;
.	return yytext[0];
\n	return 0;
%%
