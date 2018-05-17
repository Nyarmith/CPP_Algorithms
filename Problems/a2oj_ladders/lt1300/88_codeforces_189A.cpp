#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(){
  std::string w;
  std::vector<std::string> G;
  for (int i=0; i<4; ++i){
    std::cin >> w;
    G.push_back(w);
  }
  bool can=false;
  for (int y=0; y<3; ++y){
    for (int x=0; x<3; ++x){
      int b = (G[y][x] == '#')
        + (G[y+1][x  ] == '#')
        + (G[y  ][x+1] == '#')
        + (G[y+1][x+1] == '#');
      if (b<=1 || b>=3)
        can = true;
    }
  }
  if (can)
    std::cout << "YES";
  else
    std::cout << "NO";
}

