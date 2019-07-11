# Moving to Modern C++

## 7 - Distinguish between () and {} when creating objects
* "Uniform Initialization"
* Braced initializer makes you immune to vexing parse (oops I'm a fn)
* Braced initializer, expectedly, matches to std::initializer_list c-tor first
* Empty braces then mean an initializer list w/o values, not the default ctor
* From a design perspective, you then have to consider parens and braces within creation of objects in templated functions

## 8 Prefer nullptr to 0 and NULL
* nullptr doesn't have an integral type and cant be converted to anything other than ptr types

## 9 - Prefer alias declarations to typedefs
* `using myAlias=some::type` is nice and scoped
* Avoids typename in templates
* Type traits are a thing

## 10 - Prefer scoped enums to unscoped enums
* Use `enum class` instead of just `enum` to avoid leaking symbols
* Scoped enums default to int
* Should define operators for the enum type if needed
* Scoped enums can be forward-declared, with or without the underlying type. The syntax is nicer than forward declaring normal enums. Normal enums need their underlying type specified.
   - This allows to keep the same header and to change the enums in a cc, thus not trigger a total recompile on things dependent on the header
* Valid use of normal enums: for like `std::get<paramEnumVal>(myTuple)`, when we're trying to not use magic-numbers
* If you want type conversion for enums to happen during compilation, you have to make the convertor constexpr

```
template<typename E>
constexpr auto toUType(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}
```

## 11 - Prefer deleted functions to private undefined ones
* As usual, prevent consumers of your code from doing anything stupid; put all the training wheels on you can
* Now, instead of making c-tors and whatever auto fns don't want consumers to use private, you set them `= delete;`
* You can enforce not to type-convert by defining a function that will take a type that can convert (implicitly, usually), to the actual type of the function, but then deleting it.
* Any functions may be deleted, includign non-member functions and template instantiations

## 12 - Declare overriding functions override
* There are member function _reference qualifiers_ and they limit use of a member function to instances where `this` is an lvalue or rvalue only
  - this is done with a single or double ampersand at the end of the method signature.
* you should always use overrides and force a compiler setting that warns when an inherited method that's overridden isnt specified as _override_
  - It will also fail if you mess up the overridden signature
## 13 - Prefer const_iterators to iterators
- use `auto` with vec.cbegin() or std::cbegin(vec)
- `const auto` doesn't work here with .begin() ;_;
- you should also prefer std::begin(), std::end, std::cbegin(), std::cend() to the member versions

## 14 - Declare functions noescept if they won't emit exceptions
- Exceptions were a mistake CMV
- You should declare a function noexcept if it won't emit an exception
- not actually enforced by type system and everything throws exceptions
- helps optimize stuff for swap and move functions, all previous c-tor d-tor considerations still apply

## 15 Use constexpr when possible
- I could probably stand to use it more
- You can't assume the results of constexpr are const
- You can apply constexpr to objects
- Constexpr functions produce compile-time constants when they are called with compile-time constants
- You can apply constexpr to member fn's and c-tors weird
- Probably most useful thing so far to tiny embedded stuff
- side: const objects don't need to be known at compile-time (can be copies of something known at run-time)
- side: std::pow isn't constexpr (sucks)

## 16 - Make const member functions thread safe
- _shakes fist at mutable_
- author suggests using atomics to avoid threading cruft

## 17 - Understand special member function generation
- Aside from special rule-of-three stuff, there are two more inductees: the move c-tor and the move assignment operator
- Types that aren't _mvoe enabled_ are "moved" with their copy-ctor
- Move operators are generated for classes, when needed, only if no copy operations are declared, no move operations are declared, and no c-tors are declared
- Can also set `= default` to fore generation
- https://stackoverflow.com/questions/32225874/do-compilers-provide-default-move-assignment-operators-and-move-constructors
- https://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11?rq=1

## 18 - 
