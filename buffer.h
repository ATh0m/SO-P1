#ifndef buffer_h
#define buffer_h
#include <mutex>

template<typename T>
class Buffer
{
public:
    T* buffer;
    const unsigned int capacity;
    int front;
    int last;
    unsigned int amount;
    
    std::mutex m;
    std::condition_variable is_full;
    std::condition_variable is_empty;
    
    Buffer ( const unsigned int capacity )
    : capacity { capacity },
    front { 0 },
    last { 0 },
    amount { 0 }
    {
        buffer = new T [capacity];
    }
    
    ~Buffer()
    {
        delete[] buffer;
    }
    
    void produce( T product )
    {
        std::unique_lock < std::mutex > lock (m);
        is_full.wait(lock, [this] () { return amount != capacity; });
        
        buffer[last] = product;
        ++ last %= capacity;
        ++ amount;
        
        is_empty.notify_one();
        lock.unlock();
    }
    
    T consume()
    {
        std::unique_lock< std::mutex > lock (m);
        is_empty.wait(lock, [this] () { return amount != 0; });
        
        T result = buffer [front];
        ++ front %= capacity;
        -- amount;
        
        is_full.notify_one();
        lock.unlock();
        
        return result;
    }
    
};

#endif /* buffer_h */
