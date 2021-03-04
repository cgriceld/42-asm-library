; rdi = dst, rsi = src
; returns ptr to dst

section .text

global _ft_strcpy

_ft_strcpy:
	push rdi			; save dst start
	jmp copy

copy:
	lodsb				; copy 1 byte from rsi to al
	stosb				; save 1 byte from al to rdi
	test al, al			; al & al, ZF is set if al = 0 (\0)
	je end				; then end
	jmp copy			; otherwise continue

end:
	pop rax
	ret