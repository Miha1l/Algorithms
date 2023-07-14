#include "Axo.h"

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

Bohr::Bohr(){
    Node root;
    bohr.push_back(root);
}

void Bohr::createBohr(){
    std::cout << "Enter text: ";
    std::cin >> text;
    int n;
    std::cout << "Enter number of patterns: ";
    std::cin >> n;
    std::cout << "Enter patterns:\n";
    std::string p;
    for (int i = 0; i<n; i++){
        std::cin >> p;
        addString(p, i+1);
        patterns.push_back(p);
    }
}

void Bohr::addString(std::string& s, int n){
    int num = 0;
    for (auto& sym: s){
        if (!bohr[num].nextNode[sym]){
            std::cout << "Added symbol: " << sym << '\n';
            Node tmp;
            tmp.parent = num;
            tmp.edgeSym = sym;
            bohr.push_back(tmp);
            bohr[num].nextNode[sym] = bohr.size() - 1;
        }
        num = bohr[num].nextNode[sym];
    }
    bohr[num].patNum = n;
    
}

int Bohr::getSuffLink(int v){
    if (bohr[v].suffLink == -1){
        if (v == 0 || bohr[v].parent == 0){
            bohr[v].suffLink = 0;
        }
        else{
            bohr[v].suffLink = getMove(getSuffLink(bohr[v].parent), bohr[v].edgeSym);
        }
    }
    return bohr[v].suffLink;
}

int Bohr::getMove(int v, char c){
    if (!bohr[v].move[c]){
        if (bohr[v].nextNode[c]){
            bohr[v].move[c] = bohr[v].nextNode[c];
        }
        else{
            if (v == 0){
                bohr[v].move[c] = 0;
            }
            else{
                bohr[v].move[c] = getMove(getSuffLink(v), c);
            }
        }
    }
    return bohr[v].move[c];
}

int Bohr::getTermLink(int v){
    if (bohr[v].termLink == -1){
        int u = getSuffLink(v);
        if (u == 0){
            bohr[v].termLink = 0;
        }
        else{
            bohr[v].termLink = (bohr[u].patNum) ? u : getTermLink(u);
        }
    }
    return bohr[v].termLink;
}

void Bohr::check(int v, int i){
    for (int u = v; u != 0; u = getTermLink(u)){
        if (bohr[u].patNum){
            answer.push_back(std::make_pair(i - patterns[bohr[u].patNum - 1].length() + 1, bohr[u].patNum));
        }
    }
}

void Bohr::findSubstringsPos(){
    int u = 0;
    for (int i = 0; i < text.length(); i++){
        u = getMove(u, text[i]);
        check(u, i + 1);
    }
}

void Bohr::doAlgorithm(){
    findSubstringsPos();
    std::sort(answer.begin(), answer.end(), cmp);
    for (auto& el: answer){
        std::cout << el.first << " " << el.second << '\n';
    }
}