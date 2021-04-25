; Calculette
	const ax,debut:program
	jmp ax
:debut:program
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Saut à fin définition printTrue()
	const dx,function:definition:end:printTrue
	jmp dx
:function:definition:printTrue
; Début de l'exécution du code de printTrue()
; Ajout de TRUE
	const ax,1
	push ax
; Affichage booleen (0)
	pop ax
	const bx,1
	const cx,bool:affichage:vrai:0
; Comparaison de expr1 à true
	cmp ax,bx
	jmpc cx
; Si expr1 == true saut à bool:affichage:vrai
; Code cible bool:affichage:faux
	const cx,bool:str:faux
	callprintfs cx
	const cx,bool:affichage:fin:0
	jmp cx
; Saut à bool:affichage:fin

; Code cible bool:affichage:vrai
:bool:affichage:vrai:0
	const cx,bool:str:vrai
	callprintfs cx

:bool:affichage:fin:0
	const dx,function:call:end:printTrue
	jmp dx
; Saut à la fin de l'exécution du code de printTrue()
:function:definition:end:printTrue
; Saut à printTrue() pour exécution
	const dx,function:definition:printTrue
	jmp dx
:function:call:end:printTrue
; Ajout du nombre 0
	const ax,0
	push ax
; Code nouvelle variable globale a
	const ax,var:global:val:a
	jmp ax
; Saut à var:global:val

:var:global:a
@int 0

:var:global:val:a
	pop ax
	const bx,var:global:a
	storew ax,bx
:debut:while:1
; Debut évaluation ID (variable globale)
; Recuperation valeur de a et mise en pile
	const bx,var:global:a
	loadw ax,bx
	push ax
; Ajout du nombre 10
	const ax,10
	push ax
; Debut INF (2)
	pop bx
	pop ax
	const cx,inf:vrai:2
; Comparaison de expr1 et expr2
	sless ax,bx
	jmpc cx
; Si (expr1 < expr2) saut à inf:vrai
; Si (expr1 !(<) expr2) code cible inf:faux
; Code cible inf:faux
	const dx,0
	push dx
	const cx,inf:fin:2
	jmp cx

;Saut à inf:fin
; Code cible inf:vrai
:inf:vrai:2
	const dx,1
	push dx
; Code cible inf:fin
:inf:fin:2
; Fin INF
; while No 1
	pop ax
	const bx,0
	const cx,fin:while:1
	cmp ax,bx
	jmpc cx
; Debut évaluation ID (variable globale)
; Recuperation valeur de a et mise en pile
	const bx,var:global:a
	loadw ax,bx
	push ax
; Pour afficher la valeur calculée, qui se trouve normalement en sommet de pile
	cp ax,sp
	callprintfd ax
	pop ax
; Debut évaluation ID (variable globale)
; Recuperation valeur de a et mise en pile
	const bx,var:global:a
	loadw ax,bx
	push ax
; Ajout du nombre 1
	const ax,1
	push ax
; Debut addition
	pop ax
	pop bx
	add bx,ax
	push bx
; Code affectation variable a
	pop ax
	const bx,var:global:a
	storew ax,bx
; fin tour de boucle
	const cx,debut:while:1
	jmp cx
:fin:while:1
	end
; La zone de pile
:pile
@int 0

; Définition Chaine de charactère boolean faux
:bool:str:faux
@string "false"

; Définition Chaine de charactère boolean true
:bool:str:vrai
@string "true"

; Définition chaine de charactère erreur de division par zéro
:err:div0:msg
@string "Erreur: division par 0"

; Code cible erreur de division par zéro
:err:div0
	const ax,err:div0:msg
	callprintfs ax
	end
