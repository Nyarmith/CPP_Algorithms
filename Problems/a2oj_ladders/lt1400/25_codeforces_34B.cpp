#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

// int main()
// {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> a(n,0);
//     for (int i=0; i<n; ++i)
//     {
//         std::cin >> a[i];
//     }
//     std::sort(std::begin(a), std::end(a));
// 
//     n = 0;
//     int ret=0;
//     while(n<m && a[n] < 0)
//     {
//         ret -= a[n];
//         ++n;
//     }
//     std::cout << ret << "\n";
// }
// The above solution works... but let's do a cooler operation since we know the range!

uint8_t numCnt[2001] = {0}; //keep count of instances of the values [-1000,1000]

int main()
{
    int n,m,tmp;

    std::cin >> n >> m;

    for (int i=0; i<n; ++i)
    {
        std::cin >> tmp;
        ++numCnt[tmp+1000];
    }

    int ret = 0;
    for (int i=0; i<1000 && m > 0; ++i)
    {
        while(numCnt[i] && m > 0)
        {
            ret += (1000 - i);
            --numCnt[i];
            --m;
        }
    }
    std::cout << ret << "\n";
    return 0;
}
