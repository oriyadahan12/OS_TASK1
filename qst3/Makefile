CC = gcc
CFLAGS = -fPIC -Wall -Wextra -pedantic

LDFLAGS = -lm

TARGET_LIB = libpoisson.so
TARGET_EXEC = main

SRCS_LIB = q2.c
SRCS_EXEC = q2main.c

HEADERS = q2.h

OBJS_LIB = $(SRCS_LIB:.c=.o)
OBJS_EXEC = $(SRCS_EXEC:.c=.o)

all: $(TARGET_LIB) $(TARGET_EXEC)

$(TARGET_LIB): $(OBJS_LIB)
	$(CC) -shared -o $@ $^ $(LDFLAGS)

$(TARGET_EXEC): $(OBJS_EXEC) $(TARGET_LIB)
	$(CC) -o $@ $(OBJS_EXEC) -L. -lpoisson $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS_LIB) $(OBJS_EXEC) $(TARGET_LIB) $(TARGET_EXEC)

.PHONY: all clean
