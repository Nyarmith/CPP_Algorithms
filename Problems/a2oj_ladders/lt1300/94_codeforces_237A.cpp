#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>

int times[24*60+1];
int main(){
  int n,h,m;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> h >> m;
    ++times[h*60+m];
  }
  std::cout << *std::max_element(times, times+24*60);
}
