	.file	"led_driver.c"
	.text
	.local	led_buffer
	.comm	led_buffer,8,8
	.local	led_count
	.comm	led_count,8,8
	.globl	led_init
	.type	led_init, @function
led_init:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	-8(%rbp), %rax
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, led_buffer(%rip)
	movq	led_buffer(%rip), %rax
	testq	%rax, %rax
	jne	.L4
	movl	$-1, %eax
	jmp	.L3
.L4:
	movq	-8(%rbp), %rax
	movq	%rax, led_count(%rip)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,4), %rdx
	movq	led_buffer(%rip), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	led_init, .-led_init
	.globl	led_shutdown
	.type	led_shutdown, @function
led_shutdown:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	led_buffer(%rip), %rax
	testq	%rax, %rax
	je	.L7
	movq	led_buffer(%rip), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	$0, led_buffer(%rip)
	movq	$0, led_count(%rip)
.L7:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	led_shutdown, .-led_shutdown
	.globl	led_set_pixel_color
	.type	led_set_pixel_color, @function
led_set_pixel_color:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%ecx, %eax
	movl	%esi, %ecx
	movb	%cl, -28(%rbp)
	movb	%dl, -32(%rbp)
	movb	%al, -36(%rbp)
	movq	led_buffer(%rip), %rax
	testq	%rax, %rax
	je	.L12
	movq	led_count(%rip), %rax
	cmpq	%rax, -24(%rbp)
	jnb	.L13
	movl	$0, -4(%rbp)
	movzbl	-32(%rbp), %eax
	sall	$16, %eax
	orl	%eax, -4(%rbp)
	movzbl	-28(%rbp), %eax
	sall	$8, %eax
	orl	%eax, -4(%rbp)
	movzbl	-36(%rbp), %eax
	orl	%eax, -4(%rbp)
	movq	led_buffer(%rip), %rax
	movq	-24(%rbp), %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	jmp	.L8
.L12:
	nop
	jmp	.L8
.L13:
	nop
.L8:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	led_set_pixel_color, .-led_set_pixel_color
	.globl	led_fill
	.type	led_fill, @function
led_fill:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%esi, %ecx
	movl	%edx, %eax
	movl	%edi, %edx
	movb	%dl, -20(%rbp)
	movl	%ecx, %edx
	movb	%dl, -24(%rbp)
	movb	%al, -28(%rbp)
	movq	led_buffer(%rip), %rax
	testq	%rax, %rax
	je	.L19
	movl	$0, -12(%rbp)
	movzbl	-24(%rbp), %eax
	sall	$16, %eax
	orl	%eax, -12(%rbp)
	movzbl	-20(%rbp), %eax
	sall	$8, %eax
	orl	%eax, -12(%rbp)
	movzbl	-28(%rbp), %eax
	orl	%eax, -12(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L17
.L18:
	movq	led_buffer(%rip), %rax
	movq	-8(%rbp), %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, (%rdx)
	addq	$1, -8(%rbp)
.L17:
	movq	led_count(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L18
	jmp	.L14
.L19:
	nop
.L14:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	led_fill, .-led_fill
	.globl	led_clear
	.type	led_clear, @function
led_clear:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	led_fill
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	led_clear, .-led_clear
	.globl	led_get_buffer
	.type	led_get_buffer, @function
led_get_buffer:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	led_buffer(%rip), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	led_get_buffer, .-led_get_buffer
	.globl	led_get_pixel_count
	.type	led_get_pixel_count, @function
led_get_pixel_count:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	led_count(%rip), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	led_get_pixel_count, .-led_get_pixel_count
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
