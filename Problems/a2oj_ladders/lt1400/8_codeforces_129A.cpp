#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>


int main(){
  int n,tmp;
  int odds=0, evens=0;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    if (tmp % 2 == 0)
      ++evens;
    else
      ++odds;
  }

  if (odds % 2 == 0){
    std::cout << evens;
  } else {
    std::cout << odds;
  }
}
