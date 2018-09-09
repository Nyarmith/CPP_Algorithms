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

//dude must pass exactly n exams
//has two options for each exam

int main(){
  ll n, a, b;
  std::vector<std::pair<ll,ll>> exams;
  std::cin >> n;
  exams.reserve(n);
  for (ll i=0; i<n; ++i)
  {
    std::cin >> a >> b;
    exams.push_back({a,b});
  }
}

