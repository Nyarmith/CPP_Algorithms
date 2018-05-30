#include <iostream>
#include <cstdint>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

int main(){
  unsigned int a,b,c;
  std::cin >> a >> b;
  c = a + b;

  unsigned int nc=0,nb=0,na=0;
  unsigned int pow=1;
  while (c){
    if (c%10 != 0){
      nc  += (c%10)*pow;
      pow *= 10;
    }
    c = c/10;
  }
  pow=1;
  while (b){
    if (b%10 != 0){
      nb  += (b%10)*pow;
      pow *= 10;
    }
    b = b/10;
  }
  pow=1;
  while (a){
    if (a%10 != 0){
      na  += (a%10)*pow;
      pow *= 10;
    }
    a = a/10;
  }

  if (na+nb==nc)
    std::cout << "YES";
  else
    std::cout << "NO";
}
