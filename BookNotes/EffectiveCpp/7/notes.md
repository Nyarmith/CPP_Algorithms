Chapter 7 - Templates and Generic Programming
- C++ templates are turing complete

# Item 41: Understand implicit interfaces and compile-time polymorphism
- In normal inheritance you get explicit interfaces and runtime polymorphism
- In generic programming, you get _implicit interfaces_ and _compile-time polymorphism_

# Item 42: Undersand the two meanings of typename
- In a template, typename tells the template that a nested dependent name is a type, resolving ambiguity

# Item 43: Know how to access names in templatized base classes(where inheriting from a base class w/ a template type)
- Templating breaks ineritance
- specialize a template with `template<> class Template<SpecificType> {...`
- you have to use `this->`, or `using className<T>::methodName` then just `methodName(..)` later in class, or statically with `className<T>:methodName(..)`. Probably prefer first.

# Item 44: Factor Parameter-Independent Code Out of Templates
- Using some kind of variable size parameter in a template instead of a c-tor causes code-bloat, know what code you're generating!
- It is a trade-off
- Probably in facor of bloat nowadays, unless you have n^3 bloat (perhaps that's the best way to think of it)

# Item 45: Use member function templates to accept "all compatible types"
- Member functions can be templated separately
- Templates can be used as an extra step for converting types

# Item 46: Define non-member functions inside templates when type conversions are desired
- Again, defining some operator as a template outside of a class offes another degree of freedom w.r.t. type conversion

# Item 47: Use traits classes for information about types
- This is a hack and use `if (std::is_same<newType, T>)` instead

# Item 48: Be aware of template metaprogramming
- did't know about `std::advance`
- there are better ways of doing this now
- too out of date
