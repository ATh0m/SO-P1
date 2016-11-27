#include "cook.h"

void Cook::run()
{
    Meal meal;

    while (true) {
        meal = Meal(orders.consume());
        std::cout << "[Cook] Got new order: " << meal.recipe.name << std::endl;

        while (!meal.is_completed()) {
            Ingredient missing_ingredient = meal.get_missing_ingredient();
            
            Ingredient ingredient;

            for (auto i : ingredients)
            {
                if (i.first == missing_ingredient)
                {
                    if (i.second.amount == 0)
                        mail.push_message(i.first);
                    
                    ingredient = i.second.consume();
                    break;
                }
            }

            meal.update_misiing_ingredients();
            std::cout << meal << std::endl;
        }
        std::cout << "[Cook] Completed meal: " << meal.recipe.name << std::endl;

        completed_meals.produce(meal);
        std::cout << "[Cook] Added meal " << meal.recipe.name << " to deliever" << std::endl;
    }
}
