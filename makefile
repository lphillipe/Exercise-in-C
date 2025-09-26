CC = cc
CFLAGS = -Wall -Werror -std=c11
LDFLAGS = -lcs50

# Regra padrão: compilar qualquer arquivo .c para um executável
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

