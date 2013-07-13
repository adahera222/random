.data
_1: .long 1
.data
___Temporary_1: .long 0
LC0: .ascii "%d\12\0"
.data
_a: .long 1
.data
_b: .long 4
.text
.def _fun; .scl 2; .type 32; .endef
_fun:
pushl %ebp
movl %esp, %ebp
movl _a, %eax
popl %ebp
ret
.def ___main; .scl 2; .type 32; .endef
.section .rdata,"dr"
.text
.def _main; .scl 2; .type 32; .endef
_main:
pushl %ebp
movl %esp, %ebp
andl $-16, %esp
subl $48, %esp
call ___main
movl _1, %eax
movl %eax, 0(%esp)
movl _1, %eax
movl %eax, 4(%esp)
movl _1, %eax
movl %eax, 8(%esp)
movl _1, %eax
movl %eax, 12(%esp)
movl _1, %eax
movl %eax, 16(%esp)
movl _1, %eax
movl %eax, 20(%esp)
movl _1, %eax
movl %eax, 24(%esp)
movl _1, %eax
movl %eax, 28(%esp)
movl _1, %eax
movl %eax, 32(%esp)
movl _1, %eax
movl %eax, 36(%esp)
call _fun
movl %eax, ___Temporary_1
movl ___Temporary_1, %eax
movl %eax, _a
movl _a, %eax
movl %eax, 0(%esp)
movl _a, %eax
movl %eax, 4(%esp)
movl $LC0, (%esp)
call _printf
leave
ret
