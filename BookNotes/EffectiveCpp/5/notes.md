# Item 26 - Postpone variable definitions as long as possible
- Or, don't prematurely define variable
- This also makes it clear what part of the code it's relevant to
- Increases clarity and efficiency

# Item 27 - Minimize casting
- Casting cheats past the safety that the type system is trying to create
- Leads to code that is executed at run-time, which is less potentially performant as well
- When casting is necessary, try to hide it inside a function
- Don't use C-style casts in C++ pls

# Item 28 - Avoid returning "handles" to object internals
- handle := references, pointers, iterators
- otherwise, you violate const-ness (very sad)

# Item 29: Strive for exception-safe code
- When exceptions are thrown, code shouldn't leak resources, or cause DS corruption (by violaing some DS precondition)
- Understand the stack unwinding, use it to your advantage w/ managed objects
- Exception-safe code should provide one the following guarantees:
- _basic guarantee_ : if an exception is thrown, everything in the program remains a valid state.
- _strong guarantee_ : If an exception is thrown, the state of the program is unchanged; the call to the throwing is atomic
- _nothrow_ : Promise to never throw exceptions

# Item 30: Understand the ins and outs of inlining
- For larger functions, it is just code-bloat and doesn't increase performance
- Templating should be treated independently of inlining even though it's entirely in header (v.tempting)
- Though, aren't template functions by definition inline?
- Google style guideline recommends keeping inline functions to <10 lines
- Also while loops are not recommended
- Q: How much does -O3 inline for you?
- Also, isn't inlining "solved" by the compiler?

# Item 31: Minimize compilation dependencies between files
- Minimize objects when objct references and pointers wil do
- Depend on class declarations instead of clas definitions
- idk how I feel about the header file separation suggestion
- I guess also don't add more headers than needed
- Again, check out google code guidelines header ordering
