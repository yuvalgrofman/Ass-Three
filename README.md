# **KNN Classifier**

## About The Project

Our project predicts classifications using the KNN algorithm with a k value between 1 and 10, and one of the following 
distance metrics: euclidean, manhattan, chebyshev.

The number of attributes that every data point has is up to the user of the program.
Although please note that the number of attributes must be the same for all the data points of the train and test files.
Though if you replace both files, you can change the number of attributes, as long as the new number is the same for both files.


The project is divided into to parts, The server and the clients.
They communicate using the TCP protocol.


**information about the server:**

    The server is responsible for receiving the data from multiple clients,
    and running the knn algorithm on that data, based on the k value and distance metric, given by each client.
    The server is also responsible for sending the results to the clients, based on their requests.
    The server can deal with multiple clients at the same time, using a thread for each client. 

**information about the clients:**

    Each clients is responsible for sending the data inputted by a specific user to the server,
    and receiving the results from the server, based on the user's requests.
   

## Running The Whole Project

In order to run the project, the user must first run the server according to the running instructions in the server's
part of this README.md file. and then run the clients according to the running instructions in the 
client's part of this file.

As mentioned earlier, the server can deal with multiple clients at the same time, and thus the user can run 
multiple clients at the same time and independently from each other.


# Getting Started

## 1) Prerequisites

This project requires CMake (3.16 or above) in order to function properly.
To install CMake, follow the instructions [here](https://cmake.org/install/). In addition, a cpp compiler that supports c++11 is required.

## 2) Install And Run Project

Firstly, clone the project from the GitHub repository:

        git clone 'https://github.com/yuvalgrofman/Ass_Two'

Then, to run the server, based on the instructions in the server's part of this README.md file,
followed by the clients, based on the instructions in the client's part of this README.md file.


### 3) .csv Files

This project relies on two .csv files to properly function.
1. train.csv - contains the classified data point, and is used for training the KNN algorithm.

    This file contains the following columns (separated by a comma):

   - Attribute 1 - the first attribute of the data point.
   - Attribute 2 - the second attribute of the data point.
   - Attribute 3 - the third attribute of the data point.
   - ....
   - ....
   - Attribute n - the n'th attribute of the data point.
   - Type - the type of the flower.

2. test.csv - contains the data of unclassified data points, and is used to predict the type of the data points inside it.

    This file contains the following columns (separated by a comma):

   - Attribute 1 - the first attribute of the data point.
   - Attribute 2 - the second attribute of the data point.
   - Attribute 3 - the third attribute of the data point.
   - ....
   - ....
   - Attribute n - the n'th attribute of the data point.
   
**please note that the number of attributes must be the same for all the data points of the train and test files.**


Each client could send its train and test files to the server, and is given them by the user.
The client can also later send a new train and test files to the server, but note that the previous train and test files will be deleted.

Please note, that these **csv file must end with a blank line**. Otherwise, the program will not operate properly.


## Communication between clients and server
After a client is accepted, the server sends the client a list of 7 things it could run:

1. upload train and test files.

   The client sends the server the train and test csv files, and the server saves them to its data directory.
   if the client already sent a train and test files, the server will delete them and replace them with the new ones.
   In addition, if the client sends invalid test or train files the server's behavior is undefined.
   (Information about the format of a valid train and test files can be found in the previous section).


2. change the settings of the KNN algorithm (k value and distance metric).

   The server sends the client the current settings of the KNN algorithm, and the client can change them and send them back to the server. The settings for each client are stored in a config file, in the server's data directory.


3. classify the test data.

   the server runs the KNN algorithm on the test data points, based on the train data points, and the settings of the KNN algorithm. It saves the results to a file in the server's data directory.


4. display the results of the last classification.

   The server sends the prediction results of the classification process performed in option 3. If option 3 wasn't performed before this, it will tell the client that it must perform option 3 first. otherwise, it will send the results of the last classification, and the client will display them on the screen.


5. download the results of the last classification. 1. display confusion matrix.

   The server sends the prediction results of the classification process performed in option 3. If option 3 wasn't performed before this, it will tell the client that it must perform option 3 first. otherwise, it will send the results of the last classification, and the client save the results to a file whose path will be given by the user.

   This option will be run on different threads, and so the client will be able to run other options while this option is running.


6. display confusion matrix.

   The server will classify the train data points, based on the train data points, and the settings of the KNN algorithm. It will then compare its prediction with the real classification of the train data, calculate the confusion matrix, and send it to the client. Then the client will display the confusion matrix on the screen.


7. exit.

   The connection between the client and the server will be closed, and the server thread that deals with the client will be terminated.

Additionally, if the client or server are terminated artificially by the user, then errors might occur and the programs functionality is not defined.

# The Server

As mentioned above, the project contains a server and a client.
This part of the README.md is dedicated to the server.

## Running The Server

Firstly, assuming the project has been installed navigate to the project file, most likely called Ass-Three.
Then execute the following commands:

        mkdir -p build && cd build
        cmake ..
        make -j
        ./Server

After executing the mentioned commands, the server will be run and wait for clients.

## Output

The server doesn't have an output of its own, but it does send messages to the clients, based on their requests,
and so helps create an output for the clients. 

## Algorithm

### Reciving new clients

The server is responsible for receiving new clients. 
It deals with each client in a different thread, and so can deal with multiple clients at the same time.

The server stops accepting clients 60 seconds after the last client connects to the server.

**Please note that if a client tries to connect to the server, but the server is not running or stopped accepting clients, 
then the client will not be able to connect, and an exception would be displayed on the screen.**

### Classifier algorithm
The classifier algorithm works, by reading the classified data points from the train file given by the user, 
and then using the KNN algorithm to predict the type of the unclassified data points from the test file given by the user.

It also can predict the types of the classified data points from the train file, and compare the results 
to the actual types of the data points. To display a confusion matrix, for the results of the prediction.

To predict the classifications of each file's data, it separately predicts the type of each data point from that file.
To do so, it sorts the list of data points from the train file, based on the distance between the data point it is 
trying to predict, and the classified data points from the train file. It then takes the k closest data points from 
the train file, and predicts the type of the data point based on the most common type from the k closest data points.

The k value is a value between 1 and 10, and decided by the user. And also the distance metric is one of the following:
    CHEBYSHEV, EUCLIDEAN, MANHATTAN. And is also decided by the user.
if the user doesn't give a k value or a distance metric, the default values are 5 and EUCLIDEAN respectively.

**please note that in the program, the name of each of the distance metrics is shortened to its first 3 letters, and
is written in capital letters.**

## Additional Info

Firstly, the algorithm currently supports running the client and server on the same machine.
In order to change this behavior, the ip address in the client must be changed. Moreover, the port used by the server is 5555, the client also uses the same port number.

Secondly, This algorithm automatically sets the k value used in the KNN algorithm to 5
and the distance metric used is the euclidean distance.

Thirdly, there exists default train and test files called classified.csv and Unclassified.csv accordingly.
These files are placed in `client/data` directory, the relative path from the build file is `../client/data`.

Finally, if a client tries to connect to the server after the timeout length passed and the server isn't accepting more clients, 
the client will just wait until the server closes and then will print the error message `connection refused`.

# The Client

As mentioned above, the project contains a server and a client.
This part of the README.md is dedicated to the client.

## Running A Client

Executing the client is similar to executing the server.
Note that if the server has already been made using the build, cmake and make commands
then the client can immediately be run. 
This can be done by navigating to the dir Ass-Three/build and executing the command `./Client` in the terminal.

Otherwise, assuming the project has been installed navigate to the project file, most likely called Ass-Three.
Then execute the following commands:

        mkdir -p build && cd build
        cmake ..
        make -j
        ./Client

This will run the client, and it will connect to the server.

## Output

The output of each client is dependent on the user's input, and requests.
and is dependent on the options the user chooses to run, from the options menu.


# Additional Notes
- If a client classifies a file that it uploaded, and then changed the configuration of the KNN algorithm, 
  then the results of the classification will be still based on the new configuration of the KNN algorithm, until the client classifies it again.

- If a client classifies a file that it uploaded, and  then uploaded a new file then the results of the classification based on the old file will be deleted from the server. Although offcurse if the client already downloaded the results of the classification, then the results will still be saved on the client's machine.

- To run the confusion matrix option, the client doesn't have to classify the data beforehand.

- Some of the options that the client can run, need the user to input an "ENTER" key-press, in order to continue the program. So if the options menu doesn't appear, after an option has been run, then the user must press the "ENTER" key.

## Authors

[Yuval Grofman](https://github.com/yuvalgrofman)

[Jonathan Moiseyev](https://github.com/OldRimStalker)