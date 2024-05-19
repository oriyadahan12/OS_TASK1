CC=gcc
CFLAGS=-Wall -g --coverage
TARGET=q5
TARGET2=q5main

all: $(TARGET2)

$(TARGET2): $(TARGET).o $(TARGET2).o
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET).o $(TARGET2).o

$(TARGET).o: $(TARGET).c $(TARGET).h
	$(CC) $(CFLAGS) -c $(TARGET).c

$(TARGET2).o: $(TARGET).c $(TARGET2).c
	$(CC) $(CFLAGS) -c $(TARGET2).c

clean:
	rm -f $(TARGET) $(TARGET).o $(TARGET).gcda $(TARGET).gcno $(TARGET).gcov $(TARGET2) $(TARGET2).o $(TARGET2).gcda $(TARGET2).gcno $(TARGET2).gcov

gcov: $(TARGET2)
	./$(TARGET2) < input.txt
	gcov $(TARGET).c $(TARGET2).c


