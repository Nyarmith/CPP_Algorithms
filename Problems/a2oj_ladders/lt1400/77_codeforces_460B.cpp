#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

long long  s(long long  x){
  long long  ret=0;
  while(x){
    ret += x%10;
    x/=10;
  }
  return ret;
}


long long  poww(long long  num, long long  p){
  long long ret = num;
  if (p==0)
    return 1;
  --p;
  while(p){
    ret *= num;
    --p;
  }
  return ret;
}

int main(){
  long long  a,b,c,x;
  std::vector<long long > out;
  std::cin >> a >> b >> c;
  for (long long  i=1; i<=81; ++i){
    x = b*poww(i,a) + c;
    if (s(x) == i && x < 1000000000){
      out.push_back(x);
    }
  }

  std::cout << out.size() << "\n";
  for (int i=0; i<out.size(); ++i){
    std::cout << out[i] << " ";
  }
}
