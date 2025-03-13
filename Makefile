# Compiler and Flags
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude # Include header directory

# SDL Framework Paths
FRAMEWORKS = -F/Library/Frameworks -framework sdl3 -rpath /Library/Frameworks

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Find all .cpp files in src/ and create corresponding .o files in build/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output Executable
TARGET = tetris

# Default rule: Build the program
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(FRAMEWORKS)

# Compilation step (with header include path)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
