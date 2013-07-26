.data
_5: .long 5
.data
___Temporary_1: .long 0
.data
_10: .long 10
.data
_m: .long 0
LC0: .string "%d\n"
.data
___Temporary_3: .long 0
.data
___Temporary_4: .long 0
.data
_a: .long 0
.data
_b: .long 0
.data
.comm _v, 36
.data
_x: .long 1
.data
_i: .long 97
.text
.globl main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
andl $-16, %esp
subl $12, %esp
movl _5, %eax
movl %eax, 0(%esp)
call f
movl %eax, ___Temporary_1
movl ___Temporary_1, %eax
movl %eax, _a
leave
ret
.text
.globl f
.type f, @function
f:
pushl %ebp
movl %esp, %ebp
movl 8(%ebp), %eax
movl _10, %edx
cmpl %edx, %eax
jge __Label_1__
movl _m, %eax
movl %eax, 4(%esp)
movl 8(%ebp), %eax
movl %eax, 4(%esp)
movl $LC0, (%esp)
call printf
movl ___Temporary_3, %eax
movl %eax, 0(%esp)
call f
movl %eax, ___Temporary_4
movl ___Temporary_4, %eax
movl %eax, _a
__Label_1__:
popl %ebp
ret
