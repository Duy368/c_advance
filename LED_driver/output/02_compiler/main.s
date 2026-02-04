	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Init failed"
.LC1:
	.string	"Initial buffer:"
.LC2:
	.string	"[%d] = 0x%08X\n"
.LC3:
	.string	"\nAfter setting colors:"
.LC4:
	.string	"Pixel 0 = 0x%08X\n"
.LC5:
	.string	"Pixel 4 = 0x%08X\n"
.LC6:
	.string	"Pixel 9 = 0x%08X\n"
.LC7:
	.string	"\nAfter fill green:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$10, %edi
	call	led_init@PLT
	testl	%eax, %eax
	je	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$0, %eax
	call	led_get_buffer@PLT
	movq	%rax, -8(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -16(%rbp)
	jmp	.L4
.L5:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -16(%rbp)
.L4:
	cmpl	$9, -16(%rbp)
	jle	.L5
	movl	$0, %ecx
	movl	$0, %edx
	movl	$255, %esi
	movl	$0, %edi
	call	led_set_pixel_color@PLT
	movl	$255, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movl	$9, %edi
	call	led_set_pixel_color@PLT
	movl	$255, %ecx
	movl	$255, %edx
	movl	$255, %esi
	movl	$4, %edi
	call	led_set_pixel_color@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	addq	$16, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	addq	$36, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edx
	movl	$255, %esi
	movl	$0, %edi
	call	led_fill@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -12(%rbp)
	jmp	.L6
.L7:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -12(%rbp)
.L6:
	cmpl	$9, -12(%rbp)
	jle	.L7
	movl	$0, %eax
	call	led_shutdown@PLT
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
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
