%{
#include<stdio.h>
#include<stdlib.h>
int res=0;
%}

%token id num
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
stmt:expression {res=$$;}
;

expression:'(' expression ')' {$$=$2;}
|expression '+' expression {$$=$1+$3;}
|expression '-' expression {$$=$1-$3;}
|expression '*' expression {$$=$1*$3;}
|expression '/' expression {if($3==0) exit(0); else $$=$1/$3;}
|expression '-' {printf("error \n");}
|expression '+' {printf("error \n");}
|expression '*' {printf("error \n");}
|expression '/' {printf("error \n");}
|id
|num
;
%%
int main()
{
printf("enter expression \n");
yyparse();
printf("valid expression and result is %d",res);
exit(0);
}
int yyerror()
{
printf("invalid expression\n");
exit(0);
}

