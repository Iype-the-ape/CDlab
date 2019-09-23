%{
/* Definition section */
#include <stdio.h>
#include "y.tab.h"
%} 

/* Rule Section */
%%
[a-z A-Z][a-z A-Z 0-9]* {return E;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap() { return 1; }
