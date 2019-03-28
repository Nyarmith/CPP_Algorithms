# Item 5 - Know What Functions C++ Silently Writes For You
- sort of like rule of 3 thing
- copy-ctor, assignment op, dtor
- ctor defn doesn't affect above three
- generated d-tor is non-virtual
- making any ctor means no default other ctors
- generation of default assignment operator breaks with const members, reference members, other things that don't make sense w/ default genn'd behavior

# Item 6 - Explicitly disallow the use of compiler-generated functions you don't want
- they make it private, but c++11 has `delete`

# Item 7 - Declare destructors virtual in base-classes
- it won't work because of d-tor unfolding, but also imagine the intent of not letting class get inherited
- in cpp11 there's also a final keyword

# Item 8 - Prevent destructors from throwing exceptions
- throw exceptions after cleaning things up/before allocating resources
- either swallow the exception(and log) or terminate the program(preferrable)

# Item 9 - Never call virtual functions during construction or destruction
- I have messed this up at least 3 times in my life
- tl;dr It's statically bound, so you get the one in the base-class (where it's bound)
- Keep c-tors and d-tors simple!

# Item 10 - Have assignment operators return a reference to *this
- can be assigned to, get cool assignment-chaining

# Item 11 - Handle self-assignment in operator=
- this was often mentioned in interviews
- I still mess this up
- Really more of a gotcha than anything
- Think of generalizing this to any relevant binary operator

# Item 12 - Copy all parts of an object
- Use all part of the animal
- Inheritance makes this sort of painful; you have to invoke base-class, normal init-list stuff
- Consider using a separate function to factor out similar assignment & copy-ctor code

## Misc
