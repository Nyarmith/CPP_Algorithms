#include <iostream>
#include <cstdio>
#include <string>

int main(){
  int k,tmp;
  std::cin >> k;
  for (int i=0; i<k; ++i){
    double lastangle=60;
    double n=3;
    double start=180;
    std::cin >> tmp;
    if (tmp < 60){
      std::cout << "NO\n";
    } else {
      while (start/n < tmp){
        lastangle = start/n;
        ++n;
        start += 180;
      }
      if (start/n == tmp){
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
}
