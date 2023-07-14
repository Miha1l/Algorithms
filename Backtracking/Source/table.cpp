#include "table.h"

Table::Table(int N) : N(N){
    std::vector<int> tmp(N);
    for (int i = 0; i<N; i++){
        table.push_back(tmp);
    }
    int tmp1, tmp2;

    if (!(N % 2)){
        tmp1 = N/2;
        tmp2 = tmp1;
    }
    else if (!(N % 3)){
        tmp1 = N*2/3;
        tmp2 = N/3;
    }
    else if (!(N % 5)){
        tmp1 = N*3/5;
        tmp2 = N*2/5;
    }
    else{
        tmp1 = (N+1)/2;
        tmp2 = (N-1)/2;
    }

    addSquare(0, 0, tmp1);
    addSquare(tmp1, 0, tmp2);
    addSquare(0, tmp1, tmp2);
    curSolution.push_back({1, 1, tmp1});
    curSolution.push_back({tmp1 + 1, 1, tmp2});
    curSolution.push_back({1, tmp1 + 1, tmp2});
    curCount = 3;
    countOperation = 3;
    bestCount = 2*N + 1;
}

void Table::addSquare(int x, int y, int size){
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            table[i][j] = 1;
        }
    }
}

void Table::deleteSquare(int x, int y, int size){
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            table[i][j] = 0;
        }
    }
}

void Table::printRes(){
    std::cout << bestCount << '\n';
    for (const auto& square: bestSolution){
        std::cout << square.x << ' ' << square.y << ' ' << square.size << '\n';
    }
    std::cout << "Count operations: " << countOperation << '\n';
}

bool Table::isFree(int x, int y, int size){
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (table[i][j]){
                return false;
            }
        }
    }
    return true;
}

void Table::backtracking(){
    bool flag = true;
    int curX, curY;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!table[i][j]){
                flag = false;
                curX = j;
                curY = i;
                break;
            }
        }
        if (!flag){
            break;
        }
    }

    if (curCount >= bestCount){
        return;
    }

    if (flag){
        bestCount = curCount;
        bestSolution = curSolution;
        return;
    }
    
    for (int i = N - 1; i > 0; i--){
        if (curX + i > N || curY + i > N || !isFree(curX, curY, i)){
            continue;
        }
        addSquare(curX, curY, i);
        countOperation++;
        curSolution.push_back({curX + 1, curY + 1, i});
        curCount++;
        backtracking();
        deleteSquare(curX, curY, i);
        curSolution.pop_back();
        curCount--;
    }
}