#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>


int main(){
  std::uint32_t n,m;
  std::scanf("%u %u", &n, &m);
  int myArr[m];
  for (uint32_t i=0; i<m; ++i){
    std::scanf("%i", myArr+i);
  }
  std::sort(myArr, myArr+m);
  int minDiff = 9999;
  for (int i=n-1; i<m; ++i){
    int diff = std::abs(myArr[i] - myArr[i-(n-1)]);
    if(diff < minDiff)
      minDiff = diff;
  }
  std::printf("%i", minDiff);
}
