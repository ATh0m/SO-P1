#include <vector>
#include <thread>

#include "ingredient.h"
#include "buffer.h"
#include "recipe.h"
#include "meal.h"

class Cook {
public:
    std::vector<std::pair<Ingredient&, Buffer<Ingredient>&>> ingredients;
    Buffer<Recipe>& orders;
    Buffer<Meal>& completed_meals;

    Meal meal;

    Cook (std::initializer_list<std::pair<Ingredient&, Buffer<Ingredient>&>> init,
          Buffer<Recipe>& orders,
          Buffer<Meal>& completed_meals)
    : orders {orders},
      completed_meals {completed_meals}
    {
        for ( auto i = init.begin() ; i != init.end() ; ++ i )
            ingredients.push_back(*i);
    }

    void run();
    void runMultiThread();
};
