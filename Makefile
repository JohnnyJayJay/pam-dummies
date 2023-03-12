CC = gcc
CFLAGS = -Wall -Wextra -pedantic -fPIC -std=c11
LDFLAGS = -shared

SRC = keystroke.c yesman.c
OBJ = ${SRC:.c=.o}
TARGETS = ${SRC:.c=}
LIBS = $(addprefix pam_,${SRC:.c=.so})

all: $(LIBS)

pam_keystroke.so: LDLIBS += -luiohook

pam_%.so: %.o
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

%:
	$(MAKE) pam_$@.so


install: all
	sudo cp -v -t /usr/lib/security $(LIBS)
	@echo PAM Dummies installed to /usr/lib/security

uninstall:
	sudo rm -vf $(addprefix /usr/lib/security/,$(LIBS))
	@echo PAM Dummies successfully uninstalled

.PHONY : clean

clean:
	$(RM) $(OBJ)
	$(RM) $(LIBS)
