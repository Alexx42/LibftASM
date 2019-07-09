section .text
	global _ft_memalloc
	extern _malloc
	extern _ft_bzero

_ft_memalloc:
	enter 10,0
	push rdi
	call _malloc
	cmp rax,0
	je _end

	pop rdi
	mov r8, rax
	mov rsi,rdi
	mov rdi,rax
	call _ft_bzero
	mov rax, r8

_end:
	leave
	ret
