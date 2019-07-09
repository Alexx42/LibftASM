section .text
	global _ft_abs

_ft_abs:
	cmp edi,0
	jl _neg
	jge _end

_neg:
	neg rdi
	mov rax,rdi
	ret

_end:
	mov rax,rdi
	ret
