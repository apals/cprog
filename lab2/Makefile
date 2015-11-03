CC = g++

FLAGS = -std=c++11 -g -Wall -pedantic

main.out: Date.o Gregorian.o Julian.o
		$(CC) $(FLAGS) main.cpp -o main.out

Date.o: Date.cpp
		$(CC) $(FLAGS) -c Date.cpp
Gregorian.o: Gregorian.cpp
		$(CC) $(FLAGS) -c Gregorian.cpp
Julian.o: Julian.cpp
		$(CC) $(FLAGS) -c Julian.cpp

clean:
	rm -f main.out *.o
