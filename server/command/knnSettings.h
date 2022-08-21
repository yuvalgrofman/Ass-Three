#ifndef ASS_THREE_KNNSETTINGS_H
#define ASS_THREE_KNNSETTINGS_H

#include "command.h"
#include <sstream>
#include "classifier/distances/distance.h"
#include "classifier/distances/euclideanDistance.h"
#include "classifier/distances/manhattanDistance.h"
#include "classifier/distances/chebyshevDistance.h"

class KnnSettings : Command {

    private:
        int userId;

        int getK();
        Distance* getDistance();

    public:
        KnnSettings(int userId);
        void execute() override;
};

#endif //ASS_THREE_KNNSETTINGS_H
