# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Output executable name
TARGET = colculator

# Source files
SRCS = clean.cpp main.cpp math.cpp braces.cpp

# Object files derived from source files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

