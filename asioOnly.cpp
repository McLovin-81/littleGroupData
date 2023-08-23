#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <iostream>


std::vector<char> vBuffer(1 * 1024);

// This should output the received data
void GrabSomeData(asio::ip::tcp::socket& socket) {
    socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
        [&](std::error_code ec, std::size_t lenght) {
            if (!ec) {
                std::cout << "\n\nRead " << lenght << " bytes\n\n";

                for (int i = 0; i < lenght; i++)
                    std::cout << vBuffer[i];

                GrabSomeData(socket);
            }
        }
    );
}

int main() {

    asio::error_code ec;

    asio::io_context context;

    asio::io_context::work idleWork(context);

    std::thread thrContext = std::thread([&]() { context.run(); });
    
    // I hope this is what you meant
    asio::ip::tcp::resolver res(context);
    asio::ip::tcp::socket socket(context);
    asio::connect(socket, res.resolve("echo.websocket.org", std::to_string(443)));

    // Check the socket is open
    if (socket.is_open()) {
        // Start to output incoming data
        GrabSomeData(socket);

        // Send data to the websocket, which should be sent back
        std::string sRequest = "Echo";
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
        
        // Wait some time, so the data is received
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(20000ms);

        context.stop();
        if (thrContext.joinable()) thrContext.join();
    }

    return 0;
}