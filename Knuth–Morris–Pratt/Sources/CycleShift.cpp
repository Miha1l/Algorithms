#include "CycleShift.h"

void readData(std::string& s1, std::string& s2){
    int mode;
    std::cout << "Input mode:\n1 - Terminal\n2 - File\n";
    std::cin >> mode;
    if (mode == 1){
        std::cin >> s1;
        std::cin >> s2;
    }
    else{
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        std::ifstream fin(filename);
        fin >> s1;
        fin >> s2;
        fin.close();
    }
}

int cycleShift(std::string& A, std::string& B){
    std::cout << "String A: " << A << " len = " << A.length() << '\n';
    std::cout << "String B: " << B << " len = " << B.length() << '\n';
    int res = -1;
    if (A.length() != B.length()){
        return res;
    }
    std::cout << "String B#AA: " << B + "#" + A + A << '\n';
    std::string s = B + "#" + A + A;
    int lenB = B.length();
    int lenS = s.length();
    int j = 0;
    for (int i = lenB + 1; i < lenS; i++){
        int k = i;
        while (s[j] == s[k]){
            std::cout << "s[" << j << "] = " << s[j] << "\ts[" << k << "] = " << s[k] << '\n';
            j++;
            k++;
            if (j == lenB){
                res = k - 2*lenB - 1;
                return res;
            }
        }
        j = 0;
    }
    return res;
}