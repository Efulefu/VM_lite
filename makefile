CC = gcc # compiler to use

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}
	@echo "Compilation terminated"
	
%: %.o
	@echo "Checking..."
	${CC} -v $< -o $@
	
%.o: %.c
	@echo "Creating object..."
	${CC} -v -c $<

clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}