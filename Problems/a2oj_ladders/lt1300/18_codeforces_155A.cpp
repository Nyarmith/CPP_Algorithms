#include <cstdio>
#include <cstdint>
#include <cstdint>

int perfArr[1001];

int main(){
  uint32_t n;
  std::scanf("%u",&n);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%i",perfArr+i);
  }

  int amazings=0;
  int min, max;
  min=max=perfArr[0];
  for (uint32_t i=1; i<n; ++i){
    if (perfArr[i] < min){
      min = perfArr[i];
      ++amazings;
    } else if (perfArr[i] > max){
      max = perfArr[i];
      ++amazings;
    }
  }
  printf("%i", amazings);
}
