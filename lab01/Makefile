UNAME_S := $(shell uname -s)
CC=g++
LD=g++
CFLAGS=-g -Wall
LDFLAGS=

BIT_OPS_OBJS = bit_ops.o test_bit_ops.o
BIT_OPS_PROG = bit_ops

LFSR_OBJS = lfsr.o test_lfsr.o
LFSR_PROG = lfsr

BINARIES=$(VECTOR_PROG) $(BIT_OPS_PROG) $(LFSR_PROG)

all: $(BINARIES)

$(BIT_OPS_PROG): $(BIT_OPS_OBJS)
	$(CC) $(CFLAGS) -g -o $(BIT_OPS_PROG) $(BIT_OPS_OBJS) $(LDFLAGS)

$(LFSR_PROG): $(LFSR_OBJS)
	$(CC) $(CFLAGS) -g -o $(LFSR_PROG) $(LFSR_OBJS) $(LDFLAGS)

lfsr.cpp: lfsr.h
test_lfsr.cpp: lfsr.h

bit_ops.cpp: bit_ops.h
test_bit_ops.cpp: bit_ops.h

.cpp.o:
	$(CC) -c $(CFLAGS) $<

launch:
	./$(BIT_OPS_PROG) ./$(LFSR_PROG)
1:
	./speciality
2:
	cat gdb.txt
4:
	./no_segfault_ex | ./segfault_ex
5:
	./test_ll_cycle
6:
	cat make.txt
7:
	./$(BIT_OPS_PROG)
8:
	./$(LFSR_PROG)

clean:
	-rm -rf core *.o *~ "#"*"#" Makefile.bak $(BINARIES) *.dSYM

