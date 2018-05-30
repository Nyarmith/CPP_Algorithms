#include <iostream>
#include <cstdio>
#include <cstdint>

int main(){
  std::pair<int,int> c1,c2,c3,c4;
  std::cin >> c1.first >> c1.second;
  std::cin >> c2.first >> c2.second;
  //special case
  if (c1.first != c2.first && c1.second != c2.second){
    //am I not a square?
    if (std::abs(c1.first - c2.first) != std::abs(c1.second - c2.second)){
      std::cout << "-1";
      return 0;
    } else {
      c3.first = c1.first;
      c3.second = c2.second;
      c4.first = c2.first;
      c4.second = c1.second;
    }
  } else {
    if (c1.first == c2.first){
      int ydiff = c2.second - c1.second;
      c3.first = c1.first + ydiff;
      c3.second = c1.second;
      c4.first = c1.first + ydiff;
      c4.second = c2.second;
    } else {
      int xdiff = c2.first - c1.first;
      c3.first = c1.first;
      c3.second = c1.second + xdiff;
      c4.first = c2.first;
      c4.second = c1.second + xdiff;
    }
  }

  if (c3 < c4){
    std::cout << c3.first << " " << c3.second << " " << c4.first << " " << c4.second;
  } else {
    std::cout << c4.first << " " << c4.second << " " << c3.first << " " << c3.second;
  }
}
