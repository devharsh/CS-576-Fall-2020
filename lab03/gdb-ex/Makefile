CC=gcc
TARGETS=stack-of simple so

all: $(TARGETS) 

stack-of: stack-of.c
	$(CC) -o $@ -fno-stack-protector -z execstack $<

simple: simple.c
	$(CC) -o $@ -fno-stack-protector -g -O0 $<

so: so.c
	$(CC) -o $@ -static -fno-stack-protector -g -O0 $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o
