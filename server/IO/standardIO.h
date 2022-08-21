#ifndef ASS_THREE_STANDARDIO_H
#define ASS_THREE_STANDARDIO_H

#include "defaultIO.h"

class StandardIO : DefaultIO {
    public:
        virtual string read() const override;
        virtual void write(string str) const override;
};


#endif //ASS_THREE_STANDARDIO_H
