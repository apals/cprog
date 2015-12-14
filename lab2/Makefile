CC = g++

FLAGS = -std=c++11 -g -Wall -pedantic

main.out: date.o gregorian.o julian.o main.o calendar.o
		$(CC) $(FLAGS) main.o date.o gregorian.o julian.o calendar.o -o main.out

main.o: main.cpp
		$(CC) $(FLAGS) -c main.cpp
date.o: date.cpp
		$(CC) $(FLAGS) -c date.cpp
gregorian.o: gregorian.cpp
		$(CC) $(FLAGS) -c gregorian.cpp
julian.o: julian.cpp
		$(CC) $(FLAGS) -c julian.cpp
calendar.o: calendar.hpp calendar_impl.hpp
		$(CC) $(FLAGS) -c calendar.hpp -o calendar.o

clean:
	rm -f main.out *.o
