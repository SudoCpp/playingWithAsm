macro writeConsole pointerAddress, strSize
{
    SCall3 SC_write, 1, pointerAddress, strSize ;1 is std out
}

endl equ 0xA

macro readConsole bufferAddress, bufferSize
{
    SCall3 SC_read, 1, bufferAddress, bufferSize ;1 is std out
}