//
// Created by onikenx on 05/12/21.
//

#include "day5"
#include <vector>
#include <math.h>
#include <sstream>

struct Lugar {
    int row;
    int column;

    Lugar(Lugar const &a) : row(a.row), column(a.column) {}

    Lugar(int row, int column) : row(row), column(column) {}

    /// verifies if the other is bigger than this
    bool compare(Lugar other) {
        return this->get_id() < other.get_id();
    }

    int get_id() {
        return this->row * 8 + this->column;
    }
};

void day5::all() {
    auto file = read_file(5);
//    auto line = std::string{"FBFBBFFRLR"};
    auto line = std::string();
    auto highest_value = 0;
    auto lugares = std::vector<Lugar>();
    while (std::getline(file, line)) {
        //f - front
        //b -back
        //l - left
        //r - right
        //128 rows
        //os primeiros 7 chars sao ou f ou b
        auto high_row = 127.0;
        auto low_row = 0.0;
        auto high_column = 7.0;
        auto low_column = 0.0;
        for (auto command = std::begin(line); command != std::end(line); command++) {
            switch (*command) {
                case 'F'://lower half
                    high_row = std::floor((high_row - low_row) / 2.0) + low_row;
                    break;
                case 'B'://upper half
                    low_row = std::ceil((high_row - low_row) / 2.0) + low_row;
                    break;
                case 'L'://lower half
                    high_column = std::floor((high_column - low_column) / 2.0) + low_column;
                    break;
                case 'R'://upper half
                    low_column = std::ceil((high_column - low_column) / 2.0) + low_column;
                    break;
                default:
                    auto error = std::stringstream();
                    error << "unexpeted character: " << *command;
                    throw std::runtime_error(error.str().c_str());
            }
//            std::cout << "char: " << *command << "; low: " << low_row << " ;high: " << high_row << "; low: " << low_column << " ;high: " << high_column << std::endl;
        }
        if (low_row != high_row || low_column != high_column)
            throw std::runtime_error("different values high and low");
//        std::cout << "response: " << high_row << "* 8 + " << high_column << "=" << high_row * 8 + high_column << std::endl;
        highest_value = std::max(static_cast<int>( high_row * 8 + high_column), static_cast<int>(highest_value));
        lugares.push_back(Lugar{static_cast<int>(high_row), static_cast<int>(high_column)});
    }
    std::sort(lugares.begin(), lugares.end(), [](Lugar a, Lugar b) { return a.compare(b); });
    auto previous_id = lugares[0].get_id(), this_id = 0;
    int i = 1;
    for (; i != lugares.size(); i++) {
        this_id = lugares[i].get_id();
        if (previous_id + 2 == this_id)
            break;
        previous_id = this_id;
    }

    auto lugar_para_mim = lugares[i];
    if (lugar_para_mim.column == 0) {
        lugar_para_mim.row = lugar_para_mim.row - 1;
        lugar_para_mim.column = 7;
    } else {
        lugar_para_mim.column = lugar_para_mim.column - 1;
    }

    std::cout << "highest_value: " << highest_value << std::endl;
    std::cout << "Part 2 answer: " << lugar_para_mim.get_id() << std::endl;
}
