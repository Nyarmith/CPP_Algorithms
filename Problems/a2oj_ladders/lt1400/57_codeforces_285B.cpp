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
#define ll long long

int main(){
  ll n,s,t,tmp;
  std::vector<ll> arr;
  std::cin >> n >> s >> t;
  arr.reserve(n);
  for (ll i=0; i<n; ++i){
    std::cin >> tmp;
    arr.push_back(tmp);
  }

  int current = s-1;
  ll moves = 0;
  //detect loop
  ll delay=current, ayy=0;
  while (current != t-1){
    current = arr[current]-1;
    ++moves;
    ++ayy;
    if (ayy%2 == 0){
      delay = arr[delay]-1;
      if (delay == current){
        moves = -1;
        break;
      }
    }
  }

  std::cout << moves << "\n";
}
