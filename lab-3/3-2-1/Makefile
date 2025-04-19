SRCS = accounts.cpp accounts_main.cpp

CXXFLAGS = -Wall -Wextra -std=c++11

HEADERS = accounts.h

TARGET = simple_account

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	g++ ${CXXFLAGS} -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET) *.o