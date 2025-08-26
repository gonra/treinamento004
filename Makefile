CC = gcc
SRC = exemplo2b.c exemplo2a.c 
OBJ = $(SRC:.c=.o)
EXEC = demo

$(EXEC): $(OBJ)
	$(CC) $(OBJ) –o $(EXEC)

%.o: %.c
	$(CC) –c $< -o $@

clean:
	rm –f $(OBJ) $(EXEC)
