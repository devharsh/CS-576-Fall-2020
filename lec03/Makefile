CC=gcc
LDFLAGS=-no-pie -z execstack
CFLAGS0=-fno-stack-protector -z execstack -O0 -fno-unwind-tables -fno-asynchronous-unwind-tables -U_FORTIFY_SOURCE
CFLAGS1=-fno-stack-protector -z execstack -O1 -fno-unwind-tables -fno-asynchronous-unwind-tables -U_FORTIFY_SOURCE
DEMO_TGTS=simple_call simple_insns so
DEMO_TARGETS32=$(addsuffix -32fp, $(DEMO_TGTS)) $(addsuffix -32, $(DEMO_TGTS))
DEMO_TARGETS64=$(addsuffix -64fp, $(DEMO_TGTS)) $(addsuffix -64, $(DEMO_TGTS))

all: $(DEMO_TARGETS32) $(DEMO_TARGETS64)

$(DEMO_TARGETS32): %: %.s
	$(CC) -m32 $(LDFLAGS) -o $@ $^

%-32fp.s: %.c
	$(CC) -m32 $(CFLAGS1) -S -o $@ $<

%-32.s: %.c
	$(CC) -m32 -fomit-frame-pointer $(CFLAGS1) -S -o $@ $<

$(DEMO_TARGETS64): %: %.s
	$(CC) -m64 $(LDFLAGS) -o $@ $^

%-64fp.s: %.c
	$(CC) -m64 $(CFLAGS1) -S -o $@ $<

%-64.s: %.c
	$(CC) -m64 -fomit-frame-pointer $(CFLAGS1) -S -o $@ $<

.PHONY: clean cleanall


clean:
	rm -f *.o $(DEMO_TARGETS32) $(DEMO_TARGETS64) *.s *.o
