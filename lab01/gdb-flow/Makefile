CC=gcc
TARGETS=find_me find_me-sp find_me-dbg find_me-strip

all: $(TARGETS) 

find_me-strip: find_me.c
	$(CC) -o $@ -g -s $<

find_me-dbg: find_me.c
	$(CC) -o $@ -g $<

find_me: find_me.c

find_me-sp: find_me.c
	$(CC) -o $@ -g -fomit-frame-pointer $<


.PHONY: clean


clean:
	rm -f $(TARGETS) *.o
