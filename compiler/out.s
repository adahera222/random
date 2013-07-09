.data
_1: .long 1
.data
_0: .long 0
.data
_2: .long 2
.data
___Temporary_1: .long 0
LC0: .ascii "%d\12\0"
.data
_a: .long 1
.data
_b: .long 4
.data
.comm _v, 8
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
movl _1, %eax
movl %eax, _v+0
movl _2, %eax
movl %eax, _v+4
movl _v+4, %eax
movl %eax, ___Temporary_1
movl ___Temporary_1, %eax
movl %eax, 4(%esp)
movl $LC0, (%esp)
call _printf
leave
ret
