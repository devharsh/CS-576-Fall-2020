CC=gcc
LDFLAGS=-no-pie
CFLAGS=-fstack-protector -O1 -U_FORTIFY_SOURCE -Wno-format-security -Wno-format
CFLAGS_FS=-fstack-protector -O1 -Wno-format-security
DEMO_TGTS=so so2 heap heap2 heap3 formatstr
DEMO_TARGETS64_FS=$(addsuffix -64fs, $(DEMO_TGTS))
DEMO_TARGETS64=$(addsuffix -64, $(DEMO_TGTS))


all: $(DEMO_TARGETS32) $(DEMO_TARGETS64) $(DEMO_TARGETS32_FS) $(DEMO_TARGETS64_FS) 

$(DEMO_TARGETS64): %-64: %.c
	$(CC) -m64 $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS64_FS): %-64fs: %.c
	$(CC) -m64 $(LDFLAGS) $(CFLAGS_FS) -o $@ $^

.PHONY: clean cleanall

clean:
	rm -f *.o

cleanall: clean
	rm -f $(DEMO_TARGETS64) $(DEMO_TARGETS64_FS)
