; Title: asciiHexPrint.asm
; Author: Joshua Suit
; Date: 5/14/2025
; Description: takes bytes and translate them into 2 ascii hex characters and then prints them

SECTION .data
inputBuf  db 0x83, 0x6A, 0x88, 0xDE, 0x9A, 0xC3, 0x54, 0x9A ; creates inputBuf of provided variables of assignment
bufLength equ 8 ; creates variable for the inputbuf length and sets it to 8
hexList   db "0123456789ABCDEF" ; creates list of all hex characters

SECTION .bss
outputBuf resb 80 

SECTION .text

global _start

_start:

    mov esi, 0 ; register set to zero as index for inputBuf
    mov edi, 0 ; register set to zero as index for outputBuf
    call inputBuf_loop

    dec edi ; removes the extra space at the end
    mov byte [outputBuf + edi], 0xA ; replaces space with line break
    inc edi

    mov eax, 4 ; calls sys_write using opcode 4
    mov ebx, 1 ; calls stdout
    mov ecx, outputBuf ; loads outputBuf to ecx to use ascii characters
    mov edx, edi ; sets up edx to print the total length 
    int 0x80

     mov     eax, 1     ; returns the value 0 for exist status to tell it there are 'No Errors'
     mov     ebx, 0     ; calls SYS_EXIT calling opcode 1
     int     80h

inputBuf_loop: 
    cmp esi, bufLength ; compare if register reached max length of buffer
    jge .finish

    movzx eax, byte [inputBuf + esi] ; load in byte from the current index 

    mov ebx, eax ; copy the current byte and put it in ebx
    shr ebx, 4 ; shift 4 bits right to get only first character
    mov bl, [hexList + ebx] ; translates index value to ascii 
    mov [outputBuf + edi], bl ; stores ascii into the output buffer
    inc edi

    and eax, 0x0F ; mask keeping only the second character
    mov al, [hexList + eax] ; translates index value to ascii
    mov [outputBuf + edi], al ; stores ascii into the output buffer
    inc edi

    mov byte [outputBuf + edi], ' ' ; adds a space between ever 2 hex characters
    inc edi

    inc esi
    jmp inputBuf_loop

.finish:
    ret