#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

int64_t vals[27];
int main(){
  int64_t n,k;
  std::string cards;
  std::cin >> n >> k >> cards;
  for (auto it=cards.begin(); it!=cards.end(); ++it){
    ++vals[*it-'A'];
  }
  int64_t max=0;
  for (int i=0; i<27; ++i){
    if (vals[i] > max)
      max = vals[i];
  }
  int64_t res=0;
  while(k){
    int64_t max=0;
    int64_t maxi=0;
    for (int i=0; i<27; ++i){
      if (vals[i] > max){
        max  = vals[i];
        maxi = i;
      }
    }

    int64_t v = std::min(max,k);
    res += v*v;
    k -= v;
    vals[maxi] -= v;
  }

  std::cout << res;
}
