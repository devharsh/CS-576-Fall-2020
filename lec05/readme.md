# Lecture 05 files

## Requirements

### Additional tools

Checkout repo https://github.com/JonathanSalwan/ROPgadget for collecting gadgets.


## Files

- `so.c`: Echo program suffering a stack overflow.

## Exploitation

Use scripts `run32.sh` and `run64.sh` to execute the vulnerable executables when exploiting outside gdb to ensure defenses are switched off.

## Process layout outside gdb

GDB can alter the layout of the program (stack). To learn its actual addresses, you can run the program at the command line and attach to it wit GDB using the `attach <pid>` command.


## Radare 2 commands used

Open binary BIN:

`r2 BIN`

Seek to function:

`s main`

Disassemble N instructions:

`pd N`

Seek forward N bytes:

`s+ N`


