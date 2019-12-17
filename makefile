all: build run

build:
	@echo "Building hello.cpp.."
	g++ -std=c++14 -Wall src/hello.cpp -o game.out

run:
	./game.out

clean:
	@echo "Cleaning executables.."
	rm *.out
	
transfer1:
	scp hy352/* csd3787@kiwi.csd.uoc.gr://home/ugrads/class16/csd3787/hy352/
transfer2:
	scp hy352/* csd****@kiwi.csd.uoc.gr://home/ugrads/class15/csd****/hy352/
connect_kiwi:
	ssh kiwi.csd.uoc.gr