target = main
OBJ = main.o
SOURCE = main.c

CC = gcc
CFLAGS = -w -fno-stack-protector  -g  -fsanitize=address

$(target): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<
$(OBJ): $(SOURCE)
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(target) $(OBJ) 
