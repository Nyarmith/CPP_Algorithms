#include <cstdio>
#include <cstdint>
#include <cstdlib>

int main(){
  int n, i=0, j=0;
  for (int row=1; row<=5; ++row){
    for (int col=1; col <=5; ++col){
      scanf("%i",&n);
      if (n == 1){
        i=row; j=col;
      }
    }
  }

  printf("%i", std::abs(i-3) + std::abs(j-3));
}
