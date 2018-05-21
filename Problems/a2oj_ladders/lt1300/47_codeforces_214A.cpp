#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>


bool satEqns(int a, int b, int n, int m){
  return (a*a+b==n && a+b*b==m);
}

int main(){
  int n,m;
  std::vector< std::pair<int,int> > v;
  std::cin >> n >> m;
  int s = sqrt(n+m);
  int solns = 0;
  for (int a=0; a<=s; ++a){
    int b = n - a*a;
    if (b < 0)
      continue;
    if (satEqns(a,b,n,m))
      ++solns;
  }
  std::cout << solns;
}
