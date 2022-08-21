#ifndef ASS_THREE_SOCKETIO_H
#define ASS_THREE_SOCKETIO_H

#include "defaultIO.h"

class SocketIO : DefaultIO {
    public:
        virtual string read() const override;
        virtual void write(string str) const override;
        virtual void close() const override;
};


#endif //ASS_THREE_SOCKETIO_H
