FLAGS=-w -Werror -Wall -g -lm
SDL_CFLAGS=`sdl2-config --cflags --libs`

all: exec

exec: main.o window.o events.o maths.o
	gcc -o exec main.o window.o events.o maths.o $(SDL_CFLAGS) $(FLAGS)
	
main.o : main.c window.h events.h maths.h
	gcc -o main.o -c main.c $(SDL_CFLAGS) $(FLAGS)

window.o : window.c window.h
	gcc -o window.o -c window.c

events.o : events.c events.h
	gcc -o events.o -c events.c

maths.o : maths.c maths.h
	gcc -o maths.o -c maths.c

clean:
	rm -f *.o

mrproper: clean
	rm -f exec