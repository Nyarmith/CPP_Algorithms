#include <iostream>
#include <string>
#include <cstdio>

uint64_t num=0;

uint64_t magic(uint64_t n){
  uint64_t ret=0;
  while (n){
    ret += n%10;
    n /= 10;
  }
  return ret;
}

int main(){
  int casts=0;
  std::string numstr;
  //char c;
  std::cin >> numstr;
  if (numstr.size() > 1){
    ++casts;
  }
  for (int i=0; i<numstr.length(); ++i){
    num += numstr[i] - '0';
  }

  while (num > 9){
    num = magic(num);
    ++casts;
  }
  std::cout << casts;
}
