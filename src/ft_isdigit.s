section .text
	global _ft_isdigit

_ft_isdigit:
	call _first_condition

_first_condition:
	cmp rdi,60o
	jge _second_condition
	jl _false

_second_condition:
	cmp rdi,71o
	jg _false
	jle _true

_true:
	mov rax,1
	ret
_false:
	mov rax,0
	ret
