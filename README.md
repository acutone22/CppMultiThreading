# **CppMultiThreading**
**Thread Join vs Detach**
- **join** forces the main thread to wait until the thread that is called upon finishes its execution.
- **detach** lets multiple threads run in "parallel". The launched thread is separated from the thread object it is launched from

If you do not join or detach a joinable thread, at thread destructor time, std::terminate will be called (unsafe program).
A default constructed (no argument) thread object is not joinable by definition.

**Passing arguments to a thread**
- by value: just pass args after the function arg
- by reference: need for a std::ref(x) wrapper. Pay also attention if the variable passed by ref goes out of scope

**Thread vs processes**
- A process has its own memory, which is not shared with other processes. A process may contain multiple threads
- Threads in a process share the same memory, need for locks to avoid race conditions

**Race condition and solutions**

In a race conditions, multiple threads try to access the same resource. This can lead to unexpected results, or crashes. To avoid these, locks have to be implemented. In this way, the thread has exclusive access to the resource for the time it needs to perform its operation on the resource. After that, the resource is released (unlock) and used by other threads. There are multiple types of locks:
1. **Mutex**: provides mututal exclusive access of shared data for multiple threads. When lock method is called, thread gains exclusive access to the resource, other threads cannot use that object (they go in the so called "waiting state") until the unlock method is called on the object. Lock_guards is provided in C++ to handle mutex following RAII-style mechanism. Pay attention to dead lock, a scenario in which two threads are waiting for acquiring a lock from the other thread in an endless loop.

**Communication between threads using variables and futures**
**Condition variable:** basic mechanism for waiting for an event to be triggered by another thread.
**Futures** provide a mechanism to access the results of an asynchronous operation. Future may launch a "background" task while other operations are running and handle it when finished.