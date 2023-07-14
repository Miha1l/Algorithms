#ifndef AXO
#define AXO

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b);

struct Node{
    std::map<char, int> nextNode;
    int patNum = 0;
    int parent = -1;
    char edgeSym;
    int suffLink = -1;
    int termLink = -1;
    std::map<char, int> move;
};

class Bohr{
private:
    std::string text;
    std::vector<std::string> patterns;
    std::vector<std::pair<int, int>> answer;
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