section .text
	global _ft_memcpy

_ft_memcpy:
	push rdi
	mov rcx,rdx
	cld
	repne movsb

_end:
	pop rax
	ret
