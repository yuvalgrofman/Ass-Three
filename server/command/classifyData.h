#ifndef ASS_THREE_CLASSIFYDATA_H
#define ASS_THREE_CLASSIFYDATA_H

#include "command.h"

class ClassifyData : Command{

    public:
            ClassifyData(DefaultIO* dio, int userId);
            virtual void execute() override;

};

#endif //ASS_THREE_CLASSIFYDATA_H
