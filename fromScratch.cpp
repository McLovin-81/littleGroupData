#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

// Function to send data over the socket
void send_data(int socket_fd, const char* data)
{
    send(socket_fd, data, strlen(data), 0);
}

// Function to receive data from the socket
int receive_data(int socket_fd, char* buffer, int buffer_size)
{
    return recv(socket_fd, buffer, buffer_size, 0);
}

int main() {
    const char* hostname = "api.bitfinex.com";
    const char* path = "/ws/2";
    const int port = 443; // HTTPS port

    // Step 1: Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Step 2: Resolve server address
    struct hostent* server = gethostbyname(hostname);
    if (server == nullptr) {
        perror("Error resolving host");
        close(socket_fd);
        return 1;
    }

    // Step 3: Establish connection
    struct sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    bcopy(server->h_addr, &server_address.sin_addr.s_addr, server->h_length);
    
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error connecting to server");
        close(socket_fd);
        return 1;
    }

    // Step 4: WebSocket Handshake
    const char* websocket_key = "abc"; // Generate a random key
    const char* handshake_request = "GET /ws/2 HTTP/1.1\r\n"
                                   "Host: api.bitfinex.com\r\n"
                                   "Upgrade: websocket\r\n"
                                   "Connection: Upgrade\r\n"
                                   "Sec-WebSocket-Key: ";
    char handshake_buffer[1024];
    snprintf(handshake_buffer, sizeof(handshake_buffer), "%s%s\r\n\r\n", handshake_request, websocket_key);

    send_data(socket_fd, handshake_buffer);

    // Step 5: Receive and validate response
    char response_buffer[1024];
    int bytes_received = receive_data(socket_fd, response_buffer, sizeof(response_buffer));
    response_buffer[bytes_received] = '\0';
    std::cout << response_buffer << std::endl;

    // Step 6: Send and receive WebSocket messages
    const char* message = "{\"event\":\"subscribe\",\"channel\":\"ticker\",\"symbol\":\"tBTCUSD\"}";
    send_data(socket_fd, message);

    char message_buffer[1024];
    while (true) {
        int message_length = receive_data(socket_fd, message_buffer, sizeof(message_buffer));
        if (message_length <= 0) {
            break;
        }
        message_buffer[message_length] = '\0';
        std::cout << "Received: " << message_buffer << std::endl;
    }

    // Step 7: Close the connection
    close(socket_fd);

    return 0;
}

