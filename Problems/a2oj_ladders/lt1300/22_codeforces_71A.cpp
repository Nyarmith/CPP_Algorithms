#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

int main(){
  int n;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::string w;
    std::cin >> w;
    if (w.size() > 10){
      std::cout << w[0] << w.size()-2 << *(w.rbegin()) << "\n";
    } else {
      std::cout << w << "\n";
    }
  }
}
