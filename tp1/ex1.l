%{
  #include <limits.h>
  #include "ex1.tab.h"
  void string_to_int(int *v, const char *s);
%}
%option noyywrap

LID [a-zA-Z]+[1-9a-zA-Z_]*

UID _[1-9a-zA-Z_]*[a-zA-Z][1-9a-zA-Z_]*

ID  {UID}|{LID}

%%

"return"		      { return RETURN; }

"if"			        { return IF; }

"while"			      { return WHILE; }

"print"			      { return PRINT; }

"else"		      	{ return ELSE; }

[[:digit:]]+      {
                    string_to_int(&yylval.entier, yytext);
                    return NUMBER;
                  }

"=="							{ return EQ; }

"<"               { return INF; }

"<="              { return INF_EQ; }

">"               { return SUP; }

">="              { return SUP_EQ; }

"&&"							{ return AND; }

"!"							  { return NEG; }

"||"							{ return OR; }

"true"						{ return TRUE; }

"false"						{ return FALSE; }

"bool"						{ return BOOL_LEX; }

"int"							{ return INT_LEX; }

"void"						{ return VOID_LEX; }

{ID}              {
                    yylval.chaine = (char*) malloc(sizeof(char) * (strlen(yytext) + 1));
                    memcpy(yylval.chaine, yytext, strlen(yytext));
                    return ID;
                  }

[[:blank:]]

.|\n              { return yytext[0]; }

%%

void string_to_int(int *r, const char *s) {
  char *p;
  long v;
  errno = 0;
  v = strtol(yytext, &p, 10);
  if ( ( *p != '\0' || ( errno == ERANGE && ( v == LONG_MIN || v == LONG_MAX ) ) )
      || ( v < INT_MIN || v > INT_MAX ) ) {
    fprintf(stderr, "Error converting string to int\n");
    exit(EXIT_FAILURE);
  }
  *r = v;
}
