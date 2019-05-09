// old stype template mp

#include <iostream>

// https://stackoverflow.com/a/499146
template<unsigned T>
struct fibonacci{
    enum { v =  fibonacci<T - 1>::v + fibonacci<T - 2>::v};
};
template<>
struct fibonacci<0>{
    enum { v = 1 };
};
template<>
struct fibonacci<1>{
    enum { v = 1 };
};

int main(){
    int fib10 = fibonacci<10>::v;
    std::cout << fib10 << "\n";
}
