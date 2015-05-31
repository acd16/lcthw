CFLAGS='-Wall'
CC='gcc'
1.o:
	$(CC) $(CFLAGS) 1.c -o $@
3.o:
	$(CC) $(CFLAGS) 3.c -o $@
6.o:
	$(CC) $(CFLAGS) 6.c -o $@
