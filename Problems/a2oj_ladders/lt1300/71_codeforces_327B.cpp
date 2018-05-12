#include <string>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

//sieve of eratosthenes
void makePrimes(int n, std::vector<int> &vec){
}

int main(){
  int n;
  std::vector<int> vec;
  vec.reserve(100000);
  std::scanf("%i",&n);
  makePrimes(n,vec);
  std::copy(vec.begin(),vec.end(),
      std::ostream_iterator<int>(std::cout," "));
}
