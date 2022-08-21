#include "close.h"

Close::Close(DefaultIO *dio, int userId) : Command(dio, userId) {
    description.assign("exit");
}

void Close::execute() {
    dio->close();
}