%{
#include<stdio.h>
%}

%token id num

%%
stmt:exp{printf("valid expression");}
;
exp:exp '&''&' exp {$$=($1&&$4);printf("result is %d",$$);}
| exp '|''|' exp {$$=($1||$4);printf("result is %d",$$);}
| '!' exp {$$=(!$2);printf("result is %d",$$);}
|id
|num
;
%%

int main(){
printf("enter expression");
yyparse();

}

int yyerror(){
printf("invalid expression");
}

