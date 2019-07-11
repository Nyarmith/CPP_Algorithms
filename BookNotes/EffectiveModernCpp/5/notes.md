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
