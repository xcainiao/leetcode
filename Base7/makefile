target = main
OBJ = main.o
SOURCE = main.c

CC = gcc
CFLAGS = -lm -w -fno-stack-protector

$(target): $(OBJ)
	$(CC) -o $@ $< $(CFLAGS) 
$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) -c $< 
clean:
	rm -f $(target) $(OBJ) 
