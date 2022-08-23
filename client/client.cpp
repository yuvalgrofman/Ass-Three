#include "client.h"

Client::Client(DefaultIO* dio) : dio(dio) {}

void Client::run() {
    int op = 1;

    while (op != 7) {
        bool validInput = false;

        do {
            string in;
            cin >> in;

            if (!in.empty() && std::all_of(in.begin(), in.end(), ::isdigit)) {
                op = stoi(in);
                validInput = 0 < op && op < 8;
            }
        } while (!validInput);

        dio->write(to_string(op));

//        switch (op) {
//            case 1:
//                uploadData();
//                break;
//            case 2:
//
//        }
    }
}

void Client::uploadData() const {
    string filePath;
    cout << "Please upload your local train csv file." << endl;
    cin >> filePath;

    ifstream is;
    is.open(filePath);
    if (!is.is_open()) {
        //TODO: print error
    }

    string fileContents;
    is >> fileContents;
    dio->write(fileContents);

    cout << dio->read();

    cout << "Please upload your local train csv file." << endl;
    cin >> filePath;

    is.open(filePath);
    if (!is.is_open()) {
        //TODO: print error
    }

    is >> fileContents;
    dio->write(fileContents);
}

void Client::setKnnSettings() const {
    cout << dio->read();

    string input;
    string serverMessage = "";

    do {
        cin >> input;
        dio->write(input);

        serverMessage = dio->read();

        if (serverMessage.compare("DONE")) {
            cout << serverMessage;
        }
    } while (serverMessage.compare("DONE"));
}