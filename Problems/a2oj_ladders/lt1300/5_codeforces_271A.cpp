#include <cstdio>
#include <cstdint>

using std::uint32_t;

bool isdistinct(uint32_t y){
  int digits[10]={0};
  while(y){
    digits[y%10]++;
    y/=10;
  }

  for (int i=0; i<10; ++i)
    if (digits[i] > 1)
      return false;

  return true;
}

int main(){
  uint32_t y, y_t;
  std::scanf("%u", &y);
  y_t = y+1;
  while (!isdistinct(y_t)) ++y_t;
  
  printf("%i", y_t);
}
