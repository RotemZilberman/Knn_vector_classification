//Rotem Zilberman 213231418
//Ohad Langer

#include "ServerTask.h"
#include "CLI.h"

ServerTask::ServerTask(int n): socketNumber(n){}

void ServerTask::execute(){
    SocketIO io(socketNumber);
    CLI commands(io);
    commands.start();
    close(socketNumber);
}