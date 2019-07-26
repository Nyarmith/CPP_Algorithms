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


// a move only type

template <typename T>
struct X
{
    void print()
    {
        for (size_t i=0; i<size_; ++i)
            std::cout << arr_[i] << " ";
        std::cout << "\n";
    }

    X(size_t n, T o = {})
    {
        size_ = n;
        arr_ = new T[n];
        for (size_t i=0; i<n; ++i) arr_[i] = o;
    }

    ~X()
    {
        std::cout << "deleting: ";
        print();
        delete[] arr_;
    }

    X& operator=(const X&& o)
    {
        std::cout << "deleting in move: ";
        print();
        delete[] arr_;
        size_ = o.size_;
        arr_ = o.arr_;  //this is the part that matters
        return *this;
    }

    X(X &&o)
    {
        *this = std::move(o);
    }

    X(const X &o) = delete;
    X& operator=(const X& o) = delete;

    T* arr_;
    size_t size_;
};

auto makeX(){
    return X<int>(3,3);
}

template<typename T>
void handleType(X<T> &o)
{
    std::cout << "in lval ref\n";
}
template <typename T>
void handleType(X<T> &&o)
{
    std::cout << "in rval ref\n";
}

template <typename T>
void constHandleType(const X<T> &o)
{
    std::cout << "in const lval ref\n";
}
template <typename T>
void otherConstHandleType(const X<T> &&o)
{
    std::cout << "in const rval ref\n";
}

int main()
{
    // what does the rvalue pick?
     handleType(makeX());
     auto r = makeX();
     handleType(r);

     constHandleType(r);
     // otherConstHandleType(r);
     constHandleType(makeX());

     otherConstHandleType(makeX());
}
