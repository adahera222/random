.data
_1: .long 1
.data
___Temporary_2: .long 0
.data
___Temporary_3: .long 0
.data
_0: .long 0
LC0: .ascii "%d\12\0"
.data
_a: .long 1
.data
_b: .long 4
.def ___main; .scl 2; .type 32; .endef
.section .rdata,"dr"
.text
.def _main; .scl 2; .type 32; .endef
_main:
pushl %ebp
movl %esp, %ebp
andl $-16, %esp
subl $16, %esp
call ___main
jmp __Label_2__
__Label_1__:
movl _a, %edx
movl _1, %eax
addl %eax, %edx
movl %edx, ___Temporary_2
movl ___Temporary_2, %eax
movl %eax, _a
movl _b, %edx
movl _1, %eax
subl %eax, %edx
movl %edx, ___Temporary_3
movl ___Temporary_3, %eax
movl %eax, _b
__Label_2__:
movl _b, %eax
movl _0, %edx
cmpl %eax, %edx
jl __Label_1__
movl _a, %eax
movl %eax, 4(%esp)
movl $LC0, (%esp)
call _printf
leave
ret
