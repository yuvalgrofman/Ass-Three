#ifndef ASS_THREE_CLIENTSOCKET_H
#define ASS_THREE_CLIENTSOCKET_H

#include <string>
using namespace std;

/**
 * @brief The ClientSocket class
 * this class is responsible for communicating with the server using sockets.
 */
class ClientSocket {
private:
    const string server_ip;
    const int port_num;
    const int sock;

public:
    //size of the messages sent.
    static const int BUFFER_SIZE = 4096;

    //character which represents the end of a message.
    static const char END_OF_MESSAGE = ';';

    /**
     * Constructor.
     * @param server_ip - the ip of the server.
     * @param port - the port of the server.
     */
    ClientSocket(const string server_ip = "127.0.0.1", const int port = 5555);

    /**
     * Sends a line to the server.
     * @param line - the line to send.
     */
    void write(const string str) const;

    /**
     * Receives a line from the server.
     * @return the line received.
     */
    string read() const;

    /**
     * Closes the connection.
     */
    void closeConnection() const;
};


#endif //ASS_THREE_CLIENTSOCKET_H
