#include <cstdio>
#include <cstdint>
#include <cinttypes>

int main(){
  uint32_t n, l=0, r=0;
  uint32_t tl, tr;
  std::scanf("%i",&n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%i %i", &tl, &tr);
    l += tl;
    r += tr;
  }
  uint32_t altl = n-l;
  if (altl < l)
    l = altl;

  uint32_t altr = n-r;
  if (altr < r)
    r = altr;

  std::printf("%i", l+r);
}
