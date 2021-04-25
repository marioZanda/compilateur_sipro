%%

\"([^"]*|(.*\\\".*)*)\"                                                                   printf("chaîne de caractère C: < %s >\n", yytext);

(_[1-9a-zA-Z_]*[a-zA-Z][1-9a-zA-Z_]*)|([a-zA-Z][1-9a-zA-Z_]*[a-zA-Z][1-9a-zA-Z_]*)        printf("Identifiacteur C: < %s >\n", yytext);

`([^`]*|(``.)*)`                                                                          printf("chaînes de caractère Pascal: < %s >\n", yytext);


\/\/.*                                                                                    printf("commentaire C++: < %s >\n", yytext);

((0[xX]?)|[-+])?[0-9]+                                                                    printf("entier: < %s >\n", yytext );


(([0-9]+.|.[0-9]+|[0-9]+.[0-9]+)(e[0-9]+)?)|[0-9]+e[0-9]+                                 printf("reel: < %s > \n", yytext);
%%

int yywrap() { return 1; }

int main() {
  yylex();
  return 0;
}
