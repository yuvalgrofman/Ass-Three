#ifndef ASS_THREE_CLOSE_H
#define ASS_THREE_CLOSE_H

#include "command.h"

class Close : public Command {

    public:
        Close(DefaultIO* dio, int userId);
        virtual void execute() override;
};


#endif //ASS_THREE_CLOSE_H
