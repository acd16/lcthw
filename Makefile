CFLAGS=-g -Wall
CC=gcc
1.o:
	$(CC) $(CFLAGS) 1.c -o $@
3.o:
	$(CC) $(CFLAGS) 3.c -o $@
6.o:
	$(CC) $(CFLAGS) 6.c -o $@
15.o:15.c
	$(CC) $(CFLAGS) 15.c -o $@
16.o:16.c
	$(CC) $(CFLAGS) 16.c -o $@
17.o:17.c
	$(CC) $(CFLAGS) 17.c -o $@
