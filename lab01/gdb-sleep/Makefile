CC=gcc
TARGETS=sleeper sleeper-sp

all: $(TARGETS)

sleeper: sleeper.c

sleeper-sp: sleeper.c
	$(CC) -o $@ -g -fomit-frame-pointer $<

.PHONY: clean


clean:
	rm -f $(TARGETS) *.o                        
