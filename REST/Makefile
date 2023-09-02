# Makefile for cUrl-API

# Compiler and compiler flags
CC = g++
CFLAGS = -Wall
LIBS = -lcurl

# Source file and executable name
SRC = cUrl-API.cpp
EXECUTABLE = cUrl-API

# Target: all (default target)
all: $(EXECUTABLE)

# Rule to compile the executable
$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SRC) $(LIBS)

# Target: run (compile and run the executable)
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Target: clean (remove the executable)
clean:
	rm -f $(EXECUTABLE)

# Declare the 'all', 'run', and 'clean' targets as phony targets,
# meaning they don't correspond to actual files.
.PHONY: all run clean
