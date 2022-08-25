#ifndef ASS_THREE_RECVDATA_H
#define ASS_THREE_RECVDATA_H

#include "server/command/command.h"
#include <string>

/**
 * @brief The RecvData class
 *
 * This class is Responsible for receiving the data, given by a specific user.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
class RecvData : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        RecvData(DefaultIO* dio, int userId);

        virtual void execute() override;

};

#endif //ASS_THREE_RECVDATA_H