#include <iostream>
#include <cmath>
#include <cstdint>
#include <cinttypes>

/* This was just for fun, huh
struct vec2{
  int x,y;
  vec2(int x=0,int y=0):x(x),y(y){}
  vec2 operator-(const vec2& o){
    return vec2(x-o.x,y-o.y);
  }
  vec2 operator_(const vec2& o){
    return vec2(x+o.x,y+o.y);
  }
};*/


int main(){
  long long int  n, sx, sy, ex, ey;
  int earliestTime=-1;
  char strArr[100000];

  std::cin >> n >> sx >> sy >> ex >> ey;
  long long xdir = 0;
  long long ydir = 0;

  if (ey > sy)
    ydir = 1;
  else if (ey < sy)
    ydir = -1;

  if (ex > sx)
    xdir = 1;
  else if (ex < sx)
    xdir = -1;

  std::scanf("%s",strArr);

  for (int i=0; i<n; ++i){
    switch(strArr[i]){
      case 'N':
        if (ydir > 0)
          ++sy;
        break;
      case 'S':
        if (ydir < 0)
          --sy;
        break;
      case 'E':
        if (xdir > 0)
          ++sx;
        break;
      case 'W':
        if (xdir < 0)
          --sx;
        break;
    }
    if (sx == ex)
      xdir=0;
    if (sy == ey)
      ydir=0;
    if (sx == ex && sy == ey && earliestTime == -1)
      earliestTime = i+1;
  }
  std::cout << earliestTime;
}
