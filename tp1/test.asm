; Calculette
	const ax,program:debut
	jmp ax
:program:debut
; Préparation de la pile
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; Saut à fin définition printTrue()
	const dx,fun:def:fin:printTrue
	jmp dx
:fun:def:printTrue
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
; Saut à la fin de l'exécution du code de printTrue()
:fun:def:fin:printTrue
; Saut à la défintion de printTrue() pour exécution
	const dx,fun:def:printTrue
	jmp dx

:fun:def:finprintTrue	pop
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
