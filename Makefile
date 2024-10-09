CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = output

SRCS = main.cpp include/arrays/1darray/Array.cpp include/arrays/2darray/2d_array.cpp src/programs/first_program.cpp src/programs/second_program.cpp src/main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
