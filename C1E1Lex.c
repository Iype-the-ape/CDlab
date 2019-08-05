#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char found[50][10];
int foundindex = 0;

int iskeyword(char buffer[]) {
	int i, flag = 0;
	char keywords[33][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long", "print", "register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	for ( i = 0; i < 32; i ++ ) {
		if ( strcmp( keywords[i], buffer ) == 0 ) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int isoperator(char buffer[]) {
	int flag = 0, i;
	char operators[14][4] = {"+", "-", "*", "/", "=", "%", "==", "||", "&&", "!=", "<=", ">=", ">", "<"};
	for ( i = 0; i < 14; i ++ ) {
		if ( strcmp(operators[i], buffer) == 0 ) {
			flag = 1;
			break;
		}
	}
	return flag;	
}

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

void main(int argc, char *argv[]) {
	FILE *fp;
	fp = fopen(argv[1], "r");
	char ch, buffer[50];
	int bufflength = 0;
	
	if (fp == NULL) { printf("error opening file\n"); }
	
	while ( ( ch = fgetc(fp) ) != EOF ) {
		if ( ch == ' ' || ch == '\t' || ch == '\n' ) {
			buffer[bufflength++] = '\0';
			if ( iskeyword(buffer) && isnew(buffer) )
				printf("%s is a keyword\n", buffer);
			else if ( isoperator(buffer) && isnew(buffer) )
				printf("%s is an operator\n", buffer);
			else if ( isnew(buffer) )
				printf("%s is an identifier\n", buffer);
			bufflength = 0;
		} else buffer[bufflength++] = ch;
	}
}
