; rdi = s
; for malloc, rdi = size

section .text

extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy
global _ft_strdup

_ft_strdup:
	push rdi			; save ptr to s
	call _ft_strlen		; rax = length
	mov rdi, rax		; copy to rdi, malloc uses rdi as size
	inc rdi				; for \0
	call _malloc		; rax = ptr to new string
	test rax, rax		; if NULL, then ZF = 1
	je end				; then return (NULL)
	mov rdi, rax		; copy new ptr to rdi, dst for strcpy
	pop rsi				; pop rdi to rsi, src for strcpy
	call _ft_strcpy		; rax = ptr to new string
	ret

end:
	ret