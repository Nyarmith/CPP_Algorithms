#include <cstdio>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <fstream>

int main(){
  int n,m;
  std::cin >> n >> m;
  int i=1;
  while (m >= n*(n+1)/2){
    m -= n*(n+1)/2;
  }

  while (m >= i){
    m -= i;
    ++i;
    if (i > n)
      i=1;
  }
  std::cout << m;
}
