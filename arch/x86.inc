use32

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

RSysCall equ eax
RReturn equ eax
RArg0 equ ebx
RArg1 equ ecx
RArg2 equ edx
RArg3 equ esi
RArg4 equ edi
RArg5 equ edp

kernCall equ int 0x80

SC_exit equ 0x01
SC_read equ 0x03
SC_write equ 0x4
SC_open equ 0x5
SC_close equ 0x6
SC_brk equ 0x2d