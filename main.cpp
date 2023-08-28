#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>

int main() {
  boost::asio::io_context io;

  boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws(io);
  ws.connect("wss://api-pub.bitfinex.com/ws/2");

  ws.write("hello");
  std::string message = ws.read();

  std::cout << message << std::endl;

  ws.close();

  return 0;
}
