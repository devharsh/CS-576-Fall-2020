CC=gcc
CFLAGS0=-fno-stack-protector -z execstack -O0 -g
TARGETS=buffers

all: $(TARGETS) 

buffers: buffers.c
	$(CC) -o $@ $(CFLAGS0) $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o
