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

RSysCall equ x8
RReturn equ x0
RArg0 equ x0
RArg1 equ x1
RArg2 equ x2
RArg3 equ x3
RArg4 equ x4
RArg5 equ x5

kernCall equ syscall

SC_exit equ 0x5d ;RArg0 errorCode
SC_read equ 0x3f
SC_write equ 040
;SC_open equ 0x5
SC_close equ 0x39
SC_brk equ 0xd6