CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

all: add2PB findPhone 

add2PB: add2PB.o 
$(CC) $(CFLAGS) -o add2PB add2PB.o 

findPhone: findPhone.o 
$(CC) $(CFLAGS) -o findPhone findPhone.o 

add2PB.o: add2PB.c 
$(CC) $(CFLAGS) -c add2PB.c 

findPhone.o: findPhone.c
 $(CC) $(CFLAGS) -c findPhone.c
 
  clean: rm -f *.o add2PB findPhone