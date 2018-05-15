#include <cstdio>
#include <iostream>
#include <string>
#include <array>
#include <vector>

//cool make-a-diamond problem

using vvi = std::vector<std::vector<int>>;


//if this were ncurses I'd write to the image buffer recursively
void grow_out(int n, int y, int x, int sz, vvi &A){
  if (n < 0 || A[y][x] >= n)
    return;
  A[y][x] = n;
  //pj...
  grow_out(n-1, y-1, x,   sz, A);
  grow_out(n-1, y+1, x,   sz, A);
  grow_out(n-1, y,   x-1, sz, A);
  grow_out(n-1, y,   x+1, sz, A);
}

int main(){
  int n;
  std::scanf("%i", &n);
  //if this works that's magic
  vvi vec(n*2+1,std::vector<int>(n*2+1,-1));
  grow_out(n, n, n, n, vec);
  for (int y=0; y<2*n+1; ++y){
    int bound = n + (n-std::abs(y-n));
    for (int x=0; x<=bound; ++x){
      if (vec[y][x] == -1)
        std::printf("  ");
      else
        std::printf("%i ",vec[y][x]);
    }
    std::printf("\n");
  }
}

/*
treat thing as 2*n+1x4*n+1 array
 */
