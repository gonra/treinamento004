CC = gcc
SRC = main.c pizza_entity.c pizza_repo.c pizza_service.c
OBJ = $(SRC:.c=.o)
EXEC = pizzaria

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
