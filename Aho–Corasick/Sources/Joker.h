#ifndef JOKER
#define JOKER

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

struct Node{
    std::map<char, int> nextNode;
    std::vector<int> patNum;
    bool isTerm = false;
    int parent = -1;
    char edgeSym;
    int suffLink = -1;
    int termLink = -1;
    std::map<char, int> move;
};

class Bohr{
private:
    std::string text;
    std::string pattern;
    std::vector<std::pair<std::string, int>> patterns;
    std::vector<int> answer;
    std::vector<Node> bohr;
public:
    Bohr();
    void createBohr();
    void addString(std::string& s, int n);
    int getSuffLink(int v);
    int getMove(int v, char c);
    int getTermLink(int v);
    void check(int v, int i);
    void findSubstringsPos();
    void doAlgorithm();
};

#endif