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
  ll n,k,tmp;
  std::vector<ll> laws;
  std::cin >> n >> k;
  laws.reserve(n);
  for(ll i=0; i<n; ++i){
    std::cin >> tmp;
    laws.push_back(tmp);
  }

  std::vector< std::priority_queue<std::pair<ll,ll>> > set_things(k, std::priority_queue<std::pair<ll,ll>>());

  ll sum=0;
  //get first pqueue
  for (int i=0; i<k; ++i){
    sum += laws[i];
  }
  
  set_things[0].push(std::make_pair(sum,0));

  for (int i=1; i<=n-k; ++i){
    sum -= laws[i-1];
    sum += laws[i+k-1];
    set_things[i%k].push(std::make_pair(sum,i));
  }
  //now get the max in each thing
  ll max=-1;
  std::pair<ll,ll> bestC = std::make_pair(0,0);
  for (int i=0; i<k; ++i){
    std::priority_queue<std::pair<ll,ll>> &cur = set_things[i];
    ll tp=0;
    ll best = cur.top().first;
    tp = cur.top().second;
    cur.pop();
    best += cur.top().first;
    if (best > max){
      max = best;
      bestC.first = tp;
      bestC.second = cur.top().second;
    }
  }
  std::cout << bestC.first+1 << " " << bestC.second+1 << "\n";
}
