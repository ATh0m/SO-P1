#ifndef meal_h
#define meal_h

#include "recipe.h"
#include "ingredient.h"
#include <vector>

class Meal {
public:
    Recipe recipe;
    std::vector<std::pair<Ingredient, unsigned int>> missing_ingredients;

    Meal ()
    : missing_ingredients {},
    recipe {Recipe()}
    { }

    Meal (Recipe recipe)
    : recipe {recipe}
    {
        for (auto i : recipe.ingredients) {
            missing_ingredients.push_back(i);
        }
    }

    Meal& operator = (const Meal& m)
    {
        if (&m == this)
            return *this;
        recipe = m.recipe;
        for ( auto i : m.missing_ingredients )
            missing_ingredients.push_back(i);
        return *this;
    }
    
    bool is_completed();
    Ingredient get_missing_ingredient();
    void update_misiing_ingredients();
};

#endif /* meal_h */
