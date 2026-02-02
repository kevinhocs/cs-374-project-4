CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: lswc redirout

lswc: lswc.c
	$(CC) $(CFLAGS) -o lswc lswc.c

redirout: redirout.c
	$(CC) $(CFLAGS) -o redirout redirout.c

clean:
	rm -f lswc redirout