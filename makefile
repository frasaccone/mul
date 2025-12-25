include config.mk

MAIN = main.o
OBJS = mul.o
BIN  = mul
INC  = mul.h
LIB  = libmul.a

.PHONY: all clean install uninstall

all: $(BIN) $(LIB)

clean:
	rm -f $(MAIN) $(OBJS) $(BIN) $(LIB)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin \
	         $(DESTDIR)$(PREFIX)/include \
	         $(DESTDIR)$(PREFIX)/lib \
	cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin
	cp -f $(INC) $(DESTDIR)$(PREFIX)/include
	cp -f $(LIB) $(DESTDIR)$(PREFIX)/lib

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(OUT)
	cp -f $(DESTDIR)$(PREFIX)/include/$(INC)
	cp -f $(DESTDIR)$(PREFIX)/lib/$(LIB)

$(BIN): $(MAIN) $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIB): $(OBJS)
	$(AR) -cr $@ $^

$(MAIN) $(OBJS):
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c)
