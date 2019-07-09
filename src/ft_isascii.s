section .text
	global _ft_isascii

_ft_isascii:
	call _first_condition

_first_condition:
	cmp rdi,0
	jge _second_condition
	jl _false

_second_condition:
	cmp rdi,177o
	jg _false
	jle _true

_true:
	mov rax,1
	ret
_false:
	mov rax,0
	ret
