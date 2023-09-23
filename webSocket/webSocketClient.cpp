#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

typedef websocketpp::client<websocketpp::config::asio_tls_client> Client;
typedef websocketpp::lib::error_code ErrorCode;
typedef websocketpp::connection_hdl ConnectionHdl;
typedef websocketpp::lib::asio::ssl::context SslContext;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

void sendMessageOnOpen(Client* client, ConnectionHdl hdl, std::string msg);
void getMessageOnOpen(Client* client, ConnectionHdl hdl, websocketpp::config::asio_client::message_type::ptr msg);
websocketpp::lib::shared_ptr<SslContext> on_tls_init();


int main()
{
  Client client;
  ErrorCode errorCode;

  std::string msg = R"( { "event":"subscribe","channel":"ticker","symbol":"tBTCUSD" } )";
  std::string url = "wss://api-pub.bitfinex.com/ws/2";
  //std::string proxy = "http://squid-proxy.gcp.dbgcloud.io:3128";
  std::string https_proxy = getenv("HTTPS_PROXY");
  std::string http_proxy = getenv("HTTP_PROXY");
  std::string proxy = https_proxy.length() > 0 ? https_proxy : http_proxy;

  client.clear_access_channels(websocketpp::log::alevel::all);
  client.clear_error_channels(websocketpp::log::elevel::all);

  client.init_asio();

  client.set_tls_init_handler(websocketpp::lib::bind(&on_tls_init));

  client.set_open_handler(websocketpp::lib::bind(&sendMessageOnOpen, &client, ::_1, msg));

  client.set_message_handler(websocketpp::lib::bind(&getMessageOnOpen, &client, ::_1, ::_2));

  auto connection = client.get_connection(url, errorCode);

  //connection->set_proxy(proxy, errorCode);
  
  if (proxy.length() > 0)
  {
    connection->set_proxy(proxy, errorCode);
  }

  client.connect(connection);

  client.run();

  return 0;
}



void sendMessageOnOpen(Client* client, ConnectionHdl hdl, std::string msg)
{
  std::cout << "Send ↑: " << msg << std::endl;
  client->send(hdl, msg, websocketpp::frame::opcode::text);
}

void getMessageOnOpen(Client* client, ConnectionHdl hdl, websocketpp::config::asio_client::message_type::ptr msg)
{
  std::cout << "Get ↓: " << msg->get_payload() << std::endl;
} 

websocketpp::lib::shared_ptr<SslContext> on_tls_init()
{
  auto sslContext_ptr = websocketpp::lib::make_shared<SslContext>(boost::asio::ssl::context::sslv23);
  return sslContext_ptr;
}