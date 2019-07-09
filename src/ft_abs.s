section .text
	global _ft_abs

_ft_abs:
	test edi,edi
	js _neg
	jmp _end

_neg:
	neg rdi
	mov rax,rdi
	ret

_end:
	mov rax,rdi
	ret
