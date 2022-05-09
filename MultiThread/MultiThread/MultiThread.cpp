// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

using namespace std;

void foo()
{
    cout << "Hello World!\n";
}

class callable_class
{
public:
    void operator()()
    {
        cout << ("Hello from class with func call operator") << endl;
    }
};

int main()
{
    std::thread thread1(foo);
    thread1.join();

    callable_class obj;
    std::thread thread2(obj);
    thread2.join();

    std::thread lambdaThread([]()
        {
            cout << "Calling thread from lambda function" << endl;
        });
    lambdaThread.join();

    cout << "main" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
