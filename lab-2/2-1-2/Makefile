all: convert_c.o
	g++ -o convert_c convert_c.o
convert_c.o: convert_c.cpp
	g++ -c -o convert_c.o convert_c.cpp
clean: 
	rm convert_c *.o