# makefile

all: pokimac clean exec


pokimac: main.o f_map.o f_dialogs.o f_fight.o f_interactions.o f_menus.o f_pokedex.o
	g++ -o pokimac main.o f_map.o f_dialogs.o f_fight.o f_interactions.o f_menus.o f_pokedex.o -Wall

main.o: main.cpp main.h
	g++ -o main.o -c main.cpp -Wall -ansi

f_menus.o: f_menus.cpp main.h
	g++ -o f_menus.o -c f_menus.cpp -Wall -ansi

f_fight.o: f_fight.cpp main.h
	g++ -o f_fight.o -c f_fight.cpp -Wall -ansi

f_interactions.o: f_interactions.cpp main.h
	g++ -o f_interactions.o -c f_interactions.cpp -Wall -ansi

f_dialogs.o: f_dialogs.cpp main.h
	g++ -o f_dialogs.o -c f_dialogs.cpp -Wall -ansi

f_map.o: f_map.cpp main.h
	g++ -o f_map.o -c f_map.cpp -Wall -ansi

f_pokedex.o: f_pokedex.cpp main.h
	g++ -o f_pokedex.o -c f_pokedex.cpp -Wall -ansi



%.o: %.cpp
	g++ -o $@ -c $<

clean:
	rm *.o

exec:
	./pokimac

	


