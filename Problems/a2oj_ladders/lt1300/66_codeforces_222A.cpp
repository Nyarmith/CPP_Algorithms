#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <list>

//list might be most appropraite for this interesting problem
int main(){
  uint32_t arr[100000];
  uint32_t k,n;

  std::scanf("%u %u",&n,&k);
  for (uint32_t i=0; i<n; ++i){
    std::scanf("%u", arr+i);
  }
  bool equal=true;
  for (uint32_t i=k; i<n; ++i){
    if (arr[i] != arr[i-1]){
      equal=false;
      break;
    }
  }
  if (!equal){
    std::printf("-1");
  } else {
    int i;
    equal=true;
    for (i=k-1; i>=0; --i){
      if (arr[i] != arr[k-1]){
        equal=false;
        break;
      }
    }
    if (!equal)
      printf("%i",i+1);
    else
      printf("0");
  }
}

