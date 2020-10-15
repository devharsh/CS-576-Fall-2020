# ----------------------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls. Runs on 32-bit Linux only.
# To assemble and run:
#
#     gcc -c hello.s && ld hello.o && ./a.out
#
# or
#
#     gcc -nostdlib hello.s && ./a.out
# ----------------------------------------------------------------------------------------

        .global _start

        .text
_start:
        # write(1, message, 11)
        mov     $4, %eax                # system call 1 is write
        mov     $1, %ebx                # file handle 1 is stdout
	jmp	load_message
message_loaded:
	pop	%ecx
        mov     $11, %edx               # number of bytes
        int	$0x80                   # invoke operating system to do the write

        # exit(0)
	mov	$1, %eax
        xor     %ebx, %ebx              # we want return code 0
        int	$0x80                   # invoke operating system to exit
load_message:
	call message_loaded
        .ascii  "Hello world"
