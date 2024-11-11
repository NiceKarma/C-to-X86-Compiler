	.global main
main:
	mov $1, %rax
	push %rax
	mov $22, %rax
	push %rax
	mov $6, %rax
	push %rax
	mov $1, %rax
	pop %rcx
	add %rcx, %rax
	pop %rcx
	push %rax
	push %rcx
	pop %rax
	pop %rcx
	mov $0, %rdx
	idiv %rcx
	pop %rcx
	add %rcx, %rax
	ret
