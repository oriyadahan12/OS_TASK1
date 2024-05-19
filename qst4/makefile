CC=gcc
CFLAGS=-Wall -g --coverage
TARGET=q4

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	rm -f $(TARGET) $(TARGET).o $(TARGET).gcda $(TARGET).gcno $(TARGET).gcov

gcov: $(TARGET)
	./$(TARGET) < input.txt
	gcov $(TARGET).c
