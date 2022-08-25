#ifndef ASS_THREE_CLASSIFYDATA_H
#define ASS_THREE_CLASSIFYDATA_H

#include "command.h"

/**
 * @brief The ClassifyData class
 *
 * This class is Responsible for classifying the data, given by a specific user.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
class ClassifyData : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        ClassifyData(DefaultIO* dio, int userId);

        virtual void execute() override;

};

#endif //ASS_THREE_CLASSIFYDATA_H
