	.file	"asm.c"
	.globl	_a
	.data
	.align 4
_a:
	.long	1
	.globl	_b
	.align 4
_b:
	.long	4
	.text
	.globl	_fun
	.def	_fun;	.scl	2;	.type	32;	.endef
_fun:
LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	20(%ebp), %eax
	movl	16(%ebp), %edx
	addl	%edx, %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE6:
	.globl	_fun2
	.def	_fun2;	.scl	2;	.type	32;	.endef
_fun2:
LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
LFE7:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB8:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	_b, %eax
	movl	$7, 36(%esp)
	movl	$6, 32(%esp)
	movl	$5, 28(%esp)
	movl	$4, 24(%esp)
	movl	$3, 20(%esp)
	movl	$2, 16(%esp)
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	_fun
	movl	%eax, _a
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	_fun2
	movl	%eax, _b
	movl	_a, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	_b, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8:
	.def	_printf;	.scl	2;	.type	32;	.endef
