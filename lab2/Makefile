CC = g++

FLAGS = -std=c++11 -g -Wall -pedantic

main.out: Date.o Gregorian.o Julian.o Main.o calendar.o
		$(CC) $(FLAGS) main.o Date.o Gregorian.o Julian.o calendar.o -o main.out

#main.out: main.cpp Date.cpp Gregorian.cpp Julian.cpp
#	$(CC) $(FLAGS) main.cpp Date.cpp Gregorian.cpp Julian.cpp -o main
Main.o: Main.cpp
		$(CC) $(FLAGS) -c main.cpp
Date.o: Date.cpp
		$(CC) $(FLAGS) -c Date.cpp
Gregorian.o: Gregorian.cpp
		$(CC) $(FLAGS) -c Gregorian.cpp
Julian.o: Julian.cpp
		$(CC) $(FLAGS) -c Julian.cpp
calendar.o: calendar.hpp
		$(CC) $(FLAGS) -c calendar.hpp -o calendar.o

clean:
	rm -f main.out *.o
