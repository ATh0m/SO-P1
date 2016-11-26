#include <mutex>

class Budget {
public:
    int budget;
    std::mutex m;

    Budget (int amount)
    : budget {amount}
    {}

    void increase(int amount);
    void decrease(int amount);
};
