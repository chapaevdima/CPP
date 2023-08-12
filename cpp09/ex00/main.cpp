#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>

bool isValidDateFormat(const std::string &dateStr) {
    if (dateStr.length() != 10) {
        return false;
    }

    if (dateStr[4] != '-' || dateStr[7] != '-') {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if (i != 4 && i != 7 && !isdigit(dateStr[i])) {
            return false;
        }
    }

    int year = atoi(dateStr.substr(0, 4).c_str());
    int month = atoi(dateStr.substr(5, 2).c_str());
    int day = atoi(dateStr.substr(8, 2).c_str());

    if (year < 1900 || year > 2023 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month != 2 && (day > daysInMonth[month])) {
        return false;
    }

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29) {
            return false;
        } else if (!isLeapYear && day > 28) {
            return false;
        }
    }

    return true;
}

bool isValidExchangeRate(const std::string &exchangeRateStr) {
    std::istringstream exchangeRateStream(exchangeRateStr);
    float exchangeRate;
    std::string trash;
    if (exchangeRateStream >> exchangeRate) {
        if (getline(exchangeRateStream, trash))
        {
            return false;
        }

        if (exchangeRate >= 0.0f) {
            return true;
        }
    }
    return false;
}

bool isValidFile(const std::string &filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return false;
    }

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date,exchange_rate") {
        std::cout << "Файл некорректный: некорректная первая строка." << std::endl;
        inputFile.close();
        return false;
    }

    std::string line;
    int lineNumber = 2;
    std::unordered_set<std::string> uniqueDates;

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr)) {

            if (!isValidDateFormat(dateStr)) {
                std::cout << "Файл некорректный: строка " << lineNumber << " некорректный формат даты." << std::endl;
                inputFile.close();
                return false;
            }

            if (!isValidExchangeRate(exchangeRateStr)) {
                std::cout << "Файл некорректный: строка " << lineNumber << " некорректный курс обмена." << std::endl;
                inputFile.close();
                return false;
            }

            if (uniqueDates.find(dateStr) != uniqueDates.end()) {
                std::cout << "Файл некорректный: строка " << lineNumber << " найден дубликат даты." << std::endl;
                inputFile.close();
                return false;
            }
            uniqueDates.insert(dateStr);
            
        } else {
            std::cout << "Файл некорректный: строка " << lineNumber << " некорректная строка." << std::endl;
            inputFile.close();
            return false;
        }

        ++lineNumber;
    }

    inputFile.close();
    return true;
}

int main() {
    std::string filename = "data.csv";

    if (!isValidFile(filename)) {
        return 1;
    }

    std::map<std::string, float> exchangeDataMap;

    std::ifstream inputFile(filename);
    std::string firstLine;
    std::getline(inputFile, firstLine);

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr)) {
            exchangeDataMap[dateStr] = static_cast<float>(atof(exchangeRateStr.c_str()));
        }
    }

    std::map<std::string, float>::const_iterator it;
    for (it = exchangeDataMap.begin(); it != exchangeDataMap.end(); ++it) {
        std::cout << "Дата: " << it->first << ", Курс обмена: " << it->second << std::endl;
    }

    return 0;
}
