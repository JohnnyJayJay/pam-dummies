CC = gcc
CFLAGS = -Wall -Wextra -pedantic -fPIC -std=c11
LDFLAGS = -shared

SRC = keystroke.c yesman.c
OBJ = ${SRC:.c=.o}
TARGETS = ${SRC:.c=}

all: $(TARGETS)

keystroke: LDLIBS += -luiohook

%: %.c
	$(CC) -c $(CFLAGS) -o $@.o $^
	$(CC) $(LDFLAGS) $(LDLIBS) $@.o -o pam_$@.so


clean:
	rm -f $(OBJ)
	rm -f pam_*.so
