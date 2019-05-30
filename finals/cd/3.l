%{
#include <stdio.h>
int lineno=1;
%}
id [_|a-z|A-Z][a-z|0-9|A-Z|_]*
num [0-9]+
binop [+|-|*|/]
unop [--|++]
relop (==)|(!=)|(<)|(>)|(<=)|(>=)
%%
\n {++lineno;}
({id}|{num})({binop}({id}|{num}))?{relop}({id}|{num})({binop}({id}|{num}))? {printf("Recognised Rel at line %d \n",lineno);}
{unop}{id} {printf("Recognised Pre Unop at line %d \n",lineno);}
{id}{unop} {printf("Recognised Post Unop at line %d \n",lineno);}
{id}=({id}|{num}){binop}({id}|{num}) {printf("Recognised Bin at line %d",lineno);}
{id}{binop}?=({id}|{num})({binop}({id}|{num}))? {printf("Recognised Bin Sp at line %d \n",lineno);}
. {;}
%%

void main()
{
yyin = fopen("input3.c","r");
yylex();
fclose(yyin);
}
