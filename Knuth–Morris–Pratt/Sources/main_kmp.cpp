#include "KMP.h"

int main(){
    std::string P;
    std::string T;
    readData(P, T);
    std::vector<int> answer;
    answer = kmp(P, T);
    for (int i = 0; i < answer.size(); i++){
        std::cout << answer[i];
        if (i != answer.size() - 1){
            std::cout << ',';
        }
    }
    std::cout << '\n';
    return 0;
}