#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "day2.h"
#include "day3.h"

//gold coins -> stars
//find 50 stars until 25 december

bool hasElement(std::vector<char> letras, char c) {
    for (auto l :letras)
        if (l == c)
            return true;
    return false;
}

void day6() {
    std::ifstream input("day6input.txt");
    std::string x;
    int soma = 0;

    std::vector<char> letras;
    while (getline(input, x)) {
        if (x.empty()) {
            soma += letras.size();
            letras.clear();
        } else
            for (auto c : x) {
                if (isalpha(c))
                    if (!hasElement(letras, c))
                        letras.push_back(c);

            }
    }
    soma += letras.size();
    letras.clear();

    std::cout << soma << std::endl;
}

int main() {
//    day3::day3logic();
//    std::cout << !4%2
//    << std::endl;
    day6();
    return 0;

}
