#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>

int sum[12];
int main(){
  std::fill(sum,sum+12,4);
  sum[0]=0;
  sum[10] = 15;
  int n;
  std::cin >> n;

  n -= 10;
  if (n>11 || n < 0){
    std::cout << 0;
  } else  {
    std::cout << sum[n];
  }
}
