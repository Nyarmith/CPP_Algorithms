#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

int main(){
  int n;
  int tmp,sum=0;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    sum += tmp;
  }

  if (sum % n == 0)
    std::cout << n;
  else
    std::cout << n-1;

}
