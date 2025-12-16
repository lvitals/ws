#
# Makefile for ws editor (C version)
#

all: ws

UNAME = uname -s
OS = $(UNAME:sh)$(shell $(UNAME))
CFLAGS_EXTRA = -D$(OS)

SRC = ws.c wsbuf.c termx.c keyx.c
OBJ = $(SRC:.c=.o)

ws: $(OBJ)
	$(CC) $(OBJ) -lcurses -o $@

clean:
	rm -f *.o ws

# ----------------- Standard Rules ------------------

.SUFFIXES: .c

CFLAGS = -g -Wall -O2 $(CFLAGS_EXTRA)

CC = gcc
LD = ld
RM = rm -f

%.o: %.c
	@ $(RM) $@
	$(CC) $(CFLAGS) -c $<
