#include "displayData.h"

DisplayData::DisplayData(DefaultIO *dio, int userId) : Command(dio, userId, "display results") {}

void DisplayData::execute() {
    ifstream istream("../server/data/user_" + to_string(userId)
    + "_train_prediction.csv");

    string word;
    int lineNumber = 1;

    while(getline(istream, word)) {
        dio->write(to_string(lineNumber) + " " + word + "\n");
    }

    dio->write("Done.");
}