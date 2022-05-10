// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

#include "thread_safe_stack.h"

using namespace std;

void foo(thread_safe_stack<int>& stk) { stk.pop(); }
void bar(thread_safe_stack<int>& stk) { stk.push(1); }

int main()
{


}