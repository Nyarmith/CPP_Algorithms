#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

int main(){
  int n,val=0;
  std::string w;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> w;
    if (w.substr(0,2) == "++" || w.substr(1,2) == "++")
      ++val;
    else
      --val;
  }
  std::cout << val;
}
