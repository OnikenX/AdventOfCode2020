//
// Created by onikenx on 03/12/20.
//

#include <vector>
#include <iostream>
#include <fstream>
#include "day1.h"

void day1::day1p2() {
    day1logic(true);
}

void day1::day1p1() {
    day1logic(true);
}



int day1::findValueSum2(std::vector<int> &numbers) {
    int value1 = 0, value2 = 0;
    for (value1 = 0; value1 < numbers.size(); ++value1) {
        for (value2 = value1; value2 < numbers.size(); ++value2)
            if ((numbers[value1] + numbers[value2]) == 2020) {
                std::cout << "numbers[value1]: " << numbers[value1] << " ; numbers[value2]: " << numbers[value2]
                          << "; resultado: " << numbers[value1] + numbers[value2] << std::endl;
                return (numbers[value1]) * (numbers[value2]);
            }
    }
    throw std::exception();
}

int day1::findValueSum3(const std::vector<int>& numbers) {
    int value1, value2, value3;
    for (value1 = 0; value1 < numbers.size(); ++value1) {
        for (value2 = value1; value2 < numbers.size(); ++value2)
            for (value3 = value2; value3 < numbers.size(); ++value3)
                if ((numbers[value1] + numbers[value2] + numbers[value3]) == 2020) {
                    return (numbers[value1]) * (numbers[value2]) * (numbers[value3]);
                }
    }
    throw std::exception();
}


 void day1::day1logic(bool isPart1) {
    //find the 2 entries that sum to 2020
    //and then multiply those two numbers together

    //Exemple:
    /**
     * Numbers:
     *  1721
     *  979
     *  366
     *  299
     *  675
     *  1456
     *
     *  the 2 numbers are 1721 and 299 both mutplied give 513579 so thats the answer
     */


    std::vector<int> numbers;
    int temp;
    std::ifstream day1input;
    day1input.open("day1input.txt");
    int cnt = 0;
    int x;
    // check that array is not already full
    while (day1input >> x) {
        // and read integer from file
        numbers.push_back(x);
    }// print the integers stored in the array
    if (numbers.empty()) {
        throw std::exception();
    }
    //print file
    for (auto i : numbers)
        std::cout << i << std::endl;
    day1input.close();
    int result;
    try {
        if (isPart1) {
            result = findValueSum2(numbers);
        } else {
            result = findValueSum3(numbers);
        }
    } catch (std::exception &e) {
        std::cout << "Could not found a sum for 2020." << std::endl;
    }
    std::cout << "The answer is " << result << std::endl;
}
