#include "client.h"

void writeDataToFile(string* filepath, string* fileContents) {
    ofstream s;
    s.open(*filepath);
    if (!s.is_open()) {
        cout << "Error opening file : " + *filepath << endl;
    } else {
        s << *fileContents;
        s.close();
    }

    delete filepath;
    delete fileContents;
}

Client::Client(ClientSocket* dio) : clientIO(dio) {}

void Client::run() {
    int op = 1;

    while (op != 7) {
        bool validInput = false;

        do {
            cout << clientIO->read();
            string in;
            cin >> in;

            if (!in.empty()) {
                try {
                    op = stoi(in);
                } catch (invalid_argument& e) {
                    op = -1; // invalid input, to make the loop repeat.
                }
                validInput = (0 < op && op < 8);
                clientIO->write(to_string(op));
            }
        } while (!validInput);

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
    ifstream is;
    string filePath;
    while (true) {
        cout << "Please upload your local train csv file." << endl;
        cin >> filePath;
        is.open(filePath);

        if (!is) {
            cout << "File not found. ";
            is.close();
        } else {
            break;
        }
    }

    if (!is.is_open()) {
        perror("Error opening file");
    }

    string fileContents;
    fileContents.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
    is.close();

    clientIO->write(fileContents);

    cout << clientIO->read();

    while (true) {
        cout << "Please upload your local test csv file." << endl;
        cin >> filePath;
        is.open(filePath);

        if (!is) {
            cout << "File not found. ";
            is.close();
        } else {
            break;
        }
    }

    is.open(filePath);
    if (!is.is_open()) {
        perror("Error opening file");
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

void Client::classifyData() const {
    cout << clientIO->read();
}

void Client::displayData() const {
    string str = clientIO->read();

    if (str.compare("Sending data.\n")) {
        cout << str;
    } else {
        while (str.compare("Done.\n")) {
            str = clientIO->read();
            cout << str;
        }
    }

    char c;
    do {
        cin.clear();
        cin.ignore();
        c = cin.get();
    } while (c != '\n');
}

void Client::displayConfusionMatrix() const {
    string str = clientIO->read();
    if (std::equal(str.begin(), str.end(), "Sending data.\n")) {
        while(true) {
            string readString = clientIO->read();
            if (readString.compare("Not sending data.")) {
                cout << readString << endl;
            } else {
                break;
            }
        }
    } else {
        cout << str;
    }

    char c;
    do {
        cin.clear();
        cin.ignore();
        c = cin.get();
    } while (c != '\n');
}

void Client::downloadData() const {
    string str = clientIO->read();

    if (std::equal(str.begin(), str.end(), "The data hasn't been classified.\nTo classify the data "
       "choose option 3 from the options screen.\n")) {
        cout << str;

        char c;
        do {
            cin.clear();
            cin.ignore();
            c = cin.get();
        } while (c != '\n');

        return;
    }

    cout << "Enter path for data-file:\n";
    string filepath;
    cin >> filepath;

    ofstream s;
    s.open(filepath);
    bool is_open = s.is_open();
    s.close();

    while(!is_open) {
        cout << "The path you entered was not valid." << endl;
        cout << "Please enter a valid path for data-file:\n";

        cin >> filepath;

        ofstream st;
        st.open(filepath);
        is_open = st.is_open();
        st.close();
    }

    std::thread thread(writeDataToFile, new string(filepath), new string(clientIO->read()));
    thread.detach();
}

void Client::exit() const {}

void Client::close() {
    clientIO->closeConnection();
}