SRCS = vehicle.cpp vehicle_code.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = vehicle.h

TARGET = vehicle

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o