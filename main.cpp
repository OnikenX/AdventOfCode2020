#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sstream>

#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "day5"
#include "day6.hpp"

/// runs a specific _day_
void run_day(int day) {
    std::cout << "Day " << day << ":" << std::endl;
    switch (day) {
        case 1:
            day1::day1p1();
            day1::day1p2();
            break;
        case 2:
            day2::part1();
            day2::part2();
            break;

        case 3:
            day3::day3logic();
            break;
        case 4:
            day4::run();
            break;
        case 5:
            day5::all();
            break;
        case 6:
            day6::run();
            break;
        default:
        error:
            std::cerr << ((day > 25 || day < 1) ? "Is not implemented"
                                                : "Day does not exist.")
                      << std::endl;
    }
}

/// runs all days
void run_all() {
    for (auto i = 1; i <= 25; i++) {
        run_day(i);
    }
}
#define DAY 5
void aoc2020(int argc, char **args) {
    int day = -1;
    if (argc > 1) {
        auto arg_str = std::string(args[1]);
        auto arg_ss = std::stringstream(arg_str);
        try {
            arg_ss >> day;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
#ifdef DAY
        day = DAY;
#else
        day = 0;
#endif
    }

    if (day == 0) {
        run_all();
    }else{
        run_day(day);
    }
}


int process_ops(int argc, char **args) {
    int dia = -1;
    auto path = std::string{"inputs/"};
    auto number = std::string{};
    char c = '\0';
    opterr = 0;

    // a - all
    // p - path
    // n - numero do dia
    while ((c = getopt(argc, args, "ap:n:")) != -1) { // NOLINT(cppcoreguidelines-narrowing-conversions)
        switch (c) {
            case 'a':
                dia = 0;
                break;
            case 'p':
                path = optarg;
                break;
            case 'n':
                number = optarg;
                break;
            case '?':
                if (optopt == 'p') {
                    fprintf(stderr, "You need to put an path in -p.\n");
                } else if (isprint(optopt)) {
                    fprintf(stderr, " Unknown option -%c.\n", optopt);
                } else {
                    fprintf(stderr, "Unknown option character \\x%x.\n", optopt);
                    return 1;
                    default:
                        std::cerr << "Fudeu" << std::endl;
                    abort();
                }
        }
    }
    return 0;
}

int main(int argc, char **args) {
    aoc2020(argc, args);
return 0;
}
