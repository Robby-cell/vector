
CC         =    gcc
CFLAGS     =    
SRCS       =    $(wildcard src/*.c)
OBJS       =    $(SRCS:src/%.c=obj/%.o)
BIN        =    bin/main
DEBUG_FLAGS=    -g

all: ${BIN}


${BIN}: ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^


obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f ${OBJS} ${BIN}

debug: bin/debug


bin/debug:
	$(CC) $(DEBUG_FLAGS) -o $@ $(SRCS)
