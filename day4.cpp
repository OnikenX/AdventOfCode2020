//
// Created by onikenx on 12/7/20.
//
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "day4.h"

//verifies if everything is true, while it makes everything false
inline bool all_true_but_false(auto &map) {
    bool return_value = true;
    for (auto i : map) {
        if (!i.second)
            return_value = false;
        map[i.first] = false;
    }
    return return_value;
}

inline bool verifica_corretos(auto valores, int n_valores) {
    return n_valores == valores.size();
}

bool verify_conditions(std::string key, std::string value) {
    if (key == "byr") {
        if (value.length() != 4)
            return false;
        int tmp;
        try { tmp = stoi(value); } catch (...) { return false; }
        if (tmp >= 1920 && tmp <= 2002)
            return true;
        return false;
    } else if (key == "iyr") {
        if (value.length() != 4)
            return false;
        int tmp;
        try { tmp = stoi(value); } catch (...) { return false; }
        if (tmp >= 2010 && tmp <= 2020)
            return true;
        return false;
    } else if (key == "eyr") {
        if (value.length() != 4)
            return false;
        int tmp;
        try { tmp = stoi(value); } catch (...) { return false; }
        if (tmp >= 2020 && tmp <= 2030)
            return true;
        return false;
    } else if (key == "hgt") {
        auto prefix = value.substr(0, value.size() - 2);
        int tmp;
        try { tmp = stoi(value); } catch (...) { return false; }
        auto sufix = value.substr(value.size() - 2, value.size());
        if (sufix == "cm") {
            if (tmp >= 150 && tmp <= 193)
                return true;
            return false;
        } else if (sufix == "in") {
            if (tmp >= 59 && tmp <= 76)
                return true;
            return false;
        }
        return false;
    } else if (key == "hcl") {
        if (value.size() != 7)
            return false;
        if (value[0] != '#')
            return false;
        for (int i=1;i< value.size();++i)
            if (!(isdigit(value[i]) || ('a' <= value[i] && value[i] <= 'f')))
                return false;
        return true;
    } else if (key == "ecl") {
        if (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" ||
            value == "oth")
            return true;
        return false;
    } else if (key == "pid") {
        if (value.size() != 9)
            return false;
        for (auto c : value)
            if (!isdigit(c))
                return false;
        return true;
    } else return false;
}

void day4::run() {
    std::ifstream input("day4input.txt");
    std::string str, key;
    int corretos_parte1 = 0;
    int corretos_parte2 = 0;
    int n_valores_parte1 = 0, n_valores_parte2 = 0;
    //defines whats obligatory or not
    std::map<std::string, bool> vality_table, inputed_values;
    const std::set<std::string> valores{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    std::vector<std::string> strings;
    while (getline(input, str)) {
        if (str.empty()) {
            if (verifica_corretos(valores, n_valores_parte1))
                ++corretos_parte1;
            if (verifica_corretos(valores, n_valores_parte2))
                ++corretos_parte2;
            n_valores_parte1 = 0;
            n_valores_parte2 = 0;
        } else {
            std::stringstream ss(str);
            while (ss >> str) {
                //descobre se a string esta certa
                key = str.substr(0, str.find(':'));
                if (valores.find(key) != valores.cend()) {
                    ++n_valores_parte1;
                    //descobre se os valores estao certos
                    if (verify_conditions(key, str.substr(str.find(':') + 1, str.length())))
                        ++n_valores_parte2;
                }
            }
        }
    }

    if (verifica_corretos(valores, n_valores_parte1))
        ++corretos_parte1;
    if (verifica_corretos(valores, n_valores_parte2))
        ++corretos_parte2;
    std::cout << corretos_parte1 << std::endl;//nao funca
    std::cout << corretos_parte2 << std::endl;//nao funca
}