#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client;

int main() {
    // Create a WebSocket client
    client c;

    // Initialize ASIO
    c.init_asio();

    // Set up the handlers for WebSocket events
    c.set_open_handler([](websocketpp::connection_hdl hdl) {
        std::cout << "Connected to server!" << std::endl;
    });

    c.set_message_handler([](websocketpp::connection_hdl hdl, client::message_ptr msg) {
        std::cout << "Received message: " << msg->get_payload() << std::endl;
    });

    c.set_close_handler([](websocketpp::connection_hdl hdl) {
        std::cout << "Connection closed." << std::endl;
    });

    // Connect to the Bitfinex WebSocket API
    std::string uri = "wss://api.bitfinex.com/ws/2";
    websocketpp::lib::error_code ec;
    client::connection_ptr con = c.get_connection(uri, ec);
    if (ec) {
        std::cout << "Error creating connection: " << ec.message() << std::endl;
        return 1;
    }

    c.connect(con);

    // Start the ASIO event loop
    c.run();

    return 0;
}
