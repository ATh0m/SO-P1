#include "meal.h"

bool Meal::is_completed()
{
    if (missing_ingredients.empty())
        std::cout << "[Meal] Meal is ready: " << recipe.name << std::endl;
    return missing_ingredients.empty();
}

Ingredient Meal::get_missing_ingredient()
{
    return missing_ingredients.back().first;
}

void Meal::update_misiing_ingredients()
{
    if (!--missing_ingredients.back().second) {
        missing_ingredients.pop_back();
    }
}
