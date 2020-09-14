CC=gcc
CFLAGS0=-no-pie -fno-stack-protector -fomit-frame-pointer -z execstack -O0 -g
TARGETS=buffers

all: $(TARGETS) 

buffers: buffers.c
	$(CC) -o $@ $(CFLAGS0) $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o
