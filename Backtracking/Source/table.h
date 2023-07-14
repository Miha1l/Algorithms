#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>

struct Square{
    int x;
    int y;
    int size;
};

class Table{
private:
    std::vector<std::vector<int>> table;
    std::vector<Square> bestSolution;
    std::vector<Square> curSolution;
    int bestCount;
    int curCount;
    int countOperation;
    int N;
public:
    Table(int N);
    void addSquare(int x, int y, int size);
    void deleteSquare(int x, int y, int size);
    void printRes();
    bool isFree(int x, int y, int size);
    void backtracking();
};

#endif