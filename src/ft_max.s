section .text
	global _ft_max

_ft_max:
	cmp rdi,rsi
	jge _bigger
	jl _smaller

_bigger:
	mov rax,rdi
	ret

_smaller:
	mov rax,rsi
	ret

