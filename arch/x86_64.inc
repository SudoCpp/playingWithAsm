use64

macro SCall0 callNumber
{
    mov RSysCall, callNumber
    kernCall
}

macro SCall1 callNumber, arg0
{
    mov RSysCall, callNumber
    mov RArg0, arg0
    kernCall
}

macro SCall2 callNumber, arg0, arg1
{
    mov RSysCall, callNumber
    mov RArg0, arg0
    mov RArg1, arg1
    kernCall
}

macro SCall3 callNumber, arg0, arg1, arg2
{
    mov RSysCall, callNumber
    mov RArg0, arg0
    mov RArg1, arg1
    mov RArg2, arg2
    kernCall
}

RSysCall equ rax
RReturn equ rax
RArg0 equ rdi
RArg1 equ rsi
RArg2 equ rdx
RArg3 equ r10
RArg4 equ r8
RArg5 equ r9

kernCall equ syscall

SC_exit equ 0x3c
SC_read equ 0x0
SC_write equ 0x1
SC_open equ 0x2
SC_close equ 0x3
SC_brk equ 0x0c