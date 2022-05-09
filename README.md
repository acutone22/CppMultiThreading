### CppMultiThreading
#Thread Join vs Detach
- join force the main thread to wait until the thread that is called upon finishes its execution
- detach let multiple threads run in parallel
  
If you do not join or detach a joinable thread, at thread destructor time, std::terminate will be called (unsafe program).
A default constructed (no argument) thread object is not joinable by definition.