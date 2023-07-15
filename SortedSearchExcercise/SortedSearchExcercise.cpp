#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    return std::count_if(sortedVector.begin(), sortedVector.end(), [lessThan](int val) {
            return val < lessThan;
        });
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << "\n" << countNumbers(v, 4) << "\n";
    std::cout << countNumbers(v, 1) << "\n";
}
#endif