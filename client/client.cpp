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
        getline(cin, input);
        dio->write(input);

        serverMessage = dio->read();

        if (serverMessage.compare("DONE\n")) {
            cout << serverMessage;
        }
    } while (serverMessage.compare("DONE\n"));
}

void Client::classifyData() const {}

void Client::displayData() const {
    string str = "garbage value";

    while (str.compare("Done.\n")) {
        str = dio->read();
        cout << str;
    }

    cout << str;
}

void Client::displayConfusionMatrix() const {
    //TODO: implement function
}

void Client::downloadData() const {
    string trainData = dio->read();
    string testData = dio->read();

    ofstream s;

    s.open("../client/data/classified_train.csv");
    if (!s.is_open()) {
        //TODO: print error
    }
    s << trainData;
    s.close();

    s.open("../client/data/classified_test.csv");\
    if (!s.is_open()) {
        //TODO: print error
    }
    s << testData;
    s.close();
}

void Client::exit() const {}