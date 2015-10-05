CC = g++

all: 
car: Car.o Main.o
	$(CC) Car.o Main.o -o vroom

.cpp.o:
	$(CC) -c $< =- $@