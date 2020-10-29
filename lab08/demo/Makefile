CC=gcc
CXX=g++
CFLAGS=-no-pie -O0 -fno-stack-protector -U_FORTIFY_SOURCE
CXXFLAGS=-O0
DEMO_TGTS=uaf
DEMO_TGTS_MARCH=
DEMO_TGTS_32=$(addsuffix -32, $(DEMO_TGTS_MARCH))
DEMO_TGTS_64=$(addsuffix -64, $(DEMO_TGTS_MARCH))
DEMO_CPP=virtual

all: $(DEMO_TGTS)

$(DEMO_TGTS): %: %.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean cleanall

clean:
	rm -f *.o $(DEMO_TGTS)


cleanall: clean
	rm -f $(DEMO_TGTS)
