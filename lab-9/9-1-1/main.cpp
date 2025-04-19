#include <iostream>
#include <sstream>
#include <string>
#include "shapes.h"
using namespace std;

int main()
{
    MessageBook message_book;
    string input; 

    string command,  message;
    int number;
    while (command != "quit")
    {
        getline(cin, input);
        istringstream iss(input); 
        iss >> command; 

        if (command == "add")
        {
            iss >> number; 
            getline(iss, message); 
            if (!message.empty() && message[0] == ' ') {
                message.erase(0, 1); 
            }        
            else if (message.empty()) continue;

            message_book.AddMessage(number, message);
        }
        if (command == "delete")
        {
            iss >> number;
            message_book.DeleteMessage(number);
        }
        if (command == "print")
        {
            iss >> number;
            string message = message_book.GetMessage(number);
            cout << message << endl;
        }
        if (command == "list")
        {
            vector<int> numbers = message_book.GetNumbers();
            for (auto it = numbers.begin(); it != numbers.end(); it++)
            {
                cout << *it << ": " << message_book.GetMessage(*it) << endl;
            }
        }
        else if (command == "quit") return 0;
        else continue;
    }
    return 0;
}