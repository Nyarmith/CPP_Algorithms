#include <cstdio>
#include <cstdint>
#include <iostream>


//there's a better way to do this, but since d is small, I can just iterate through all d
int main(){
  uint64_t k,l,m,n,d;
  std::cin >> k >> l >> m >> n >> d;
  int dragVictim=0;

  for (int i=1; i<=d; ++i){
    if (i%k==0 || i%l==0 || i%m==0 || i%n==0)
      ++dragVictim;
  }

  printf("%i",dragVictim);
}
