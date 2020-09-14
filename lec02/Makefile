CC=gcc
CFLAGS0=-no-pie -fno-stack-protector -z execstack -O0
TARGETS=buffers
ALL_TARGETS=$(TARGETS) $(addsuffix -dbg, $(TARGETS)) $(addsuffix -stripped, $(TARGETS))

all: $(ALL_TARGETS)

%-dbg: %.c
	$(CC) -o $@ $(CFLAGS0) -g $<

%: %.c
	$(CC) -o $@ $(CFLAGS0)  $<

%-stripped: %
	strip -o $@ $<

.PHONY: clean


clean:
	rm -f *.o

cleanall:
	rm -f $(ALL_TARGETS) *.o
