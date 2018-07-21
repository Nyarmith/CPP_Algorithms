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
  ll n,m,tmp;
  std::vector<ll> arr;
  std::cin >> n >> m;
  arr.reserve(n);
  for (ll i=0; i<n; ++i){
    std::cin >> tmp;
    arr.push_back(tmp);
  }
  //now the operations
  ll inc = 0;
  for (ll i=0; i<m; ++i){
    std::cin >> tmp;
    switch(tmp){
      case 1:
        std::cin >> tmp >> n;
        arr[tmp-1] = n - inc; //compensate for global increment
        break;
      case 2:
        std::cin >> tmp;
        inc += tmp;
        break;
      case 3:
        std::cin >> tmp;
        std::cout << arr[tmp-1] + inc << "\n";
        break;
    }
  }
}

