CC := gcc
LD := gcc
CFLAGS  := -Wall -Wextra
LDFLAGS := -lm

BINDIR := bin
PROG := $(BINDIR)/6502-emu
SRCS := $(shell find src -name "*.c")
OBJS := $(SRCS:.c=.o)

.PHONY: all
all: $(BINDIR) $(PROG)

$(BINDIR):
	mkdir $(BINDIR)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean cleaner
clean:
	rm -f $(OBJS)
	rm -rf $(PROG)