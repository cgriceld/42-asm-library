; rdi = fd, rsi = s, rdx = length
; CF (carry flag, control registers), sets to 1 if last system call fails (only for MacOS!)

section .text

extern ___error
global _ft_write

_ft_write:
	mov rax, 0x2000004	; write syscall - 0x2000004
	syscall				; write syscall, use call id from rax and write return value to rax
	jc end				; jump short if CF = 1, then rax = errno
	ret					; if ok, return rax (rax = num of written bytes)

end:
	push rax			; push to stack errno value
	call ___error		; rax containts int * to errno variable
	pop qword [rax]		; pop value to variable to which rax points (pop r8 / mov [rax], r8)
	mov rax, -1
	ret