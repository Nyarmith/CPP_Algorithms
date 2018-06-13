#include <iostream>
#include <cstdint>
#include <algorithm>


char carr[10][10];
int R,C;

bool canEatRow(int r){
  bool ret = true;
  for (int i=0; i<C; ++i){
      ret = ret && (carr[r][i] != 'S');
  }
  return ret;
}

bool canEatCol(int c){
  bool ret = true;
  for (int i=0; i<R; ++i){
      ret = ret && (carr[i][c] != 'S');
  }
  return ret;
}

void markRow(int r){
  for (int i=0; i<C; ++i){
      carr[r][i] = ',';
  }
};

void markCol(int c){
  for (int i=0; i<R; ++i){
      carr[i][c] = ',';
  }
};

int main(){
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
