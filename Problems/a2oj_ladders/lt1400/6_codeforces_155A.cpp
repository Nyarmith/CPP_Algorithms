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

int main()
{
    ll n;
    std::cin >> n;
    std::vector<int16_t> v(n,0);

    for (int i=0; i<n; ++i)
        std::cin >> v[i];

    int min,max,amaze=0;
    min = max = v[0];

    for (int i=1; i<n; ++i)
    {
        if (v[i] > max)
        {
            max = v[i];
            ++amaze;
        }
        if (v[i] < min)
        {
            min = v[i];
            ++amaze;
        }
    }

    std::cout << amaze << "\n";
    return 0;
}
