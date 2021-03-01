; rdi = s1, rsi = s2

global _ft_strcmp

section .text:

_ft_strcmp:
	xor rcx, rcx
	jmp comp

comp:
	mov	al, [rsi + rcx]
	cmp al, [rdi + rcx]
	jne end

end:
	  