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

//yogurt can be nutritious, but must be consumed before it expires.
//lucy bought N cups of yogurt
//the ith cup expires in A_i days, and it cannot be consumed on the day it expires
//She can consume at most K cups of yogurt a day
// - what is the largest amount of yogurt lucy can consume?
// 

//So this seems fairly greedy, like I'll be able to prioritize consuming the most stale yogurts first



ll g_yogArr[5000];

ll MaximizeYogs(ll n, ll k);

int main(){
  std::vector<ll> results;
  ll T; //num testcases
  std::cin >> T;
  results.reserve(T);

  ll N,K;
  for (int i=0; i<T; ++i)
  {
    std::cin >> N >> K;
    for (ll i=0; i<N; ++i){
      std::cin >> g_yogArr[i];
    }
    std::sort(g_yogArr, g_yogArr+N);
    results.push_back( MaximizeYogs(N,K) );
  }

  for (size_t i=0; i<results.size(); ++i){
    std::cout << "Case #" << (i+1) << ": " << results[i] << "\n";
  }
}

ll MaximizeYogs(ll n, ll k){
  ll ret   = 0;
  ll day   = 0;
  ll glut  = 0;
  ll i = 0;
  while(i<n){
    if (day < g_yogArr[i]){
      ++ret;
      ++glut;
    }
    if (glut >= k){
      glut=0;
      ++day;
    }

    ++i;
  }

  return ret;
}
