format ELF executable
include 'arch/x86.inc'

include 'io/console.inc'
include 'mem/heap.inc'
include 'syntax/types.inc'
include 'mem/variableStack.inc'

segment readable executable

struc twoStrings first,last
{
    .first char first
    .last char last
}

entry start    ; in the original file this was located before the segment. You should put it here instead

start:
    initHeap
    initStack

    salloc 10, bufferAddress
    ;readConsole [bufferAddress], 10
    ;writeConsole [bufferAddress], 10
    
    readConsole structTest.first, 10
    readConsole structTest.last, 10
    writeConsole structTest.first, 10
    writeConsole structTest.last, 10
    
    
    deinitHeap
    SCall1 SC_exit, 0
        

segment readable writeable ; basically .bbs

bufferAddress int32 0
structTest twoStrings '          ', '          '