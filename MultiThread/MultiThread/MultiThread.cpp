// MultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <future>

int find_answer_how_old_universe_is()
{
    return 5000; //it is a false value
}

void do_other_calculations()
{
    std::cout << "Doing other stuff" << std::endl;
}

int main()
{
    //Future runs in background
    std::future<int> the_answer_future = std::async(find_answer_how_old_universe_is);
    do_other_calculations();
    //When I need results from futures, I call get(). If the async task has not completed yet, the main thread
    //will be blocked until the async task has finished
    std::cout << "The answer is " << the_answer_future.get() << std::endl;

}