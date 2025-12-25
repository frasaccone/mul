include config.mk

OBJS = buffer.o mul.o parse.o
OUT  = mul

.PHONY: all clean install uninstall

all: $(OUT)

clean:
	rm -f $(OBJS) $(OUT)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(OUT) $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(OUT)

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJS):
	$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c)
