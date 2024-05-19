
CC = gcc

CFLAGS = -Wall -Wextra -pedantic

LIBS = -lm

SRCS = q2.c

OBJS = $(SRCS:.c=.o)

EXEC = poisson

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
