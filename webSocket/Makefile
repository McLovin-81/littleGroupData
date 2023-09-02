CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lpthread -lssl -lcrypto

# Specify the source file and the output executable
SRC = webSocketClient.cpp
OUT = webSocketClient

# Specify include directories
INCLUDES = -I/path/to/websocketpp/include

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@ $<

clean:
	rm -f $(OUT)

.PHONY: clean
