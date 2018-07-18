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

using std::cin;
using std::cout;


std::map <std::tuple <ll, ll, bool>, ll> memo;

ll numTotalPaths(ll n, ll k, ll d, bool sat){
  if (n<0){
    return 0;
  }
  else if (n == 0 && sat){
    return 1;
  }
  else {
    auto key = std::make_tuple(n,k,sat);
    auto itr = memo.find(key);
    if ( itr != memo.end()){
      return itr->second;
    } else {
      ll ret = 0;
      for (ll i=1; i<=k; ++i){
        ret += numTotalPaths(n-i, k, d, sat || (i >= d));
      }
      memo[key] = ret;
      return ret;
    }
  }
}

int main(){
  ll n, k, d;
  ll out=0;
  std::cin >> n >> k >> d;

  for (ll i=1; i<=k; ++i){
    out += numTotalPaths(n-i, k, d, d<=i);
  }

  std::cout << out;
}
