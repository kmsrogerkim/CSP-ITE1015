SRCS = zebra.cpp zebra_code.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = zebra.h

TARGET = zebra

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o