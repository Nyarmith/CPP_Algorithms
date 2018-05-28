#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> digits;
int main(){
  int64_t a,b,n;
  std::cin >> a >> b >> n;


  int i=0;
  int mod=0;
  uint64_t d=0;
  while(i<n){
    a *= 10;
    d=0;
    while ((a+d)%b!=0 && d<=9)
      ++d;
    if (d==10){
      std::cout << -1;
      return 0;
    }
    a += d;
    ++i;
    if (std::find(digits.begin(),digits.end(),d) != digits.end()){
      mod = std::distance(digits.begin(), std::find(digits.begin(), digits.end(),d));
      break;
    }
    digits.push_back(d);

  }

  n -= i;

  std::vector<int> D(digits.begin()+mod, digits.end());
  mod = 1 % D.size();
  std::string out = std::to_string(a);

  while(n){
    out += '0' + D[mod];
    ++mod;
    mod = mod%D.size();
    --n;
  }

  std::cout << out;
}
