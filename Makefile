FLAGS=-w -Werror -Wall -g
SDL_CFLAGS=`sdl2-config --cflags --libs`

all: exec

exec: main.o 
	gcc -o exec main.o $(SDL_CFLAGS) $(FLAGS)
	
main.o : main.c
	gcc -o main.o -c main.c $(SDL_CFLAGS) $(FLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f exec