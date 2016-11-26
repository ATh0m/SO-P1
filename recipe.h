#ifndef recipe_h
#define recipe_h
#include "ingredient.h"
#include <vector>
class Recipe
{
    const std::string name;
    const unsigned int price;
    std::vector < std::pair < Ingredient, unsigned int > > ingredients;
    Recipe ( const std::string & name, const unsigned int price, std::initializer_list < std::pair < Ingredient, unsigned int > > init )
    : name { name },
    price { price }
    {
         for ( auto i = init.begin() ; i != init.end() ; ++ i )
             ingredients.push_back(*i);
    }
};

#endif /* recipe_h */
