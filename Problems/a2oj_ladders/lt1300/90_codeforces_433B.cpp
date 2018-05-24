#include <cstdio>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <cinttypes>

int main(){
  std::vector<uint64_t> v, u, sumv, sumu;
  uint64_t n, m, tmp;
  std::scanf("%" PRIu64 , &n);
  v.reserve(n);
  u.reserve(n);
  sumv.reserve(n);
  sumu.reserve(n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%" PRIu64, &tmp);
    v.push_back(tmp);
    u.push_back(tmp);
  }
  std::sort(u.begin(), u.end(), std::less<uint64_t>());
  sumv.push_back(0);
  sumu.push_back(0);
  for (uint32_t i=1; i<=n; ++i){
    sumv.push_back(sumv[i-1] + v[i-1]);
    sumu.push_back(sumu[i-1] + u[i-1]);
  }
  std::scanf("%" PRIu64, &m);
  std::vector<uint64_t> outs;
  outs.reserve(m);
  uint64_t type,l,r;
  for (uint32_t i=0; i<m; ++i){
    std::scanf("%" PRIu64 " %" PRIu64 " %" PRIu64 ,  &type, &l, &r);
    if ( type == 1 ){
      outs.push_back(sumv[r]-sumv[l-1]);
    } else {
      outs.push_back(sumu[r]-sumu[l-1]);
    }
  }
  for (uint32_t i=0; i<m; ++i){
    std::printf("%" PRIu64 "\n", outs[i]);
  }
}
