#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cout << "Error, could not open file." << std::endl;
        return 1;
    }

    std::string ifname = argv[1];

    if (!isValidDataFile("data.csv")) {
        return 1;
    }

    std::map<std::string, float> exchangeDataMap;

    parsingData(exchangeDataMap);
    inputParsing(exchangeDataMap, ifname);

    return 0;
}
