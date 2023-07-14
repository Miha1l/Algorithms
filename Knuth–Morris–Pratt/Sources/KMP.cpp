#include "KMP.h"

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

std::vector<int> prefixFunction(std::string s){
    int n = s.length();
    std::vector<int> pi(n, 0);
    std::cout << "pi[0] = " << pi[0] << '\n';
    for (int i = 1; i < n; i++){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if (s[i] == s[j]){
            pi[i] = j + 1;
        }
        else{
            pi[i] = j; 
        }
        std::cout << "pi[" << i << "] = " << pi[i] << '\n';
    }
    return pi;
}

std::vector<int> kmp(std::string P, std::string T){
    std::cout << "String P: " << P << " len = " << P.length() << '\n';
    std::cout << "String T: " << T << " len = " << T.length() << '\n';
    std::cout << "String P#T: " << P + "#" + T << '\n';
    std::vector<int> pi = prefixFunction(P + "#" + T);
    std::vector<int> index;
    int lenP = P.length();
    int lenT = T.length();
    for (int i = 0; i < lenT; i++){
        if (pi[lenP + i + 1] == lenP){
            index.push_back(i - lenP + 1);
        }
    }
    if (index.empty()){
        index.push_back(-1);
    }
    return index;
}