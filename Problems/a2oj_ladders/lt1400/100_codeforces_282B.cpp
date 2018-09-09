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
  std::vector<ll> l, r;
  ll n, tmp;
  std::cin >> n;
  for (ll i=0; i<n; ++i){
    std::cin >> tmp;
    l.push_back(l);
    r.push_back(r);
  }

  ll lsum = std::accumulate(l.begin(), l.end(), 0);
  ll rsum = std::accumulate(r.begin(), r.end(), 0);

  float lavg = (float)lsum / l.size();
  float ravg = (float)rsum / r.size();

  //idk dude
}
