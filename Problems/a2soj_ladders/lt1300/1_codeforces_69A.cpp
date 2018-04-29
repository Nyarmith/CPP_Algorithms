#include <cstdio>
#include <cstdint>

int main(){
  int x=0,y=0,z=0;
  int t_x=0,t_y=0,t_z=0;
  uint32_t i=0,T=0;
  scanf("%u",&T);
  while (i<T){
    scanf("%i %i %i", &t_x, &t_y, &t_z);
    x += t_x;
    y += t_y;
    z += t_z;
    ++i;
  }

  if ( x == 0 && y == 0 && z == 0)
    printf("YES\n");
  else
    printf("NO\n");

}
