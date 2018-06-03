#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#define ll long long

ll sum[100000];

int main(){
  ll m,l,r;
  std::vector<ll> outs;
  std::string w;
  std::cin >> w;
  std::cin >> m;
  outs.reserve(m);

  //calculate sume
  sum[0] = 0;
  for (int i=1; i<w.size(); ++i){
    if (w[i] == w[i-1]){
      sum[i] = sum[i-1] + 1;
    } else {
      sum[i] = sum[i-1];
    }
  }

  for (int i=0; i<m; ++i){
    std::cin >> l >> r;
    outs.push_back(sum[r-1]-sum[l-1]);
  }

  std::copy(outs.begin(),outs.end(), std::ostream_iterator<ll>(std::cout,"\n"));
}
