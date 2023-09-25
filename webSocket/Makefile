# Target executable name
TARGET = webSocketClient
TARGET_MAC = wsClient

# Define the compiler
CXX = g++

# Source files
SOURCES = webSocketClient.cpp

# Object files (derived from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Compiler flags
CXX_FLAGS = -Wall -std=c++2a
CXX_MAC_FLAGS = -Wall -c -std=c++20 -I /opt/homebrew/include

# Linker flags
LD_FLAGS = -lpthread -lssl -lcrypto
LD_MAC_FLAGS = -L /opt/homebrew/Cellar/openssl@3/3.1.2/lib -lssl  -lpthread  -lcrypto


# Defalut target to build the executable
all: $(TARGET)
# Rule to build the executable
$(TARGET): $(SOURCES)
	@echo "Compiling..."
	@$(CXX) $(CXX_FLAGS) $(SOURCES) -o $(TARGET) $(LD_FLAGS)


# Target to build the executable on Mac
mac: $(TARGET_MAC)
# Rule to build the executable
$(TARGET_MAC): $(OBJECTS)
	@$(CXX) -o $(TARGET_MAC) $(OBJECTS) $(LD_MAC_FLAGS)
# Rule to compile source files into object files
%.o: %.cpp
	@echo "Compiling..."
	@$(CXX) $(CXX_MAC_FLAGS) $<


# Run the executable
run:
	@./$(TARGET) || ./$(TARGET_MAC)

# Clean up compiled files and the executable
clean:
	@rm -f $(TARGET) $(TARGET_MAC) $(OBJECTS)
	@echo "Cleaning..."

# Mark "all" and "clean" as phony targets (no files with these names)
.PHONY: all mac run clean