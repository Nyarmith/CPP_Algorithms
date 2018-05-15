#include <string>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#define PRIMELIM 1300000
bool primz[ PRIMELIM ];

//sieve of eratosthenes
void printPrimes(int n){
  int nt=0;
  for (int i=2; i< PRIMELIM && nt<n; ++i){
    if (!primz[i]){
      std::printf("%i ",i);
      ++nt;
      for (int k=i+i; k < PRIMELIM; k += i){
        primz[k] = true;
      }
    }
  }
}

int main(){
  int n;
  std::scanf("%i",&n);
  printPrimes(n);
}
