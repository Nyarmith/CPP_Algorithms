#include <cstdio>
#include <cstdint>

using std::printf;
using std::scanf;
using std::uint32_t;
using std::uint64_t;

bool g_light[3][3] = {
  {1,1,1},
  {1,1,1},
  {1,1,1}
};

void toggle_grid(int r, int c, int num){
  bool toggle = num%2;
  if (toggle){
    g_light[r][c] = !g_light[r][c];
    //up-down
    if (r-1 >=0)
      g_light[r-1][c] = !g_light[r-1][c];
    if (r+1 <=2)
      g_light[r+1][c] = !g_light[r+1][c];
    //left-right
    if (c-1 >=0)
      g_light[r][c-1] = !g_light[r][c-1];
    if (c+1 <=2)
      g_light[r][c+1] = !g_light[r][c+1];
  }
}

int main(){
  uint32_t num=0;
  for (int row=0; row<3; ++row)
    for (int col=0; col<3; ++col){
      scanf("%i", &num);
      toggle_grid(row, col,num);
    }

  for (int r=0; r<3; ++r){
    for (int c=0; c<3; ++c){
      printf("%i",g_light[r][c]);
    }
    printf("\n");
  }
}
