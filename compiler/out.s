.data
_1: .long 1
.data
___Temporary_2: .long 0
.data
___Temporary_3: .long 0
.data
___Temporary_4: .long 0
.data
___Temporary_5: .long 0
.data
_0: .long 0
.data
___Temporary_6: .long 0
.data
___Temporary_7: .long 0
.data
___Temporary_8: .long 0
.data
___Temporary_9: .long 0
.data
___Temporary_10: .long 0
.data
_3: .long 3
.data
___Temporary_11: .long 0
.data
___Temporary_12: .long 0
.data
_2: .long 2
.data
___Temporary_13: .long 0
.data
_5: .long 5
.data
___Temporary_14: .long 0
.data
___Temporary_15: .long 0
.data
___Temporary_16: .long 0
.data
___Temporary_17: .long 0
.data
___Temporary_18: .long 0
.data
___Temporary_19: .long 0
.data
___Temporary_20: .long 0
LC0: .ascii "%d\12\0"
LC1: .ascii "%d\12\0"
.data
_a: .long 1
.data
_b: .long 4
.data
.comm _v, 16
.text
.def _fun; .scl 2; .type 32; .endef
_fun:
pushl %ebp
movl %esp, %ebp
jmp __Label_2__
__Label_1__:
movl 8(%ebp), %edx
movl _1, %eax
addl %eax, %edx
movl %edx, ___Temporary_2
movl ___Temporary_2, %eax
movl %eax, 8(%ebp)
movl 12(%ebp), %edx
movl _1, %eax
subl %eax, %edx
movl %edx, ___Temporary_3
movl ___Temporary_3, %eax
movl %eax, 12(%ebp)
movl 16(%ebp), %edx
movl _1, %eax
subl %eax, %edx
movl %edx, ___Temporary_4
movl ___Temporary_4, %eax
movl %eax, 16(%ebp)
movl 20(%ebp), %edx
movl _1, %eax
subl %eax, %edx
movl %edx, ___Temporary_5
movl ___Temporary_5, %eax
movl %eax, 20(%ebp)
__Label_2__:
movl 20(%ebp), %eax
movl _0, %edx
cmpl %eax, %edx
jl __Label_1__
movl 8(%ebp), %edx
movl 12(%ebp), %eax
addl %eax, %edx
movl %edx, ___Temporary_6
movl ___Temporary_6, %edx
movl 16(%ebp), %eax
addl %eax, %edx
movl %edx, ___Temporary_7
movl ___Temporary_7, %eax
popl %ebp
ret
.text
.def _fun2; .scl 2; .type 32; .endef
_fun2:
pushl %ebp
movl %esp, %ebp
movl 8(%ebp), %eax
movl %eax, _v+0
movl 12(%ebp), %eax
movl %eax, _v+4
movl _v+0, %eax
movl %eax, ___Temporary_8
movl _v+4, %eax
movl %eax, ___Temporary_9
movl ___Temporary_8, %edx
movl ___Temporary_9, %eax
addl %eax, %edx
movl %edx, ___Temporary_10
movl ___Temporary_10, %eax
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
movl _b, %edx
movl _3, %eax
imull %eax, %edx
movl %edx, ___Temporary_11
movl ___Temporary_11, %edx
movl _1, %eax
addl %eax, %edx
movl %edx, ___Temporary_12
movl ___Temporary_12, %edx
movl _2, %eax
addl %eax, %edx
movl %edx, ___Temporary_13
movl _1, %eax
movl %eax, 0(%esp)
movl _b, %eax
movl %eax, 4(%esp)
movl _5, %eax
movl %eax, 8(%esp)
movl _5, %eax
movl %eax, 12(%esp)
call _fun
movl %eax, ___Temporary_14
movl ___Temporary_13, %edx
movl ___Temporary_14, %eax
subl %eax, %edx
movl %edx, ___Temporary_15
movl ___Temporary_15, %eax
movl %eax, _a
movl _1, %edx
movl _2, %eax
addl %eax, %edx
movl %edx, ___Temporary_16
movl _1, %eax
movl %eax, 0(%esp)
movl _3, %eax
movl %eax, 4(%esp)
call _fun2
movl %eax, ___Temporary_17
movl ___Temporary_16, %edx
movl ___Temporary_17, %eax
addl %eax, %edx
movl %edx, ___Temporary_18
movl ___Temporary_18, %eax
movl %eax, _b
movl _v+0, %eax
movl %eax, ___Temporary_19
movl _b, %edx
movl ___Temporary_19, %eax
addl %eax, %edx
movl %edx, ___Temporary_20
movl ___Temporary_20, %eax
movl %eax, _b
movl _a, %eax
movl %eax, 0(%esp)
movl _a, %eax
movl %eax, 4(%esp)
movl $LC0, (%esp)
call _printf
movl _b, %eax
movl %eax, 4(%esp)
movl _b, %eax
movl %eax, 4(%esp)
movl $LC1, (%esp)
call _printf
leave
ret
