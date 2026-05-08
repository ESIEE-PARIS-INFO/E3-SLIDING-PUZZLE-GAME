CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lMLV -lm
OBJ=taquin.o main.o

taquin: $(OBJ)
	$(CC) $(CFLAGS) -o taquin $(OBJ) $(LDFLAGS)

main.o: main.c taquin.h
	$(CC) -c main.c $(CFLAGS)

taquin.o: taquin.c taquin.h
	$(CC) -c taquin.c $(CFLAGS)

.PHONY: clean
clean: 
	rm -f *.o
	rm -f *~
	rm -f taquin
