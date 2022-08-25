#ifndef ASS_THREE_UPLOADDATA_H
#define ASS_THREE_UPLOADDATA_H

#include "command.h"

class UploadData : public Command {

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         */
        UploadData(DefaultIO* dio, int userId);

        virtual void execute() override;
};

#endif //ASS_THREE_UPLOADDATA_H
