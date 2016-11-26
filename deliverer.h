#ifndef deliverer_h
#define deliverer_h
#include "buffer.h"
#include "ingredient.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
class Deliverer
{
public:
    std::vector< std::pair< Ingredient& , Buffer<Ingredient>& > > buffer_set;
    Deliverer( std::initializer_list < std::pair< Ingredient& , Buffer<Ingredient>& > > init )
    {
        for ( auto i = init.begin() ; i != init.end() ; ++ i )
            buffer_set.push_back(*i);
    }
    void run();
};

#endif /* deliverer_h */
