CFLAGS := -Wall

all: exe

exe: pi.o racine2.o main.o
	gcc $(CFLAGS) pi.o racine2.o main.o -o exe -lm

pi.o: pi.c pi.h
	gcc -c pi.c -o pi.o $(CFLAGS) -lm

racine2.o: racine2.c racine2.h
	gcc -c racine2.c -o racine2.o $(CFLAGS) -lm

main.o: main.c pi.h racine2.h
	gcc -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f exe
	rm -rf html
	rm -rf latex
	@echo "tout a été éffacé"