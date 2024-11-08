	.global main
main:
	movl $0, %eax
	cmpl $0, %eax
	mov $0, %eax
	sete %al
	ret
