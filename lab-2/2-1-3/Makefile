all: convert_cc.o
	g++ -o convert_cc convert_cc.o
convert_cc.o: convert_cc.cpp
	g++ -c -o convert_cc.o convert_cc.cpp
clean: 
	rm convert_cc *.o