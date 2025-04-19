#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "reply_admin.h"
using namespace std;

int sti(std::string str)
{
    return atoi(str.c_str());
}

int main()
{
    ReplyAdmin reply_admin;

    while (1)
    {
        string line_input;
        getline(cin, line_input); 
        istringstream stream(line_input);
        vector<string> inputs;  
        string input;
        while (stream >> input) {
            inputs.push_back(input);
        }

        if (inputs[0][0] != '#')
        {
            if (!reply_admin.addChat(line_input)) return 0;
        }
        else
        {
            if (inputs[1][1] == ',')
            {
                int size = inputs.size() - 1;
                int* indices = new int[size];

                for (int i=0; i<size; i++){
                    indices[i] = int(inputs[i+1][0]) - '0';
                }
                if(!reply_admin.removeChat(indices, size)) std::cout << "Error!\n";

                delete[] indices;
            }
            else if (inputs[1][1] == '-')
            {
                int start, end;
                start = inputs[1][0] - '0';
                end = inputs[1][2] - '0';
                if(!reply_admin.removeChat(start, end)) std::cout << "Error!\n";
            }
            else
            {
                if(!reply_admin.removeChat(sti(inputs[1]))) std::cout << "Error!\n";
            }
        }

        reply_admin.printChats();
    }

    
    return 0;
}
