#ifndef ASS_THREE_STANDARDIO_H
#define ASS_THREE_STANDARDIO_H

#include "defaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO {

    public:
        virtual string read() const override;
        virtual void write(string str) const override;
        virtual void close() const override;
};


#endif //ASS_THREE_STANDARDIO_H
