#include<cstdio>
#include<cstdlib>
#include<cstdint>

int main(){
  uint32_t n;
  std::scanf("%u", &n);

  if (n%2 == 1)
    std::printf("-1");
  else{
    for (int i=1; i<=n/2; ++i){
    std::printf("%i %i ", 2*i, 2*i-1);
    }
  }
}
