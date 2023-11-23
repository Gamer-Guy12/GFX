NAME:=GFX
CC:=gcc
CFLAGS:=-c -Isrc/include -Iinclude
LIBS=
LIBPATH=-Llibs
LD:=gcc
LDFLAGS= -o bin/$(NAME) 
SOURCES=$(wildcard src/*.c)
OBJS:=$(patsubst src/%.c, bin/int/%.o, $(SOURCES))

.PHONY: clean build run all init

all: init build

init:
	git submodule init

build: $(OBJS)
	$(LD) $(LDFLAGS) $(LIBPATH) $(LIBS) $(OBJS)

bin/int/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o bin/int/$*.o

clean:
	rm -r bin
	mkdir -p bin/int
	
run:
	./bin/$(NAME)
