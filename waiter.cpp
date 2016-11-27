#include "waiter.h"

void Waiter::run()
{
    srand((unsigned int) time(NULL));
    
    while (true)
    {
        int rnd = rand() % recipe_vec.size();
        buff.produce ( recipe_vec[rnd] ) ;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}
