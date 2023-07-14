#include "Joker.h"

Bohr::Bohr(){
    Node root;
    bohr.push_back(root);
}

void Bohr::createBohr(){
    std::cout << "Enter text: ";
    std::cin >> text;
    std::cout << "Enter pattern: ";
    std::cin >> pattern;
    std::cout << "Enter joker: ";
    char joker;
    std::cin >> joker;
    std::string tmp = "";
    for (int i = 0; i < pattern.length(); i++){
        if (pattern[i] == joker){
            if (tmp.length()){
                patterns.push_back(std::make_pair(tmp, i - tmp.length()));
                addString(tmp, patterns.size() - 1);
            }
            tmp = "";
        }
        else{
            tmp.push_back(pattern[i]);
        }
    }
    if (tmp.length()){
        patterns.push_back(std::make_pair(tmp, pattern.length() - tmp.length()));
        addString(tmp, patterns.size() - 1);
    }
    answer.resize(text.length());
    std::fill(answer.begin(), answer.end(), 0);
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
    bohr[num].patNum.push_back(n);
    bohr[num].isTerm = true;
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
            bohr[v].termLink = (bohr[u].isTerm) ? u : getTermLink(u);
        }
    }
    return bohr[v].termLink;
}

void Bohr::check(int v, int i){
    for (int u = v; u != 0; u = getTermLink(u)){
        if (bohr[u].isTerm){
            for (auto& ind: bohr[u].patNum){
                int dif = i - patterns[ind].first.length() + 1 - patterns[ind].second;
                if (dif > -1){
                    answer[dif]++;
                }
            }
        }
    }
}

void Bohr::findSubstringsPos(){
    int u = 0;
    for (int i = 0; i < text.length(); i++){
        u = getMove(u, text[i]);
        check(u, i);
    }
}

void Bohr::doAlgorithm(){
    findSubstringsPos();
    for (int i = 0; i <= answer.size() - pattern.length(); i++){
        if (answer[i] == patterns.size()){
            std::cout << i + 1 << '\n';
        }
    }
}