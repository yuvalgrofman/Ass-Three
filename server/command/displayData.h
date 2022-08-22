#ifndef ASS_THREE_DISPLAYDATA_H
#define ASS_THREE_DISPLAYDATA_H

#include "command.h"

class DisplayData : public Command {

    public:
        DisplayData(DefaultIO* dio, int userId);
        virtual void execute() override;
};

#endif //ASS_THREE_DISPLAYDATA_H
