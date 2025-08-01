# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++17
LDFLAGS = -lncurses

# Project files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = roguelike

# Default rule
all: $(TARGET)

# Link objects into final binary
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Compile .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Install dependencies (Debian/Ubuntu)
deps:
	sudo apt update && sudo apt install libncurses5-dev libncursesw5-dev

.PHONY: all clean run deps

