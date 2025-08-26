CC = gcc
SRC = exemplo2b.c exemplo2a.c
OBJ = $(SRC:.c=.o)
EXEC = demo

$(EXEC): $(OBJ)
        $(CC) -o $@ $(OBJ)

%.o: %.c
        $(CC) -c -o $@ $<

clean:
        rm $(OBJ) $(EXEC)
