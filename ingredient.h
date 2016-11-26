#ifndef ingredient_h
#define ingredient_h
#include <utility>
#include <string>
#include <iostream>
class Ingredient {
public:
    std::string name;
    unsigned int price;

    Ingredient (const std::string & name, const unsigned int price)
    :   name {name}, 
        price {price}
    {}
    
    Ingredient (const Ingredient& i)
    : name {i.name},
    price {i.price}
    {}
    
    Ingredient& operator = (const Ingredient& i)
    {
        if(&i == this)
            return *this;
        name = i.name;
        price = i.price;
        return *this;
    }
};

#endif /* ingredient_h */
