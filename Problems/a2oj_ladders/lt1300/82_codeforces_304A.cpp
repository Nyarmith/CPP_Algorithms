#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

int main(){
  int numSum=0,n;
  std::scanf("%i",&n);
  for (int c=5; c<=n; ++c){
    for (int b=1; b<c; ++b){
      int a = sqrt(c*c - b*b);
        if (a<=b && a*a + b*b == c*c)
          ++numSum;
    }
  }

  std::cout << numSum;
}
