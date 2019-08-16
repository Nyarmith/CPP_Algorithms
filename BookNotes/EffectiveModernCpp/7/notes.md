# Concurrency API

## 35 Prefer task-based programming to thread-based
- Orient your abstractions around doing some task asynchronously rather than spinning up and down threads
- std::async offers some benefits in this regard
    - is lazily evaluated
    - doesn't necessarily run in another thread
    - `.get()` also gives access to exceptions if they're thrown, in a normal thread-approach, the exception would terminate the program
- basically, `std::async()` is another layer of abstraction on top of threads
- the onus of thread management is on the stdlib implementer of std::async; if all threads are in use, it has to decide to time-slice/whatever
    - avoids machine-specific code

- on embedded systems Zack prefers global thread-pools, e.g. mls::thread (or whatever)

## 36 Specify std::launch::async if asynchronicity is essential
- The default launch policy lets `std::async` run the task in the same thread, or defer execution until `.get()` or `.wait()` is run
    - When you run std::async, you're asking a function be run in accord with the `std::async` launch policy

- There are two policies for std::async
    - std::launch::deferred  -  f may run only when get or wait is called on the future, and when get or wait is invoked, f will execute synchronously
    - std::launch::async     -  f must be run on a different thread

- You probably want to use the `std::launch::async` policy if you're using `thread_local` variables
    - this modifier gives each thread its own copy of given variable

- If an async job is deferred, you should not try waiting until it finishes (and checking its status), given that it isn't guaranteed to run until access is tried

- With the default policy, under heavy load, the task will most likely be deferred, and there's now ay fo checking whether a thread is deferred or not

- Basically be aware of these policies and don't be caught by it

## 37 Make std::threads unjoinable on all paths
- A thread, at any given time, is joinable or unjoinable

    Joinable:
        * waiting to be scheduled, blocked, or completed

    Unjoinable:
        * a thread that has been detached
        * a thread that has already been joined

- If a joinable thread is destructed, all threads are terminated
- You can't set a priority with a future, unlike threads (via `.native_handle()`)
- D-tor of thread called when out of scope, like anything else, and if it's joinable and you exit, game over man
    - The alternatives aren't really better (implicit join or detach)
    - Feel like a compiler warning should fix this
- Basically don't leave dangling (joinable) threads when you wrap up your fn
- This is not very RAII

## 38 Be aware of varying thread handle destructor behavior
- the last future referring to a shared future-handle-state-thing, in its d-tor,  blocks until completion
    - this is how the "normal" `std::async` works
- If the task's launch policy is async, the d-tor will block until the async task completes
- all other d-tors implicitly dtach the thread and destroy their future object

- `std::packaged_task` wraps a function into a shared state, preparing it for asynchronous stuff
    - this can give you a future, and then you can also create and modify the thread
    - essentially no reason to make a packaged task for a `std::async`

- not sure what happens to deferred tasks
- There's a `std::shared_future` btw

## 39 Consider void futures for one-shot event communication
- For inter-thread communication, instead of `condition_variables` and, `waiting`, and `notify_*`
- Spurious wakeups are a legit thread-problem
- I have tried all the methods listed in this chapter, in the same order

## 40 Use std::atomic for concurrency, volatile for special memory
- volatize just means that you don't want writes to the memory optimized away (redundand loads and dead stores)
    - you know, memory-mapped i/o
- you all know what std::atomics are
- volatile is only necessary for repeated reading, really

## 41 Consider pass-by-value for copyable parameters that are cheap to move and always copied
- a lot of the time it actually doesn't matter
- if you're copying in the funciton anyway, you might as well use pass by value, then you can `std::move` that

## 42 Consider emplacement instead of insertion
- basically you save making an extra copy

