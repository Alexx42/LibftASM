section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	enter 0,0	
	call _ft_isalpha
	cmp rax,1
	je _end

_test:
	call _ft_isdigit

_end:
	leave
	ret
