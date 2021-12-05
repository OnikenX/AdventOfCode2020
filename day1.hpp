//
// Created by onikenx on 03/12/20.
//

#ifndef ADVENTOFCODE2020_DAY1_H
#define ADVENTOFCODE2020_DAY1_H

#include <vector>

/**
 * implementation of the day 1 problem
 */
class day1 {
public:
    /**
     * part 1
     */
    static void day1p1();
    /**
     * part 2
     */
    static void day1p2();
private:
    static void day1logic(bool isPart1);

    static int findValueSum3(const std::vector<int>& numbers);

    static int findValueSum2(std::vector<int>& numbers);

};


#endif //ADVENTOFCODE2020_DAY1_H
