CC=gcc
CFLAGS=-W -Wall -Wextra -Wunreachable-code -Wwrite-strings
LDFLAGS=-lm -lSDL -lGL -lGLU
EXEC=boid

all: $(EXEC)

boid: main.o modele.o affichage.o boid.o vecteur.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)