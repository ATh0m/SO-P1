#ifndef ingredient_h
#define ingredient_h

#include <string>

class Ingredient {
    const std::string name;
    const unsigned int price;

    Ingredient (const std::string & name, const unsigned int price)
    :   name {name}, 
        price {price}
    {}
};

#endif /* ingredient_h */
