#ifndef ASS_THREE_CLASSIFYDATA_H
#define ASS_THREE_CLASSIFYDATA_H

#include "command.h"

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
