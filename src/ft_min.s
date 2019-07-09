section .text
	global _ft_min

_ft_min:
	cmp rdi,rsi
	jge _smaller
	jl _bigger

_bigger:
	mov rax,rdi
	ret

_smaller:
	mov rax,rsi
	ret
