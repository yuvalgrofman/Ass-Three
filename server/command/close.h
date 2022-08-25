#ifndef ASS_THREE_CLOSE_H
#define ASS_THREE_CLOSE_H

#include "command.h"

class Close : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        Close(DefaultIO* dio, int userId);

        virtual void execute() override;
};


#endif //ASS_THREE_CLOSE_H
