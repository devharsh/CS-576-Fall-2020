CC=gcc
CXX=g++
CFLAGS=-no-pie -O0 -fno-stack-protector -U_FORTIFY_SOURCE
CXXFLAGS=-O0
DEMO_TGTS=heap uninitialized
DEMO_TGTS_MARCH=
DEMO_TGTS_32=$(addsuffix -32, $(DEMO_TGTS_MARCH))
DEMO_TGTS_64=$(addsuffix -64, $(DEMO_TGTS_MARCH))
DEMO_CPP=virtual

all: $(DEMO_TGTS_32) $(DEMO_TGTS_64) $(DEMO_PIE) $(DEMO_FS) $(DEMO_CPP) $(DEMO_TGTS)

$(DEMO_TGTS_32): %-32: %.c
	$(CC) -m32 $(CFLAGS) -U_FORTIFY_SOURCE -o $@ $^

$(DEMO_FS): %-fs: %.c
	$(CC) -m32 $(CFLAGS) -o $@ $^

$(DEMO_TGTS_64): %-64: %.c
	$(CC) -m64 -no-pie $(CFLAGS) -U_FORTIFY_SOURCE -o $@ $^

$(DEMO_TGTS): %: %.c
	$(CC) $(CFLAGS) -o $@ $^

$(DEMO_CPP): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^


.PHONY: clean cleanall

clean:
	rm -f *.o $(DEMO_TGTS) $(DEMO_PIE) $(DEMO_FS) $(DEMO_CPP) $(DEMO_TGTS)


cleanall: clean
	rm -f $(DEMO_TGTS_64) $(DEMO_TGTS_32)
