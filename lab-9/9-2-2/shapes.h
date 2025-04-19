#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <vector>
#include <algorithm>
class SortedArray{
    public:
        void AddNumber(int num)
        {
            numbers_.push_back(num);
        };
        std::vector<int> GetSortedAscending()
        {
            sort(numbers_.begin(), numbers_.end());
            return numbers_;
        };
        std::vector<int> GetSortedDescending()
        {
            sort(numbers_.begin(), numbers_.end(), std::greater<int>());
            return numbers_;
        };
        int GetMax()
        {
            return *max_element(numbers_.begin(), numbers_.end());
        };
        int GetMin() {
            return *min_element(numbers_.begin(), numbers_.end());
        };
    private:
        std::vector<int> numbers_;
};


#endif