CFLAGS_V=-fno-stack-protector -O0 -z execstack -no-pie#-mpreferred-stack-boundary=2 
CFLAGS=-O2 -Wall 
VULN=stack_overflow
CC=gcc

all: $(TARGETS) $(VULN)

stack_overflow: stack_overflow.c
	$(CC) $(CFLAGS_V) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) *.o

clean-all:
	make clean
	rm -f  $(VULN)
