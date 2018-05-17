#include <cstdio>
#include <cstdint>
#include <iostream>
#include <cmath>

//the only answers to this problem will either be 1, 0 or -1
int main(){
  int lsum=0;
  int rsum=0;
  int dom=-1; //first domino that has one half even and other half uneven
  int n,a,b;
  std::scanf("%i",&n);
  for(int i=0;i<n;++i){
    std::scanf("%i %i", &a, &b);
    if (dom == -1 && std::abs(a-b) % 2 == 1){
      dom = i;
    }
    lsum += a;
    rsum += b;
  }
  if (lsum%2 == 0 && rsum %2 == 0)
    std::cout << 0;
  else if (dom != -1 && lsum%2==1 && rsum%2==1 && n != 1)
    std::cout << 1;
  else
    std::cout << -1;
}
