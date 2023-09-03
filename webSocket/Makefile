# Google Test library location
WEBSOCKETPP_LIB = websocketpp

# Compiler flags
CXX_FLAGS = -Wall -c -I /opt/homebrew/include -std=c++20

# Linker flags
LD_FLAGS = -L /opt/homebrew/Cellar/openssl@3/3.1.2/lib -lssl  -lpthread  -lcrypto

# Target executable name
TARGET = webSocketClient

# Source files
SOURCES = webSocketClient.cpp

# Object files (derived from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target to build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

# Rule to compile source files into object files
%.o: %.cpp
	g++ $(CXX_FLAGS) $<

# Clean up compiled files and the executable
clean:
	rm -f $(TARGET) $(OBJECTS)

# Mark "all" and "clean" as phony targets (no files with these names)
.PHONY: all clean
