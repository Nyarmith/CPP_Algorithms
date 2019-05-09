Chapter 6 - Inheritance and Object-Oriented Design

virtual-function = "interface must be inherited"
non-virtual-function = "interface and implementation must be inherited"

# Item 32: Make sure public inheritance models "is-a"
- public inheritance means "is-a"

# Item 33: Avoid hiding inherited names
- It is never good to mask names in inherited classes w/ public keywd
- To make hidden names visible again, employ using declarations or forwarding functions

# Item 34: Differentiate between inheritance of interface and inheritance of implementation
- `virtual`
- I have never seen private inheritence used
- Separate inheritence of interface from inheritence of implementation
- non-virtual public = inheritence of interface and impl, pure-virtual public = inheritence of interface, virtual public = inheritence of interface and default impl

# Item 35: Consider alternatives to virtual functions
- mvp item
- Try using template patterns and NVI!
- Strategy pattern is aggregation instead of explcit inheritance (has-a)

# Item 36: Never redefine an inherited non-virtual function
- uh, final for virtuals
- is this still a thing?

# Item 37: Never redefine a function's inherited default parameter value
- default parameters are statically bound
- really selling us on the NVI

# Item 38: Model"has-a" or "is-implemented-in-terms-of" through composition
- Already known

# Item 39: Use private inheritance judiciously
- You can't cast something to its privately inherited base type
- Private inheritance means "is implemented in terms of" and should only be used when composition can't be used

# Item 40: Use multiple inheritance judiciously
- Multiple inheritance is only useful for combining multiple pure virtual classes (i.e. pure interfaces) and for inheriting privately the implementation, then publicly inheriting the interface, and gluing them together in the class
- By default MI duplicates the data (to mitigate the diamond inheritance problem), but data de-duplication is supported
- Generally, avoid
