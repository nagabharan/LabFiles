%{
	#include "y.tab.h"
%}
%%
[ \t]	;
[0-9]+		{return DIGIT;}
[a-zA-Z]+	{return ALPHA;}
.		{return yytext[0];}
\n		{return 0;}
%%
