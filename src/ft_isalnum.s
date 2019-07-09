section .text
	global _ft_isalnum

_ft_isalnum:
	call _first_digit
	
	
_first_digit:
	cmp rdi,60o
	jge _second_digit
	jl _false

_second_digit:
	cmp rdi,71o
	jle _true
	jg _first_alpha

_first_alpha:
	cmp rdi, 101o
	jl _false
	jge _second_alpha

_second_alpha:
	cmp rdi,172o
	jg _false
	jle _true

_true:
	mov rax,1
	ret
_false:	
	mov rax,0
	ret
