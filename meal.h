#ifndef meal_h
#define meal_h

#include "recipe.h"
#include "ingredient.h"
#include <vector>

class Meal {
public:
    const Recipe & recipe;
    std::vector<std::pair<Ingredient, unsigned int>> missing_ingredients;

    Meal (const Recipe & recipe) 
    : recipe {recipe}
    {
        for (auto i : recipe.ingredients) {
            missing_ingredients.push_back(i);
        }
    }

    bool is_completed();
    Ingredient get_missing_ingredient();
    void update_misiing_ingredients();
};

#endif /* meal_h */
