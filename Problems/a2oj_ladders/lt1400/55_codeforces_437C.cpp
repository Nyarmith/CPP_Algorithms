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
#define ul unsigned long

bool notRemoved[3000];

//WARNING == UNORIGINAL CODE
template <typename T>
std::vector<size_t> sort_indexes(const std::vector<T> &v) {

  // initialize original index locations
  std::vector<size_t> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

void populate(std::vector< std::vector<ll> > &el, ll n){
  for (int i=0; i<n; ++i){
    el[i] = std::vector<ll>();
  }
 }

int main(){
  ll n,m, a, b, numLeft,tmp;
  std::vector<ll> v;
  std::vector< std::vector<ll> > el;
  std::cin >> n >> m;
  std::fill(notRemoved, notRemoved+n, true);
  std::vector<ll> costs(n,0);
  v.reserve(n);
  el.reserve(n);
  populate(el,n);
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    v.push_back(tmp);
  }
  for (int i=0; i<m; ++i){
    std::cin >> a >> b;
    --a; --b; //turn into our 0based indexing
    el[a].push_back(b);
    el[b].push_back(a);
    costs[a] += v[b];
    costs[b] += v[a];
  }

  std::vector<ll> nucosts(n,0);

  ll totalCost=0;
  numLeft = n;
  while (numLeft > 0){
    //sort cost's indices
    for(ul i=0; i<nucosts.size(); ++i){
      nucosts[i] = costs[i] - v[i];
    }
    auto inds = sort_indexes(nucosts);
    ll ind=0;
    //ll maxVal  = 0;
    //ll minCost = 2000000000;
    //get cheapest index that hasn't been removed
    for (ul i=0; i<inds.size(); ++i){
      if (notRemoved[inds[i]]){
        ind = inds[i];
        break;
      }
    }
    //remove it
    notRemoved[ind] = false;
    totalCost += costs[ind];
    for (ul i=0; i<el[ind].size(); ++i){
      ll o = el[ind][i];
      costs[o] -= v[ind];
      el[o].erase(std::remove(el[o].begin(), el[o].end(), ind), el[o].end());
    }
    --numLeft;
  }

  std::cout << totalCost;
}
