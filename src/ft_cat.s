section .text
	global _ft_cat

_ft_cat:
	enter 0,0

_read_file:
	push rdi
	mov rax,0x2000003
	lea rsi,[rel buff]
	mov rdx,buff_size
	syscall
	jc _end
	cmp rax,0
	jle _end

_write_file:
	mov rdx,rax
	mov rax,0x2000004
	mov rdi,1
	lea rsi,[rel buff]
	syscall

	cmp rax,0
	jl _end
	pop rdi
	jmp _read_file

_end:
	pop rdi
	leave
	ret

section .bss
	buff resb 10
	buff_size equ 10
