#ifndef ASS_THREE_DEFAULTIO_H
#define ASS_THREE_DEFAULTIO_H

#include <string>

using namespace std;

/**
 * @brief The DefaultIO class
 *
 * This class is Responsible for communicating with the client.
 * It is responsible for reading and writing to the client.
 * It is an abstract class, which is purposed to be inherited by other IO classes.
 */
class DefaultIO {

    public:
        /**
         * @return a string got from the client.
         */
        virtual string read() const = 0;

        /**
         * Writes a string to the client.
         * @param message - the message to write to the client.
         */
        virtual void write(string str) const = 0;

        /**
         * Close the connection with the client.
         */
        virtual void close() const = 0;

};

#endif //ASS_THREE_DEFAULTIO_H
