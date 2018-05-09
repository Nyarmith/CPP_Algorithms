#include <cstdio>
#include <cstdint>

int g1[50];
int g2[50];

int main(){
  int n,m;

  std::scanf("%i", &n);

  for(int i=0; i<n; ++i){
    std::scanf("%i", g1+i);
  }

  std::scanf("%i", &m);

  for(int i=0; i<m; ++i){
    std::scanf("%i", g2+i);
  }

  //compare
  int maxRat=0;
  int mrw=0;
  int i=0;
  while (i<n){
    int gear1 = g1[i];
    for (int j=m-1; j>=0; --j){
      int gear2=g2[j];
      if (gear2 % gear1 == 0){
        if (gear2/gear1 > maxRat){
          maxRat = g2[j]/gear1;
          mrw=1;
        } else if (g2[j]/gear1 == maxRat){
          mrw++;
        } else {
          continue;
        }
      }
    }
    ++i;
  }
  std::printf("%i", mrw);
}
