CC = gcc
SRC = main.c pizza_entity.c pizza_repo.c
OBJ = $(SRC:.c=.o)
EXEC = pizzaria

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ) -lsqlite3

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
