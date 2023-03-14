CC = gcc
CFLAGS = -Wall -Wextra -pedantic -fPIC -std=c11
LDFLAGS = -shared

TARGETS = keystroke yesman delayed
OBJ = $(addsuffix .o,$(TARGETS))
SRC = $(addsuffix .c,$(TARGETS))
LIBS = $(addprefix pam_,$(addsuffix .so,$(TARGETS)))

all: $(LIBS)

pam_keystroke.so: LDLIBS += -luiohook

pam_%.so: %.o
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(TARGETS):
	$(MAKE) pam_$@.so

install: all
	cp -v -t /usr/lib/security $(LIBS)
	@echo PAM Dummies installed to /usr/lib/security

uninstall:
	rm -vf $(addprefix /usr/lib/security/,$(LIBS))
	@echo PAM Dummies successfully uninstalled

.PHONY : clean

clean:
	$(RM) $(OBJ)
	$(RM) $(LIBS)
