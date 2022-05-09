// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void foo()
{
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "Hello foo thread id:" << this_thread::get_id() << endl;
}

void bar()
{
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "Hello bar thread id:" << this_thread::get_id() << endl;
}

class callable_class
{
public:
    void operator()()
    {
        cout << "Hello from thread id:" << this_thread::get_id() << " with func call operator" << endl;
    }
};

void some_operation_before_join()
{

}

int main()
{
    std::thread foo_thread(foo);
    std::thread bar_thread(bar);

    bar_thread.detach();
    cout << "After bar thread detach" << endl;

    
    try {
        some_operation_before_join();
        foo_thread.join();
        cout << "After foo thread join" << endl;
    }
    catch (...)
    {
        foo_thread.join();
    }

}