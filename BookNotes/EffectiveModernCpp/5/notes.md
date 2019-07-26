# Rvalue References, Move Semantics, Perfect Forwarding

## 23 - Understand std::move and std::forward
- std::move and std::forward are functions that perform casts
- at run-time, std::move and std::forward don't move anything, no code is generated from these statements
- forward is used when the arg is bound to an rvalue, and it casts only if the arg of the fn was initialized with an rvalue. it casts its arg to an rvalue. forward can technically do it all
- move requests on const objects are treated as copy requests

## 24 - Distinguish universal reerences from rvalue references
- I think he's just going over the definition of universal reference but catch me if I'm wrong

## 25 - Use std::move on rvalue references and std::forward on universal references
- I thought this was explained in 23
- idk about returning w/ std::move and copy elision

## 26 - Avoid overloading on universal references
- You'll call it more than you intend
- Use template type annotations if you need this granularity

## 27 - Familiarize yourself with alernatives to overloading on universal references
- pass-by-value-reference-to-const; ez
- Pass by vaue
- Constrain templates with `std::enable_if`
- `std::is_base_of` and `std::is_same`
- `std::is_constructible`

## 28 - Understand reference collapsing
- You are forbidden from creeating references to references, but compilers can create them in certain contexts (i.e. things like T& & var;)
- If either reference (in the (T) (&&) a) thing is an lvalue reference, the result is an lvalue reference, otherwise (i.e. bpth are rvalue references), then the result is an rvalue reference
- Occurs in : auto type deduction, template type deduction, using/typedef aliases, decltype
- Universal reference is an rvalue-reference in the context 

## 29 - Assume that move operations are not present, not cheap, and not used
- Why would you do this, scott
- I guess it could be reasonable for old code with unknown types, but it's 2019

## 30 - Familiarize yourself with perfect forwarding failure cases
- these seem more like "things that will kill your templates", i.e. compilers are unable to deduce a type, or deduce a type you didn't want them to
- braced initializers
- 0 or null as null pointers
- declaration-only integral `static const` and `constexpr` data members (it should fail to link since the memory address hasn't been defined yet)
- bitfields (referring no longer to type, but to specific offset in memory address; there's no way to create a pointer to arbitrary bits)

