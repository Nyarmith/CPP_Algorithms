#include <iostream>
#include <cstdio>
#include <string>

int main(){
  double n,x,y;
  std::cin >> n >> x >> y;
  if ((100.0*x)/n >= y){
    std::cout << 0;
  } else {
    double num = (int)(n*y/100.0);
    while (100.0*num/n < y)
      ++num;
    std::cout << num-x;
  }
}

