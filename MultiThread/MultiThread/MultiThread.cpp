// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

#include "thread_guard.h"

using namespace std;

void foo() { cout << "foo" << endl; return; }
void bar() { cout << "bar" << endl; return; }

int main()
{
    thread t1(foo);
    //thread t2 = t1; //error: thread copy constructor is deleted 
    thread t2 = move(t1); //ok. After move assignment, t1 does not own any object

    t1 = thread(bar);

    t1.join();
    t2.join();

}