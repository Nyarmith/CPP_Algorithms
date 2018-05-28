#include <cstdio>
#include <iostream>
#include <string>
#include <string>
#include <cstdint>
#include <cinttypes>


int main(){
  int64_t x,y,z,n;
  std::cin >> x >> y >> n;
  z = y-x;
  int64_t ans=0;
  switch(n % 6){
    case (0):
      ans = -z;
      break;
    case (1):
      ans = x;
      break;
    case (2):
      ans = y;
      break;
    case (3):
      ans = z;
      break;
    case (4):
      ans = -x;
      break;
    case (5):
      ans = -y;
      break;
  }

  while (ans < 0){
    ans += 1000000007;
  }
  ans = ans % 1000000007;
  std::cout << ans;
}

