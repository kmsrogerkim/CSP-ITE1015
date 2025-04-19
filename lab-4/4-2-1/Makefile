SRCS = reply_admin.cpp main.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = reply_admin.h

TARGET = reply_admin

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o