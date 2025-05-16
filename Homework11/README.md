AUTHORING: Joshua Suit UMBC CMSC 313 8:30 Class
PURPOSE OF SOFTWARE: To take bytes and translate them into 2 ascii hex characters and print them
FILES: README.md - to explain the file's contents
       asciiHexPrint.asm - code for printing bytes into 2 ascii hex characters
BUILD INSTRUCTIONS: nasm -f elf32 -g -F dwarf -o asciiHexPrint.o asciiHexPrint.asm
                    ld -m elf_i386 -o asciiHexPrint asciiHexPrint.o
                    ./asciiHexPrint
TESTING METHODOLOGY: The code comes with list of bytes provided in the assignment details to test, so it simply needs to be ran.
ADDITIONAL INFORMATION: Uses the inputBuf and outputBuf from the provided assignment instructions to test the program.