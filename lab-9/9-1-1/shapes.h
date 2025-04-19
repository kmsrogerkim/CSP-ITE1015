#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <string>
#include <map>
#include <vector>
class MessageBook
{
    public:
        void AddMessage(int number, const std::string& message)
        {
           messages_[number] = message;
        };
        void DeleteMessage(int number)
        {
            messages_.erase(number);
        };
        std::vector<int> GetNumbers()
        {
            std::vector<int> numbers;
            for (auto& pair: messages_)
            {
                numbers.push_back(pair.first);
            }
            return numbers;
        };
        const std::string& GetMessage(int number)
        {
            std::string empty_string = "";
            std::string& wtf = empty_string;
            if (messages_.count(number) == 0) return wtf;
            return messages_[number];
        };
    private:
        std::map<int, std::string> messages_;
};

#endif