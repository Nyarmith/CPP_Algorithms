#include <cstdio>
#include <cstdint>
#include <cinttypes>

int main(){
  int n, m, c;
  std::scanf("%i %i", &n, &m);
  int curHouse=1;
  uint64_t totalDist=0;

  for (int i=0; i<m; ++i){
    std::scanf("%i", &c);
    if (c < curHouse){
      totalDist += n - curHouse + c;
    } else {
      totalDist += c - curHouse;
    }
    curHouse = c;
  }
  printf("%" PRIu64, totalDist);
}
