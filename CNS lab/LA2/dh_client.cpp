#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
// #include <netinet/in.h>
#include <winsock2.h>
#include <unistd.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char server_key_buffer[1024];
    recv(client_socket, server_key_buffer, sizeof(server_key_buffer), 0);
    std::string server_key_data(server_key_buffer);

    int prime, base, client_partial_key;
    std::istringstream server_key_stream(server_key_data);
    server_key_stream >> prime;
    server_key_stream.ignore(1);
    server_key_stream >> base;
    server_key_stream.ignore(1);
    server_key_stream >> client_partial_key;

    int client_private_key = std::rand() % (prime - 1) + 1;
    int client_partial_key = std::pow(base, client_private_key);
    client_partial_key = fmod(client_partial_key, prime);

    send(client_socket, std::to_string(client_partial_key).c_str(), std::to_string(client_partial_key).size(), 0);

    int shared_key = std::pow(server_partial_key, client_private_key);
    shared_key = fmod(shared_key, prime);

    std::cout << "Shared Key: " << shared_key << std::endl;

    close(client_socket);

    return 0;
}
