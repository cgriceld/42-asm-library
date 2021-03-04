; rdi = s1, rsi = s2

section .text

global _ft_strcmp

_ft_strcmp:
	mov rcx, -1				; i = -1
	jmp comp

comp:
	inc rcx					; i++
	mov	al, [rdi + rcx]		; get char from s2
	cmp al, [rsi + rcx]		; comp with char from s1
	jne end					; if equal, ZF = 1, if not, end
	test al, al				; al & al, ZF is set if al = 0
	je end					; end, if ZF = 1
	jmp comp				; if al != 0, continue loop

end:
	movzx eax, al
	movzx ecx, byte [rsi + rcx]
	sub eax, ecx
	ret

; we must return int, but compare chars