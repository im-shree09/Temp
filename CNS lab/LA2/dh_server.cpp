#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int getPrimitiveRoot(int prime) {
    for (int root = 2; root < prime; root++) {
        int result = 1;
        bool found = false;
        for (int i = 1; i < prime - 1; i++) {
            result = (result * root) % prime;
            if (result == 1) {
                found = true;
                break;
            }
        }
        if (!found) {
            return root;
        }
    }
    return -1; // No primitive root found
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    std::cout << "Server waiting for connections..." << std::endl;

    client_socket = accept(server_socket, nullptr, nullptr);

    int prime, base;
    std::cout << "Enter a prime number: ";
    std::cin >> prime;
    base = getPrimitiveRoot(prime);

    int server_private_key = std::rand() % (prime - 1) + 1;
    int server_partial_key = std::pow(base, server_private_key);
    server_partial_key = fmod(server_partial_key, prime);

    std::ostringstream server_key_stream;
    server_key_stream << prime << "," << base << "," << server_partial_key;
    std::string server_key_data = server_key_stream.str();

    send(client_socket, server_key_data.c_str(), server_key_data.size(), 0);

    char client_key_buffer[1024];
    recv(client_socket, client_key_buffer, sizeof(client_key_buffer), 0);
    int client_partial_key = std::stoi(client_key_buffer);

    int shared_key = std::pow(client_partial_key, server_private_key);
    shared_key = fmod(shared_key, prime);

    std::cout << "Shared Key: " << shared_key << std::endl;

    close(client_socket);
    close(server_socket);

    return 0;
}
