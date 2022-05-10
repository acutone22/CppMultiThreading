#pragma once

#include <mutex>
#include <queue>

template<class T>
class thread_safe_queue
{
    std::mutex m;
    std::condition_variable cv;
    std::queue<std::shared_ptr<T>> queue;
public:
    thread_safe_queue();
    thread_safe_queue(thread_safe_queue const& other_queue);

    void push(T& value)
    {
        std::lock_guard<std::mutex> lg(m);
        queue.push(std::make_shared<T>(value));

        //One of the threads waiting in the wait_pop() condition wakes up and acquires the unique lock
        cv.notify_one();
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lg(m);
        if (queue.empty())
        {
            return std::shared_ptr<T>();
        }
        else
        {
            std::shared_ptr<T> ref(queue.front());
            queue.pop();
            return ref;
        }
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lg(m);
        return queue.empty();
    }

    size_t size()
    {
        std::lock_guard<std::mutex> lg(m);
        return queue.size();
    }

    std::shared_ptr<T> wait_pop()
    {
        std::unique_lock<std::mutex> lg(m);
        //When the following condition fails, we unlock the mutex
        cv.wait(lg, [this] {
            return !queue.empty();
            });
        std::shared_ptr<T> ref = queue.front();
        queue.pop();
        return ref;
     }

    bool wait_pop(T& ref)
    {

    }

    bool pop(T& ref)
    {

    }

};

