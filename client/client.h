#ifndef ASS_THREE_CLIENT_H
#define ASS_THREE_CLIENT_H

#include "server/IO/defaultIO.h"
#include "classifier/distances/distance.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include "classifier/distances/euclideanDistance.h"
#include "classifier/distances/manhattanDistance.h"
#include "classifier/distances/chebyshevDistance.h"
#include "clientSocket.h"

/**
 * @brief The Client class
 * This class is responsible for communicating with the server, from the client machine.
 */
class Client {
    private:
        // The IO method used to communicate with the server.
        ClientSocket* clientIO;

        /**
         * @breif uploadData
         * this method is responsible for uploading data to the server.
         */
        void uploadData() const;

        /**
         * @breif setKnnSettings
         * this method is responsible for setting the knn settings of the server.
         * Using the user's input, it will set the knn settings of the server.
         */
        void setKnnSettings() const;

        /**
         * @breif classifyData
         * This method is responsible for ordering the server to classify the data.
         */
        void classifyData() const;

        /**
         * @breif displayData
         * This method is responsible for ordering the server send.
         * Then the method will receive and display the data.
         */
        void displayData() const;

        /**
         * @breif downloadData
         * This method is responsible for downloading the data from the server
         * into a file given by the user.
         */
        void downloadData() const;

        /**
         * @breif displayConfusionMatrix
         * This method is responsible for receiving the confusion matrix from the server and displaying it.
         */
        void displayConfusionMatrix() const;

        /**
         * @breif exit
         * this method is responsible for exiting the run function.
         */
        void exit() const;

    public:
        /**
         * @breif Client
         * Constructor.
         * @param dio ClientSocket* - the IO to communicate with the server.
         */
        Client(ClientSocket* dio);

        /**
         * @breif run
         * This method is responsible for running the client.
         */
        void run();

        /**
         * @breif close
         * this method is responsible for closing the client.
         */
        void close();
};


#endif //ASS_THREE_CLIENT_H
