# Item 1 : View C++ as a federation of languages
- c + objects + templates + stl (stl is a separate language?)

# Item 2 : Prefer consts, enums, inlines to #defines
- only use #defines as a last resort
- string replacements have no symbol entries
- you can have multiple copies of a constant in your binary if it's not bound to a symbol
- I forgot about the `const char * const myString = ...` thing. Maybe I can correct that somewhere.
- Better to declare variables without an assignment operator, since it's the same as using parentheses and (ultimately the copy-constructor); no assignment actually happens so it's misleading
- Remember the class-static gotcha: the declaration in the class is not the definition
- use enum to create clas-specific constants (cool hack)
- is "prefer inline functions" better than anonymous namespace functions?
- should you explicitly use the inline keyword?

# Item 3 : Use const whenever possible
- logical constness vs bitwise constness (logical := it's all an illussion!)
- have non-const operator refer to const one and cast away the const-ness (therefore you have one implementation) (const_cast the result, static_cast<const thisType>(this))

# Item 4 : Initialize objects before they're used
- uninitialized var := undefined behavior, prety clear
- assignment != initialization
\-> for objects, responsibility is delegated to assignment operator, which doesn't guarantee initialization of all members
- data-members that are const must be part of an initializer-list
- basically, prefer c-tor in all cases
- initialization of non-local static objects in other transation-units is undefined
\-> just don't use it raw, use getters/setters to defer it (singleton)
- pretty sure static objects are thread-safe by default now

## Misc
- I think _function objects_, things that overload `operator()` are still a core c++ thing
- C++ thinks of an "interface" more abstractly, which is more general but also more difficult, "interface" = "exposed signature", essentially
- Client := Consumer of interfaces
- Everything in TR1 is now a part of c++11
