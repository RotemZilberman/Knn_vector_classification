#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fstream>
#include "Helper.h"
#include "ClassifiedCollection.h"
#include "ThreadPool.h"
#include "ServerTask.h"

//Rotem Zilberman 213231418
//Ohad Langer
int main(int argc, char* argv[]){
    //in this part we are creating the server main socket
    if (argc != 2) {
        std::cout << "invalid input\n";
        return 0;
    }
    size_t length;
    const int ServerPort = std::stoi(argv[1], &length);
    if (length != std::string(argv[1]).length() || ServerPort < 0 || ServerPort > 65535) {
        std::cout << "invalid input\n";
        return 0;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "error creating socket\n";
        return 0;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(ServerPort);
    if (bind(sock,(struct sockaddr*)&sin, sizeof(sin)) < 0) {
        std::cout << "error creating socket\n";
        return 0;
    }
    if (listen(sock,5) < 0){
        std::cout << "error creating socket\n";
        return 0;
    }
    //finish in the creating of the server socket
    ThreadPool thread(5);
    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            std::cout << "error connecting to client\n";
            continue;
        }
        ServerTask *executable = new ServerTask(client_sock);
        thread.enqueue(executable);
    }
}
