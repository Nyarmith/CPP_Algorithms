#include <cstdio>
#include <cstdint>

int main(){
  int maxC=0;
  int currC=0;
  int n,l,e;
  std::scanf("%i", &n);
  for (int i=0; i<n; ++i){
    std::scanf("%i %i",&l,&e);
    currC += (e-l);
    if (currC > maxC)
      maxC = currC;
  }
  std::printf("%i",maxC);
}
