# Lambda Expressions
- Make `std::algorithm` great again

## 31 - Avoid Default Capture Modes
- Default by-reference capture can lead to dangling references, and default by-values can lead to dangling pointers
- Even if you capture, a pointer or some managed-data can be deleted from under you
- Be wary of capturing members by value, when you're actually capturing \*this
- Also it doesn't capture static variables (they are referred to but not "captured")
- Note: Magical c++14 alias sugar syntax

## 32 - Use init capture to move objects into closures
- c++14 has init capture, which lets you create little aliases for variables inside your closures
- So use it with `std::move` to move objects into closures
- Similar to c-tor move lesson in item 41

## 33 - Use decltype on auto&& parameters to std::forward them
- decltype(x) yields an rvalue reference when passed an rvalue
- this is really just a fancy templated lambda
- `[](auto&& x){ return someCrustyFunction(std::forward<decltype(x)>(x));}`

## 34 - Prefer lambdas to std::bind
- I think I used `std::bind` twice in my life, so this is welcomed advice
- More seriously, there's no way for std::bind to be more efficient than a lambda, it's uglier, and you have to get stuff from the stl to make it work
- note: `std::literals` exists

