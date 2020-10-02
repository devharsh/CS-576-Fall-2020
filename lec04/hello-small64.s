# ----------------------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
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
	xor	%eax, %eax
	inc	%eax			# system call 1 is write
	mov	%eax, %edi 		# file handle 1 is stdout
	lea	message(%rip), %rsi
	incb	message+11(%rip)
	xor	%edx, %edx
	mov	$12, %dl		# number of bytes
        syscall                         # invoke operating system to do the write

        # exit(0)
	xor	%eax, %eax
	mov	$60, %al
        xor     %edi, %edi              # we want return code 0
        syscall                         # invoke operating system to exit
message:
        .ascii  "Hello world\x09"
