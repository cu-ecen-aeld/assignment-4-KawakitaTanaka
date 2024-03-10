CC = gcc
CFLAGS = -g -Wall
TARGET = aesdsocket

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)

