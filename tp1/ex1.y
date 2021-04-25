%{
  #include <ctype.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <limits.h>
  #include <stdarg.h>
  #include "stable.h"

  int yylex(void);
  void yyerror(char const *);
  #define STACK_CAPACITY 50
  #define MAXBUF 500
  #define OK 1
  #define ERR 0
  #define T_BOOL 2
  #define T_INT 3

  #define PROGRAM_START			"debut:program"

  #define NEG_VRAI				"neg:vrai"
  #define NEG_FAUX				"neg:faux"
  #define NEG_FIN				"neg:fin"

  #define OR_VRAI				"or:vrai"
  #define OR_FAUX				"or:faux"
  #define OR_FIN				"or:fin"

  #define EQ_FIN 				"eq:fin"
  #define EQ_VRAI 				"eq:vrai"
  #define EQ_FAUX 				"eq:faux"

  #define INF_FIN 				"inf:fin"
  #define INF_VRAI 				"inf:vrai"
  #define INF_FAUX 				"inf:faux"

  #define SUP_FIN 				"sup:fin"
  #define SUP_VRAI 				"sup:vrai"
  #define SUP_FAUX 				"sup:faux"

  #define INF_EQ_FIN 			"inf:eq:fin"
  #define INF_EQ_VRAI 			"inf:eq:vrai"
  #define INF_EQ_FAUX 			"inf:eq:faux"

  #define SUP_EQ_FIN 			"sup:eq:fin"
  #define SUP_EQ_VRAI 			"sup:eq:vrai"
  #define SUP_EQ_FAUX 			"sup:eq:faux"

  #define FUNCTION_DEFINITION 				"function:definition"
  #define FUNCTION_DEFINITION_FIN			"function:definition:end"

  #define VAR_GLOBAL			"var:global"
  #define VAR_GLOBAL_VAL 		"var:global:val"

  #define VAR_LOCAL				"var:local"
  #define VAR_LOCAL_VAL 		"var:local:val"

  #define VAR_PARAM 			"var:fun:param"
  #define VAR_PARAM_VAL 		"var:fun:param:val"

  #define VAR_PARAM_INIT		"var:fun:param:init"
  #define VAR_PARAM_INIT_FIN	"var:fun:param:init:fin"

  #define ERR_DIV_ZERO			"err:div0"
  #define ERR_DIV_ZERO_MSG		"err:div0:msg"

  #define BOOL_STR_FALSE		"bool:str:faux"
  #define BOOL_STR_TRUE			"bool:str:vrai"

  #define PRINT_TRUE			"bool:affichage:vrai"
  #define PRINT_FALSE			"bool:affichage:faux"
  #define PRINT_FIN				"bool:affichage:fin"

  char buffer1[MAXBUF];
  char buffer2[MAXBUF];

  static unsigned int new_label_number();
  static void create_label(char *buf, size_t buf_size, const char *format, ...);
  void fail_with(const char *format, ...);

  symbol_table_entry* function_def = NULL;

%}
//%define api.value.type { int }
%union { int entier; char* chaine; }

%token NUMBER AND EQ OR NEG TRUE FALSE BOOL_LEX INT_LEX VOID_LEX ID IF WHILE PRINT ELSE NON_ELSE RETURN SUP SUP_EQ INF INF_EQ

%start lignes


%left OR
%left AND
%left EQ SUP INF SUP_EQ INF_EQ
%left '+' '-'
%left '*' '/'
%left NEG
%precedence NON_ELSE
%precedence ELSE

%type <entier> expr NUMBER decl type largs largV sdecl sdeclV instr sinstrV sinstr lexpr lexprV blocinstr
%type <chaine> ID

%%
lignes:
  lignes error '\n'     {yyerrok;}
| ligne error '\n' 	{yyerrok; }
| error '\n'           	{yyerrok; }
| lignes ligne '\n'
| lignes '\n'
| ligne '\n'
| '\n'
;

ligne:
  instr
| decl
| deffun
;

fixif : %empty
{
	unsigned int number = new_label_number();
	$<entier>$ = number;
	printf("; If No %d\n"
	"\tpop ax\n"
	"\tconst bx,0\n"
	"\tconst cx,if:test:neg:%d\n"
	"\tcmp ax,bx\n"
	"\tjmpc cx\n"
	, number, number);
};

type :
  BOOL_LEX 	{ $$ = BOOL_T; }
| INT_LEX	{ $$ = INT_T; }
| VOID_LEX	{ $$ = VOID_T; }
;

/* ---- Langage de traitement de la définition du fontion ---- */
deffun :
 type ID 	{
	 
			// Vérification de l'unicité de l'identifiant de la fonction
				function_def = search_symbol_table($2);
				if (function_def != NULL) {
					fail_with("ID existe deja\n");
				}

			/* Ajout de l'identifiant de la fontion dans la
			table des symboles et préparation du traitement 
			de la définition de la fontion */
				function_def = new_symbol_table_entry($2);
				function_def->class = FUNCTION;
				function_def->nParams = 0;
				function_def->nLocalVariables = 0;
				function_def->desc[0] = $1;

				
			} '(' largV ')' {
				printf(
					"; Saut à fin définition %s()\n"
					"\tconst dx,"FUNCTION_DEFINITION_FIN":%s\n"
					"\tjmp dx\n",
				function_def->name,
				function_def->name);

				printf(":"FUNCTION_DEFINITION":%s\n", $2);

				for (int i = function_def->nParams; i > 0 ; i--) {
					printf(
						"; Code saut à l'initialisation du paramètre %d de %s()\n"
						"\tconst dx,"VAR_PARAM_INIT":%s:%d\n"
						"\tjmp dx\n"
						":"VAR_PARAM_INIT_FIN":%s:%d\n",
					i, function_def->name,
					function_def->name, i,
					function_def->name, i
					);
				}
				printf(
					"; Début de l'exécution du code de %s()\n",
				function_def->name);

			} blocinstr {

			/* Fin de traitement de la définition de la fonction donc
			 libération  des ressources */
				for(int i = 0; i < function_def->nParams; i++){
					free_first_symbol_table_entry();
				}
				printf(
					"; Saut à la fin de l'exécution du code de %s()\n"
					":function:definition:end:%s\n",
				function_def->name,
				function_def->name);
				function_def = NULL;
			};

/* ---- Langage de traitement de la liste des arguments d'une fonction ---- */
largV :
  %empty		{ $$ = 0; }
| largs			{ $$ = $1; };

/* ---- Langage de traitement d'un argument d'une fonction ---- */
largs :
// Cas d'argument unique
  type ID			{
					// Vérification de l'unicité de l'identifiant de l'argument
						symbol_table_entry* funArg = search_symbol_table($2);
						if (funArg != NULL){
							fail_with("ID existe deja\n");
						}

					/* Ajout de l'identifiant de l'argument dans la
					table des symboles */
						funArg =  new_symbol_table_entry($2);
						funArg->class = LOCAL_VARIABLE;
						funArg->desc[0] = $1;

					/* Mise à jour des informations de définition de
					la fontion dans la table des symboles */
						function_def->desc[function_def->nParams] = $1;
						function_def->nParams++;

						printf(
							"; Code de définition et d'initialisation du paramètre %s de %s()\n"
							":"VAR_PARAM_INIT":%s:%lu \n"
							"\tconst ax,"VAR_PARAM_VAL":%s:%s\n"
							"\tjmp ax\n"
							":"VAR_PARAM":%s:%s\n"
							"@int 0\n"
							":"VAR_PARAM_VAL":%s:%s\n"
							"\tpop ax\n"
							"\tconst bx,"VAR_PARAM":%s:%s\n"
							"\tstorew ax,bx\n"
							"\tconst dx,"VAR_PARAM_INIT_FIN":%s:%lu\n"
							"\tjmp dx\n",
						$2, function_def->name,
						function_def->name, function_def->nParams,
						function_def->name, $2,
						function_def->name, $2,
						function_def->name, $2,
						function_def->name, $2,
						function_def->name, function_def->nParams
						);
					}
// Dans une liste d'arguments
| largs ',' type ID	{
					// Vérification de l'unicité de l'identifiant de l'argument
						symbol_table_entry* funArg = search_symbol_table($4);
						if (funArg != NULL){
							fail_with("ID existe deja\n");
						}

					/* Ajout de l'identifiant de l'argument dans la
					table des symboles */
						funArg =  new_symbol_table_entry($4);
						funArg->class = LOCAL_VARIABLE;
						funArg->desc[0] = $3;

					/* Mise à jour des informations de définition de
					la fontion dans la table des symboles */
						function_def->nParams++;
						function_def->desc[function_def->nParams] = $3;

						
						printf(
							"; Code de définition du paramètre %s de %s()\n"
							":"VAR_PARAM_INIT":%s:%lu\n"
							"\tconst ax,"VAR_PARAM_VAL":%s:%s\n"
							"\tjmp ax\n"
							":"VAR_PARAM":%s:%s\n"
							"@int 0\n\n"
							":"VAR_PARAM_VAL":%s:%s\n"
							"\tpop ax\n"
							"\tconst bx,"VAR_PARAM":%s:%s\n"
							"\tstorew ax,bx\n"
							"\tconst dx,"VAR_PARAM_INIT_FIN":%s:%lu\n"
							"\tjmp dx",
						$4, function_def->name,
						function_def->name, function_def->nParams,
						function_def->name, $4,
						function_def->name, $4,
						function_def->name, $4,
						function_def->name, $4,
						function_def->name, function_def->nParams
						);
					};


blocinstr :
 '{' sdeclV sinstrV '}'	{
							for (int i = 0; i < $2; i++) {
								free_first_symbol_table_entry();
							}
							$$ = $2 + $3;
						}
;

sdeclV : 
  %empty		{ $$ = 0; }
| sdecl			{ $$ = $1; }
;

sdecl :
 decl			{ $$ = 1; }
| sdecl decl	{ $$ = $1 + 1; }
;

sinstrV :
  %empty		{ $$ = 0; }
| sinstr		{ $$ = $1; }
;

sinstr :
  instr			{ $$ = 1; }
| sinstr  instr	{ $$ = $1 +1; }
;




lexpr :
  expr			{ $$ = 1;  }
| lexpr  expr	{ $$ = $1 + 1;}
;

lexprV :
  %empty 		{ $$ = 0; }
| lexpr			{ $$ = $1; }
;


instr:
  blocinstr			{ $$ = $1; }

| RETURN ';'		{
						if (function_def == NULL) {
							fail_with("Espace global, retour de valeur impossible !");
								$$ = ERR;
						} else {
							if (function_def->desc[0] != VOID_T) {
								fail_with("Types de retour incompatible !");
								$$ = ERR;
							} else {
								$$ = VOID_T;
							}
						}
					}

| RETURN expr ';'	{
						if ($2 != ERR) {
							if (function_def == NULL) {
								fail_with("Espace global, retour de valeur impossible !");
								$$ = ERR;
							} else {
								if ((function_def->desc[0] == INT_T && $2 != T_INT)
									|| (function_def->desc[0] == BOOL_T && $2 != T_BOOL)) {
										fail_with("Types de retour incompatible !");
										$$ = ERR;
								} else {
									$$ = $2;
								}
							}
						}
					}

| expr ';'			{
 					if ($1 != ERR){
 						printf("\tpop\n");
 					}
 				}
| ID '=' expr ';'		{
					symbol_table_entry* ste = search_symbol_table($1);
					if(ste == NULL){
						fail_with("ID n'existe pas");
					}
					if( (ste->desc[0] == INT_T && $3 != T_INT) || (ste->desc[0] == BOOL_T && $3 != T_BOOL)){
						fail_with("Type incompatible");
					}
					printf("; Code affectation variable %s\n"
					"\tpop ax\n"
					"\tconst bx,"VAR_GLOBAL":%s\n"
					"\tstorew ax,bx\n",
					 ste->name, ste->name);
				}

| IF '(' expr fixif ')' instr ELSE {
					printf(";si if No %d vrai et instr executé\n"
					"\tconst ax,if:fin:%d\n"
					"\tjmp ax\n"
					";si if No %d est faux\n"
					":if:test:neg:%d\n"
					, $<entier>4, $<entier>4, $<entier>4, $<entier>4);
				} instr {
						if ( $3 != T_BOOL ) { fail_with("condition du if non booleenne \n"); }
						printf(";fin du if No %d\n"
						":if:fin:%d\n"
						, $<entier>4, $<entier>4);
					}
| IF '(' expr fixif ')' instr {
				if ( $3 != T_BOOL ) { fail_with("condition du if non booleenne \n"); }
				printf(";si if No %d est faux\n"
				":if:test:neg:%d\n"
				, $<entier>4, $<entier>4);
			} %prec NON_ELSE
| WHILE '('{
	unsigned int number = new_label_number();
	$<entier>$ = number;
	printf(":debut:while:%u\n",number);
	}expr{
		printf("; while No %u\n"
		"\tpop ax\n"
		"\tconst bx,0\n"
		"\tconst cx,fin:while:%u\n"
		"\tcmp ax,bx\n"
		"\tjmpc cx\n"
		, $<entier>3, $<entier>3);
				}')' instr{
						if( $4 != T_BOOL ){ fail_with("condition non booléenne\n");}
						printf("; fin tour de boucle\n"
						"\tconst cx,debut:while:%u\n"
						"\tjmp cx\n"
						":fin:while:%u\n", $<entier>3, $<entier>3);
							}
| PRINT expr ';'		{
					if ($2 == T_INT) {
 						printf("; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile\n"
						"\tcp ax,sp\n"
						"\tcallprintfd ax\n"
						"\tpop ax\n");
 					} else if ($2 == T_BOOL) {
						
						unsigned int labelNumber = new_label_number();
						create_label(buffer1, MAXBUF, "%s:%u", PRINT_TRUE, labelNumber);
						create_label(buffer2, MAXBUF, "%s:%u", PRINT_FIN, labelNumber);

 						printf(
							"; Affichage booleen (%d)\n"
							"\tpop ax\n"
							"\tconst bx,1\n"
							"\tconst cx,%s\n"
						// Test (expr1 == true)
							"; Comparaison de expr1 à true\n"
							"\tcmp ax,bx\n"
							"\tjmpc cx\n"
							"; Si expr1 == true saut à "PRINT_TRUE"\n"
						// PRINT_FALSE
							"; Code cible "PRINT_FALSE"\n"
							"\tconst cx,"BOOL_STR_FALSE"\n"
							"\tcallprintfs cx\n"
							"\tconst cx,%s\n"
							"\tjmp cx\n"
							"; Saut à "PRINT_FIN"\n\n"
						// PRINT_TRUE
							"; Code cible "PRINT_TRUE"\n"
							":%s\n"
							"\tconst cx,"BOOL_STR_TRUE"\n"
							"\tcallprintfs cx\n\n"
						// PRINT_FIN
							":%s\n",
						labelNumber,
						buffer1,
						buffer2,
						buffer1,
						buffer2);
 					}
				}


decl:
 type ID '=' expr ';'	{
	 					// Vérifier la comatibilité des types
						// Ajouter l'ID dans la table des symboles en fontion
						//  de la portée de la varible
						// 		* Si analyes de definition de fonction variable locale
						//		* Sinon variable globale
							if (($4 == T_INT && $1 == INT_T) || ($4 == T_BOOL && $1 == BOOL_T) ) {
								
								symbol_table_entry* var = search_symbol_table($2);
								if (var != NULL){
									fail_with("ID existe deja\n");
								}
								
								var = new_symbol_table_entry($2);
								var->desc[0] = $1;

								if (function_def != NULL) {
							// Analyse d'une fonction la variable est locale
							// Mise à jour de la définition de la fonction
									var->class = LOCAL_VARIABLE;
									function_def->nLocalVariables++;
									printf(
										"; Code nouvelle variable locale (%s, %s)\n"
										"\tconst ax,"VAR_LOCAL_VAL":%s:%s\n"
										"\tjmp ax\n"
										"; Saut à "VAR_LOCAL_VAL"\n\n"
										":"VAR_LOCAL":%s:%s\n"
										"@int 0\n\n"
										":"VAR_LOCAL_VAL":%s:%s\n"
										"\tpop ax\n"
										"\tconst bx,"VAR_LOCAL":%s:%s\n"
										"\tstorew ax,bx\n",
									function_def->name, $2,
									function_def->name, $2,
									function_def->name, $2,
									function_def->name, $2,
									function_def->name, $2);
								} else {
							// Aucune analyse de fonction en cours, la variable est globale
									var->class = GLOBAL_VARIABLE;

									printf(
										"; Code nouvelle variable globale %s\n"
										"\tconst ax,"VAR_GLOBAL_VAL":%s\n"
										"\tjmp ax\n"
										"; Saut à "VAR_GLOBAL_VAL"\n\n"
										":"VAR_GLOBAL":%s\n"
										"@int 0\n\n"
										":"VAR_GLOBAL_VAL":%s\n"
										"\tpop ax\n"
										"\tconst bx,"VAR_GLOBAL":%s\n"
										"\tstorew ax,bx\n",
									$2, $2, $2, $2, $2);
								}

								$$ = $4;

							} else {
								$$ = ERR;
								fail_with("Type imcompatible !");
							}
						}
| type ID ';'	{
						// Ajouter l'ID dans la table des symboles en fontion
						//  de la portée de la varible
						// 		* Si analye de definition de fonction variable locale
						//		* Sinon variable globale
								symbol_table_entry* var = search_symbol_table($2);
								if (var != NULL){
									fail_with("ID existe deja\n");
								}

								var = new_symbol_table_entry($2);
								var->desc[0] = $1;
								
								if (function_def != NULL) {
							// Analyse d'une fonction la variable est locale
							// Mise à jour de la définition de la fonction
									var->class = LOCAL_VARIABLE;
									function_def->nLocalVariables++;
									printf(
										"; Code nouvelle variable locale (%s, %s)\n"
										":"VAR_LOCAL":%s:%s\n"
										"@int 0\n",
									function_def->name, $2,
									function_def->name, $2);

								} else {
							// Aucune analyse de fonction en cours, la variable est globale
									var->class = GLOBAL_VARIABLE;

									printf(
										"; Code nouvelle variable globale %s\n"
										":"VAR_GLOBAL":%s\n"
										"@int 0\n",
									$2, $2);
								}

								$$ = ($1 == INT_T) ? T_INT : T_BOOL;
						}
;


expr	 :
  ID '(' lexprV ')'		{
						// Vérifation de l'existance de la définition de la fonction
							symbol_table_entry* fun = search_symbol_table($1);

							if (fun == NULL) {
								fail_with("ID n'existe pas déja\n");
								$$ = ERR;
							}


						// Traitement de l'appel de la function 
						// Vérification de l'appel avec nombre de paramètres correct
							if ($3 != fun->nParams ) {
								fail_with(
									"Syntaxe incorrecte:\n"
									"\t%s() a %d arguments\n",
								$1, $3);
							}


							//- Exécution de la fonction */
							printf(
								"; Saut à %s() pour exécution\n"
								"\tconst dx,"FUNCTION_DEFINITION":%s\n"
								"\tjmp dx\n\n"
								":"FUNCTION_DEFINITION_FIN"%s",
							fun->name,
							fun->name,
							fun->name);

							$$ = (fun->desc[0] == INT_T)
								? T_INT
								: T_BOOL;
						}
| expr '+' expr		{
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer l'addition
						if ($1 == T_INT && $3 == T_INT ){
							printf(
								"; Debut addition\n"
								"\tpop ax\n"
								"\tpop bx\n"
								"\tadd bx,ax\n"
								"\tpush bx\n");

							$$ = T_INT;
						} else {
							$$ = ERR;
						}
					}
| expr '-' expr			{
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la soustraction
							if ($1 == T_INT && $3 == T_INT){
								printf(
									"; Debut soustraction\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tsub bx,ax\n"
									"\tpush bx\n");
								$$ = T_INT;
							} else {
								$$ = ERR;
							}
						}
| expr '*' expr			{
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la multiplication
							if ($1 == T_INT && $3 == T_INT){
								printf(
									"; Debut multiplication\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tmul bx,ax\n"
									"\tpush bx\n");
								$$ = T_INT;
							} else {
								$$ = ERR;
							}
						}
| expr '/' expr			{
						// Vérifier que expr1 et expr2 sont de type int sinon erreur de typage
						// puis évaluer la division
							if ($1 == T_INT && $3 == T_INT){
								printf(
									"; Debut division"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tconst cx,"ERR_DIV_ZERO"\n"
									"\tdiv bx,ax\n"
									"\tjmpe cx\n"
									"\tpush bx\n");
								$$ = T_INT;
							} else {
								$$ = ERR;
							}
						}
| NUMBER				{
							printf(
								"; Ajout du nombre %d\n"
								"\tconst ax,%d\n"
								"\tpush ax\n",
							$1,
							$1);

							$$ = T_INT;
						}

| '(' expr ')'			{ $$ = $2; }

| expr EQ expr			{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le EQ
							if ($1 == $3 && $1 != ERR) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", EQ_FIN, labelNumber);

								printf(
									"; Debut EQ (%d)\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tconst cx,%s\n"
								// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si expr1 == expr2 saut à "EQ_VRAI"\n"
									"; Si expr1 != expr2 code cible "EQ_FAUX"\n"
								//EQ_FAUX
									"; Code cible "EQ_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n"
									";Saut à "EQ_FIN"\n"
								//EQ_VRAI
									"; Code cible "EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
								// EQ_FIN
									"; Code cible "EQ_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;
							} else {
								$$ = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
								printf("; Fin EQ\n");
						}
| expr INF expr			{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le INF
							if ($1 == T_INT && $3 == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", INF_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", INF_FIN, labelNumber);

								printf(
									"; Debut INF (%d)\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr1 < expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tsless ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 < expr2) saut à "INF_VRAI"\n"
									"; Si (expr1 !(<) expr2) code cible "INF_FAUX"\n"
									//INF_FAUX
									"; Code cible "INF_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									";Saut à "INF_FIN"\n"
									//INF_VRAI
									"; Code cible "INF_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// INF_FIN
									"; Code cible "INF_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;
							} else {
								$$ = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin INF\n");
						}
| expr SUP expr        	{
							if ($1 == T_INT && $3 == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", SUP_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", SUP_FIN, labelNumber);

								printf(
									"; Debut SUP %d\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr2 < expr1)
									"; Comparaison de expr1 et expr2\n"
									"\tsless bx,ax\n"
									"\tjmpc cx\n"
									"; Si expr2 < expr1 saut à "SUP_VRAI"\n"
									"; Si expr2 !(<) expr1 code cible "SUP_FAUX"\n"
									//EQ_FAUX
									"; Code cible "SUP_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									";Saut à "SUP_FIN"\n"
									//EQ_VRAI
									"; Code cible "SUP_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// EQ_FIN
									"; Code cible "SUP_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;
							} else {
								$$ = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin SUP\n");
						}
| expr INF_EQ expr		{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le INF_EQ
							if ($1 == T_INT && $3 == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", INF_EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", INF_EQ_FIN, labelNumber);
								
								printf(
									"; Debut INF_EQ %d\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
									// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 == expr2) saut à "INF_EQ_VRAI"\n"
									// Test (expr1 < expr2)
									"\tsless ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 < expr2) saut à "INF_EQ_VRAI"\n"
									"; Si (expr1 !(<=) expr2) code cible "INF_EQ_FAUX"\n"
									//INF_EQ_FAUX
									"; Code cible "INF_EQ_FAUX"\n"
									"\tconst dx,0\n"
									"\tpush dx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
									"; Saut à "INF_EQ_FIN"\n"
									//INF_EQ_VRAI
									"; Code cible "INF_EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
									"\tpush dx\n"
									// INF_EQ_FIN
									"; Code cible "INF_EQ_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;
							} else {
								$$ = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf("; Fin INF_EQ\n");
                      	}
| expr SUP_EQ expr		{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le SUP_EQ
							if ($1 == T_INT && $3 == T_INT) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", SUP_EQ_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", SUP_EQ_FIN, labelNumber);
								printf(
									"; Debut SUP_EQ (%d)\n"
									"\tpop bx\n"
									"\tpop ax\n"
									"\tconst cx,%s\n"
								// Test (expr1 == expr2)
									"; Comparaison de expr1 et expr2\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Si (expr1 == expr2) saut à "SUP_EQ_VRAI"\n"
								// Test (expr1 < expr2)
									"\tsless bx,ax\n"
									"\tjmpc cx\n"
									"; Si (expr2 < expr1) saut à "SUP_EQ_VRAI"\n"
									"; Si (expr2 !(<=) expr1) code cible "SUP_EQ_FAUX"\n"
								// SUP_EQ_FAUX
									"; Code cible "SUP_EQ_FAUX"\n"
									"\tconst dx,0\n"
									"; Saut à "SUP_EQ_FIN"\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n\n"
								// SUP_EQ_VRAI
									"; Code cible "SUP_EQ_VRAI"\n"
									":%s\n"
									"\tconst dx,1\n"
								// SUP_EQ_FIN
									"; Code cible "SUP_EQ_FIN"\n"
									":%s\n"
									"\tpush dx\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;
							} else {
								$$ = ERR;
								printf("Erreur de sémentique !\n");
								exit(0);
							}
							printf(";Fin INF_EQ\n");
                      	}
| expr AND expr			{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// puis évaluer le ET (epxr1 * expr2 car true = 1)
							if ($1 == T_BOOL && $3 == T_BOOL){
								printf(
									"; Code cible AND\n"
									"\tpop ax\n"
									"\tpop bx\n"
									"\tmul bx,ax\n"
									"\tpush bx\n");
								$$ = T_BOOL;
							} else {
								$$ = ERR;
							}
							printf("; Fin AND\n");
						}
| expr OR expr			{
						// Vérifier que expr1 et expr2 sont de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer le OU
							if ($1 == T_BOOL && $3 == T_BOOL) {
									unsigned int labelNumber = new_label_number();
									create_label(buffer1, MAXBUF, "%s:%u", OR_VRAI, labelNumber);
									create_label(buffer2, MAXBUF, "%s:%u", OR_FIN, labelNumber);
									
									printf(
										"; Debut OU (%d)\n"
										"\tconst cx,%s\n"
										"\tpop bx\n"
										"\tpop ax\n"
									// Test (expr1 == true)
										"; Comparaison à true de expr1\n"
										"\tconst dx,1\n"
										"\tcmp ax,dx\n"
										"\tjmpc cx\n"
										"; Saut à "OR_VRAI" si expr1 == vrai\n"
									// Test (expr2 == true)
										"; Comparaison à true de expr2\n"
										"\tcmp bx,dx\n"
										"\tjmpc cx\n"
										"; Saut à "OR_VRAI" si expr2 est vrai\n"
										"; L'esxpressin est évaluée à false\n"
									// OR_FAUX
										"; Code cible "OR_FAUX"\n"
										"\tconst bx,0\n"
										"\tpush bx\n"
										"\tconst dx,%s\n"
										"\tjmp dx\n"
									// OR_VRAI
										"; Code cible "OR_VRAI"\n"
										":%s\n"
										"\tconst bx,1\n"
										"\tpush bx\n"
									// OR_FIN
										"; Code cible "OR_FIN"\n"
										":%s\n",
									labelNumber,
									buffer1,
									buffer2,
									buffer1,
									buffer2);
									$$ = T_BOOL;
							} else {
								$$ = ERR;
							}
							printf("; Fin OR\n");
						}
	| NEG expr			{
						// Vérifier que expr est de type bool sinon erreur de typage
						// Créer un nouveau label pour anticiper la récursivité
						// puis évaluer la négation
							if ($2 == T_BOOL) {
								unsigned int labelNumber = new_label_number();
								create_label(buffer1, MAXBUF, "%s:%u", NEG_VRAI, labelNumber);
								create_label(buffer2, MAXBUF, "%s:%u", NEG_FIN, labelNumber);
								printf(
									"; Debut NEG (%d)\n"
									"\tconst cx,%s\n"
									"\tpop ax\n"
								// Test (expr == false)
									"; Comparaison à false\n"
									"\tconst bx,0\n"
									"\tcmp ax,bx\n"
									"\tjmpc cx\n"
									"; Saut  à "NEG_VRAI" en cas d'égalité\n"
								// NEG_FAUX
									"; La comparison est évaluée à true\n"
									"; Code cible "NEG_FAUX"\n"
									"\tpush bx\n"
									"\tconst cx,%s\n"
									"\tjmp cx\n"
									"; Saut  à "NEG_FIN"\n"
								// NEG VRAI
									"; Code cible "NEG_VRAI"\n"
									":%s\n"
									"\tconst bx,1\n"
									"\tpush bx\n"
								// NEG_FIN
									"; Code cible "NEG_FIN"\n"
									":%s\n",
								labelNumber,
								buffer1,
								buffer2,
								buffer1,
								buffer2);

								$$ = T_BOOL;

							}else{
								$$ = ERR;
							}
							printf("; Fin NEG\n");
						}
	| TRUE				{
						// Ajouter true en pile
							printf(
								"; Ajout de TRUE\n"
								"\tconst ax,%u\n"
								"\tpush ax\n",
							1);
							$$ = T_BOOL;
						}
	| FALSE				{
						// Ajouter false en pile
							printf(
								"; Ajout de FALSE\n"
								"\tconst ax,%u\n"
								"\tpush ax\n",
							0);
							$$ = T_BOOL;
						}
	| ID				{
						// Vérifation de l'existance de la déclaration de la variable
							symbol_table_entry* var = search_symbol_table($1);

							if (var == NULL){
								//fail_with("%s n'a pas été déclaré\n", $1);
								$$ = ERR;
							} else if (function_def == NULL && var->class == GLOBAL_VARIABLE) {
						// Accès à une varibale globale
								printf(
									"; Debut évaluation ID (variable globale)\n"
									"; Recuperation valeur de %s et mise en pile\n"
									"\tconst bx,"VAR_GLOBAL":%s\n"
									"\tloadw ax,bx\n"
									"\tpush ax\n",
								var->name,
								var->name);

								$$ = (var->desc[0] == INT_T)
									? T_INT
									: T_BOOL;

							} else if (function_def != NULL && var->class == LOCAL_VARIABLE) {
						// Accès à une varibale locale ou un paramètre
								printf(
									"; Debut évaluation ID (variable locale)\n"
									"; Recuperation valeur de %s:%s et mise en pile\n"
									"\tconst bx,"VAR_LOCAL":%s:%s\n"
									"\tloadw ax,bx\n"
									"\tpush ax\n",
								function_def->name, $1,
								function_def->name, $1);
								$$ = (var->desc[0] == INT_T)
									? T_INT
									: T_BOOL;
							} else {
						// ID n'est pas une varibale ou un paramètre
								$$ = ERR;
							}
						}
;
%%

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}

static unsigned int new_label_number() {
	static unsigned int current_label_number = 0u;
	if ( current_label_number == UINT_MAX ) {
		fail_with("Error: maximum label number reached!\n");
	}
	return current_label_number++;
}
/*
* char buffer1[MAXBUF], char buffer2[MAXBUF];
* unsigned ln = new_label_number();
* create_label(buffer1, MAXBUF, "%s:%u:%s", "loop", ln, "begin"); // "loop:10:begin"
* create_label(buffer2, MAXBUF, "%s:%u:%s", "loop", ln, "end");  //  "loop:10:end"
*/

static void create_label(char *buf, size_t buf_size, const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	if ( vsnprintf(buf, buf_size, format, ap) >= buf_size ) {
		va_end(ap);
		fail_with("Error in label generation: size of label exceeds maximum size!\n");
	}
	va_end(ap);
}

void fail_with(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

int main (int argc, char** argv){
	printf(
		"; Calculette\n"
		"\tconst ax,"PROGRAM_START"\n"
		"\tjmp ax\n"
		":"PROGRAM_START"\n"
		"; Préparation de la pile\n"
		"\tconst bp,pile\n"
		"\tconst sp,pile\n"
		"\tconst ax,2\n"
		"\tsub sp,ax\n");

	yyparse();

	printf(
		"\tend\n"
		"; La zone de pile\n"
		":pile\n"
		"@int 0\n\n"
		"; Définition Chaine de charactère boolean faux\n"
		":"BOOL_STR_FALSE"\n"
		"@string \"false\"\n\n"
		"; Définition Chaine de charactère boolean true\n"
		":"BOOL_STR_TRUE"\n"
		"@string \"true\"\n\n"
		"; Définition chaine de charactère erreur de division par zéro\n"
		":"ERR_DIV_ZERO_MSG"\n"
		"@string \"Erreur: division par 0\"\n\n"
		"; Code cible erreur de division par zéro\n"
		":"ERR_DIV_ZERO"\n"
		"\tconst ax,"ERR_DIV_ZERO_MSG"\n"
		"\tcallprintfs ax\n"
		"\tend\n"
	);
	return 0;
}
