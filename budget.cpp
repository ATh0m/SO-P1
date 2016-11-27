#include "budget.h"

void Budget::increase(int amount)
{
    std::unique_lock<std::mutex> lock(m);

    budget += amount;

    lock.unlock();
}

void Budget::decrease(int amount)
{
    std::unique_lock<std::mutex> lock(m);

    budget -= amount;

    lock.unlock();
}

bool Budget::bankrupt() { return budget <= 0; }
