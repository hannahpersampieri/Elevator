CC=g++
CFLAGS=-std=c++0x -g
SRCS=main.cpp
EXEC=elevator

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

clean: 
	rm elevator *~ 