CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=add-nbo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=add-nbo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

