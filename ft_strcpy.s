; rdi = dst, rsi = src
; returns ptr to dst

global _ft_strcpy

section .text:

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

; call _ft_strlen
; mov rcx, rax
; rep movsb
; 



; _ft_strcpy:
; 	xor rcx, rcx				; clear iterator
; 	jmp copy

; copy:
; 	cmp [rsi + rcx], byte 0		; while (*src)
; 	je end						; jump if equal
; 	mov dl, [rsi + rcx]
; 	mov [rdi + rcx], dl			;
; 	inc rcx						; src++
; 	jmp copy					; next iter

; end:
; 	mov [rdi + rcx], byte 0		; null-terminating
; 	mov rax, rdi				; save dst ptr to rax
; 	ret