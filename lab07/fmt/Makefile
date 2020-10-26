CC=gcc
CXX=g++
CFLAGS=-O1 -Wno-format-security -Wno-format 
CXXFLAGS=-O0
DEMO_TGTS_MARCH=fmt_examples fmt_victim
DEMO_TGTS_32=$(addsuffix -32, $(DEMO_TGTS_MARCH))
DEMO_TGTS_64=$(addsuffix -64, $(DEMO_TGTS_MARCH))

all: $(DEMO_TGTS_32) $(DEMO_TGTS_64)

$(DEMO_TGTS_32): %-32: %.c
	$(CC) -m32 -no-pie $(CFLAGS) -U_FORTIFY_SOURCE -o $@ $^

$(DEMO_TGTS_64): %-64: %.c
	$(CC) -m64 -no-pie $(CFLAGS) -U_FORTIFY_SOURCE -o $@ $^

.PHONY: clean

clean:
	rm -f *.o $(DEMO_TGTS_64) $(DEMO_TGTS_32)

