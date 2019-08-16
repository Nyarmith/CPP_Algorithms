EffectiveModernCpp
* 5 : prefer auto to explicit type declarations
* 7 : distinguish between () and {} when creating objects, prefer {}
* 8 : use nullptr instead of null
* 9 : prefer using myType=othertype to typedef existingType myType;
* 11 : prefer deleted functions to private undefined ones and/or delete functions you don't want
* 12 : declare override functions override
* 13 : prefer const\_iterators to iterators
* 14 : declare functions noexcept if they won't emit an exception
* 15 : spam constexpr (I think the need is being reduced in c++20)
* 16 : const implies thread-safe, so make const member functions thread safe
* 18 : Pretty much use unique\_ptr's instead of pointers
* 23 : use std:move on rvalue refs and std::forward on universal refs
* 32 : Use init capture to move objects into closures, this also lets you alias them
* 33 : `[](auto&& x){ return someCrustyFunction(std::forward<decltype(x)>(x));}`
* 35 : Prefer task-based programming to thread-based, but (36) use an actual async policy

EffectiveCpp
* 3 : Use const whenever possible
* 4 : Always, always initialize
* 14 : Think carefully about copying behavior in resource-managing classes
* 19 : Treat class design as type design
* 35 : Consider alternatives to virtual functions, like nvi, template patterns, and aggregation
* 53 : Use max compiler warnings


an aside: homeworks?
