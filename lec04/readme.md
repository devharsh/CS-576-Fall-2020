# Lecture 04 files

## Requirements

### remnux VM

You will need to enable that debuggers can attach to already running processes. This can be done by updating the value of `kernel.yama.ptrace_scope` in `/etc/sysctl.d/10-ptrace.conf` to 0 and restarting the VM.

For example, you can edit the file with vim and using sudo:
`sudo vim /etc/sysctl.d/10-ptrace.conf`

## Files

- `so.c`: Echo program suffering a stack overflow.

## Exploitation

Use scripts `run32.sh` and `run64.sh` to execute the vulnerable executables when exploiting outside gdb to ensure defenses are switched off.

## Process layout outside gdb

GDB can alter the layout of the program (stack). To learn its actual addresses, you can run the program at the command line and attach to it wit GDB using the `attach <pid>` command.

