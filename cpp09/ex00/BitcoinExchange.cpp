# include "BitcoinExchange.hpp"

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

bool isValidDataFile(const std::string &filename) {
    std::ifstream inputFile(filename.c_str());

    if (!inputFile.is_open()) {
        std::cout << "Error, could not open file." << std::endl;
        return false;
    }

    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine != "date,exchange_rate") {
        std::cout << "File is incorrect: incorrect first line." << std::endl;
        inputFile.close();
        return false;
    }

    std::string line;
    int lineNumber = 2;
    std::set<std::string> uniqueDates;

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, exchangeRateStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, exchangeRateStr)) {

            if (!isValidDateFormat(dateStr)) {
                std::cout << "File is incorrect: line " << lineNumber << ": incorrect date format." << std::endl;
                inputFile.close();
                return false;
            }

            if (!isValidExchangeRate(exchangeRateStr)) {
                std::cout << "File is incorrect: line" << lineNumber << ": incorrect exchange rate." << std::endl;
                inputFile.close();
                return false;
            }

            if (uniqueDates.find(dateStr) != uniqueDates.end()) {
                std::cout << "File is incorrect: line" << lineNumber << ": found a duplicate date." << std::endl;
                inputFile.close();
                return false;
            }
            uniqueDates.insert(dateStr);
            
        } else {
            std::cout << "File is incorrect: line" << lineNumber << ": incorrect line" << std::endl;
            inputFile.close();
            return false;
        }

        ++lineNumber;
    }

    inputFile.close();
    return true;
}

void parsingData( std::map<std::string, float>& exchangeDataMap)
{
    std::ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        std::cout << "Error, could not open file." << std::endl;
        return;
    }
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
}

void myPrint(const std::map<std::string, float>& exchangeDataMap, const std::string& line, float value)
{
    std::map<std::string, float>::const_iterator it;
    it = exchangeDataMap.begin();

    if (line < it->first)
    {
        std::cout << line << " => 0 (no info)" << std::endl;
        return;
    }

    for (; it != exchangeDataMap.end(); ++it)
    {
        if (it->first > line && it != exchangeDataMap.begin())
        {
            --it;
            std::cout << line << " => " << it->second * value << std::endl;
            return;
        }

        if (it->first == line)
        {
            std::cout << line << " => " << it->second * value << std::endl;
            return;
        }
    }
    
    --it;
    std::cout << line << " => " << it->second * value << std::endl;
}

bool checkLine(std::string line)
{
    if(isdigit(line[0]) == false || line[10] != ' ' || line[11] != '|' || line[12] != ' ' || (isdigit(line[13]) == false && line[13] != '-'))
    {
        return false;
    }
    return true;
}

void inputParsing(const std::map<std::string, float> exchangeDataMap, const std::string ifname)
{
    std::ifstream inputFile(ifname.c_str());
    
    if (!inputFile.is_open()) {
        std::cout << "Error, could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    if(line != "date | value")
    {
        std::cout << ifname << ": first line error" << std::endl;
        return;
    }

    while(getline(inputFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        float value;
        char c;
        if(checkLine(line) == true && ss >> date >> c >> value && ss.eof())
        {
            if (isValidDateFormat(date) == false)
            {
                std::cout << "Error: bad input => " << date << std::endl; 
            }
            else if (value < 0.0f)
            {
                std::cout << "Error: not a positive number." << std::endl; 
            }
            else if (value > 1000.0f)
            {
                std::cout << "Error: too large a number." << std::endl; 
            }
            else
                myPrint(exchangeDataMap, date, value);
        } else
        {
            std::cout << "Error: bad input: " << line <<std::endl;
        }

    }

}