section .text
	global _ft_toupper

_ft_toupper:
	call _first_condition

_first_condition:
	cmp rdi,141o
	jge _second_condition
	jl _end

_second_condition:
	cmp rdi,172o
	jle _success
	jg _end

_success:
	sub rdi,32

_end:
	mov rax, rdi
	ret
