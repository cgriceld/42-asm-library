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
	test al, al			; al & al, ZF is set if al = 0
	je end				; then end
	jmp copy			; otherwise continue

end:
	pop rax
	ret

; _ft_strcpy:
; 	xor rcx, rcx				; clear iterator
; 	jmp copy

; copy:
; 	cmp byte [rsi + rcx], 0		; while (*src)
; 	je end						; jump if equal
; 	mov dl, [rsi + rcx]
; 	mov [rdi + rcx], dl			;
; 	inc rcx						; src++
; 	jmp copy					; next iter

; end:
; 	mov byte [rdi + rcx], 0		; null-terminating
; 	mov rax, rdi				; save dst ptr to rax
; 	ret