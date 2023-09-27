#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

#include "configuration/config.h"
const std::string CONFIG_FILEPATH = "configuration/config.json";


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
  Config config(CONFIG_FILEPATH);

  std::string msg = config.subscriptionMessage;
  std::string url = config.url;
  std::string https_proxy;
  std::string http_proxy;
  std::string proxy;

  if (getenv("HTTPS_PROXY") != NULL)
  {
    https_proxy = getenv("HTTPS_PROXY");
  }
  else if (getenv("HTTP_PROXY") != NULL)
  {
    http_proxy = getenv("HTTP_PROXY");
  }

  if (https_proxy.length() > 0)
  {
    proxy = https_proxy;
  }
  else if (http_proxy.length() > 0)
  {
    proxy = http_proxy;
  }

  client.clear_access_channels(websocketpp::log::alevel::all);
  client.clear_error_channels(websocketpp::log::elevel::all);

  client.init_asio();

  client.set_tls_init_handler(websocketpp::lib::bind(&on_tls_init));

  client.set_open_handler(websocketpp::lib::bind(&sendMessageOnOpen, &client, ::_1, msg));

  client.set_message_handler(websocketpp::lib::bind(&getMessageOnOpen, &client, ::_1, ::_2));

  auto connection = client.get_connection(url, errorCode);

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
