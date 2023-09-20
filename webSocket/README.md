# WebSocket Client with websocketpp Library

This is a C++ WebSocket client example using the websocketpp library to connect to a WebSocket server.

## Prerequisites
- C++ compiler (C++2a / C++20)
- pthread library
- OpenSSL library
- Crypto library
- [websocketpp](https://github.com/zaphoyd/websocketpp) library

## Dependencies
This code relies on the websocketpp library. You can download it using Git with the following command:
```bash
git clone https://github.com/zaphoyd/websocketpp.git
```

## Compilation
To compile the WebSocket client code, you can use the provided Makefile. Simply run the following command in your terminal:

```bash
make
```

This will automatically compile the `webSocketClient.cpp` source code and generate the executable `webSocketClient`.

## Usage
1. Clone the websocketpp library as mentioned above.
2. Compile the WebSocket client using the provided Makefile.
3. Run the executable to establish a WebSocket connection to the Bitfinex API.
4. The client will subscribe to ticker updates for the BTC/USD trading pair.
5. Messages received from the WebSocket server will be displayed on the console.

## Customization
You can modify the WebSocket server URL, message format, and handling functions according to your specific use case by editing the `webSocketClient.cpp` file.
