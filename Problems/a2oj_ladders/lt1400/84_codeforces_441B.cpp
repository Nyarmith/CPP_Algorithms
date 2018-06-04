#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#define ll long long

ll f[3001];
ll c[3002];
int main(){
  ll n, v;
  ll day, num;
  std::cin >> n >> v;
  for (int i=0; i<n; ++i){
    std::cin >> day >> num;
    f[day] += num;
  }

  for (int i=0; i<3002; ++i){
    ll col = std::min(f[i],v-c[i]);
    f[i] -= col;
    c[i] += col;
    c[i+1] += std::min(f[i],v);
    f[i] -= c[i+1];
  }

  std::cout << std::accumulate(c,c+3002,0);
}
