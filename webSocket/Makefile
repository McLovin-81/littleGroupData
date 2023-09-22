# Websocketpp library location
WEBSOCKETPP_LIB = websocketpp

# Target executable name
TARGET = webSocketClient

# Source files
SOURCES = webSocketClient.cpp

# Object files (derived from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Compiler flags
CXX_FLAGS = -Wall -c -std=c++20 -I /opt/homebrew/include

# Linker flags
LD_FLAGS = -L /opt/homebrew/Cellar/openssl@3/3.1.2/lib -lssl  -lpthread  -lcrypto

# Default target to build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

# Rule to compile source files into object files
%.o: %.cpp
	g++ $(CXX_FLAGS) $<

# Run the executable
run:
	@echo "Run!"
	@./$(TARGET)

# Clean up compiled files and the executable
clean:
	@rm -f $(TARGET) $(OBJECTS)
	@echo "Cleaning..."

linux:
	@echo "Compiling..."
	@g++ -Wall -std=c++2a webSocketClient.cpp -o webSocketClient -lpthread -lssl -lcrypto
	@./webSocketClient

# Mark "all" and "clean" as phony targets (no files with these names)
.PHONY: all clean run
