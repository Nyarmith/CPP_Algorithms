#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long

/*
 * Types of expressions in terms of lvalues and ralues
 *
 *           expression
 *           /       \
 *     glvalue        rvalue
 *     /      \      /      \
 * lvalue      xvalue       prvalue
 */


// LValues
// Locator-Value = locates an object in memory
int lvalue;
int &thisFunctionNameIsAnLvalue()
{
    int &stillAnLval = lvalue;
    int *ptrsAreLvalsToo{&lvalue};

    std::cout << "object:\t" << lvalue << "\n";
    std::cout << "reference:\t" << stillAnLval << "\n";
    std::cout << "ptr:\t" << *ptrsAreLvalsToo << "\n";

    return lvalue;
}

/*
 * prvalues are4 rvalues that are not xvalues
 * prvalue = "pure rvalue"
 */
constexpr int wew(int x) {
    return x*x;
}

void prValueExamples()
{
    int prValueOnTheRight {42}; //42 is the rvalue

    constexpr int anLval {420};
    // Whenever a glvalue appears in a context where a prvalue is expected, the glvalue is converted to a prvalue.
    int prv2 {anLval};  // anLval is _converted_ to a prvalue (isn't that just called its evaluation?)

    int prv3 = wew(23);  //function return value is a prvalue

    int prv4 {prv3 + 23 / 2 };  // more generally, all expressions that return a value, return an rvalue
    // rvalues are not the objects nor the functions, they are just the values that are ultimately used
}

void f1(int &w)
{
    std::cout << "in f1 (lvalue ref) with " << w << "\n";
}

void f1(int &&w)
{
    std::cout << "in f1 (rvalue ref) with " << w << "\n";
}

void interrimExample()
{
    // let's delve into pass by value reference and rvalue reference
    int T = 42;
    f1(T);
    f1(38);

    int &&rvalRef{50};
    //this would be illegal: `int &&rvalRef{T};`
    f1(rvalRef);
    f1(wew(9));

    f1(static_cast<int&&>(T));
}

/**
 * Move Semantics
 * It's more efficient to move than copy, but to do so with lang semantics instead of ptrs
 * Initialization and assignment
 */
template<typename T>
struct anObj {
  anObj(T t) { t_ = new T{t}; }  // Constructor
  anObj(const anObj &o); // Copy Constructor
  anObj& operator=(const anObj &o){ // Copy Assignment Operator
      *t_ = *(o.t_);
  }
  anObj& operator=(anObj &&o){ // Move Assignment Operator (other object is expiring)
      delete t_;
      t_ = o.t_; //just move ptr
      o.t_ = nullptr;
      return *this;
  }

  anObj(anObj &&o){ // Move c-tor
      *this = std::move(o);
  }

  ~anObj(){
      std::cout << "deleting : " << t_ << " " << (t_ ? *t_ : 0) << std::endl;
      delete t_;
  }
  T* t_;
};

/**
 * xvalues
 * eXpiring value
 */
void moveSemanticsExample()
{
    anObj<int> z(2);
    {
        anObj<int> a(23);
    }

    {
        anObj<int> a(20);
        anObj<int> b(21);
        anObj<int> c(22);
        // an xvalue has an identity, and can be moved from
        z = std::move(a);
    }

}


int main(){
    thisFunctionNameIsAnLvalue() = 20;
    std::cout << "now: " << lvalue << "\n";

    prValueExamples();
    interrimExample();

    moveSemanticsExample();
}

