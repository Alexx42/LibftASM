section .text
	global _ft_tolower

_ft_tolower:
	call _first_condition

_first_condition:
	cmp rdi,101o
	jge _second_condition
	jl _end

_second_condition:
	cmp rdi,132o
	jle _success
	jg _end

_success:
	add rdi,32

_end:
	mov rax, rdi
	ret
