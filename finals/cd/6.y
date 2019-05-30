%{
#include<stdio.h>
%}

%token id num
%left '+' '-'
%left '/' '*' '%'
%left "++" "--"
%left '(' ')'
%nonassoc UMINUS

%%
stmt: exp {printf("correct expression \n");}
;
exp: '(' exp ')'
| '+''+' exp {printf("Unary plus prefix");$$=$3+1;printf("Result=%d",$$);}
| '-''-' exp {printf("Unary minus prefix \n");$$=$3-1;printf("Result=%d",$$);}
| exp '-''-' {printf("Unary minus postfix \n");printf("Result=%d",$$);$$=$3-1;}
| exp '+''+' {printf("Unary plus postfix \n");printf("Result=%d",$$);$$=$3+1;}
| exp '+' exp {printf("plus operator \n");$$=$1+$3;printf("Result=%d",$$);}
| exp '*' exp {printf("plus operator \n");$$=$1*$3;printf("Result=%d",$$);}
| exp '-' exp {printf("plus operator \n");$$=$1-$3;printf("Result=%d",$$);}
| exp '/' exp {printf("plus operator \n");$$=$1/$3;printf("Result=%d",$$);}
|id
|num
%%

int main(){
printf("enter the expression \n--");
yyparse();
}

yyerror(){
printf("some error");
}
