//
// Created by onikenx on 03/12/20.
//

#include <fstream>
#include "day3.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

void day3::day3part1() {

}
//50 index
//30 max da linha
//50%30, vai dar quantas vezes mais o 50 esta do 30
// logo para descobrir o sitio onde ele esta basta buscar por defeito o resultado

class tree_counter {
public:
    int counter, index;
    const int down, right;

    tree_counter(int down, int right) : down(down), right(right) {
        counter = 0;
        index = 0;
    };

    void evaluete(int line, std::string &x) {
        if ((line % down) != 0)
            return;
        index += right;
        if (x[(int) (index - ((index / x.length()) * x.length()))] == '#')
            ++counter;
    }

    std::string to_string() const {
        std::stringstream input;
        input << "counter: " << counter << "; index: " << index << "; down: " << down << ";right: " << right << ";";
        return input.str();
    }

};

void day3::day3logic() {
    std::vector<std::shared_ptr<tree_counter>> counters;
    //adiciona as condicoes
    counters.push_back(std::make_shared<tree_counter>(1, 1));
    counters.push_back(std::make_shared<tree_counter>(2, 1));
    counters.push_back(std::make_shared<tree_counter>(1, 3));
    counters.push_back(std::make_shared<tree_counter>(1, 5));
    counters.push_back(std::make_shared<tree_counter>(1, 7));
    //ler o file e avalia as arvores
    {
        std::ifstream day3input("day3input.txt");
        std::string x;
        int line = 0;
        day3input >> x;//skip at the first line
        while (day3input >> x) {
            ++line;
            for (const auto &it : counters)
                it->evaluete(line, x);

        }
    }
    //avalia a multiplicação e imprime
    {
        long long small = 1;
        for (const auto &it : counters) {
//            std::cout << it->to_string() << std::endl;
            if (it->counter == 0)
                continue;
            small *= it->counter;
//            std::cout << "small: " << small << std::endl;
        }

        std::cout << "Value part 2: " << small << std::endl;
    }
}

