%{
#include<stdio.h>
int lc=0;
FILE *fp;
%}
%%
[\n] {lc++;}
["][a-zA-Z0-9]* {ECHO; printf("\nterminated string found at line %d \n",(lc+1));}
["][a-zA-Z0-9]*["] {ECHO; printf("\na string found at line %d \n" ,(lc+1));}
%%
main(){
yyin=fopen("file.c","r");
yylex();
fclose(yyin);
}
