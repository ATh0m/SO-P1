#include "waiter.h"

void Waiter::run()
{
    srand((unsigned int)time(NULL));

    while (true) {
        int rnd = rand() % recipe_vec.size();
        buff.produce(recipe_vec[rnd]);
        std::cout << "[Waiter] Added order: " << recipe_vec[rnd].name << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Waiter2::run()
{
    while (true) {
        Meal meal = completed_meals.consume();
        budget.increase(meal.recipe.price);
        std::cout << "[Waiter2] Meal delieverd: " << meal.recipe.name << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
