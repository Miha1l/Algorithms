#include "table.h"

int main(){
    int N;
    std::cout << "Enter table size\n";
    std::cin >> N;
    Table table(N);
    table.backtracking();
    table.printRes();
    return 0;
}