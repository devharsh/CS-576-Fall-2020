CC=gcc
LDFLAGS=-no-pie -z execstack
LDFLAGS_SC=-Wl,--omagic
CFLAGS=-fno-stack-protector -z execstack -O1 -U_FORTIFY_SOURCE
#CFLAGS1=-fno-stack-protector -O1 -U_FORTIFY_SOURCE #-fno-unwind-tables -fno-asynchronous-unwind-tables
DEMO_TGTS=so
SC_TGTS=hello64.sc hello-rip64.sc hello32.sc hello-rel32.sc hello-small64.sc hello-nonul64.sc
DEMO_TARGETS32fp=$(addsuffix -32fp, $(DEMO_TGTS))
DEMO_TARGETS32=$(addsuffix -32, $(DEMO_TGTS))
DEMO_TARGETS64fp=$(addsuffix -64fp, $(DEMO_TGTS))
DEMO_TARGETS64=$(addsuffix -64, $(DEMO_TGTS))

all: $(DEMO_TARGETS32) $(DEMO_TARGETS64) $(DEMO_TARGETS32fp) $(DEMO_TARGETS64fp) $(SC_TGTS) $(SC_TGTS:.sc=.bin)

$(DEMO_TARGETS32): %-32: %.c
	$(CC) -m32 -fomit-frame-pointer $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS64): %-64: %.c
	$(CC) -m64 -fomit-frame-pointer $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS32fp): %-32fp: %.c
	$(CC) -m32 $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS64fp): %-64fp: %.c
	$(CC) -m64 $(LDFLAGS) $(CFLAGS) -o $@ $^

%.sc : %.bin
	objcopy -O binary --only-section=.text $< $@

%32.bin: %32.s
	$(CC) -m32 -nostdlib -no-pie $(LDFLAGS_SC) -o $@ $<

%64.bin: %64.s
	$(CC) -m64 -nostdlib -no-pie $(LDFLAGS_SC) -o $@ $<

.PHONY: clean cleanall


clean:
	rm -f $(SC_TGTS) *.sc *.bin *.o
	
cleanall: clean
	rm -f $(DEMO_TARGETS32) $(DEMO_TARGETS64) $(DEMO_TARGETS32fp) $(DEMO_TARGETS64fp)
