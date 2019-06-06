# Focal Concepts of Modern C++
- Move-semantics
    - Based on distinguishing rvalues & lvalues
    - rvalues indicate objects eligible for move operations
    - lvalues don't (generally)
- rvalue := temporary objects returned from functions
- lvalue := objects you can refer to by name, ptr or lvalue-reference

- && = rvalue reference
- move construction/assignment != cop construction/assignment

## 1 - Understand Template Type Deduction
* Template type T and the argument paramType should be thought of as separate when qualifiers are added
* Universal reference is a conception
  * Doesn't care when something is already a refernce
* Universal reference (these are now called forward refernces)
  * T&& seems to be either rvalue ref or lvalue ref
  * I think it's only a forward reference if theres type deduction

* If paramtype is `T&&`, then if an lvalue is passed, the actual type is an lvalue reference `T&`, if an rvalue is passed, the actual type is an rvalue reference `T&&`
* If paramtype is neither a ptr or a ref, then pass-by-value rules apply, const-ness is ignored

* Array arguments are deduced as their acutal type (with actual array sizes)
  * by-value is ptr, by-ref is array-ref

## 2 - Understand auto type deduction
* auto works the same way as templates, except it will deduce things to be initializer-lists, whereas templates just fail (i.e. you need to give an initializer-list<T> type in the template sig)
* auto means template deduction when in a lambda param or return type!

## 3 - Understand decltype
* `decltype(expr)` gives you the type of the expression `expr`
* wait, you can define a fn like
```
template<typename Container, typename Index>
auto authAndAccess(Cotainer &c, Index i) -> decltype(c[i])
{
    return c[i];
}
```
* This is called _trailing return type, which lets you use the parameter in the return type
* decltype(auto)
  * I guess thihnk of `decltype` as additional rules to run after type deduction

## 4 - Know how to view deduced types
* State of Template Metaprogramming: Use templating error messages to tell you the types
* Make a class template you don't define, and use decltype of the type you want to figure out in the `<>`
* type_info::name is not reliable



