#include "cook.h"

void Cook::run()
{
    Meal meal;

    while(true)
    {
        meal = Meal(orders.consume());

        while(!meal.is_completed())
        {
            Ingredient missing_ingredient = meal.get_missing_ingredient();

            Ingredient ingredient;
            for (auto i : ingredients)
            {
                if (i.first.name == missing_ingredient.name)
                {
                    ingredient = i.second.consume();
                    break;
                }
            }

            meal.update_misiing_ingredients(); 
        }

        completed_meals.produce(meal);
    }
}

void Cook::runMultiThread() 
{    
   std::thread t1(&Cook::run, this);
}
