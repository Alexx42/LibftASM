section .text
	global _ft_strcat

_ft_strcat:
	mov rax,rdi
	cmp rdi,0
	je end
	xor rcx,rcx	

length:
	cmp byte [rdi],0
	je concat
	inc rdi
	jmp length

concat:
	cmp byte [rsi], 0
	je zerobyte
	mov r8b, [rsi]
	mov byte [rdi],r8b
	inc rdi
	inc rsi
	jmp concat

zerobyte:
	mov byte [rdi],0

end:
	ret
