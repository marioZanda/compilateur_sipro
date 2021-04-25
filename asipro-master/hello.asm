;Premier programme

	const ax,debut
	jmp ax

:chaine
@string "Hello World"

:debut
	const ax,chaine
	callprintfs ax
	end
