#include <cstdio>
#include <iostream>
#include <cstdint>

int main(){
  int n,k;
  int i=1;
  std::cin >> n >> k;
  while(i<n-k){
    std::cout << i << " ";
    ++i;
  }
  i = n;
  while (i >= n-k){
    std::cout << i << " ";
    --i;
  }
}
