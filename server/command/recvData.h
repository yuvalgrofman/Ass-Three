#ifndef ASS_THREE_RECVDATA_H
#define ASS_THREE_RECVDATA_H

#include "command.h"
#include <string>

class recvData : Command {

    private:
        int userId;


    public:
        recvData(int userId);
        void execute() override;

};

#endif //ASS_THREE_RECVDATA_H