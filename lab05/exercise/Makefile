CC=gcc
LDFLAGS=-no-pie -static -z execstack
LDFLAGS_SC=-Wl,--omagic
CFLAGS=-fno-stack-protector -O1 -U_FORTIFY_SOURCE
CFLAGSSP=-fstack-protector -O1 -U_FORTIFY_SOURCE
CFLAGSSPFORT=-fstack-protector -O1
#CFLAGS1=-fno-stack-protector -O1 -U_FORTIFY_SOURCE #-fno-unwind-tables -fno-asynchronous-unwind-tables
DEMO_TGTS=so
SC_TGTS=hello-nonul64.sc
DEMO_TARGETS32=$(addsuffix -32, $(DEMO_TGTS))


all: $(DEMO_TARGETS32)

$(DEMO_TARGETS32): %-32: %.c
	$(CC) -m32 -fomit-frame-pointer $(LDFLAGS) $(CFLAGS) -o $@ $^

.PHONY: clean cleanall


clean:
	rm -f $(SC_TGTS) *.sc *.bin *.o
	
cleanall: clean
	rm -f $(DEMO_TARGETS32) $(DEMO_TARGETS64) $(DEMO_TARGETS32fp) $(DEMO_TARGETS64fp)
