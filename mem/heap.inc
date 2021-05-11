include 'syntax/types.inc'

match x, _HEAP_INC
{
    define _HEAP_INC

    segment readable writeable

    heap_start int32 0
    heap_current int32 0
}

macro initHeap
{
    SCall1 SC_brk, 0 ;invalid address so current heap position returned
    mov [heap_start], RReturn
    mov [heap_current], RReturn
}

macro deinitHeap
{
    SCall1 SC_brk, [heap_start] ;move heap back to start position
}

macro heapAlloc sizeToIncrease
{
    mov RSysCall, SC_brk
    mov RArg0, [heap_current]
    add RArg0, sizeToIncrease
    kernCall
    mov [heap_current], RReturn
}

macro malloc sizeInBytes, variableAddress
{
    heapAlloc sizeInBytes
    mov [variableAddress], RReturn
}