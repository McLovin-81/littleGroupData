#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

#include <websocketpp/transport/asio/connection.hpp>

using Client = websocketpp::client<websocketpp::config::asio_tls_client>;

using ConnectionHdl = websocketpp::connection_hdl;

using SslContext = websocketpp::lib::asio::ssl::context;

using websocketpp::lib::placeholders::_1;

using websocketpp::lib::placeholders::_2;

 
// Callback function when a message is received.
void on_message(Client* client, ConnectionHdl hdl, websocketpp::config::asio_client::message_type::ptr msg)
{
  std::cout << "callback ↓: " << msg->get_payload() << std::endl;
  //client->close(hdl, websocketpp::close::status::normal, "done");
}

// Send message.
void on_open(Client* client, ConnectionHdl hdl)
{
  // Prepare and send a message to subscribe to trade updates.
  std::string msg = R"( { "event":"subscribe","channel":"ticker","symbol":"tBTCUSD" } )";
  std::cout << "send ↑: " << msg << std::endl;
  client->send(hdl, msg, websocketpp::frame::opcode::text);
}

// Initialize the SSL/TLS context for secure communication.
websocketpp::lib::shared_ptr<SslContext> on_tls_init()
{
  auto ctx = websocketpp::lib::make_shared<SslContext>(boost::asio::ssl::context::sslv23);
  return ctx;
}
 
// Disables logging (protocol) to reduce console output.
void turn_off_logging(Client& client)
{
  client.clear_access_channels(websocketpp::log::alevel::all);
  client.clear_error_channels(websocketpp::log::elevel::all);
}

// Handling incoming WebSocket messages.
void set_message_handler(Client& client)
{
  client.set_message_handler(websocketpp::lib::bind(&on_message, &client, ::_1, ::_2));
}


void set_open_handler(Client& client)
{
  client.set_open_handler(websocketpp::lib::bind(&on_open, &client, ::_1));
}

// Initialize the SSL/TLS context for secure WebSocket communication.
void set_tls_init_handler(Client& client)
{
  client.set_tls_init_handler(websocketpp::lib::bind(&on_tls_init));
}

// Set the WebSocket server URL and establishes the WebSocket connection.
void set_url(Client& client, std::string url)
{
  websocketpp::lib::error_code ec;

  auto connection = client.get_connection(url, ec);

  // Set Proxy
  connection->set_proxy("http://squid-proxy.gcp.dbgcloud.io:3128", ec);

  client.connect(connection);
}

 

int main()
{
  // Initialize the WebSocket client
  Client client;

  // Disable logging messages
  turn_off_logging(client);

  // Initialize the Asio event loop
  client.init_asio();

  // Set the TLS initialization handler
  set_tls_init_handler(client);

  // Set the connection open handler
  set_open_handler(client);

  // Set the message handler
  set_message_handler(client);

  // Set the WebSocket server URL and establish the connection
  set_url(client, "wss://api-pub.bitfinex.com/ws/2");

  // Start the WebSocket client event loop
  client.run();

  return 0;
}

// g++ -Wall -std=c++2a webSocketClient.cpp -o webSocketClient -lpthread -lssl -lcrypto

