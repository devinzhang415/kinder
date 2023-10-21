TARGET = kinder
LIBS =
CC = g++
# CFLAGS = -O3 -w
CFLAGS = -g -Wall

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)

default: $(TARGET)
all: default

OBJECTS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(CFLAGS) -o $@

clean:
	-rm -f $(TARGET)