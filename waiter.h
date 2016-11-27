#ifndef waiter_h
#define waiter_h
#include "recipe.h"
#include "buffer.h"
#include "budget.h"
#include "meal.h"
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

class Waiter2 {
public:
    Buffer<Meal>& completed_meals;
    Budget & budget;
    
    Waiter2(Buffer<Meal>& completed_meals, Budget & budget)
    : completed_meals {completed_meals},
      budget {budget}
    {}
    
    void run();
};

#endif /* waiter_h */
