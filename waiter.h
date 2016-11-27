#ifndef waiter_h
#define waiter_h
#include "recipe.h"
#include "buffer.h"
#include <thread>
#include <chrono>
class Waiter{
public:
    Buffer<Recipe>& buff;
    std::vector <Recipe> recipe_vec;
    Waiter(std::initializer_list<Recipe> init, Buffer<Recipe>& buff)
    : buff { buff }
    {
        for ( auto i = init.begin() ; i != init.end() ; ++ i )
            recipe_vec.push_back(*i);
    }
    void run();
};

#endif /* waiter_h */
