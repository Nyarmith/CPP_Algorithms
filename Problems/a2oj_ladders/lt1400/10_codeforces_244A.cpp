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
    int n, k, tmp;
    std::cin >> n >> k;

    std::vector<int> b(k*n,-1);
    std::vector<int> a(k,0);
    for (int i=0; i<k; ++i)
    {
        std::cin >> a[i];
        b[a[i] - 1] = i;
    }

    static int ctr = 0;
    for (int i=0; i<k; ++i)
    {
        std::cout << a[i] << " ";
        for (int j=1; j<n; ++j) // print out kid's result
        {
            while(b[ctr] != -1)
                ++ctr;

            b[ctr] = i;
            std::cout << (ctr+1) << " ";
        }
        std::cout << "\n";
    }
}
