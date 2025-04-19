SRCS = shapes.cpp main.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = shapes.h

TARGET = print_member

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o