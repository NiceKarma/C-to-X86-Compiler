	.file	"main.c"
# GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# main.c:4:         int a = 0;
	movl	$0, -12(%rbp)	#, a
# main.c:5:         int b = 2;
	movl	$2, -8(%rbp)	#, b
# main.c:6:         int c = 3;
	movl	$3, -4(%rbp)	#, c
# main.c:8:         a = b + c;
	movl	-8(%rbp), %edx	# b, tmp88
	movl	-4(%rbp), %eax	# c, tmp89
	addl	%edx, %eax	# tmp88, tmp87
	movl	%eax, -12(%rbp)	# tmp87, a
# main.c:10:         return a;
	movl	-12(%rbp), %eax	# a, _5
# main.c:11: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
