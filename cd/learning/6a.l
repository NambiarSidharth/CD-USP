%{
#include"y.tab.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
extern int yylval;
%}
%%

[0-9]+ {yylval=atoi(yytext);return num;}
[a-zA-Z_][a-zA-Z_0-9]* { printf("enter value %s",yytext);scanf("%d",&yylval);return id;}
[\t] ;
[\n] {return 0;};
. {return yytext[0];}
%%

int yywrap(){
return 1;
}
