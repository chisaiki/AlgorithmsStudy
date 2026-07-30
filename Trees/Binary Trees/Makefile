# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall

# Executable name
TARGET = run

# Source and object files
SRCS = main.cpp

# Default target
# all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

exe: 
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
