FLAGS = -pedantic-errors -std=c++11

menu.o: menu.cpp menu.h
	g++ $(FLAGS) -c $<

board.o: board.cpp board.h
	g++ $(FLAGS) -c $<
	
player.o: player.cpp player.h
	g++ $(FLAGS) -c $<

main.o: main.cpp
	g++ $(FLAGS) -c $<

main: menu.o board.o player.o main.o
	g++ $(FLAGS) $^ -o $@
	
clean:
	rm -f calc *.o

tar:
	tar -czvf calc.tgz *.cpp *.h

.PHONY: clean tar