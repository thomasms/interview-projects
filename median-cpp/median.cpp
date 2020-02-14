#include "median.hpp"

#include <cmath>
#include <stdexcept>
#include <algorithm>

double median(const std::vector<int>& numbers) {
    // cannot remove exception due to unit test but throwing an exception
    // should be zero cost
    if(numbers.size() == 0)
        throw std::invalid_argument("No median for empty vector");

    const bool isOdd = numbers.size() % 2;
    // slight improvement to save the repeated operation of a shift >>
    // maybe this makes do difference but worth a try
    const int halfsize = ceil(numbers.size() / 2);

    auto mutableNumbers = numbers;

    // very slow - can we do it without a sort?
#ifdef DO_SLOW_WAY
    std::sort(mutableNumbers.begin(), mutableNumbers.end()); 
    return isOdd
        ? mutableNumbers[halfsize]
        : (mutableNumbers[halfsize - 1] + mutableNumbers[halfsize]) / 2.0;
#else
    // Yes we can and STL has it already - Use quickselect or introselect
    // quicksort but without the extra recursion that is not needed
    // std has nth_element to do this!
    if(isOdd){
        std::nth_element(mutableNumbers.begin(), mutableNumbers.begin() + halfsize, mutableNumbers.end());
        return mutableNumbers[halfsize];
    }
    else{
        std::nth_element(mutableNumbers.begin(), mutableNumbers.begin() + halfsize - 1, mutableNumbers.end());
        std::nth_element(mutableNumbers.begin() + halfsize, mutableNumbers.begin() + halfsize, mutableNumbers.end());
        return (mutableNumbers[halfsize - 1] + mutableNumbers[halfsize]) / 2.0;
    }
#endif
}
