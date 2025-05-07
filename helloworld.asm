; Title: helloworld.asm
; Author: Joshua Suit
; Date: 5/4/2025
; Description: prints the phrase "Hello World!"

SECTION .data
msg     db      'Hello World!', 0Ah     ; creates msg variable and assigns the string to it

SECTION .text
global _start

_start:

        mov     edx, 13     ; stores number of bytes to write into, including a byte for 0Ah
        mov     ecx, msg    ; moves the message string's memory address into ecx
        mov     ebx, 1      ; writes the message to the STDOUT file
        mov     eax, 4      ; uses SYS_WRITE by calling opcode 4
        int     80h

        mov     ebx, 0      ; returns the value 0 for exist status to tell it there are 'No Errors'
        mov     eax, 1      ; use SYS_EXIT calling opcode 1
        int     80h