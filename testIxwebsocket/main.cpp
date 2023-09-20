#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXWebSocket.h>
#include <ixwebsocket/IXUserAgent.h>
#include <iostream>


int main()
{
    // Our websocket object
    ix::WebSocket webSocket;

    // Connect to a server with encryption
    // See https://machinezone.github.io/IXWebSocket/usage/#tls-support-and-configuration
    //     https://github.com/machinezone/IXWebSocket/issues/386#issuecomment-1105235227 (self signed certificates)
    std::string url("http://squid-proxy.gcp.dbgcloud.io:3128/wss://api-pub.bitfinex.com/ws/2");
    webSocket.setUrl(url);

    std::cout << "Connecting to " << url << "..." << std::endl;

    // Setup a callback to be fired (in a background thread, watch out for race conditions !)
    // when a message or an event (open, close, error) is received
    webSocket.setOnMessageCallback([](const ix::WebSocketMessagePtr& msg)
        {
            if (msg->type == ix::WebSocketMessageType::Message)
            {
                std::cout << "received message: " << msg->str << std::endl;
                std::cout << "> " << std::flush;
            }
            else if (msg->type == ix::WebSocketMessageType::Open)
            {
                std::cout << "Connection established" << std::endl;
                std::cout << "> " << std::flush;
            }
            else if (msg->type == ix::WebSocketMessageType::Error)
            {
                // Maybe SSL is not configured properly
                std::cout << "Connection error: " << msg->errorInfo.reason << std::endl;
                std::cout << "> " << std::flush;
            }
        }
    );

    // Now that our callback is setup, we can start our background thread and receive messages
    webSocket.start();

    // Send a message to the server (default to TEXT mode)
    webSocket.send("Hello world");

    // Display a prompt
    std::cout << "> " << std::flush;

    std::string text;
    // Read text from the console and send messages in text mode.
    // Exit with Ctrl-D on Unix or Ctrl-Z on Windows.
    while (std::getline(std::cin, text))
    {
        webSocket.send(text);
        std::cout << "> " << std::flush;
    }
std::cout << "fuck"<< std::endl;
    return 0;
}

// Compile: g++ -std=c++11 main.cpp -o main -lixwebsocket -lssl -lcrypto -lpthread -lz -lcurl
// delete -lcurl?