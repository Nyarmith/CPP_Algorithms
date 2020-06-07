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
    int n, cnt=0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (int i=1; i<n; ++i)
    {
        if (s[i-1] == s[i]) ++cnt;
    }
    std::cout << cnt << "\n";
}
