all: build run

build:
	@echo "Building hello.cpp.."
	g++ -std=c++17 -Wall src/test.cpp src/data.hpp -o game.out
run:
	./game.out
testc:
	@echo "Building test.c"
	gcc -Wall src/testc.c -o testc.out

clean:
	@echo "Cleaning executables.."
	*.out
	
ssh_kiwi:
	ssh kiwi.csd.uoc.gr