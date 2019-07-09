section .text
	global _ft_strlen


_ft_strlen:
	sub rcx,rcx
	not rcx ; rcx to -1
	sub al,al ;set value to 0
	cld
	repne scasb
	neg rcx
	sub rcx,2

_end:
	mov rax,rcx
	ret
