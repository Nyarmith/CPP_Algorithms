#include <iostream>
#include <cstdint>
#include <algorithm>

char carr[10][10];

int main(){
  int R,C;
  std::cin >> R >> C;
  for (int r=0; r<R; ++r){
    for (int c=0; c<C; ++c){
   std::cin >> carr[r][c];
 }
  }
  for (int r=0; r<R; ++r){
    if (canEatRow(r)){
   markRow(r);
 }
  }
  for (int c=0; c<C; ++c){
    if (canEatCol(c)){
   markCol(c);
 }
  }
 
  int eatable=0;
  for (int r=0; r<R; ++r){
    for (int c=0; c<C; ++c){
   eatable += carr[r][c] == ',';
 }
  }
  std::cout << eatable;
}
