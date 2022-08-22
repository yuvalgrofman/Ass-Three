#ifndef ASS_THREE_UPLOADDATA_H
#define ASS_THREE_UPLOADDATA_H

#include "command.h"

class UploadData : public Command {

    public:
        UploadData(DefaultIO* dio, int userId);
        virtual void execute() override;
};

#endif //ASS_THREE_UPLOADDATA_H
