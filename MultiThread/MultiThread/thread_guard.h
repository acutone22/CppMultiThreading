#pragma once

#include <vector>
#include <thread>

//This class follows the RAII principle, so ensure that resources are initialized when constructor is called,
//and they are correctly deleted when constructor is called. In our case, the destructor ensures that the 
//thread is joined before being deleted, avoiding unsafe programs
class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& _t) : t(_t) {}

    ~thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    //deleting copy constructor and copy assignment operator
    thread_guard(thread_guard& const) = delete;
    thread_guard& operator= (thread_guard& const) = delete;
};

