/* Definition Section */
%{
char found[50][10];
int foundindex = 0;
int isnew(char buffer[]);
%}

/* Rules Section */
%%




(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|print|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while){1} { printf("%s is a keyword\n", yytext); }

["+""-""*""/""="] { if (isnew(yytext)) printf("%s is an operator\n", yytext); }

[A-Za-z][A-Za-z0-9]* { if (isnew(yytext)) printf("%s is an identifier\n", yytext); }

[0-9]+ { if (isnew(yytext)) printf("%s is an number\n", yytext); }

#.* {printf("\n%s is a preprocessor directive\n",yytext);}


[\t\n ] {}

.	{}

%%

int yywrap() {}

int isnew(char buffer[]) {
	int i, flag = 1;
	for (i = 0; i < foundindex; i ++ ) {
		if ( strcmp(buffer, found[i]) == 0 ) {
			flag = 0;
		}
	}
	if ( flag == 1 ) {
		strcpy(found[foundindex], buffer);
		foundindex++;
	}
	return flag;
}

int main() {
	FILE *fp;
	fp = fopen("test.txt", "r");
	if (fp == NULL) { printf("error opening file\n"); }
	
	yyin = fp;
	yylex();
	
	fclose(fp);
	return 0;
}
