#include "server.h"

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

Server::Server(DefaultIO *dio, int userId) : dio(dio), userId(userId) {}

void Server::run() {
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
                validInput = 0 < op && op < 8;
            }
        } while (!validInput);

        map->at(op)->execute();
    }
}

void Server::close() {
    //TODO: remove files server created
    //    if (remove("../server/data/user...")) ...
    dio->close();
}
