#include "deliverer.h"

void Deliverer::run()
{
    srand((unsigned int)time(NULL));

    while (true) {
        int rnd = rand() % buffer_set.size();

        buffer_set[rnd].second.produce(buffer_set[rnd].first);
        budget.decrease(buffer_set[rnd].first.price);

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}
