#include "cli.h"

using namespace std;

map<int, Command*>* getCommands(DefaultIO* dio, int userId) {
    map<int, Command*>* map = new ::map<int, Command*>();

    map->insert(std::make_pair(1, new RecvData(dio, userId)));
    map->insert(std::make_pair(2, new KnnSettings(dio, userId)));
    map->insert(std::make_pair(3, new ClassifyData(dio, userId)));
    map->insert(std::make_pair(4, new DisplayData(dio, userId)));
    map->insert(std::make_pair(5, new UploadData(dio, userId)));
    map->insert(std::make_pair(6, new DisplayConfusionMatrix(dio, userId)));
    map->insert(std::make_pair(7, new Close(dio, userId)));

    return map;
}

CLI::CLI(DefaultIO *dio, int userId) : dio(dio), userId(userId) {
    string config = "../server/data/user_" + to_string(userId) + "_config.csv";
    ofstream configStream(config);

    string trainUnclassified = "../server/data/user_" + to_string(userId) + "_train.csv";
    ofstream trainUnclassifiedStream(trainUnclassified);

    string testUnclassified = "../server/data/user_" + to_string(userId) + "_test.csv";
    ofstream testUnclassifiedStream(testUnclassified);

    string trainPredict = "../server/data/user_" + to_string(userId) + "_train_prediction.csv";
    ofstream trainPredictStream(trainPredict);

    string testPredict = "../server/data/user_" + to_string(userId) + "_test_prediction.csv";
    ofstream testPredictStream(testPredict);
}

void CLI::run() {
    map<int, Command*>* map = getCommands(dio, userId);
    int op = 1;

    while (op != 7) {
        bool validInput = false;

        do {
            string options;

            std::for_each(map->begin(), map->end(), [&](std::pair<const int, Command*>& pair) {
                options += (to_string(pair.first) + ". " + pair.second->getDescription() + "\n");
            });

            dio->write(options);

            string in = dio->read();

            if (!in.empty() && std::all_of(in.begin(), in.end(), ::isdigit)) {
                op = stoi(in);
                validInput = (0 < op && op <= NUM_OF_COMMANDS);
            }
        } while (!validInput);

        map->at(op)->execute();
    }

    for(int i = 1; i <= NUM_OF_COMMANDS; i++) {
        delete map->at(i);
    }
    delete map;
}

void CLI::close() {

    string config = "../server/data/user_" + to_string(userId) + "_config.csv";
    ifstream configStream(config);
    if (configStream && remove((config).c_str()))
        perror((config).c_str());

    string trainUnclassified = "../server/data/user_" + to_string(userId) + "_train.csv";
    ifstream trainUnclassifiedStream(trainUnclassified);
    if (trainUnclassifiedStream && remove((trainUnclassified).c_str()))
        perror((trainUnclassified).c_str());

    string testUnclassified = "../server/data/user_" + to_string(userId) + "_test.csv";
    ifstream testUnclassifiedStream(testUnclassified);
    if (testUnclassifiedStream && remove((testUnclassified).c_str()))
        perror((testUnclassified).c_str());

    string trainPredict = "../server/data/user_" + to_string(userId) + "_train_prediction.csv";
    ifstream trainPredictStream(trainPredict);
    if (trainPredictStream && remove((trainPredict).c_str()))
        perror((trainPredict).c_str());

    string testPredict = "../server/data/user_" + to_string(userId) + "_test_prediction.csv";
    ifstream testPredictStream(testPredict);
    if (testPredictStream && remove((testPredict).c_str()))
        perror((testPredict).c_str());

    dio->close();
}

CLI::~CLI() {
    delete dio;
}