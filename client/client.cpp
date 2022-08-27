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
    fileContents.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
    is.close();

    clientIO->write(fileContents);

    cout << clientIO->read();

    cout << "Please upload your local test csv file." << endl;
    cin >> filePath;

    is.open(filePath);
    if (!is.is_open()) {
        //TODO: print error
    }

    fileContents.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
    clientIO->write(fileContents);
    is.close();

    clientIO->read();
}

void Client::setKnnSettings() const {
    cout << clientIO->read();

    string input;
    string serverMessage = "";

    do {
        cin.clear();
        cin.ignore();
        string strk, distance;
        char c = cin.get();

        if (c == '\n') {
            input = "NONE";
        } else {
            cin.putback(c);
            cin >> strk;
            cin >> distance;

            input = strk + " " + distance;
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
}

void Client::displayConfusionMatrix() const {
    string str = "garbage value";

    while (str.compare("Done.\n")) {
        str = clientIO->read();
        cout << str << endl;
    }
}

void Client::downloadData() const {
    string trainData = clientIO->read();
    string testData = clientIO->read();

    ofstream s;

    s.open("../client/data/classified_train.csv");
    if (!s.is_open()) {
        //TODO: print error
    }
    s << trainData;
    s.close();

    s.open("../client/data/classified_test.csv");
    if (!s.is_open()) {
        //TODO: print error
    }
    s << testData;
    s.close();
}

void Client::exit() const {}

void Client::close() {
    clientIO->closeConnection();
}