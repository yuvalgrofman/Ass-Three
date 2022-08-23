
cmake_minimum_required(VERSION 3.16)
project(Ass-Three)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(AssThree.out
        classifier/distances/chebyshevDistance.cpp
        classifier/distances/chebyshevDistance.h
        classifier/dataspace/dataSpace.cpp
        classifier/dataspace/dataSpace.h
        classifier/dataspace/dataSpaceCreator.cpp
        classifier/dataspace/dataSpaceCreator.h
        classifier/distances/distance.h
        classifier/distances/euclideanDistance.cpp
        classifier/distances/euclideanDistance.h
        classifier/distances/manhattanDistance.cpp
        classifier/distances/manhattanDistance.h
        classifier/classifier.cpp
        classifier/classifier.h
        server/server.h
        server/server.cpp
        main.cpp
        server/server_handler.cpp
        server/server_handler.h
        server/command/command.h
        server/IO/defaultIO.h
        server/command/recvData.cpp
        server/command/recvData.h
        server/command/knnSettings.cpp
        server/command/knnSettings.h
        server/command/command.cpp
        server/IO/standardIO.cpp
        server/IO/standardIO.h
        server/IO/socketIO.h
        server/IO/socketIO.cpp
        server/command/classifyData.h
        server/command/classifyData.cpp
        server/command/displayData.cpp
        server/command/displayData.h
        server/command/uploadData.cpp
        server/command/uploadData.h
        server/command/close.cpp
        server/command/close.h
        server/command/displayConfusionMatrix.cpp
        server/command/displayConfusionMatrix.h
        classifier/classifiable/classifiable.cpp
        classifier/classifiable/classifiable.h
        classifier/classifiable/dataPoint.cpp
        classifier/classifiable/dataPoint.h
        classifier/classifiable/dataReader.cpp
        classifier/classifiable/dataReader.h
        classifier/classifiable/dataSorter.cpp
        classifier/classifiable/dataSorter.h
        )