CC := gcc
LD := gcc
CFLAGS  := -Wall -Wextra -Werror
LDFLAGS := -lm

PROG := bin/6502-emu
SRCS := $(shell find src -name "*.c")
OBJS := $(SRCS:.c=.o)

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean cleaner
clean:
	rm -f $(OBJS)
	rm -rf $(PROG)