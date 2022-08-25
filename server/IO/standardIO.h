#ifndef ASS_THREE_STANDARDIO_H
#define ASS_THREE_STANDARDIO_H

#include "defaultIO.h"
#include <iostream>

/**
 * @brief The StandardIO class
 *
 * This class is Responsible for communicating with the client via the terminal.
 * It is an IO class, and thus it inherits from the DefaultIO class.
 */
class StandardIO : public DefaultIO {

    public:
        virtual string read() const override;
        virtual void write(string str) const override;
        virtual void close() const override;
};


#endif //ASS_THREE_STANDARDIO_H
