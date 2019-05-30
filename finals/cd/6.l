%{
#include "y.tab.h"
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
int val;
extern int yylval;
%}

%%
[_a-zA-Z][a-zA-Z_0-9]* {printf("enter the value of %s \n",yytext);scanf("%d",&val);yylval=val;return id;}
[0-9]+ {yylval=atoi(yytext);return num;}
. {return yytext[0];}
[\n\t] {return 0;}
%%
int yywrap(){return 1;}
