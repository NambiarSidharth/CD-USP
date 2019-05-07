%{
#include<stdio.h>
%}
%token ID
%%
exp:exp exp '*'
exp:exp exp '+'
exp:ID
%%
main()
{
printf("enter the expression for the grammar \n S-->SS+ | SS* | a");yyparse();
printf("valid experession\n");
}
void yyerror()
{
printf("Invalid expression\n");
exit(1);
}
