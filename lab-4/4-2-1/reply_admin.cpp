#include <iostream>
#include <string>
#include "reply_admin.h"

ReplyAdmin::ReplyAdmin()
{
    chats = new std::string[NUM_OF_CHAT];
    num_chats = 0;
}
ReplyAdmin::~ReplyAdmin()
{
    delete[] chats;
}
int ReplyAdmin::getChatCount()
{
    return num_chats;
}
bool ReplyAdmin::addChat(std::string _chat)
{
    if (num_chats >= 10) return 0;
    
    chats[num_chats] = _chat;
    num_chats += 1;
    return 1;
}
bool ReplyAdmin::removeChat(int _index)
{
    if (_index < 0 || _index >= num_chats) return 0;

    for (int i = _index; i < num_chats; i++)
    {
        if (i == (num_chats - 1)){
            chats[i] = "";
        }
        chats[i] = chats[i+1];
    }
    num_chats -= 1;
    return 1;
}
bool ReplyAdmin::removeChat(int* indices, int _count)
{
    int successful_attemps = 0;
    for (int i = 0; i<_count; i++)
    {
        if (indices[i] < num_chats && indices[i] >= 0)
        {
            chats[indices[i]] = "";
            successful_attemps += 1;
        }
    }

    if (successful_attemps == 0) return 0;

    int new_num_chats = 0;
    for (int i = 0; i<num_chats; i++)
    {
        if (chats[i] == "")
        {
            for (int j=i; j<num_chats; j++)
            {
                if (chats[j] != "")
                {
                    chats[i] = chats[j];
                    chats[j] = "";
                    new_num_chats += 1;
                    break;
                }
            }
        }
        else new_num_chats += 1;
    }
    num_chats = new_num_chats;

    return 1;
}
bool ReplyAdmin::removeChat(int _start, int _end)
{
    if (_start >= num_chats || _start < 0) return 0;
    if (_end >= num_chats) _end = num_chats+1;

    for (int i=_start; i<=_end; i++)
    {
        chats[i] = "";
    }

    int new_num_chats = 0;
    for (int i = 0; i<num_chats; i++)
    {
        if (chats[i] == "")
        {
            for (int j=i; j<num_chats; j++)
            {
                if (chats[j] != "")
                {
                    chats[i] = chats[j];
                    chats[j] = "";
                    new_num_chats += 1;
                    break;
                }
            }
        }
        else new_num_chats += 1;
    }
    num_chats = new_num_chats;
    return 1;
}
void ReplyAdmin::printChats()
{
   for (int i=0; i<num_chats; i++)
   {
        std::cout << i << " " << chats[i] << std::endl;
   } 
}