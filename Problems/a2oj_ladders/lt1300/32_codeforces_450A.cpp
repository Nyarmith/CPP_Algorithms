#include <cstdio>
#include <cstdint>

using std::uint32_t;
using std::printf;
using std::scanf;

const int MAXK=100;
int kid[100] = {0};

int main(){
  uint32_t kids, candyfeed, c;
  scanf("%u %u", &kids, &candyfeed);

  for (uint32_t i=0; i < kids; ++i){
    scanf("%u", &c);
    kid[i] = c;
  }

  uint32_t lastkid=0;
  bool empty=false;
  while (!empty){
    empty=true;
    for (uint32_t i=0; i < kids; ++i){
      if (kid[i] > 0){
        lastkid=i;
        kid[i] -= candyfeed;
        empty=false;
      }
    }
  }

  printf("%i", (lastkid+1));
}
