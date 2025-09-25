CC = cc
CFLAGS = -Wall -Werror -std=c11
LDFLAGS = -lcs50

test: test.c
	$(CC) $(CFLAGS) test.c -o test $(LDFLAGS)
