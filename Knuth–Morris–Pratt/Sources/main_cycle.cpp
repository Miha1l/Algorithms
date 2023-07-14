#include "CycleShift.h"

int main(){
    std::string A;
    std::string B;
    readData(A, B);
    int res = cycleShift(A, B);
    std::cout << res << '\n';
    return 0;
}