SRCS = shapes.cpp shapes_code.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = shapes.h

TARGET = shapes

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o

# all: shapes.o shapes_code.o
# 	g++ -o shapes shapes.o shapes_code.o

# shapes.o: shapes.cpp
# 	g++ -c -o shapes.o shapes.cpp

# shapes_code.o: shapes_code.cpp
# 	g++ -c -o shapes_code.o shapes_code.cpp

# clean: 
# 	rm shapes *.o