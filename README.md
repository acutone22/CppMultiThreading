# **CppMultiThreading**
**Thread Join vs Detach**
- **join** forces the main thread to wait until the thread that is called upon finishes its execution
- **detach** lets multiple threads run in "parallel". The launched thread is separated from the thread object it is launched from

If you do not join or detach a joinable thread, at thread destructor time, std::terminate will be called (unsafe program).
A default constructed (no argument) thread object is not joinable by definition.