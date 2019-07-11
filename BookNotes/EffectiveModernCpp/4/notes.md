# Smart Pointers

* There are four smart pointers: `auto_ptr` `unique_ptr` `shared_ptr` and `weak_tr`

## 18 - Use std::unique\_ptr for exclusive-ownership resource management
- these should probably be the default preferred pointer type
- unique\_ptrs are, by default, the same size as raw pointers
- you can make custom deleters (as a sort of surrogate c-tor), but stateful deleters increase the size of the unique\_ptr
- converts to a shared pointer for free

## 19 - Use std::shared\_ptr for shared ownership resource management
- Reference counting, man
- Not immediately intuitive to visualize "shared ownership" as a concept for runtime objects
- Twice the size of raw\_pointers, ref-count memory must be dynamically allocated, increments/decrements of the reference count must be atomic
- Obviously, move-ctoring a std::shared\_ptr doesn't have to create a new ref (increment the ref)
- Inc/Dec the ref should be thought of as "expensive" b/c it's atomic
- For std::shared\_ptr the deleter is not part of te type, unlike unique\_ptr (nicer, I guess, but now it's on the heap)
- Try using std::make\_shared and std::make\_unique instead of c-tor with a raw pointer (basically avoid having raw ptrs exposed at all)
- If you want to pass `this` as a shared\_ptr, you can return `make_shared_from_this` to not have two separate ref-count lads working at turbo-charge (and leaving memory dangling)
  - furnishes method `shared_from_this()`
  - crtp!
- shared\_ptrs cant work with arrays!
  - Made to point at a single object I guess


## 20 - Use std::weak\_ptr for std::shared\_ptr-like pointers that can dangle
- Weak ptr basically specializes by being a Maybe monad, in that it can handle the ptr-less states with the same interface
- The weak ptr can get a lock and return a shared pointer!
- These are basically a patch to shared\_pointers
- Uses: caching, sub/pub, avoiding shared\_ptr cycles

## 21 - Prefer std::make\_unique and std::make\_shared to direct use of new
- There are three god-given \_make\_ functions, make\_unique, make\_shared, allocate\_shared
- Pretty easy to follow
- If you need a custom deleter, then a make function isn't appropriate

## 22 - When using the Pimpl idiom, define special member functions in the implementation file
- Do this even if the default implementations are acceptable, because default copy won't be defined for move-only type
- use `unique_ptr` for pimpl, but define the c-tor in the impl file
- to define the copies, you 
