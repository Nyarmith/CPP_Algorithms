#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <set>

const int primeMax = 15485868;

bool primes[primeMax]; 
std::set<uint64_t> t_primes;

void sievePrime(){
  for (uint64_t i=2; i<primeMax; ++i){
    if (!primes[i]){
      t_primes.insert(i*i);
      for (int j=i+i; j<primeMax; j+=i)
        primes[j] = true;
    }
  }
}

int main(){
  uint64_t n, tmp;
  sievePrime();
  std::scanf("%" PRIu64 , &n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%" PRIu64, &tmp);
    if (t_primes.find(tmp) != t_primes.end())
      std::printf("YES\n");
    else
      std::printf("NO\n");
  }
}
