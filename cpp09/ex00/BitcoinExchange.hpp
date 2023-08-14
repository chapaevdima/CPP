#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <set>

bool isValidDateFormat(const std::string &dateStr);
bool isValidExchangeRate(const std::string &exchangeRateStr);
bool isValidDataFile(const std::string &filename);
void parsingData( std::map<std::string, float>& exchangeDataMap);
void myPrint(const std::map<std::string, float>& exchangeDataMap, const std::string& line, float value);
bool checkLine(std::string line);
void inputParsing(const std::map<std::string, float> exchangeDataMap, const std::string ifname);

#endif