#ifndef ASS_THREE_DISPLAYDATA_H
#define ASS_THREE_DISPLAYDATA_H

#include "command.h"

/**
 * @brief The DisplayData class
 *
 * This class is Responsible for displaying the predictions made by
 * the KNN classifier, on the data, given by a specific user.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
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
