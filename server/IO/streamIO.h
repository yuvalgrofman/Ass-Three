#ifndef ASS_THREE_STREAMIO_H
#define ASS_THREE_STREAMIO_H

#include "defaultIO.h"
#include <sstream>

/**
 * @brief The StreamIO class
 *
 * This class is Responsible for communicating with the client
 * via given output and input streams.
 * It is an IO class, and thus it inherits from the DefaultIO class.
 */
class StreamIO : public DefaultIO {
    private:
        stringstream& input;
        stringstream& output;

    public:
        /**
         * Constructor.
         * @param input - the input stream.
         * @param output - the output stream.
         */
        StreamIO(stringstream& input, stringstream& output);

        virtual string read() const override;
        virtual void write(string str) const override;
        virtual void close() const override;
};

#endif //ASS_THREE_STREAMIO_H
