
CC         =    gcc
CFLAGS     =    
SRCS       =    $(wildcard src/*.c)
OBJS       =    $(SRCS:src/%.c=obj/%.o)
BIN        =    bin/main

all: ${BIN}


${BIN}: ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^


obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

