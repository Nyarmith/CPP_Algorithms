#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <locale>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long

int main()
{
    std::string a,b;
    std::cin >> a >> b;
    std::transform(std::begin(a),std::end(a),std::begin(a), ::tolower);
    std::transform(std::begin(b),std::end(b),std::begin(b), ::tolower);

    auto ita = std::begin(a);
    auto itb = std::begin(b);

    while (*ita == *itb && ita != a.end() && itb != b.end())
    {
        ++ita;
        ++itb;
    }

    if (*ita > *itb)
        std::cout << 1 << "\n";
    else if (*ita < *itb)
        std::cout << -1 << "\n";
    else
        std::cout << 0 << "\n";

    return 0;
}
