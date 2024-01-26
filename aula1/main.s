	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d - pessoa\12\0"
LC1:
	.ascii "%d - short_inteiro\12\0"
LC2:
	.ascii "%d - interio_muito_grande\12\0"
LC3:
	.ascii "%d - decimal\12\0"
LC4:
	.ascii "%d - muito_decimal\12\0"
LC5:
	.ascii "%d - letra\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$24, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$2, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$8, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$8, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$1, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
