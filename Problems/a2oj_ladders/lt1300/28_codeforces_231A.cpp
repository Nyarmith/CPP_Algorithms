#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

int main(){
  int n, tmp;
  int impl=0;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    int votes=0;
    for (int j=0; j<3; ++j){
      std::cin >>  tmp;
      votes += tmp;
    }
    if (votes >= 2)
      ++impl;
  }

  std::cout << impl;
}
