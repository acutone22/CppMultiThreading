// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "thread_guard.h"

using namespace std;

void foo()
{
    cout << "Hello foo thread id:" << this_thread::get_id() << endl;
}

void some_operation_before_join()
{

}

int main()
{
    std::thread foo_thread(foo);
    thread_guard tg(foo_thread);


    try {
        some_operation_before_join();
    }
    catch (...)
    {
    }

}