#ifndef ASS_THREE_DISPLAYDATA_H
#define ASS_THREE_DISPLAYDATA_H

#include "command.h"

class DisplayData : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        DisplayData(DefaultIO* dio, int userId);

        virtual void execute() override;
};

#endif //ASS_THREE_DISPLAYDATA_H
