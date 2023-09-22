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

build:
	@g++ -Wall -std=c++11 webSocketClient.cpp -o webSocketClient -lpthread -lssl -lcrypto -lboost_system

build-image:
	@docker build --tag websocket-client          \
		--build-arg ARG_HTTP_PROXY=${HTTP_PROXY}    \
    --build-arg ARG_HTTPS_PROXY=${HTTPS_PROXY}  \
    --build-arg ARG_NO_PROXY=${NO_PROXY}        \
		--file .devcontainer/Dockerfile .

run-image:
	@docker run -it --rm websocket-client

# Mark "all" and "clean" as phony targets (no files with these names)
help:
	@printf "Usage: make [target]\n"
	@printf "\n"
	@printf "Available targets:\n"
	@printf "\n"
	@printf "\thelp                     Show this help message\n";
	@printf "\tbuild-image              Build the docker image\n";
	@printf "\trun-image                Run the docker image\n";
	@printf "\n";

.PHONY: all clean run
