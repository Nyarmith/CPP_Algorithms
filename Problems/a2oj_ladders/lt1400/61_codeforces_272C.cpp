#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cinttypes>
#include <utility>
#include <iterator>

int main(){
  int64_t n,tmp;
  std::vector<int64_t> s, out;
  std::cin >> n;
  s.reserve(n);
  out.reserve(n);
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    s.push_back(tmp);
  }

  int64_t m, w, h, H=-1;
  std::cin >> m;
  for (int i=0; i<m; ++i){
    std::cin >> w >> h;
    H = std::max(H,s[w-1]);
    out.push_back(H);
    H += h;
  }

  std::copy(out.begin(), out.end(), std::ostream_iterator<int64_t>(std::cout, "\n"));
}

