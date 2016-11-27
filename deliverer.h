#ifndef deliverer_h
#define deliverer_h

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>

#include "budget.h"
#include "buffer.h"
#include "ingredient.h"

class Deliverer {
public:
    std::vector<std::pair<Ingredient&, Buffer<Ingredient>&> > buffer_set;
    Budget& budget;

    Deliverer(
        std::initializer_list<std::pair<Ingredient&, Buffer<Ingredient>&> > init,
        Budget& budget)
        : budget(budget)
    {
        for (auto i = init.begin(); i != init.end(); ++i)
            buffer_set.push_back(*i);
    }
    void run();
};

#endif /* deliverer_h */
