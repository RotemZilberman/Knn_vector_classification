//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART4_SERVERTASK_H
#define ADVANCED_PROGRAMIN_PART4_SERVERTASK_H

#include "Task.h"
#include "SocketIO.h"
#include <unistd.h>

class ServerTask : public Task{
public:
    /**
     * constructor fot the ServerTask class
     * @param socketNumber
     */
    ServerTask(int socketNumber);
    void execute() override;

private:
    int socketNumber;
};


#endif //ADVANCED_PROGRAMIN_PART4_SERVERTASK_H
