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

void wew()
{
    static int i=0;
    std::cerr << i << " wew\n";
    if (i > 3)
    {
        exit(i);
    }
    ++i;
}
int main(){
    std::set_new_handler(wew);
    int *yuge = new int[10000000000];
    yuge[30] = 23;
    return 0;
}
