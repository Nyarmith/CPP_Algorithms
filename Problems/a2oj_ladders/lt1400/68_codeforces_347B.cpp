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
  ll fixedpts=0;
  ll n, tmp;
  std::vector<ll> arr;
  std::cin >> n;
  arr.reserve(n);
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    arr.push_back(tmp);
    if (tmp == i)
      ++fixedpts;
  }

  bool done=0;
  bool canSwapOne=0;
  for (ll i=0; i<n && !done; ++i){
    if (arr[i] != i){
      if (arr[arr[i]] == i){
        done=1;
        break;
      } else if (arr[arr[i]]  != arr[i]){
        canSwapOne = 1;
      }
    }
  }
  if (done){
    std::cout << fixedpts + 2;
  } else if (canSwapOne){
    std::cout << fixedpts + 1;
  } else {
    std::cout << fixedpts;
  }

}
