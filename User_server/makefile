CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lpcap
SOURCES=*.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=IPcure

all: $(SOURCES) $(EXECUTABLE) clean
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o

