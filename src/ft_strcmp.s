section .text
	global _ft_strcmp

_ft_strcmp:
	push rbx
	xor rax,rax
	xor rbx,rbx

_loop:
	mov al, byte [rdi]
	cmp al,0
	je _success
	mov bl, byte [rsi]
	cmp bl,0
	je _success
	inc rdi
	inc rsi
	cmp al,bl
	jne _mismatch
	je _loop


_mismatch:
	sub eax,ebx
	pop rbx
	ret

_success:
	mov rax,0
	pop rbx
	ret
