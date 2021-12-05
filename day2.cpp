//
// Created by onikenx on 03/12/20.
//

#include <fstream>
#include <vector>
#include <string>
#include "day2.hpp"
#include <ctype.h>
#include <iostream>

int getNum(std::string line, int &offset) {
    std::string tmp;
    while (isdigit(line[offset]))
        tmp += line[offset++];
    return std::stoi(tmp);
}

/**
 * Evaluates password by the old policy
 * @param line to be evaluated
 * @param lower_limit of times
 * @param higher_limit of times
 * @param position to start from reading the line
 * @param character to count
 * @return if meets the policy or not
 */
bool oldPolicy(std::string &line, int lower_limit, int higher_limit, int position, char character) {
    int counter = 0;
    while (position < line.size())
        if (line[position++] == character)
            if (++counter > higher_limit)
                return false;
    if (counter < lower_limit)
        return false;
    return true;
}

bool newPolicy(std::string &line, int lower_limit, int higher_limit, int pos_start, char character) {

    //verifies if it is higer than it should
    if (pos_start + higher_limit - 1 >= line.size())
        return false;

    //verifies if the first one first_exists
    bool first_exists = false;

    if (line[pos_start + lower_limit - 1] == character)
        first_exists = true;
    if (line[pos_start + higher_limit - 1] == character)
        //if the other one already first_exists it returns false else true
        return !first_exists;
    //as if the higher one first_exists then it would answer, this is for the first one only existence
    return first_exists;
}

/**
 * Evaluates the a policy
 * @param line to be evalueted
 * @param is_the_policy_the_new_one to define the policy, true for the new one(indexes), false for the old one(counter)
 * @return if is valid (true) or not (false)
 */
bool isAccordingToPolicy(std::string line, bool is_the_policy_the_new_one) {
    if (line.empty())
        return false;
    int position = 0, lower_limit = 0, higher_limit = 0;
    char character = '0';
    std::string tmp;
    lower_limit = getNum(line, position);
    if (line[position++] != '-')
        return false;
    higher_limit = getNum(line, position);
    if (higher_limit < lower_limit)
        return false;
    if (line[position++] != ' ')
        return false;
    character = line[position++];
    if (line[position++] != ':')
        return false;
    if (line[position++] != ' ')
        return false;
    return is_the_policy_the_new_one ?// we need to use the new policy?
           newPolicy(
                   line,
                   lower_limit,
                   higher_limit,
                   position,
                   character
           )
                                     : //else use the old one
           oldPolicy(
                   line,
                   lower_limit,
                   higher_limit,
                   position,
                   character
           );


}
/**
 * Policies of passwords
 * @param is_the_policy_the_new_one to define the policy, true for the new one(indexes), false for the old one(counter)
 */

void day2::day2logic(bool is_the_policy_the_new_one) {
    std::ifstream day2input("day2inputvalent.txt");
    int counter = 0;
    std::string tmpline;
    if (day2input.is_open())
        while (std::getline(day2input, tmpline)) {
            if (isAccordingToPolicy(tmpline, is_the_policy_the_new_one)) ++counter;
        }
    std::cout << "Number is: " << counter << std::endl;
}

void day2::part2() {
    day2logic(true);
}

void day2::part1() {
    day2logic(false);
}

