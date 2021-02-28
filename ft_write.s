; rdi = fd, rsi = s, rdx = length
; CF (carry flag, control registers), sets to 1 if last system call fails (only for MacOS!)

WRITE_SYS equ 0x2000004

extern ___error
global _ft_write

section .text:

_ft_write:
	xor rax, rax		; clear rax
	mov rax, WRITE_SYS	; mov rax, 0x2000004
	syscall				; write syscall, use call id from rax and write return value to rax
	jc end				; jump short if CF = 1, then rax = errno
	ret					; if ok, return rax (rax = num of written bytes)

end:
	push rax			; push to stack errno value
	call ___error		; rax containts int * to errno variable
	pop qword [rax]		; pop value to variable to which rax points (pop r12 / mov [rax], r12)
	mov rax, -1
	ret