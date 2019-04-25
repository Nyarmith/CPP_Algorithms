Chapter 4 - Designs and Declarations
Designing and declaring good c++ interfaces

# Item 18 - Make interfaces easy to use correctly, and hard to use incorrectly
- This seems to me like a "be careful with your constructors" warning
- Use structs and enums for stricter typing to your interfaces!

# Item 19 - Treat class design as type design
- Since you're augmenting your type system, you're not just a class designer, you're a type designer
- "Designing good classes is challenging because designing good types is challenging"

# Item 20 - Prefer pass-by-reference-to-const to pass-by-value
- It's cheaper (no ctors, dtors)
- No slicing problem (inheritence)
- Doesn't apply to built-in stl types!

# Item 21 - Don't try to return a reference when you must return an object
- Yet again, thinking of references as a separate thing from an object
- Stacc memory
- "Whenever you see the declaration for a reference, immediately ask yourself what it is another name for"

# Item 22 - Declare data members private
- This is just clear
- "Protected is no more encapsulated than public"

# Item 23 - Prefer non-member non-friend functions to member functions
- I agree with avoiding making methods unless it's a tight part of the object's interface
- i.e. too many methods increases mental load -> end up with _less_ encapsulation
- Don't pollute!
- side-note: c++ anonymous namespaces for impl files

# Item 24 - Declare non-member functions when type conversions should apply to all parameters
- Implicit conversion is sometimes appropriate if it simplifies w/o introducing edge cases (e.g. math library)
- Essentially it lets you focus on only one implementation of an operator, and the conversion operation lets the expression (e.g. a matrix multiplication) look sane

# Item 25 - Consider support for a non-throwing swap
- Conforming to swap is a way of guaranteeing good code?
    - you just need to have your ype support copying (copy c-tor and copy-assignment)
- If you have an object pointer member, it could potentially copy it if you're doing deep copies
- In this case, you could specialize swap in your code
- Also based on the type, a swap member fn may be appropriate
- when calling swap, employ _using_ declaration and ten call swap w/o namespace qualification
- side-note: _pimpl_ represent!
- Never try to specialize something already defined in std

