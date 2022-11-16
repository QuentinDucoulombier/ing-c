CFLAGS := -Wall

exe: pi.o racine2.o main.o
	gcc -Wall pi.o racine2.o main.o -o exe -lm

pi.o: pi.c pi.h
	gcc -c pi.c -o pi.o $(CFLAGS) -lm

racine2.o: racine2.c racine2.h
	gcc -c racine2.c -o racine2.o $(CFLAGS) -lm

main.o: main.c pi.h racine2.h
	gcc -c main.c -o main.o $(CFLAGS)

clean:
	rm -f *.o
	rm -f exe
	@echo "tout a été éffacé"