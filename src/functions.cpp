#include "include/functions.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <cstdint>

namespace func {
    int64_t fibonacci_sum(int64_t limit, int option) {
        if (limit > std::numeric_limits<int64_t>::max() || limit < std::numeric_limits<int64_t>::min()) {
            throw std::invalid_argument("Argument 'limit' is out of range for 'int64_t' type.");
        } else if (option > std::numeric_limits<int>::max() || option < std::numeric_limits<int>::min()) {
            throw std::invalid_argument("Argument 'option' is out of range for 'int' type.");
        }
        const int f_0 = 0;
        const int f_1 = 1;
        int64_t sum = 0;
        
        //Vector to hold all, all even or all odd Fibonacci numbers less than limit.
        std::vector<int> filtered_fibo;
        
        //Calculating all even Fibonacci numbers less than limit.
        std::vector<int> all_fibo = {f_0, f_1};
        int loop_count = 2; //n aka loop_count > 1.
        
        //Get sum of all, even or odd?
        switch (option) {
            case 0: {
                //All.
                while (true) {
                    int f_n = all_fibo[loop_count - 1] + all_fibo[loop_count - 2];
                    all_fibo.push_back(f_n);
                    if (f_n > limit) {
                        break;
                    }
                    loop_count++;
                }
                sum = std::accumulate(all_fibo.begin(), all_fibo.end(), sum);

                break;
            }
            case 1: {
                //Even.
                while (true) {
                    int f_n = all_fibo[loop_count - 1] + all_fibo[loop_count - 2];
                    all_fibo.push_back(f_n);
                    if (f_n < limit && is_divisible(f_n, 2)) {
                        filtered_fibo.push_back(f_n);
                    } else if (f_n > limit) {
                        break;
                    }
                    loop_count++;
                }
                sum = std::accumulate(filtered_fibo.begin(), filtered_fibo.end(), sum);

                break;
            }
            case 2: {
                //Odd.
                while (true) {
                    int f_n = all_fibo[loop_count - 1] + all_fibo[loop_count - 2];
                    all_fibo.push_back(f_n);
                    if (f_n < limit && !is_divisible(f_n, 2)) {
                        filtered_fibo.push_back(f_n);
                    } else if (f_n > limit) {
                        break;
                    }
                    loop_count++;
                }
                sum = std::accumulate(filtered_fibo.begin(), filtered_fibo.end(), sum);

                break;
            }
            default: {
                //If no valid option argument was given.
                throw std::invalid_argument("No valid option argument was given.");
                break;
            }
        }

        return sum;
    }

    bool is_divisible(int numerator, int denominator) {
        int remainder = numerator % denominator;
        if (remainder == 0) {
            return true;
        } else {
            return false;
        }
    }
}