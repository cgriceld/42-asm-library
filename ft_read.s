; rdi = fd, rsi = buf, rdx = length
; CF (carry flag, control registers), sets to 1 if last system call fails (only for MacOS!)

section .text

extern ___error
global _ft_read

_ft_read:
	mov rax, 0x2000003	; read syscall id - 0x2000003
	syscall				; read syscall, use call id from rax and write return value to rax
	jc end				; jump short if CF = 1, then rax = errno
	ret					; if ok, return rax (rax = num of read bytes)

end:
	push rax			; push to stack errno value
	call ___error		; rax containts int * to errno variable
	pop qword [rax]		; pop value to variable to which rax points (pop r12 / mov [rax], r12)
	mov rax, -1
	ret

; 	section	.text
; 	;ssize_t ft_read(int fildes, void *buf, size_t nbyte);
; 	global	_ft_read
; 	extern	___error
; _ft_read:
; 	push	rbp			; realign rsp
; 	mov	rax, 0x2000003		; read syscall
; 	syscall
; 	jnc	.done			; syscall errors set CF flag

; 	push	rax			; save errno value + align rsp
; 	call	___error		; get errno variable location
; 	pop	rdx			; restore errno value to rdx
; 	mov	dword [rax], edx	; set errno value
; 	xor	rax, rax
; 	dec	rax			; set rax to -1 to indicate an error
; .done:
; 	pop	rbp
; 	ret