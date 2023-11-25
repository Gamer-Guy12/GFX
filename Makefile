NAME:=GFX
CC:=gcc
CFLAGS:=-c -Isrc/include -Iinclude
LIBS=-lglfw3 -lcglm -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm
LIBPATH=libs
LD:=gcc
LDFLAGS=-o bin/$(NAME) 
DEBUGFLAGS=-Wall
SOURCES=$(wildcard src/*.c)
OBJS:=$(patsubst src/%.c, bin/int/%.o, $(SOURCES))

.PHONY: clean build run rebuild

rebuild: clean build

build: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -L$(LIBPATH) $(LIBS) $(DEBUGFLAGS)

bin/int/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o bin/int/$*.o $(DEBUGFLAGS)

clean:
	rm -r bin
	mkdir -p bin/int
	cp $(LIBPATH)/*.so bin
	
run:
	./bin/$(NAME)
