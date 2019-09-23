%{
/* Definition section */
#include<stdio.h> 
#include<stdlib.h> 
%}

%token E O NL 

/* Rule Section */
%%
stmt: E NL {printf("valid variable\n"); 
			exit(0);} 
; 
S: E
| 
; 
%%

int yyerror(char *msg) 
{ 
printf("invalid variable\n"); 
exit(0); 
} 


//driver code 
main() 
{ 
printf("enter the variable\n"); 
yyparse(); 
} 

