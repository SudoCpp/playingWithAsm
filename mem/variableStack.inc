include 'syntax/types.inc'
include 'mem/heap.inc'

match x, _VARIABLESTACK_INC
{
    define _VARIABLESTACK_INC

    segment readable writeable

    StackBase int32 0
    TopOfStack int32 0
}

macro initStack
{
    malloc 1000, StackBase
    mov RArg0, [StackBase]
    mov [TopOfStack], RArg0
}

macro salloc sizeInBytes, pointerAddress
{
    mov RArg0, [TopOfStack]
    mov [pointerAddress], RArg0
    add [TopOfStack], sizeInBytes
    mov RArg0, [TopOfStack]
    mov [RArg0], dword sizeInBytes
    add [TopOfStack], 4
}