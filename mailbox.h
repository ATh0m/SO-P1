#ifndef mailbox_h
#define mailbox_h
#include "ingredient.h"
#include <queue>
#include <mutex>
class Mailbox
{
    unsigned int mail_limit;
public:
    std::queue <Ingredient> queue;
    std::mutex m;
    std::condition_variable is_full;
    
    Mailbox()
    : mail_limit { 25 }
    {}
    
    bool is_message();
    Ingredient& get_message();
    void push_message(Ingredient& i);
};

#endif
