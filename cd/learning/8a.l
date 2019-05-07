%{
 #include<stdio.h>
 #include "y.tab.h"
 extern int yylval;
 int val;
%}
%%
[a-z][a-zA-Z0-9]+ {return id;}
[0-9]+ { yylval= atoi(yytext); return num;}
[\t] ;
\n {return 0;}
. {return yytext[0];}
 
%%
int yywrap(){
return yytext[0];
}

