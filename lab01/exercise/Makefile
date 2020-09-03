CC=gcc
TARGETS=ex ex-sp

all: $(TARGETS)

ex: ex.c

ex-sp: ex.c
	$(CC) -o $@ -g -fomit-frame-pointer $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o                        
