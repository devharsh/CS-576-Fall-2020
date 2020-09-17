CC=gcc
TARGETS=ex

all: $(TARGETS)

ex: ex.c
	$(CC) -o $@ -g -fomit-frame-pointer $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o                        
