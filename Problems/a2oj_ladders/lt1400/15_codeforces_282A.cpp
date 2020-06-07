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

int main(){
    int n, ret=0;
    std::string str;
    std::cin >> n;
    for (int i=0; i<n; ++i)
    {
        std::cin >> str;
        if (str.find("++") != std::string::npos)
            ++ret;
        else
            --ret;
    }
    std::cout << ret << "\n";
}
