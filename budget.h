#ifndef budget_h
#define budget_h

#include <mutex>
#include <iostream>

class Budget {
public:
    int budget;
    std::mutex m;

    Budget(int amount)
        : budget{ amount }
    {
    }

    void increase(int amount);
    void decrease(int amount);
    bool bankrupt();
};

#endif /* budget_h */
