; rdi = s

global _ft_strlen

section .text:

_ft_strlen:
	mov rax, rdi		; put rax at the string's start
	jmp length			; start while

length:
	cmp byte [rax], 0	; while (*rax)
	je end				; jump if equal, then ZF = 1
	inc rax				; rax++
	jmp length			; next iter

end:
	sub rax, rdi		; rax - rdi, save to rax
	ret

; xor al, al
; repne scasb ; stops when ZF is set
; sub rdi, rax
; mov rax, rdi
; ret