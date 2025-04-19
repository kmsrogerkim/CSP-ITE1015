all: hello_world.o
	g++ -o hello_world hello_world.o
hello_world.o: hello_world.cpp
	g++ -c -o hello_world.o hello_world.cpp
clean: 
	rm hello_world *.o