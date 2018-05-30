#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long

int main(){
  double x,y;
  std::cin >> x >> y;
  double m = y/x < 0 ? 1 : -1;
  ll b = y - m*x;
  ll yint = b;
  ll xint = -b*m;
  if (xint < 0){
    std::cout << xint << " " << 0    << " "
              << 0    << " " << yint << "\n";
  } else {
    std::cout << 0    << " " << yint << " "
              << xint << " " << 0    << "\n";
  }
}
