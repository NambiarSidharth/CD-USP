%{
#include"y.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
extern int yylval;
int rs;
%}

%%

[0-9]+ {yylval=atoi(yytext);return num;}
[a-zA-Z][a-zA-Z0-9]* {printf("enter the value of %s",yytext);scanf("%d",&yylval);return id;}
[\t] ;
[\n] {return 0;}
. {return yytext[0];}
%%

yywrap(){
return yytext[0];
}
