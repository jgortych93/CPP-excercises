#include <vector>
#include <stdexcept>
#include <iostream>

using VectorIterator = std::vector<int>::const_iterator;

auto findEqualRangeBegin(const VectorIterator& begin, const VectorIterator& end, int value)
{
    if(begin == end) return end;

    auto prevPosition = std::prev(end);
    if(*prevPosition != value)
    {
        return end;
    }
    else
    {
        return findEqualRangeBegin(begin, prevPosition, value);
    }
}

auto binarySearchLessThanPosition(const VectorIterator& begin, const VectorIterator& end, int lessThan)
{
    auto currentBinarySearchPos = std::next(begin, (std::distance(begin, end)) / 2);
    if (*currentBinarySearchPos == lessThan)
    {
        return findEqualRangeBegin(begin, currentBinarySearchPos, lessThan);
    }
    else if (*currentBinarySearchPos < lessThan)
    {
        return binarySearchLessThanPosition(currentBinarySearchPos, end, lessThan);
    }
    else
    {
        return binarySearchLessThanPosition(begin, currentBinarySearchPos, lessThan);
    }
}

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    auto vectorSize = sortedVector.size();
    if (vectorSize == 0)
        return 0;

    if (sortedVector.back() < lessThan)
        return vectorSize;

    auto lessThanPosition = binarySearchLessThanPosition(sortedVector.begin(), sortedVector.end(), lessThan);

    return std::distance(sortedVector.begin(), lessThanPosition);
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 4, 5, 5, 5, 5, 7 };
    std::cout << "\nExpected 3, Actual: " << countNumbers(v, 5) << "\n";
    std::cout << "Expected: 2, Actual: " << countNumbers(v, 4) << "\n";
    std::cout << "Expected: 0, Actual: " << countNumbers(v, 1) << "\n";
    std::cout << "Expected: 7, Actual: " << countNumbers(v, 7) << "\n";
    std::vector<int> v2 {1};
    std::cout << "Expected: 1, Actual: " << countNumbers(v2, 4) << "\n";
    std::vector<int> v3 {1,1,1};
    std::cout << "Expected: 3, Actual: " << countNumbers(v3, 7) << "\n";
    std::vector<int> emptyVector;
    std::cout << "Expected: 0, Actual: " << countNumbers(emptyVector, 4) << "\n";
}
#endif