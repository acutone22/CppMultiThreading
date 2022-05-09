// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "thread_guard.h"

using namespace std;

//Passing thread's args by value
void func(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}

//Passing thread's args by refs
void func_2(int& x)
{
    while (true)
    {
        cout << "Thread value of x: " << x << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    int p = 9, q = 8;

    thread t1(func, p, q);
    t1.join();

    int x = 1;
    thread t_ref(func_2,std::ref(x));
    this_thread::sleep_for(chrono::milliseconds(5000));
    x = 99;
    cout << "Changing x to " << x << endl;
    t_ref.join();
}