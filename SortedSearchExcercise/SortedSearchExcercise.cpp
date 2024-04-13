#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    auto lowerBound = std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan);
    return std::distance(sortedVector.begin(), lowerBound);
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << "\n" << countNumbers(v, 4) << "\n";
    std::cout << countNumbers(v, 1) << "\n";
}
#endif