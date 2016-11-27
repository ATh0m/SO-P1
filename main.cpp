#include <iostream>
#include "buffer.h"
#include "recipe.h"
#include "meal.h"
int main() {
    int a = 2;
    ++ a %= 3;
    printf("%d\n", a);

    Ingredient pomidor( "pomidor", 2 );
    Ingredient ananas("ananas", 3);
    Ingredient pomarancza("pomarancza", 5);
    Ingredient salata("salata", 2);
    Ingredient ogorek("ogorek", 4);
    Ingredient ser("ser", 6);
    Ingredient mieso("mieso", 10);
    Ingredient makaron("makaron", 7);
    
    std::pair<Ingredient, unsigned int> para = std::make_pair(salata, 3);
    
    Recipe r1 ("salatka", 50, { std::make_pair(salata, 3), std::make_pair(pomidor, 2)});
    Recipe r2 ("pizza", 50, { std::make_pair(mieso, 1), std::make_pair(ser, 2), std::make_pair(ananas, 1)});
    Recipe r3 ("danie", 100, { std::make_pair(makaron, 1), std::make_pair(mieso, 1) } );
    
    Meal m1 (r1);
    Meal m2 (r2);
    Meal m3 (r3);
    
    Buffer <Ingredient> buff_pomidor (10);
    Buffer <Ingredient> buff_ananas (10);
    Buffer <Ingredient> buff_pomarancza (10);
    Buffer <Ingredient> buff_salata (10);
    Buffer <Ingredient> buff_ogorek (10);
    Buffer <Ingredient> buff_ser (10);
    Buffer <Ingredient> buff_mieso (10);
    Buffer <Ingredient> buff_makaron (10);
    
    Buffer <Recipe> buff_recipe (10);
    Buffer <Meal> buff_meal (10);
    

    return 0;
}
