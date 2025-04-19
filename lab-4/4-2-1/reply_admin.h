#ifndef __REPLY_ADMIN_H__
#define __REPLY_ADMIN_H__

#define NUM_OF_CHAT 10
#include <string>

class ReplyAdmin
{
    private:
        std::string* chats;
        int num_chats;
    public:
        ReplyAdmin();
        ~ReplyAdmin();
        int getChatCount();
        bool addChat(std::string _chat);
        bool removeChat(int _index);
        bool removeChat(int* indices, int _count);
        bool removeChat(int _start, int _end);
        void printChats();
};

#endif