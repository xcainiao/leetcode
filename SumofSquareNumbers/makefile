target = main
OBJ = main.o
SOURCE = main.c

CC = gcc
CFLAGS = -w -fno-stack-protector -lm

$(target): $(OBJ)
	$(CC) -o $@ $< $(CFLAGS) 
$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(target) $(OBJ) 
