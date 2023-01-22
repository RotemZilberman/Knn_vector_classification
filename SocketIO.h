//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART4_SOCKETIO_H
#define ADVANCED_PROGRAMIN_PART4_SOCKETIO_H


#include "DefaultIO.h"
#include <sys/socket.h>
#include <stdexcept>

class SocketIO : public DefaultIO{
public:
    /**
     * this is constructor for the SocketIO
     * @param socketNumber
     */
    SocketIO(int socketNumber);
    std::string read() override;
    void write(std::string) override;
private:
    int client_sock;
};


#endif //ADVANCED_PROGRAMIN_PART4_SOCKETIO_H
