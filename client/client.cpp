#include "client.h"


Client::Client(ClientSocket* dio) : clientIO(dio) {}

void Client::run() {
    int op = 1;

    while (op != 7) {
        bool validInput = false;

        do {
            cout << clientIO->read();
            string in;
            cin >> in;

            if (!in.empty() && std::all_of(in.begin(), in.end(), ::isdigit)) {
                op = stoi(in);
                validInput = 0 < op && op < 8;
            }
        } while (!validInput);

        clientIO->write(to_string(op));

        switch (op) {
            case 1:
                uploadData();
                break;
            case 2:
                setKnnSettings();
                break;
            case 3:
                classifyData();
                break;
            case 4:
                displayData();
                break;
            case 5:
                downloadData();
                break;
            case 6:
                displayConfusionMatrix();
                break;
            case 7:
                exit();
                break;
        }
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
    clientIO->write(fileContents);

    cout << clientIO->read();

    cout << "Please upload your local train csv file." << endl;
    cin >> filePath;

    is.open(filePath);
    if (!is.is_open()) {
        //TODO: print error
    }

    is >> fileContents;
    clientIO->write(fileContents);
}

void Client::setKnnSettings() const {
    cout << clientIO->read();

    string input;
    string serverMessage = "";

    do {
        string strk, distance;
        cin >> strk;
        cin >> distance;

        input = strk + " " + distance;

        if (!input.compare("")) {
            input = "NONE";
        }
        clientIO->write(input);

        serverMessage = clientIO->read();

        if (serverMessage.compare("DONE\n")) {
            cout << serverMessage;
        }
    } while (serverMessage.compare("DONE\n"));
}

void Client::classifyData() const {}

void Client::displayData() const {
    string str = "garbage value";

    while (str.compare("Done.\n")) {
        str = clientIO->read();
        cout << str;
    }

    cout << str;
}

void Client::displayConfusionMatrix() const {
    //TODO: implement function
}

void Client::downloadData() const {
    //TODO: implement function
}

void Client::exit() const {}

void Client::close() {
    clientIO->closeConnection();
}