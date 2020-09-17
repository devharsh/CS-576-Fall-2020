CC=gcc
LDFLAGS=-no-pie
CFLAGS0=-fno-stack-protector -z execstack -O0
CFLAGS00=-fno-stack-protector -O0
TARGETS=buffers
BIN_TARGETS=$(TARGETS) $(addsuffix -dbg, $(TARGETS)) $(addsuffix -stripped, $(TARGETS))
DEMO_TARGETS=simple_func

all: $(BIN_TARGETS) $(DEMO_TARGETS)

%-dbg: %.c
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS0) -g $<

%: %.c
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS0)  $<

%-stripped: %
	strip -o $@ $<

simple_func: simple_func.s
	clang $(LDFLAGS) -o $@ $^

%.s: %.bc
	clang -S $<

%.bc: %.c
	clang  $(CFLAGS00) -c -emit-llvm $<
	llvm-dis $(<:.c=.bc)


.PHONY: clean cleanall


clean:
	rm -f *.o $(DEMO_TARGETS) *.bc *.ll *.s

cleanall:
	rm -f $(BIN_TARGETS) *.o
