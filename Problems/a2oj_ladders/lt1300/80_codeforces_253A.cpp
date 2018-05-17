#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int B, G;
  std::cin >> B >> G;
  int reps = std::min(B,G);
  B -= reps;
  G -= reps;
  std::string ord="GB";
  std::string out="";
  if (B > 0)
    ord = "BG";

  for (int i=0; i<reps; ++i){
    out += ord;
  }
  if (B > 0)
    out += std::string(B,'B');
  else if (G > 0)
    out += std::string(G,'G');

  std::cout << out;
}
