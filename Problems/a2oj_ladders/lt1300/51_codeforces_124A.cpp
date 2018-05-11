#include <cstdio>
#include <cstdint>
#include <cmath>
#include <algorithm>

int main(){
  int n, a, b;
  std::scanf("%i %i %i",&n,&a,&b);
  int l = a - (n - b);
  int p = n-a;
  if (l>0)
    p-=l;
  if (p > 0)
    printf("%i", p);
  else
    printf("1");
}
