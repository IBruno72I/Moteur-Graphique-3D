FLAGS=-w -Werror -Wall -g
SDL_CFLAGS=`sdl2-config --cflags --libs`

all: exec

exec: main.o window.o
	gcc -o exec main.o window.o $(SDL_CFLAGS) $(FLAGS)
	
main.o : main.c window.h
	gcc -o main.o -c main.c $(SDL_CFLAGS) $(FLAGS)

window.o : window.c window.h
	gcc -o window.o -c window.c

clean:
	rm -f *.o

mrproper: clean
	rm -f exec