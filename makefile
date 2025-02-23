CC = g++

all: main

main: 
	$(CC) src/main.cpp -o build/main -std=c++23
	$(CC) included/writer.cpp -o build/writer -std=c++23
	dot_clean ./

clean:
	rm -rf build/*
	dot_clean ./