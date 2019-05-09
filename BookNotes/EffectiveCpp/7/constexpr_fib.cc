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

constexpr unsigned fib(unsigned n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main()
{
    std::cout << fib(10) << "\n";
}
