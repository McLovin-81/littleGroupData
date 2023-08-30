#include <websocketpp/config/asio_client.hpp> // Use TLS
// #include <websocketpp/config/asio_no_tls_client.hpp>   No TLS
#include <websocketpp/client.hpp>

#include <iostream>
#include <string>

using client = websocketpp::client<websocketpp::config::asio_tls_client>;  // Use TLS
// using client = websocketpp::client<websocketpp::config::asio_client>;      No TLS

void on_message(client* c, websocketpp::connection_hdl hdl, client::message_ptr msg)
{
   std::cout << "Received: " << msg->get_payload() << std::endl;
}


int main() {

   client c;

   // Set logging to more silent than normal (optional)
   c.set_access_channels(websocketpp::log::alevel::none);
   // c.set_error_channels(websocketpp::log::elevel::none); Silence error output

   // Initialize ASIO transport and set the handler for messages.
   c.init_asio();
   c.set_message_handler(std::bind(&on_message, &c, std::placeholders::_1, std::placeholders::_2));

   // Create a connection to Bitfinex's WSS endpoint
   websocketpp::lib::error_code ec;
   client::connection_ptr con;
std::cout << "Last working line" << std::endl;

   con->set_tls_init_handler([](websocketpp::connection_hdl)
   {
      return websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12_client);
   });

   c.get_connection("wss://ws.kraken.com", ec);

   if (ec)
   {
       std::cout << "Error creating connection: " << ec.message() << std::endl;
       return 1;
   }

   // Connect
   c.connect(con);

   // Start the ASIO io_service run loop
   c.run();

   return 0;
}

// Old Build
// g++ -std=c++2a webSocketClient.cpp -o webSocketClient -lpthread -lboost_system -lboost_thread -lssl -lcrypto -ldl

// New Build
// g++ webSocketClient.cpp -o webSocketClient -lpthread -lssl -lcrypto

// Download webSocket++ library:
//      sudo apt install libwebsocketpp-dev
