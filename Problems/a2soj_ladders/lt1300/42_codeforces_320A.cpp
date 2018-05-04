#include <cstdio>
#include <cstdint>

bool isMagic(int n){
  while(n){
    if (n % 10 == 1){
      n /= 10;
    } else if (n%100 == 14) {
      n /= 100;
    } else if (n%1000 == 144){
      n /= 1000;
    } else
      return false;
  }
  return true;
}

int main(){
  int n;
  std::scanf("%i", &n);
  if (isMagic(n))
    std::printf("YES");
  else
    std::printf("NO");
}
