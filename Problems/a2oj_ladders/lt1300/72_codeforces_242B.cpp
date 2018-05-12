#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

//n segment line
//i'th segment at l_i, ending at r_i

int main(){
  int n, l, r;
  std::cin >> n;
  int minL=2000000000;
  int maxR=-1;
  int biggestRange[3]  = {0,0,0};
  int biggestRangeSize = -1;
  for (int i=0; i<n; ++i){
    std::cin >> l >> r;
    if (r-l > biggestRangeSize){
      biggestRangeSize = r-l;
      biggestRange[0] = l;
      biggestRange[1] = r;
      biggestRange[2] = i+1;
    }
    if (l < minL){
      minL = l; }
    if (r > maxR){
      maxR = r; }
  }
  if (biggestRange[0] == minL && biggestRange[1] == maxR){
    std::cout << biggestRange[2];
  } else {
    std::cout << -1;
  }
}
