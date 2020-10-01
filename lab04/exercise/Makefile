CC=gcc
TARGETS=ex

all: $(TARGETS)

ex: ex.c
	$(CC) -o $@ -static -fno-stack-protector -g -O0 -no-pie $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o                        
