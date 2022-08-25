#ifndef ASS_THREE_DISPLAYCONFUSIONMATRIX_H
#define ASS_THREE_DISPLAYCONFUSIONMATRIX_H

#include <map>
#include "command.h"

/**
 * @brief The DisplayConfusionMatrix class
 *
 * This class is Responsible for displaying the confusion matrix of the data, given by a specific user,
 * compared to the predictions made by the KNN classifier on that data.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
class DisplayConfusionMatrix : public Command {
    private:
        /**
         * @return the classification options from the data file
         * that the user has sent.
         */
        map<string, int>& getClassificationOptions() const;

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        DisplayConfusionMatrix(DefaultIO* dio, int userId);

        virtual void execute() override;
};

#endif //ASS_THREE_DISPLAYCONFUSIONMATRIX_H
