CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = output

SRCS = main.cpp arrays/1darray/Array.cpp arrays/2darray/2d_array.cpp programs/first_program.cpp programs/second_program.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
