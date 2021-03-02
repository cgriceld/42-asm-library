; rdi = s1, rsi = s2

global _ft_strcmp

section .text:

_ft_strcmp:
	xor rcx, rcx			; i = 0
	jmp comp

comp:
	mov	al, [rsi + rcx]		; get char from s2
	cmp al, [rdi + rcx]		; comp with char from s1
	jne end					; if equal, ZF = 1, if not, end
	inc rcx					; i++
	test al, al				; al & al, ZF is set if al = 0
	je end					; end, if ZF = 1
	jmp comp				; if al != 0, continue loop

end:
	movzx eax, al
	movzx ecx, byte [rdi + rcx]
	sub eax, ecx
	ret

; we must return int, but compare chars