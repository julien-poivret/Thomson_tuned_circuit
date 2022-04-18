## Makefile Poivret Julien 04-18-22.
CC=gcc
SRC=main.c
OBJ=out
FLAG=-std=c11 -D_GNU_SOURCE -O3 -Wall -lm  
$(OBJ):$(SRC)
	@($(CC) $(SRC) -o $(OBJ) $(FLAG)) && strip $(OBJ) && ./$(OBJ)	
	@(echo "Compilation done.")
.PHONY:clean
clean:
	@(rm $(OBJ))
	@(echo "Binary removed.")
