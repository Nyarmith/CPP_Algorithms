# auto

## 5 - Prefer auto to explicit type declarations
* Should be unambigious which type `auto` should be
* Forces type initialization (i.e. rhs type required)
* Solves template typename/embedded-name conundrum
* auto doesn't resolve functions to std::function type by default

## 6 - Use the explicitly typed initialize idiom when auto deduces undesired types
* auto sometimes deduces a type you don't want it to, e.g. a reference type that no longer exists
* This idiom suggests using auto and a static_cast to the resultant type
* Basically, even in this pedantic way, be explicit rather than implicit
