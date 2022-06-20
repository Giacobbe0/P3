FLAGS= -Wall -pedantic -std=c++14 -iquote inc

___start__: program
	./program
program:si.o wynik.o plansza.o main.cpp
	g++ -o program si.o wynik.o plansza.o main.cpp

si.o:si.cpp
	g++ -c ${FLAGS}  si.cpp
	
wynik.o:wynik.cpp
	g++ -c ${FLAGS}  wynik.cpp

plansza.o:plansza.cpp
	g++ -c ${FLAGS}  plansza.cpp

clean:
	rm -f si.o wynik.o plansza.o program
