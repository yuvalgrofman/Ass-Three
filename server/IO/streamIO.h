#ifndef ASS_THREE_STREAMIO_H
#define ASS_THREE_STREAMIO_H

#include "defaultIO.h"
#include <sstream>

class StreamIO : public DefaultIO {
private:
    stringstream& input;
    stringstream& output;

public:
    StreamIO(stringstream& input, stringstream& output);
    virtual string read() const override;
    virtual void write(string str) const override;
    virtual void close() const override;
};

#endif //ASS_THREE_STREAMIO_H
