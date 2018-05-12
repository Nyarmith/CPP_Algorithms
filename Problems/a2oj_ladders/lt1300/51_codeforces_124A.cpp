#include <cstdio>
#include <cstdint>
#include <cmath>
#include <algorithm>

int main(){
  int n, a, b;
  std::scanf("%i %i %i",&n,&a,&b);
  //int minfront = a < n-b-1 ? a : n-b-1;
  //int minback = n-a-1 < b ? n-a-1 : b;
  int minFront = a < n-b-1 ? n-b-1 : a;
  int range = n-minFront;


  if (range > 0)
    printf("%i", range);
  else
    printf("1");
}
