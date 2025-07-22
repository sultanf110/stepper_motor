CC = gcc
CFLAGS = -g -Wall -O0 -std=c99
LDFLAGS = -lm

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = demo

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	@rm -f $(TARGET) $(OBJECTS) core