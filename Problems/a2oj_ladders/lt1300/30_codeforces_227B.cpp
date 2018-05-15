#include <cstdio>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>

using std::uint32_t;
using std::vector;

//WARNING == UNORIGINAL CODE
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}


int main(){

  vector<uint32_t> myVec;
  myVec.reserve(100000);

  uint32_t n, c;

  std::scanf("%u", &n);

  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u", &c);
    myVec.push_back(c);
  }
  //sory and get indices
  auto inds = sort_indexes(myVec);

  uint64_t l=0, r=0;

  std::scanf("%u", &n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u", &c);
    l += inds[c-1] + 1;
    r += myVec.size() - inds[c-1];
  }
  
  std::cout << l << " " << r << std::endl;
}
