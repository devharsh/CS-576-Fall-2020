CC=gcc
LDFLAGS=-no-pie -static
LDFLAGS_SC=-Wl,--omagic
CFLAGS=-fno-stack-protector -O1 -U_FORTIFY_SOURCE
CFLAGSSP=-fstack-protector -O1 -U_FORTIFY_SOURCE
CFLAGSSPFORT=-fstack-protector -O1
#CFLAGS1=-fno-stack-protector -O1 -U_FORTIFY_SOURCE #-fno-unwind-tables -fno-asynchronous-unwind-tables
DEMO_TGTS=so
SC_TGTS=hello-nonul64.sc
DEMO_TARGETS32fp=$(addsuffix -32fp, $(DEMO_TGTS))
DEMO_TARGETS32=$(addsuffix -32, $(DEMO_TGTS))
DEMO_TARGETS64fp=$(addsuffix -64fp, $(DEMO_TGTS))
DEMO_TARGETS64=$(addsuffix -64, $(DEMO_TGTS))
DEMO_TARGETS64sp=$(addsuffix -64sp, $(DEMO_TGTS)) so2-64sp
DEMO_TARGETS64spfort=so2-64spfort


all: $(DEMO_TARGETS32) $(DEMO_TARGETS64) $(DEMO_TARGETS32fp) $(DEMO_TARGETS64fp) $(DEMO_TARGETS64sp) $(SC_TGTS) $(DEMO_TARGETS64spfort) $(SC_TGTS:.sc=.bin)

$(DEMO_TARGETS32): %-32: %.c
	$(CC) -m32 -fomit-frame-pointer $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS64): %-64: %.c
	$(CC) -m64 -fomit-frame-pointer $(LDFLAGS) $(CFLAGS) -o $@ $^

$(DEMO_TARGETS64sp): %-64sp: %.c
	$(CC) -m64 -fomit-frame-pointer $(LDFLAGS) $(CFLAGSSP) -o $@ $^

$(DEMO_TARGETS64spfort): %-64spfort: %.c
	$(CC) -m64 -fomit-frame-pointer $(LDFLAGS) $(CFLAGSSPFORT) -o $@ $^

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
