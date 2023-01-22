#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <fstream>
#include "Helper.h"
#include "SocketIO.h"

//Rotem Zilberman 213231418
//Ohad Langer
void uploadInfo(int socket, std::string path){
    SocketIO sent(socket);
    try{
        std::ifstream file(path);
        if(file.is_open()) {
            std::string input;
            std::string line;
            while (std::getline(file, line)) {
                input += line + "\n";
            }
            size_t pos = input.find('\r');
            while (pos != std::string::npos) {
                input.erase(pos, 1);
                pos = input.find('\r');
            }
            sent.write(input + "\r\n");
        }
        else{
            throw std::invalid_argument("error");
        }
        file.close();
    }
    catch(std::exception e){
        throw std::invalid_argument("error");
    }
}

void downloadData(std::string file, std::string data){
    std::ofstream outfile(file);
    if(outfile.is_open()){
        outfile << data << std::endl;
        outfile.close();
    }
}

std::string getInput(int sock){
    SocketIO sent(sock);
    try{
        return sent.read();
    }
    catch(std::exception r){
        std::cout << "problem in sending";
        throw std::invalid_argument("error");
    }
}

int main(int argc, char* argv[]){
    if (argc != 3) {
        return 0;
    }
    size_t length;
    const int ServerPort = std::stoi(argv[2], &length);
    if (length != std::string(argv[2]).length() || ServerPort < 0 || ServerPort > 65535) {
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
    sin.sin_addr.s_addr = inet_addr(argv[1]);
    sin.sin_port = htons(ServerPort);
    if(std::string(argv[1])=="localhost"){
        const char *ip("127.0.0.1");
        sin.sin_addr.s_addr = inet_addr(ip);
    }
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        std::cout << "invalid input\n";
        return 0;
    }

    while (true) {
        std::string input;
        try {
            input = getInput(sock);
        } catch(std::exception e){
            break;
        }
        if(input.find("upload") == 0){
            try {
                uploadInfo(sock, input.substr(input.find(' ') + 1));
            }
            catch(std::exception e){
                int problem;
                do {
                    problem = 0;
                    input = "\r\n";
                    int sent_bytes = send(sock, input.c_str(), input.length(), 0);
                    if (sent_bytes < 0) {
                        problem = 1;
                        std::cout << "error sending\n";
                    }
                } while(problem);
            }
            continue;
        }
        if(input.find("download") == 0){
            int problem;
            do {
                problem = 0;
                std::string respond = "ok\r\n";
                int sent_bytes = send(sock, respond.c_str(), respond.length(), 0);
                if (sent_bytes < 0) {
                    problem = 1;
                    std::cout << "error sending\n";
                }
            } while(problem);
            size_t newLine = input.find("\n");
            std::thread t1(downloadData,input.substr(9,newLine-9), input.substr(newLine+1));
            t1.detach();
            continue;
        }
        if(input==""){
            break;
        }
        else{
            std::cout << input;
        }
        int problem;
        do {
            problem = 0;
            std::getline(std::cin, input);
            int sent_bytes = send(sock, (input + "\r\n").c_str(), (input + "\r\n").length(), 0);
            if (sent_bytes < 0) {
                problem = 1;
                std::cout << "error sending\n";
            }
        } while(problem);
    }
    close(sock);
    return 0;
}
