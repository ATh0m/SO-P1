#include "waiter.h"

void Waiter::run()
{
    srand((unsigned int) time(NULL));
    
    while (true)
    {
        int rnd = rand() % recipe_vec.size();
        buff.produce ( recipe_vec[rnd] ) ;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

void Waiter2::run()
{
    while (true) {
        Meal meal = completed_meals.consume();
        budget.increase(meal.recipe.price);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
