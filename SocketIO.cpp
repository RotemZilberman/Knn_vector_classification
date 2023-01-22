//Rotem Zilberman 213231418
//Ohad Langer

#include "SocketIO.h"

SocketIO::SocketIO(int socketNumber): client_sock(socketNumber){}
std::string SocketIO::read(){
    std::string serverOut;
    char buffer[4096];
    int read_bytes;
    while(serverOut.find("\r\n") == -1) {
        read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (read_bytes == 0) {
            break;
        }
        if (read_bytes < 0) {
            break;
        }
        serverOut += std::string(buffer, buffer + read_bytes);
    }
    if (read_bytes < 0) {
        throw std::invalid_argument("error");
    }
    return serverOut.substr(0,serverOut.length()-2);
}
void SocketIO::write(std::string output){
    char buffer[4096];
    while(output.length()!=0) {
        output.copy(buffer,4000);
        int min = 4000 > output.length() ? output.length(): 4000;
        buffer[min] = '\0';
        int sent_bytes = send(client_sock, buffer, min, 0);
        if (sent_bytes < 0) {
            throw std::invalid_argument("error");
        }
        output = output.substr(min);
    }
}