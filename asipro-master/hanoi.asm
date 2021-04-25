; Les tours de Hanoi, en recursif
; Nicolas Bedon

	const ax,debut
	jmp ax

:chaineA
@string "A"
:chaineB
@string "B"
:chaineC
@string "C"
:chaine1
@string "Je d�place "
:chaine2
@string " vers "
:chaine3
@string "\n"

:hanoi
	push sp
	push bp
	push ax
	push bx
	push cx
	push dx
; R�cup�ration des arguments
	cp dx,sp
	const cx,14
	sub dx,cx
; On met dans ax le nombre de disques
	loadw ax,dx
	const cx,2
	sub dx,cx
; On met dans bx l'adresse du poteau source
	loadw bx,dx
	sub dx,cx
	push bp
	cp bp,cx
; On met dans cx l'adresse du poteau destination
	loadw cx,dx
	sub dx,bp
	pop bp
; On met dans dx l'adresse du poteau temporaire
	loadw dx,dx
; Les arguments sont r�cup�r�s, c'est parti
; V�rification du cas de base
	push dx
	push cx
	const cx,casDeBase
	const dx,1
	cmp ax,dx
	jmpc cx
	const dx,casGeneral
	jmp dx
:casDeBase
	pop cx
	pop dx
	const dx,chaine1
	callprintfs dx
	callprintfs bx
	const dx,chaine2
	callprintfs dx
	callprintfs cx
	const dx,chaine3
	callprintfs dx
	const dx,fin
	jmp dx
:casGeneral
	pop cx
	pop dx
; Premier appel r�cursif
	push cx
	push dx
	push bx
	push bx
	const bx,1
	sub ax,bx
	pop bx
	push ax
	const ax,hanoi
	call ax
	pop ax
	pop bx
	pop dx
	pop cx
; Second appel r�cursif, avec 1 comme nombre de disques
	push dx
	push cx
	push bx
	const bx,1
	push bx
	const bx,hanoi
	call bx
	pop bx
	pop bx
	pop cx
	pop dx
; Troisi�me appel r�cursif
	push bx
	push cx
	push dx
	push ax
	const ax,hanoi
	call ax
	pop ax
	pop dx
	pop cx
	pop bx
:fin
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	pop sp
	ret

; Le main
:debut
	const bp,pile
	const sp,pile
	const ax,2
	sub sp,ax
; On va d�placer de A vers C en passant par B
	const dx,chaineB
	const cx,chaineC
	const bx,chaineA
; On va d�placer 3 anneaux
	const ax,3
	push dx
	push cx
	push bx
	push ax
	const ax,hanoi
	call ax
	pop ax
	pop bx
	pop cx
	pop dx
	end

; La zone de pile
:pile
@int 0
