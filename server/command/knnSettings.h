#ifndef ASS_THREE_KNNSETTINGS_H
#define ASS_THREE_KNNSETTINGS_H

#include "command.h"
#include <sstream>
#include "classifier/distances/distance.h"
#include "classifier/distances/euclideanDistance.h"
#include "classifier/distances/manhattanDistance.h"
#include "classifier/distances/chebyshevDistance.h"

/**
 * @brief The KNNSettings class
 *
 * This class is Responsible for setting the KNN classifier parameters,
 * given by a specific user.
 * It is a command that a user can execute, thus it inherits from the Command class.
 */
class KnnSettings : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        KnnSettings(DefaultIO* dio, int userId);

        void execute() override;
};

#endif //ASS_THREE_KNNSETTINGS_H
