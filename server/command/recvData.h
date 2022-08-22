#ifndef ASS_THREE_RECVDATA_H
#define ASS_THREE_RECVDATA_H

#include "command.h"
#include <string>

class RecvData : Command {

    public:
        RecvData(DefaultIO* dio, int userId);
        virtual void execute() override;

};

#endif //ASS_THREE_RECVDATA_H