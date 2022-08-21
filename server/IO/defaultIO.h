#ifndef ASS_THREE_DEFAULTIO_H
#define ASS_THREE_DEFAULTIO_H

#include <string>

using namespace std;

class DefaultIO {

    public:
        virtual string read() const = 0;
        virtual void write(string str) const = 0;

};

#endif //ASS_THREE_DEFAULTIO_H
