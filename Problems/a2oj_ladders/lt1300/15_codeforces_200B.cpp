#include <cstdio>
#include <cstdlib>

int main(){
  int n;
  double avg=0;
  int c;
  std::scanf("%i",&n);
  for (int i=0; i<n; ++i){
    std::scanf("%i",&c);
    avg += c;
  }
  std::printf("%.10f", avg/(double)n);
}
