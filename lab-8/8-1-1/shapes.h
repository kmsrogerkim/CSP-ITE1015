#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <vector>
using namespace std;

class IntegerSet{
    private:
        vector<int> numbers_;
    public:
        void AddNumber(int num)
        {
            numbers_.push_back(num);
        };

        void DeleteNumber(int num)
        {
            for (vector<int>::iterator itr = numbers_.begin(); itr!=numbers_.end(); itr++)
            {
                if (*itr == num)
                {
                    numbers_.erase(itr); 
                }
            }
        };

        int GetItem(int pos)
        {
            try {
                int value = numbers_.at(pos);
                return value;
            } catch (const out_of_range &e) {
                return -1;
            }
        };
        vector<int> GetAll(){ return numbers_; };
};

#endif