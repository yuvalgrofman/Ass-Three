#ifndef ASS_THREE_DISPLAYCONFUSIONMATRIX_H
#define ASS_THREE_DISPLAYCONFUSIONMATRIX_H

#include <map>
#include "command.h"

class DisplayConfusionMatrix : public Command {
    private:
        map<string, int>& getClassificationOptions() const;

    public:
        DisplayConfusionMatrix(DefaultIO* dio, int userId);
        virtual void execute() override;
};

#endif //ASS_THREE_DISPLAYCONFUSIONMATRIX_H
