#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readData(std::string& s1, std::string& s2);
std::vector<int> prefixFunction(std::string s);
std::vector<int> kmp(std::string P, std::string T);

#endif