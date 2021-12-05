//
// Created by onikenx on 05/12/21.
//

#include <sstream>
#include "macros"
const auto INPUT_FOLDER = "inputs/";

auto read_file(int day) -> std::ifstream {
    auto input_file = std::stringstream();
    input_file << INPUT_FOLDER << "day" << day << "input.txt";
    auto input = std::ifstream{input_file.str()};
    if (input.fail()) {
        auto error_message = std::stringstream();
        error_message << "Failed to receive to read file `" << input_file.str() << "`.";
        throw std::runtime_error(error_message.str().c_str());
    }
    return input;
}