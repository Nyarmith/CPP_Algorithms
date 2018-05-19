#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

//ribbon cutting into denominations a,b,c but maximizing the number of cuts


int ribbon[4001];

int max(int n, int a, int b, int c){
  if (n < 0)
    return -2000000000;
  if (ribbon[n] != -2000000000)
    return ribbon[n];
  int m = std::max({max(n-a,a,b,c), max(n-b,a,b,c), max(n-c,a,b,c)}) + 1;
  ribbon[n] = m;
  return m;
}

int main(){
  std::fill(ribbon,ribbon+4001,-2000000000);
  ribbon[0] = 0;
  int n,a,b,c;
  std::scanf("%i %i %i %i",&n,&a,&b,&c);
  std::vector<int> v{a,b,c};
  std::sort(v.begin(),v.end());
  std::cout << max(n,v[0],v[1],v[2]);
}
