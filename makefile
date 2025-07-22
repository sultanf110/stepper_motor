CC = gcc
CFLAGS = -g -Wall -O0 -std=c99
LDFLAGS = -lm

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)
TARGET = demo

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) core
