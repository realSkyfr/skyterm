CC = g++
CLEAN = dot_clean ./

all: main

main: 
	$(CC) src/main.cpp -o build/main -std=c++23
	$(CLEAN)

writer: 
	$(CC) included/writer.cpp -o build/writer -std=c++23
	$(CLEAN)

clean:
	rm -rf build/*
	$(CLEAN)