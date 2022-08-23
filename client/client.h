#ifndef ASS_THREE_CLIENT_H
#define ASS_THREE_CLIENT_H

#include "server/IO/defaultIO.h"
#include "classifier/distances/distance.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "classifier/distances/euclideanDistance.h"
#include "classifier/distances/manhattanDistance.h"
#include "classifier/distances/chebyshevDistance.h"


class Client {
    private:
        DefaultIO* dio;

        void uploadData() const;
        void setKnnSettings() const;
        void classifyData() const;
        void displayData() const;
        void downloadData() const;
        void displayConfusionMatrix() const;
        void exit() const;

    public:
        Client(DefaultIO* dio);
        void run();
        void close();
};


#endif //ASS_THREE_CLIENT_H
