section .text
	global _ft_puts

_ft_puts:
	mov r8,rdi
	cmp r8,0
	je _null
	xor rcx,rcx

_len:
	cmp byte [rdi + rcx],0
	je _putstr
	inc rcx
	jmp _len

_putstr:
	mov rax,0x2000004
	mov rdi,1
	lea rsi,[rel r8]
	mov rdx,rcx
	syscall
	cmp rax,-1
	je _failure

_newline:
	mov rax,0x2000004
	mov rdi,1
	lea rsi,[rel nl]
	mov rdx,1
	syscall
	cmp rax,-1
	je _failure
	jne _success

_null:
	mov rax,0x2000004
	mov rdi,1
	lea rsi,[rel msg]
	mov rdx,msg_end - msg
	syscall
	cmp rax, -1
	je _failure

_success:
	mov rax,10
	ret

_failure:
	mov rax,0
	ret

section .data
	msg db "(null)", 0xa, 0x0
	msg_end db 0x0
	nl db 0xa
