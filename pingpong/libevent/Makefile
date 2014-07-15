CFLAGS+=-g -Wall -O2
LDFLAGS=-levent_core -Wl,--rpath -Wl,/usr/local/lib

BINARIES=client server bench server-line-echo

#all: client server bench server-line-echo
all:$(BINARIES)

$(BINARIES):
	gcc -o $@ $^ $(LDFLAGS)

client:client.c
server:server.c
bench:bench.c
server-line-echo:server-line-echo.c


clean:
	rm -f $(BINARIES)
	#rm -f client server bench server-line-echo

.PHONY: all clean

