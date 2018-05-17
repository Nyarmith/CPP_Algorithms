#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <cinttypes>
#include <algorithm>


//useful bg info: https://stackoverflow.com/questions/110344/algorithm-to-calculate-the-number-of-divisors-of-a-given-number

int divs[10000001];

int d(int n){
  if (divs[n] != -1)
    return divs[n] + 1;
  divs[n] = 0;
  for (int i=2; i<=n; ++i){
    if (n % i == 0)
      ++divs[n];
  }
  return divs[n] + 1;
}

uint64_t sumN(uint64_t n){
  return n*(n+1)/2;
}

int main(){
  std::fill(divs,divs+101,-1);
  divs[0] = 0;
  divs[1] = 0;
  divs[2] = 1;
  uint64_t a,b,c;
  uint64_t sum=0;
  std::cin >> a >> b >> c;
  
  for (int i=1; i<=a; ++i){
    for (int j=1; j<=b;++j){
      for (int k=1; k<=c;++k){
        sum += d(i*j*k);
      }
    }
  }
  std::cout << (sum % 1073741824);
}
