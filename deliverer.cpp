#include "deliverer.h"

void Deliverer::run()
{
    srand((unsigned int) time(NULL));
    
    while (true)
    {
        int rnd = rand() % buffer_set.size();
        buffer_set[rnd].second.produce ( buffer_set[rnd].first ) ;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
