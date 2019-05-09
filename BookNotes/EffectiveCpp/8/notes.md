Chapter 8 - Customizing new and delete
- C++ templates are turing complete

# Item 49: Understand the behavior of the new-handler
- When operator new can't satisfy a memory allocation request, it throws an exception. Before it throws, it calls a client-specifiable error-handling function called the _new-handler_
- When `operator new` is unale to fulfill a memory request, it calls the new-handler repeatedly until it can find enough memory. As a result, a new handler should do one of the following: make more memory available, install a different new-handler, deinstall the new-handler, throw an exception, call abort or exit instead of returning
- `std::set_new_handler(outOfMem);`

# Item 50: Understand when it makes sense to replace new and delete
- Use-cases: to detect usage errors, to collect usage statistics, for some really specific specialization of speed if you _reallllllly_ need it
- per-class new/delete handler has more cases: reduce space-overhead of default memory management, cluster related objects next to each other, obtain unconventional behavior

# Item 51: Adhere to convention when writing new and delete
- throw `bad_alloc` if you can't make mem
- return legit ptr even when zero size specified (just make 1 byte ptr)

# Item 52: Write a placement delete if you write placement new
- placement new = we pass allocated memory and new does the construction in the allocated memory
- this can throw
- don't hide normal versions of new/delete when declaring placement ones
