#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

int main(){
  uint32_t y,k,n;
  std::scanf("%u %u %u",&y,&k,&n);
  //print all possible values of x in ascendign order(min is 1)
  int x = k - (y)%k;
  while (x < 1)
    x += k;

  int sum=x+y;
  if (x+y > n){
    std::cout << -1;
    return 0;
  }

  while (sum<=n){
    std::cout << x << " ";
    x += k;
    sum = y + x;
  }
}
