//
// Created by onikenx on 12/7/20.
//

#include <fstream>
#include <set>
#include <map>
#include <iostream>
#include "day6.h"
void day6::run() {
    std::ifstream input("day6input.txt");
    std::string x;
    int soma1 = 0;
    int soma2 = 0;
    int lines = 0;
    std::map<char, int> mapa;
    std::set<char> letras;
    while (getline(input, x)) {
        //caso esteja empty
        if (x.empty()) {
            //para o exercicio 1
            soma1 += letras.size();
            letras.clear();
            //para o exercicio 2
            for (auto s : mapa) {
                if (s.second == lines)
                    ++soma2;
            }
            mapa.clear();
            lines = 0;
        } else {
            //percorrer os characters
            for (auto c : x) {
                if (isalpha(c)) {
                    //para a parte 1
                    letras.insert(c);

                    //para a parte 2
                    mapa.contains(c) ? mapa[c] += 1 : mapa[c] = 1;
                }
            }
            ++lines;
        }
    }
    soma1 += letras.size();
    letras.clear();

    std::cout << "Dia 6, parte 1:" << soma1 << std::endl;
    std::cout << "Dia 6, parte 2:" << soma2 << std::endl;
}