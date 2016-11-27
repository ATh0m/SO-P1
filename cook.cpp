#include "cook.h"

void Cook::run()
{
    Meal meal;

    while (true) {
        meal = Meal(orders.consume());

        while (!meal.is_completed()) {
            Ingredient missing_ingredient = meal.get_missing_ingredient();
            
            Ingredient ingredient;

            for (auto i : ingredients)
            {
                if (i.first.name == missing_ingredient.name)
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

        completed_meals.produce(meal);
    }
}
