#ifndef ASS_THREE_CLOSE_H
#define ASS_THREE_CLOSE_H

#include "command.h"

/**
 * @brief The Close class
 *
 * This class is Responsible for closing the server connection of a specific user.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
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
