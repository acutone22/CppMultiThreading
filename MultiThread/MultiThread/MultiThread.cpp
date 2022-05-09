// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

using namespace std;

void foo()
{
    cout << "Hello thread id:" << this_thread::get_id() << endl;
}

class callable_class
{
public:
    void operator()()
    {
        cout << "Hello from thread id:" << this_thread::get_id() << " with func call operator" << endl;
    }
};

int main()
{
    std::thread thread1(foo);
    cout << "Thread1 is" << (thread1.joinable() ? "" : " not") << " joinable" << endl;
    thread1.join();
    cout << "After call join(), thread1 is" << (thread1.joinable() ? "" : " not") << " joinable" << endl;

    callable_class obj;
    std::thread thread2(obj);
    thread2.join();

    std::thread lambdaThread([]()
        {
            cout << "Calling thread id:" << this_thread::get_id() << " from lambda function" << endl;
        });
    lambdaThread.join();

    cout << "Running main function" << endl;
}