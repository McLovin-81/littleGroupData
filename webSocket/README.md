# WebSocket Client with websocketpp Library

This is a C++ WebSocket client example using the websocketpp library to connect to a WebSocket server.

## Prerequisites
- C++ compiler (C++2a)
- pthread library
- OpenSSL library
- Crypto library
- [websocketpp](https://secure-web.cisco.com/1mw_38VuU2HzUz8ogwhOFqh3RrMpTeNqGsHOP_RTqEXR1kXRxXoV7Z0tD_CGBtctSZcz3lL_lEF378FnXwcBAPJd7na62aQb7CmulGFlDq_bRgBwXm3Y-5fzduvRobGPS8srvtLXTXCQohfRL9A1MGUQ-8ZNPKDaJ2rOg-V-RWEIkvpyhkKfuLlUkQzGfLnQEwr5UA5T3KL7x8A2mmu4erRfRm7lNTU7QITb0q8hw1FzkXGjGPUM_bMglUp3k8E0u/https%3A%2F%2Fgithub.com%2Fzaphoyd%2Fwebsocketpp) library

## Dependencies
This code relies on the websocketpp library. You can download it using Git with the following command:

```bash
git clone https://secure-web.cisco.com/1GU3A_YP2Hfsu0dgdUJHId9KEYi0QiLNEkAuwAsroBIjIjtw9i89tVgWC0ke3Fi9ywsw7yGqv2ShOeFS34oKqc2GOklk6gsVYiC-CTqpriTojEMtCMdWk0TsA-11uJIumsrU2lORDs0R0zQQqxuIYbUbye__aNfA2wz3nhb62gBj_hRUjkuk-VCnuNx6A8BtOlKQl6NRp2DLHDMtbhZFyLam686u3oOmQdAYlOgiV9UIcuXJ4IfctHiX_NwwuKxfa/https%3A%2F%2Fgithub.com%2Fzaphoyd%2Fwebsocketpp.git


```markdown
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

Feel free to tailor this code to suit your needs and experiment with different WebSocket servers and message formats.
```


